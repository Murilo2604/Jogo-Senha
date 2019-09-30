/***************************************************************/
/**                                                           **/
/**   NOME: Murilo Viana Teixeira Alvares----------11261548   **/
/**   EXERCICIO-PROGRAMA: 01                                  **/
/**   PROFESSOR: Ernesto Birgin                               **/
/**   TURMA: (02)                                             **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){

    int k, /* Numero de digitos que a senha tera */
        i, /* Variavel utilizada dentro do comando de geracao da senha */
        c, /* Quantidade de cores/algarismos que existirao na senha */
        senha, /* Armazenara o valor da senha */
        senhaf, /* Sera usado nos ciclos para que se possa verificar a correspondencia entre o palpite e a senha sem mudar o valor original da senha */
        npalp, /* Numero maximo de palpites */
        npalpf, /* Sera usado para contar o numero de palpites ja feitos sem alterar o valor original de palpites */
        palp, /* Palpite que o jogador dara a cada rodada */
        cont, /* Contador do ciclo que ira verificar a quantidade de pinos pretos existentes em cada palpite */
        pinpret; /* Numero de pinos pretos */

    /* ENTRADAS DO JOGO */
    printf("\n\tEntre com o numero de digitos: ");
    scanf("%d", &k);

    printf("\n\tEntre com o numero de cores (entre 1 e 9): ");
    scanf("%d", &c);

    printf("\n\tEntre com o numero maximo de palpites: ");
    scanf("%d", &npalp);

    printf("\n\tEntre com a senha de %d digitos (0 para valor aleatorio): ", k);
    scanf("%d", &senha);
    if (senha == 0) {
        srand(time(NULL));
        for (i=0; i<k; i++)
        senha = senha*10 + (rand() % c + 1);
    }

    npalpf=npalp;
    pinpret=0;

    /*ESTE CICLO ENGLOBARA TODO O JOGO E SE ENCERRARA ASSIM QUE O JOGADOR INSERIR O ULTIMO PALPITE, OU QUANDO ELE ACERTAR A SENHA */
    while (npalpf>0){
        pinpret=0;
        senhaf=senha;
        printf("\n\tDe seu %do palpite: ", npalp-npalpf+1);
        scanf("%d", &palp);
        /* ESTE 2o CICLO EXISTIRA PARA VERIFICAR A QUANTIDADE DE PINOS PRETOS EXISTENTES EM CADA PALPTIE */
        for(cont=1; cont <= k; cont=cont + 1){
           if (senhaf%10 == palp%10){
            pinpret++;
           }
           senhaf=senhaf/10;
           palp=palp/10;
        }

        if (pinpret==k){
            printf("\n\tParabens, voce acertou a senha em %d palpite(s)!", npalp-npalpf+1);
            npalpf=0; /*COMO O PROGRAMA SO ENTRARA NESSA CONDICIONAL SE ELE ACERTAR A SENHA, O CONTADOR DO CICLO PRINCIPAL SERA ZERADO, PARA QUE ELE NAO CONTINUE SE REPETINDO E O JOGO SE ENCERRE */
        }

        else{
            printf("\tNumero de pinos pretos: %d\n", pinpret);
        }
        npalpf = npalpf - 1;
    }

    /*ESTA CONDICIONAL TERA A FUNCAO DE DESCOBRIR SE O JOGADOR CONSEGUIU OU NAO DESCOBRIR A SENHA */
    if (pinpret != k){
        printf("\n\tInfelizmente, voce nao descobriu a senha, e ela era %d", senha);
    }

    return 0;

}
