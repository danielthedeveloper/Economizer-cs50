//     Este programa é destinado apenas aos locais que se enquadram em na categoria "residencial" e que se localizam no estado de Minas Gerais

//    Este programa será voltado para a análise da conta de água do usuário(ainda apenas um protótipo)
//   como seu objetivo principal, mas um auxiliador de como diminuir a conta de água como um
//   objetivo paralelo.

//    Um dos principais e futuros objetivos que desejo alcançar é poder através de cada escolha do usuário dentro do
//   programa ser possível realizar uma previsibilidade através de cálculos de o quanto aproximadamente o usuário
//   está gastando de água na determinada atividade, mostrando também ao usuário o quanto esse gasto impacta em
//   sua conta de água;




#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cs50.h>
int choice;

float calculateCost(float totalCubicMeters, float ranges[], float prices[], int size) {
    float cost = 0;
    float currentCubicMeters = totalCubicMeters;
    for(int i=0; i<size; i++) {
        float cubicMetersInRange = fmin(currentCubicMeters, ranges[i]);
        cost += cubicMetersInRange * prices[i];
        currentCubicMeters -= cubicMetersInRange;
    }

    return cost;
}

//      Inicialmente o programa vai:
//        - solicitar ao usuário quantos metros cúbicos ele gastou no mês desejado

int main() {
    float totalCubicMeters;
    printf("Bem vindo ao Economizer\n " );
    printf("Digite a quantidade de metros cúbicos que você deseja analisar: ");
    scanf("%f", &totalCubicMeters);

    //     y = metros cúbicos
    //     precisamos calcular então o custo de y, na qual através de um sistema de cálculo
    //     próprio da COPASA - MG é possível calcular o valor de y gasto pelo usuário.

    //      Foi escolhido a empresa COPASA - MG uma vez que ela que atendia a minha região e seria
    //     mais fácil uma vez que eu poderia testar com usuários locais, além disso cada empresa de
    //     sanemaento possui um custo diferente, então seria mais fácil inicialmente trabalhar apenas
    //     em uma solução da minha região antes de expandir para diversas cidades e estados


    float ranges1[] = {5, 5, 5, 5, 20, 10000};
    float prices1[] = {2.11, 4.496, 6.968, 9.512, 12.099, 14.761};
    int size1 = sizeof(ranges1)/sizeof(ranges1[0]);
    float cost1 = calculateCost(totalCubicMeters, ranges1, prices1, size1);
    float ranges2[] = {5, 5, 5, 5, 20, 10000};
    float prices2[] = {1.56, 3.327, 5.156, 7.039, 8.953, 10.922};
    int size2 = sizeof(ranges2)/sizeof(ranges2[0]);
    float cost2 = calculateCost(totalCubicMeters, ranges2, prices2, size2);
    cost2 += 35.44;
    printf(" \n O custo total de %.2f metros cúbicos é R$ %.2f\n ", totalCubicMeters, cost1 + cost2);
printf (" (Esse valor é baseado no sistema de custos e valores ");
printf ("pré-definidos no ano de 2022 pela COPASA - Companhia de Saneamento de Minas Gerais) \n \n");
//   Este programa está baseado na tabela de custos da COPASA  de 2022, a tabela de custos de 2023  começará
//  a entrar em vigor a partir do mês de fevereiro do ano de 2023, necessitando atualizar o programa.


   char c = get_char ("Deseja continuar?(S/N)");

    if  (c == 'n' || c =='N')
    {
        return 0;

    }
    else if ( c == 's' || c == 'S')
    {
        printf("Podemos dominuir esse valor através de diversas atitudes, \n ");
   printf("dentre elas temos algumas possibilidades que podemos analizar"); // futuramente simulações que podemos faz aqui\n
printf("Digite aquela atitude na qual gostaria de ver melhores informações:\n ");
  printf("1. Redução do tempo de banho para 5 minutos\n");
    printf("2. Irrigação de jardins e plantas á noite ou pela manhã\n");
    printf("3. Instalação de redutores de vazão\n");
    scanf("%d", &choice);

     switch(choice) {
        case 1:
            printf("Redução do tempo de banho para 5 minutos: \n \n");
            printf("Sabia que em um banho de 15 minutos gastamos em cerca de 135 litros de água? \n");
            printf("E diminuindo o tempo para 5 minutos de banho economizaríamos cerca de 90 litros? \n");
            printf("Podendo reduzir ainda mais se deixássemos ligado o chuveiro apenas quando\n ");
            printf("terminássemos de nos ensaboar?\n");
            // Eu eu queria colocar a opção de "deseja voltar?" para que o usuário volte direto para a escolha das atitudes


            break;
        case 2:
            printf("Irrigação de jardins e plantas pela manhã: \n \n");

           printf ("Sabia que optando pelo regador  ao invés da mangueira para molhar as plantas você \n");
           printf("poderá economizar, em média, até 96 litros de água a cada 10 minutos. \n \n");
          printf(" Além disso, escolha regar as suas plantas bem de manhã. Em um banho matinal,\n");
           printf("é mais fácil que essa água desça até as raízes sem ser evaporada, evitando o\n" );
           printf("ressecamento e enrugamento das folhas. No inverno, quando a temperatura é menor, \n");
          printf("suas plantinhas também podem ser regadas em dias alternados,\n");
           printf("porque elas perde menos água.\n");
           // Eu eu queria colocar a opção de "deseja voltar?" para que o usuário volte direto para a escolha das atitudes



            break;
        case 3 :
           printf("Instalações de redutores de vazão: \n \n");
           printf ("Os redutores são pequenos anéis que controlam a quantidade de água na saída\n");
            printf ("das torneiras de banheiros, cozinhas e tanques.\n");
             printf("Uma torneira de pia ou tanque consome em média 15,6 litros por minto.\n");
             printf("Com o redutor de vazão mínimo (6 litros/minuto), o consumo cai para 6 litros\n");
             printf ("por minuto, segundo a Sabesp. \n\n");

           printf("Em torneiras com vazão maior (média de 25,2 litros/minuto) a economia chega ");
           printf("à 19,2 litros/minuto com o mesmo redutor. Nos cinco minutos de lavagem de louça, \n");
           printf("a peça impede que 96 litros de água sejam usados sem necessidade. \n");
// Eu eu queria colocar a opção de "deseja voltar?" para que o usuário volte direto para a escolha das atitudes

           break;

        default:
            printf("Seleção inválida!\n");

    return 0;

    }

    }
}

