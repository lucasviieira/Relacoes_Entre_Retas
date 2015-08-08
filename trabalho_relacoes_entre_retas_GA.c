#include <stdio.h>
#include <stdlib.h>

float vetorDiretor1[3];
float vetorDiretor2[3];
float ponto1[3];
float ponto2[3];
float vetorDiretor12[3];
float pontoInter[3];

void recebeDados();
void mostraDados();
void menu();
void pontoIntersecao(float *vetorDiretor1, float *vetorDiretor2, float *ponto1, float *ponto2);
void verificaRetas(float *vetorDiretor1, float *vetorDiretor2, float *vetorDiretor12, float *ponto1, float *ponto2);
int retasReversas(float *vetorDiretor1, float *vetorDiretor2, float *vetorDiretor12);
int retasOrtogonais(float *vetorDiretor1, float *vetorDiretor2);
int retasParalelas(float *vetorDiretor1, float *vetorDiretor2);
int retasCoincidentes(float *ponto2, float *vetorDiretor1, float *ponto1);

void recebeDados(){

    system("cls");
    printf("Um reta passa por um ponto A(x,y,z) e possui um vetor diretor(a,b,c).\n");
    //recebe as coordenas do ponto em que a reta 1 passa ponto 1(X1,Y1,Z1)
    printf("\nDigite a coordenada em X do ponto em que a reta 1 passa.\n");
    scanf("%f", &ponto1[0]);
    printf("Digite a coordenada em Y do ponto em que a reta 1 passa.\n");
    scanf("%f", &ponto1[1]);
    printf("Digite a coordenada em Z do ponto em que a reta 1 passa.\n");
    scanf("%f", &ponto1[2]);

    //recebe as coordenas do vetor diretor da reta 1(a1,b1,c1)
    printf("\nDigite a coordenada em X do vetor diretor da reta1.\n");
    scanf("%f", &vetorDiretor1[0]);
    printf("Digite a coordenada em Y do vetor diretor da reta1.\n");
    scanf("%f", &vetorDiretor1[1]);
    printf("Digite a coordenada em Z do vetor diretor da reta1.\n");
    scanf("%f", &vetorDiretor1[2]);
    
        //recebe as coordenas do ponto em que a reta 2 passa ponto 2(X2,Y2,Z2)
    printf("\nDigite a coordenada em X do ponto em que a reta 2 passa.\n");
    scanf("%f", &ponto2[0]);
    printf("Digite a coordenada em Y do ponto em que a reta 2 passa.\n");
    scanf("%f", &ponto2[1]);
    printf("Digite a coordenada em Z do ponto em que a reta 2 passa.\n");
    scanf("%f", &ponto2[2]);

    //recebe as coordenas do vetor diretor da reta 2(a2,b2,c2)
    printf("\nDigite a coordenada em X do vetor diretor da reta2.\n");
    scanf("%f", &vetorDiretor2[0]);
    printf("Digite a coordenada em Y do vetor diretor da reta2.\n");
    scanf("%f", &vetorDiretor2[1]);
    printf("Digite a coordenada em Z do vetor diretor da reta2.\n");
    scanf("%f", &vetorDiretor2[2]);

    vetorDiretor12[0] = (ponto2[0] - ponto1[0]);
    vetorDiretor12[1] = (ponto2[1] - ponto1[1]);
    vetorDiretor12[2] = (ponto2[2] - ponto1[2]);

    mostraDados();
    verificaRetas(vetorDiretor1, vetorDiretor2, vetorDiretor12, ponto1, ponto2);
}

void mostraDados(){
// funcao que mostra os pontos e vetores diretores digitados pelo usuario
int i = 0;
int contador = 0;

system("cls");

    while(contador < 5){
        //printf("\n");
        for(i = 0; i < 3; i++){
            // mostra as coordernadas do ponto 1
            if(contador == 0){
                if(i == 0){
                    printf("Ponto 1 = ");
                }
                printf("[%.1f] ", ponto1[i]);
            }
            if(contador == 1){
            // mostra as coordernadas do ponto 2
                if(i == 0){
                    printf("Ponto 2 = ");
                }
                printf("[%.1f] ", ponto2[i]);
            }
            if(contador == 2){
             // mostra as coordernadas do vetor diretor 1
                if(i == 0){
                    printf("Vetor Diretor 1 = ");
                }
                printf("[%.1f] ", vetorDiretor1[i]);
            }
            if(contador == 3){
            // mostra as coordernadas do vetor diretor 2
                if(i == 0){
                    printf("Vetor Diretor 2 = ");
                }
                printf("[%.1f] ", vetorDiretor2[i]);
            }
            if(contador == 4){
            // mostra as coordernadas do vetor diretor 12
                if(i == 0){
                    printf("Vetor Diretor 12 = ");
                }
                printf("[%.1f] ", vetorDiretor12[i]);
            }
        } printf("\n");
        contador++;
    } printf("\n");
}

int retasReversas(float *vetorDiretor1, float *vetorDiretor2, float *vetorDiretor12){
// fazendo o determinante entre os vetores diretores eh possivel determinar se as retas sao reversas ou nao.
float determinante = 0.0;
determinante+= (vetorDiretor1[0] * vetorDiretor2[1] * vetorDiretor12[2]);
determinante+= (vetorDiretor1[1] * vetorDiretor2[2] * vetorDiretor12[0]);
determinante+= (vetorDiretor1[2] * vetorDiretor2[0] * vetorDiretor12[1]);
determinante+= (vetorDiretor1[2] * vetorDiretor2[1] * vetorDiretor12[0])*-1;
determinante+= (vetorDiretor1[0] * vetorDiretor2[2] * vetorDiretor12[1])*-1;
determinante+= (vetorDiretor1[1] * vetorDiretor2[0] * vetorDiretor12[2])*-1;

    //printf("\nO determinante eh: %d \n", determinante);
// se o determinante der 0 os vetores diretores sao coplanares e portanto as retas nao sao reversas
    if(determinante == 0.0) return 0;
// se o determinante der diferente de 0 os vetores diretores nao sao coplanares e portanto as retas sao reversas
    else return 1;
}

int retasOrtogonais(float *vetorDiretor1, float *vetorDiretor2){

float resultado = 0;
int i = 0;
    // se o produto escalar entre os vetores diretores for 0, as retas sao ortogonais.
    for(i = 0; i < 3; i++){
        resultado+= vetorDiretor1[i] * vetorDiretor2[i];
    }
    if(resultado == 0) return 1;
    else return 0;
}

int retasParalelas(float *vetorDiretor1, float *vetorDiretor2){

int erro[3] = {4,4,4};
float k[3];
int i = 0;

    // se existir um K que seja possivel escrever vetorDiretor1 = k*vetorDiretor2, entao as retas sao paralelas
    for(i = 0; i < 3; i++){
        // testa se as coordenadas sao 0
        if(vetorDiretor1[i] == 0.0 && vetorDiretor2[i] == 0.0){
            erro[i] = 1;
        }
        else if(vetorDiretor1[i] == 0.0){
            k[i] = 158;
        }
        else if(vetorDiretor2[i] == 0.0){
            k[i] = 159;
        }
        else{
            k[i] = vetorDiretor1[i] / vetorDiretor2[i];
        }
    }
    // caso haja duas coordernadas com 0 na mesma posição, o programa "pula" essas coordenadas
    if(erro[0] == 1){
        k[0] = k[1];
        if(erro[1] == 1){
            k[0] = k[2];
            k[1] = k[2];
        }
        else if(erro[2] == 1){
            k[0] = k[1];
            k[2] = k[1];
        }
    }
    else if(erro[1] == 1){
        k[1] = k[0];
        if(k[2] == 1){
            k[2] = k[0];
        }
    }else if(erro[2] == 1){
        k[2] = k[1];
    }

    if(k[0] == k[1] && k[1] == k[2]) return 1;
    else return 0;
}

int retasCoincidentes(float *ponto1, float *vetorDiretor1, float *ponto2){

float lambda[3] = {99,99,99};
int erro[3] = {4,4,4};
int erros = 0;
int ignore[3] = {0,0,0};
int i = 0;
    // testa se as retas sao as mesmas retas, para isso eh necessario testar o ponto de uma na outra,
    // caso o lambda seja o mesmo para todas as coordenadas, entao sao as mesmas retas
    for(i = 0; i < 3; i++){
        if(vetorDiretor1[i] == 0){
        erro[i] = 1;
        }
        else
        {
            lambda[i] = (ponto2[i] + (-ponto1[i])) / vetorDiretor1[i];
        }
    }
    // testa se tem posicoes com zero
    if(erro[0] == 1){
        if(ponto2[0] == ponto1[0]){
            ignore[0] = 1;
            erros++;
        }
    }
    if(erro[1] == 1){
        if(ponto2[1] == ponto1[1]){
            ignore[1] = 1;
            erros++;
        }
    }
    if(erro[2] == 1){
        if(ponto2[2] == ponto1[2]){
            ignore[2] = 1;
            erros++;
        }
    }

    if(erros == 0)
    {
        if(lambda[0] == lambda[1] && lambda[0] == lambda[2])    return 1;
        else    return 0;
    }
    else if(erros == 1)
    {
        if(ignore[0] == 0 && ignore[1] == 0){
            if(lambda[0] == lambda[1])    return 1;
            else    return 0;
        }
        else if(ignore[0] == 0 && ignore[2] == 0){
            if(lambda[0] == lambda[2])    return 1;
            else    return 0;
        }
        else if(ignore[1] == 0 && ignore[2] == 0){
            if(lambda[1] == lambda[2])    return 1;
            else    return 0;
        }
    }
    else{
        return 1;
    }

}

void pontoIntersecao(float *vetorDiretor1, float *vetorDiretor2, float *ponto1, float *ponto2){

float lambda = 0;
float tempomi1 = 0;
float tempomi2 = 0;
float tempolambda1 = 0;
float tempolambda2 = 0;
float mi = 0;
float teste = 0;
int incoginata = 0;

    //o ponto eh determinando igualando as equacoes parametricas das retas
    //caso haja duas posicoes iguais dos vetores diretores com 0, sera testado as outras duas posicoes
    if(vetorDiretor1[0] == 0 && vetorDiretor2[0] == 0){
        tempomi1 = (ponto1[1] - ponto2[1])/vetorDiretor2[1];

        tempomi2 = (ponto1[2] - ponto2[2]);
        tempomi2 = tempomi2 / vetorDiretor2[2];

        tempolambda1 = (tempomi1 - tempomi2);

        tempolambda2 = (vetorDiretor1[2]/vetorDiretor2[2]) + (-1*(vetorDiretor1[1]/vetorDiretor2[1]));

        lambda = tempolambda1/tempolambda2;

        incoginata = 1;
    }
    else if(vetorDiretor1[1] == 0 && vetorDiretor2[1] == 0){
        tempomi1 = (ponto1[0] - ponto2[0])/vetorDiretor2[0];

        tempomi2 = (ponto1[2] - ponto2[2]);
        tempomi2 = tempomi2 / vetorDiretor2[2];

        tempolambda1 = (tempomi1 - tempomi2);

        tempolambda2 = (vetorDiretor1[2]/vetorDiretor2[2]) + (-1*(vetorDiretor1[0]/vetorDiretor2[0]));

        lambda = tempolambda1/tempolambda2;

        incoginata = 1;
    }
    else if(vetorDiretor1[2] == 0 && vetorDiretor2[2] == 0){
        tempomi1 = (ponto1[0] - ponto2[0])/vetorDiretor2[0];

        tempomi2 = (ponto1[1] - ponto2[1]);
        tempomi2 = tempomi2 / vetorDiretor2[1];

        tempolambda1 = (tempomi1 - tempomi2);

        tempolambda2 = (vetorDiretor1[1]/vetorDiretor2[1]) + (-1*(vetorDiretor1[0]/vetorDiretor2[0]));

        lambda = tempolambda1/tempolambda2;

        incoginata = 1;
    }
    else{
        //caso haja alguma posicao do vetor diretor com zero, eh possivel descobrir o lambda direto
        if(vetorDiretor2[0] == 0){
            lambda = (ponto2[0] - ponto1[0])/vetorDiretor1[0];
            incoginata = 1;
        }
        else if(vetorDiretor2[1] == 0){
            lambda = (ponto2[1] - ponto1[1])/vetorDiretor1[1];
            incoginata = 1;
        }
        else if(vetorDiretor2[2] == 0){
            lambda = (ponto2[2] - ponto1[2])/vetorDiretor1[2];
            incoginata = 1;
        }
        //caso haja alguma posicao do vetor diretor com zero, eh possivel descobrir o mi direto
        else if(vetorDiretor1[0] == 0){
            mi = (ponto1[0] - ponto2[0])/vetorDiretor2[0];
        }
        else if(vetorDiretor1[1] == 0){
            mi = (ponto1[1] - ponto2[1])/vetorDiretor2[1];
        }
        else if(vetorDiretor1[2] == 0){
            mi = (ponto1[2] - ponto2[2])/vetorDiretor2[2];
        }

        else{
            tempomi1 = (ponto1[0] - ponto2[0])/vetorDiretor2[0];

            tempomi2 = (ponto1[1] - ponto2[1]);
            tempomi2 = tempomi2 / vetorDiretor2[1];

            tempolambda1 = (tempomi1 - tempomi2);

            tempolambda2 = (vetorDiretor1[1]/vetorDiretor2[1]) + (-1*(vetorDiretor1[0]/vetorDiretor2[0]));

            lambda = tempolambda1/tempolambda2;

            incoginata = 1;
        }
    }

    //mi = ((ponto1[0] + (-1*ponto2[0]))/vetorDiretor2[0]) + ((vetorDiretor1[0]/vetorDiretor2[0])*lambda);

    if(incoginata == 1){
        pontoInter[0] = ponto1[0] + (vetorDiretor1[0]*lambda);
        pontoInter[1] = ponto1[1] + (vetorDiretor1[1]*lambda);
        pontoInter[2] = ponto1[2] + (vetorDiretor1[2]*lambda);
    }
    else{
        pontoInter[0] = ponto2[0] + (vetorDiretor2[0]*mi);
        pontoInter[1] = ponto2[1] + (vetorDiretor2[1]*mi);
        pontoInter[2] = ponto2[2] + (vetorDiretor2[2]*mi);
    }

}

void menu(){

int escolha = 0;
    system("cls");
    printf("Programa de classificacao da posicao relativa de duas retas no espaco\n");
    printf("Digite o numero da opcao desejada\n\n");
    printf("1 - Verificar Retas\n");
    printf("2 - Informacoes sobre as posicoes relativas entre retas\n");
    printf("3 - Creditos\n");
    printf("4 - Sair\n");
    scanf("%d", &escolha);

    if(escolha == 1){
        recebeDados();
    }
    else if(escolha == 2){
        system("cls");
        printf("Duas retas podem ser classificar de 3 formas:\n");
        printf("A) Retas Reversas - Retas que nao estao num mesmo plano\n");
        printf("B) Retas Paralelas - Retas que estao num mesmo plano mas nunca se cruzam\n");
        printf("C) Retas Concorrentes - Retas que se cruzam num unico ponto\n");
        printf("\n A) Duas retas sao reversas se o produto misto entre seus vetores diretores e o vetor formado pelo ponto A e B, der 0\n");
        printf("\n B) Sao paralelas as retas cujos vetores diretores sao paralelos\n");
        printf("\n C) Retas concorrentes podem ser ortogonais entre si\n\n");
        system("pause");
        menu();
    }
    else if(escolha == 3){
        system("cls");
        printf("Este programa foi desenvolvido para a disciplina de Geometria Analitica e Calculo Vetorial.\n");
        printf("\nO mesmo foi criado pelos alunos:\n\n- Lucas Leandro\n- Jesse Clemente\n- Ocimar Henrique\n\n");
        system("pause");
        menu();
    }
    else if(escolha == 4){
        exit(0);
    }
    else{
        printf("Digite uma opcao valida..\n\n");
        system("pause");
        menu();
    }
}

void verificaRetas(float *vetorDiretor1, float *vetorDiretor2, float *vetorDiretor12, float *ponto1, float *ponto2){

float vetorTeste1[3] = {0,-1,1};
float vetorTeste2[3] = {0,2,-2};
float pontoTeste1[3] = {2,5,-4};
float pontoTeste2[3] = {2,0,1};
float vetorTeste3[3] = {0,-5,5};

    // testa se as retas sao reversas:
    if(retasReversas(vetorDiretor1, vetorDiretor2, vetorDiretor12)){
        printf("As retas sao reversas\n");

        // caso sejam reversas, testa se alem de reversas, sao ortogonais
        if(retasOrtogonais(vetorDiretor1, vetorDiretor2)){
            printf("\nE sao retas ortogonais\n");
        }

    }
    else{
        // se elas nao forem reversas, testa se sao paralelas
        if(retasParalelas(vetorDiretor1, vetorDiretor2)){
            printf("\nAs retas sao paralelas\n");

            // se elas forem paralelas, testa se alem de paralelas, sao as mesmas retas
            if(retasCoincidentes(ponto2,vetorDiretor2,ponto1)){
                printf("\nE sao retas coincidentes\n");
            }
            else{
                printf("\nPorem sao retas distintas\n");
            }
        }
        else{
            //caso elas nao sejam reversas nem paralelas, elas sao retas concorrentes
            printf("\nAs retas sao concorrentes\n");

            // testa se alem de concorrentes, elas sao ortogonais
            if(retasOrtogonais(vetorDiretor1, vetorDiretor2)){
                printf("\nE sao retas ortogonais\n");
            }
            // testa o ponto de intersecao entre as retas
            pontoIntersecao(vetorDiretor1, vetorDiretor2, ponto1, ponto2);
            printf("\nAs Retas se encontram no ponto de coordenadas [%.1f] [%.1f] [%.1f]\n", pontoInter[0], pontoInter[1], pontoInter[2]);
        }
    }
    printf("\n");
    system("pause");
    menu();
}

int main(){

    menu();
    return 0;
}
