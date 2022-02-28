/*
 * @file: base-calculadora.c
 * @date: 28 Feb 2022
 * @author: Lucas Prado and João Paulo
 * @brief: 
 *  - Projeto Base - Utilizando C para o projeto da calculadora
 * EM PROGRESSO...
 * 
 *  - Base Project - Using C to the calculator's project
 * IN PROGRESS...
 * 
 * CODE IN PORTUGUESE-BR
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void calculadoraBasica();
void calculaQuadratica();
//void calculaDDQ(); - Diferença de quadrados
//void calculaPN(); - Produto Notável
//void calculaDerivada();
//void calculaIntegral();


int main(){
    int opcao;
    int opcaoInterna;
    printf("1 - Calculadora Básica\n2 - Equações\n3 - Calculadora Binário\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);
    switch(opcao) {
        case 1:
            calculadoraBasica();
            break;
        case 2:
            printf("1 - Quadrática(Bhaskara\n2 - Diferença de Quadrados\n3 - Produto Notável\n4 - Derivada\n5 - Integral\n");
            scanf("%d", &opcaoInterna);
            switch(opcaoInterna){
                case 1:
                    calculaQuadratica();
                
                /*case 2:
                    //codigo
                    
                case 3:
                    //codigo

                case 4:
                    //codigo
                    
                case 5:
                    //codigo
                */
            }//switch interno
    }//switch externo
    return 0;
}//main

void calculadoraBasica(){
    int opcaoInterna, numeros;
    float acumulador;
    printf("1 - Adição\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\n");
    scanf("%d", &opcaoInterna);
    printf("Deseja ultizar quantos números?: ");
    scanf("%d", &numeros);
    float quantidade[numeros];

    switch(opcaoInterna){
        case 1: //adicao
            acumulador = 0;
            for(int i = 0; i < numeros; i++){
                printf("Digite o número %d: ", i + 1);
                scanf("%f", &quantidade[i]);
            }//for
            for(int i = 0; i < numeros; i++){
                acumulador += quantidade[i];
            }//for
            printf("Resultado: %.3f\n", acumulador);
            break;

        case 2: //subtraçáo
            for(int i = 0; i < numeros; i++){
                printf("Digite o número %d: ", i + 1);
                scanf("%f", &quantidade[i]);
            }//for
            acumulador = quantidade[0];
            for(int i = 1; i < numeros; i++){
                acumulador -= quantidade[i];
            }//for
            printf("Resultado: %.3f\n", acumulador);
            break;
            
        case 3: //multiplicação
            acumulador = 1;
            for(int i = 0; i < numeros; i++){
                printf("Digite o número %d: ", i + 1);
                scanf("%f", &quantidade[i]);
            }//for
            acumulador = quantidade[0];
            for(int i = 1; i < numeros; i++){
                acumulador *= quantidade[i];
            }//for
            printf("Resultado: %.3f\n", acumulador);
            break;

        case 4: //divisão
            for(int i = 0; i < numeros; i++){
                printf("Digite o número %d: ", i + 1);
                scanf("%f", &quantidade[i]);
            }//for
            acumulador = quantidade[0];
            for(int i = 1; i < numeros; i++){
                acumulador /= quantidade[i];
            }//for
            printf("Resultado: %.3f\n", acumulador);
            break;
    }//switch
}//calculadoraBasica

void calculaQuadratica(){
    //declarar variavéis
    float A, B, C, delta, x1, x2, vxmax, vymax;

    //Pedir equação
    printf("Sabendo que AX^2 + BX + C\n");
    printf("Digite o valor de A: ");
    scanf("%f", &A);
    printf("Digite o valor de B: ");
    scanf("%f", &B);
    printf("Digite o valor de C: ");
    scanf("%f", &C);
    
    //conta delta
    delta = pow(B, 2) - (4 * A * C);
    
    //analise delta
    if(delta == 0){
        x1 = sqrt(delta) - B;
        x1 = x2;
        printf(" Delta = 0\n");
        printf(" x1 e x2 = %.3f\n", x1);
    }else if(delta > 0){
        x1 = (sqrt(delta) - B) / (2 * A);
        x2 = (-sqrt(delta) - B) / (2 * A);
        printf(" Delta = %.3f\n", delta);
        printf(" x1 = %.3f\n x2 = %.3f\n =", x1, x2);
    }else{
        printf("O Delta é menor que 0: %.3f\n Logo não existe raízes reais", delta);
    }//else
    
    //coordenadas do vertice max
    vxmax = -B / (2 * A);
    vymax = -delta / (4 * A);
    printf("As coordenadas do vertice sao: (%.3f . %.3f)", vxmax, vymax);
}//calculaQuadratica