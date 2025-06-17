#include <stdio.h>
#include <stdlib.h>
#define BANNER_CALCULOdAREA "Bem vindo! vamos fazer um calculo de area.\n"
#define BANNER_CADASTRO "Ola, vamos fazer um breve cadastro."

int calcular_area();
int cadastro();

int main(void) {
    int opc;
    cadastro();
    system("clear");

    do {
        printf("digite 1 para fazer o calculo de area, ou digite 2 para encerrar:  ");
        
        if (scanf("%d", &opc)!= 1) {
            while (getchar() != '\n');
        }

    } while (opc != 1 && opc != 2);
    
    if (opc == 1) {
        system("clear");
        calcular_area();

    } else if (opc == 2) {
        printf("Ok, Adeus...\n");
        return 0;
        
    } else {
        printf("opcao invalida! por favor digite 1 ou 2: ");
        scanf("%d", &opc);
    }
 
    return 0;   
    } 


int cadastro() {

    printf("%s\n", BANNER_CADASTRO);
    
    typedef struct {
        char nome[50];
        char idade[2];
    }usuario;

    usuario p1;

    printf("Digite seu nome: ");
    scanf("%s", p1.nome);

    printf("Digite sua idade: ");
    scanf("%s", p1.idade);

    return 0;
}


int calcular_area() {
    printf("%s\n", BANNER_CALCULOdAREA);

    float base,altura,area;

    printf("Digite a base: ");
    scanf("%f", &base);

    printf("Digite a altura: ");
    scanf("%f", &altura);

    area = base * altura;
    
    system("clear");

    printf("A area e de: %.2fm²\n", area);

    return area;
}

