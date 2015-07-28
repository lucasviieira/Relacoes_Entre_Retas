#include <stdio.h>

int vetorDiretor1[3];
int vetorDiretor2[3];
int ponto1[3];
int ponto2[3];
int vetorDiretor12[3];

void recebeDados();
void mostraDados();
int retasReversas(int *vetorDiretor1, int *vetorDiretor2, int *vetorDiretor12);

void recebeDados(){

    //recebe as coordenas do ponto em que a reta 1 passa ponto1(X1,Y1,Z1)
    printf("Uma reta deve passar por um ponto A(x,y,z) e deve possuir um vetor diretor(a,b,c).\n");

    printf("\nDigite a coordenada em X do ponto em que a reta 1 passa.\n");
    scanf("%d", &ponto1[0]);
    printf("Digite a coordenada em Y do ponto em que a reta 1 passa.\n");
    scanf("%d", &ponto1[1]);
    printf("Digite a coordenada em Z do ponto em que a reta 1 passa.\n");
    scanf("%d", &ponto1[2]);

    //recebe as coordenas do ponto em que a reta 1 passa ponto2(X2,Y2,Z2)
    printf("\nDigite a coordenada em X do ponto em que a reta 2 passa.\n");
    scanf("%d", &ponto2[0]);
    printf("Digite a coordenada em Y do ponto em que a reta 2 passa.\n");
    scanf("%d", &ponto2[1]);
    printf("Digite a coordenada em Z do ponto em que a reta 2 passa.\n");
    scanf("%d", &ponto2[2]);

    //recebe as coordenas do vetor diretor da reta 1(a1,b1,c1)
    printf("\nDigite a coordenada em X do vetor diretor da reta1.\n");
    scanf("%d", &vetorDiretor1[0]);
    printf("Digite a coordenada em Y do vetor diretor da reta1.\n");
    scanf("%d", &vetorDiretor1[1]);
    printf("Digite a coordenada em Z do vetor diretor da reta1.\n");
    scanf("%d", &vetorDiretor1[2]);

    //recebe as coordenas do vetor diretor da reta 2(a2,b2,c2)
    printf("\nDigite a coordenada em X do vetor diretor da reta2.\n");
    scanf("%d", &vetorDiretor2[0]);
    printf("Digite a coordenada em Y do vetor diretor da reta2.\n");
    scanf("%d", &vetorDiretor2[1]);
    printf("Digite a coordenada em Z do vetor diretor da reta2.\n");
    scanf("%d", &vetorDiretor2[2]);

    vetorDiretor12[0] = (vetorDiretor2[0] - vetorDiretor1[0]);
    vetorDiretor12[1] = (vetorDiretor2[1] - vetorDiretor1[1]);
    vetorDiretor12[2] = (vetorDiretor2[2] - vetorDiretor1[2]);
}

void mostraDados(){
// fun��o que mostra os pontos e vetores diretores digitados pelo usu�rio
int i = 0;
int contador = 0;

    while(contador < 5){
        printf("\n");
        for(i = 0; i < 3; i++){
            // mostra as coordernadas do ponto 1
            if(contador == 0){
                if(i == 0){
                    printf("\nPonto 1 = ");
                }
                printf("[%d] ", ponto1[i]);
            }
            if(contador == 1){
            // mostra as coordernadas do ponto 2
                if(i == 0){
                    printf("Ponto 2 = ");
                }
                printf("[%d] ", ponto2[i]);
            }
            if(contador == 2){
             // mostra as coordernadas do vetor diretor 1
                if(i == 0){
                    printf("Vetor Diretor 1 = ");
                }
                printf("[%d] ", vetorDiretor1[i]);
            }
            if(contador == 3){
            // mostra as coordernadas do vetor diretor 2
                if(i == 0){
                    printf("Vetor Diretor 2 = ");
                }
                printf("[%d] ", vetorDiretor2[i]);
            }
            if(contador == 4){
            // mostra as coordernadas do vetor diretor 12
                if(i == 0){
                    printf("Vetor Diretor 12 = ");
                }
                printf("[%d] ", vetorDiretor12[i]);
            }
        } contador++;
    } printf("\n");
}

int retasReversas(int *vetorDiretor1, int *vetorDiretor2, int *vetorDiretor12){
// fazendo o determinante entre os vetores diretores � possivel determinar se as retas s�o reversas ou n�o.
int determinante = 0;
determinante+= (vetorDiretor1[0] * vetorDiretor2[1] * vetorDiretor12[2]);
determinante+= (vetorDiretor1[1] * vetorDiretor2[2] * vetorDiretor12[0]);
determinante+= (vetorDiretor1[2] * vetorDiretor2[0] * vetorDiretor12[1]);
determinante+= (vetorDiretor1[2] * vetorDiretor2[1] * vetorDiretor12[0])*-1;
determinante+= (vetorDiretor1[0] * vetorDiretor2[2] * vetorDiretor12[1])*-1;
determinante+= (vetorDiretor1[1] * vetorDiretor2[0] * vetorDiretor12[2])*-1;

    //printf("\nO determinante eh: %d \n", determinante);
// se o determinante der 0 os vetores diretores s�o coplanares e portanto as retas n�o s�o reversas
    if(determinante == 0) return 0;
// se o determinante der diferente de 0 os vetores diretores n�o s�o coplanares e portanto as retas s�o reversas
    else return 1;
}


int main(){

int vetorTeste1[3] = {1,-3,3};
int vetorTeste2[3] = {1,2,-2};
int vetorTeste3[3] = {0,-1,1};

    //recebeDados();
    //mostraDados();

// testa se as retas s�o reversas:
    if(retasReversas(vetorTeste1, vetorTeste2, vetorTeste3))
        printf("\nAs retas sao reversas\n");
    }
    else{
        printf("\nAs retas nao sao reversas\n");
    }


return 0;
}

