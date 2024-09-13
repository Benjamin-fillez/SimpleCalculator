#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int make_calcul_format(int x, int y, char operator){
    switch(operator){
        case '+':
            return x + y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '-':
            return x - y;
        case '%':
            return x % y;
    }
}

char enter_format_operator(){
    char operator;
    scanf("%c",&operator);
    while(operator == '%'){
        if(operator == '+'){
            break;
        }
        else if(operator == '-'){
            break;
        }
        else if(operator == '/'){
            break;
        }
        else if(operator == '-'){
            break;
        }
        scanf("%c",&operator);
    }
}

int enter_num(int x){
    printf("\nEntrez un nombre: ");
    scanf("%d",&x);
    return x;
}

char select_mode(char);
void enter_file_name(char[256]);

int main(){
    char _mode;
    char file_name[256];

    enter_file_name(file_name);
    _mode = select_mode(_mode);

    FILE *open_txt_file = NULL;
    if(_mode == 'w'){
        open_txt_file = fopen(file_name, "w");
    }
    else if(_mode == 'a'){
        open_txt_file = fopen(file_name, "a");
    }
    else if (_mode == 'r'){
        open_txt_file = fopen(file_name, "r");
    }

    if(open_txt_file == NULL){
        perror("Fichier non existant ou format non valable.\n");
        return 1;
    }

    int x;
    int y;

    int exit;

    char enter_calcul_mode;
    char operator;
    char random_num_mode;

    do{
        printf("\nSi vous voulez faire un calcul est l'enregister dans le fichier que vous avez mit\nEcrivez \"y\" si vous voulez juste sortir ecrivez \"n\"\n");
        while(enter_calcul_mode != 'y'){
            if(enter_calcul_mode == 'n'){
                break;
            }
            scanf("%c",&enter_calcul_mode);
        };
        if(enter_calcul_mode == 'y'){
            printf("\nEntrer un signe d'operation pour faire un calcul: ");
            operator = enter_format_operator();
            switch(operator){
                case '%': break;
                case '+': break;
                case '-': break;
                case '/': break;
                case '*': break;
                default:
                    operator = enter_format_operator();
                    break;
            }
            printf("Vous voulez vous inserez les nombres vous meme ou les mettres en aleatoire ?\n");
            while(random_num_mode != 'y'){
                if(random_num_mode == 'n'){
                    break;
                }
                scanf("%c",&random_num_mode);
            };
            if(random_num_mode == 'y'){
                srand(time(0));
                x = (rand() % 10000) + 1;
                y = (rand() % 10000) + 1;
                int result = make_calcul_format(x,y,operator);
                if(_mode == 'w' || _mode == 'a'){
                    char format_calcul[256];
                    if(operator != '+' && operator != '*' && operator != '/' && operator != '-'){
                        result = x % y;
                        snprintf(format_calcul,256,"Calcul: %d %% %d = %d\n",x,y,result);
                    }
                    else{
                        snprintf(format_calcul,256,"Calcul: %d %c %d = %d\n",x,operator,y,result);
                    }
                    fputs(format_calcul,open_txt_file);
                }
                else{
                    printf("\nMode lecture activer, votre calcul ne sera pas ajouter a l'historique.\n");
                }
            }
            else{
                x = enter_num(x);
                y = enter_num(y);
                int result = make_calcul_format(x,y,operator);
                if(_mode == 'w' || _mode == 'a'){
                    char format_calcul[256];
                    if(operator != '+' && operator != '*' && operator != '/' && operator != '-'){
                        result = x % y;
                        snprintf(format_calcul,256,"Calcul: %d %% %d = %d\n",x,y,result);
                    }
                    else{
                        snprintf(format_calcul,256,"Calcul: %d %c %d = %d\n",x,operator,y,result);
                    }
                    fputs(format_calcul,open_txt_file);
                }
                else{
                    printf("\nMode lecture activer, votre calcul ne sera pas ajouter a l'historique.\n");
                }
            }
        }
        else{
            printf("\n");
            printf("Entrer -1 pour quitter: ");
            while(exit != -1){
                scanf("%d",&exit);
                if (exit == -1){
                    break;
                }
                else{
                    printf("Veuillez mettre \"-1\" pour quitter: ");
                };
            }
            if (exit == -1){
                break;
            }       
        }
    }while(exit == -1);

    return 0;
}

char select_mode(char mode){
    printf("Entrer (w = ecrire,r = lire,a = ajouter) \npour ouvrir un fichier avec un mode specifique\n");
    while(mode != 'w'){
        scanf("%c",&mode);
        if(mode == 'r'){
            break;
        }
        else if(mode == 'a'){
            break;
        }
        else if(mode == 'a'){
            break;
        }
    };
    return mode;
}

void enter_file_name(char name[256]){
    printf("Entrer un nom de fichier (.txt) pour l'ouverture de celui ci ");
    fgets(name,256,stdin);
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }
    printf("\n");
}
