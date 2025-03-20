#include <stdio.h>
#include <string.h>
//função para dar um nome dinâmico para as variáveis
typedef struct {

    //definição dos variáveis
    int pontos_turisticos;
    int codigo;
    int populacao;
    float area;
    float PIB;
    char estado[50];
    char cidade[50];
}Carta;
   //função para cadastrar cartas
   int cadastrarCarta(Carta cartas[], int num_cartas,const int max_cartas) {
   if (num_cartas >= max_cartas) {
   printf("O Limite de Cartas foi atingido! \n)");
   return num_cartas;
   }

   Carta nova_carta;
   printf("Digite o nome do Estado:\n");
   scanf("%s", nova_carta.estado);

   printf("Digite o código da carta:\n");
   scanf("%d", nova_carta.codigo);

   printf("Digite o nome da cidade:\n");
   scanf("%s", nova_carta.cidade);

   printf("Digite o PIB da cidade:\n");
   scanf("%f", nova_carta.PIB);

   printf("Digite a área da cidade:\n");
   scanf("%f", nova_carta.area);

   printf("Digite a população da cidade:\n");
   scanf("%d", nova_carta.populacao);

   printf("Digite o número de pontos turisticos da cidade:\n");
   scanf("%d", nova_carta.pontos_turisticos);

   cartas[num_cartas] = nova_carta;
   num_cartas++;
   printf("Sua carta foi cadastrada!\n");

   return num_cartas;

}
//função para exibir cartas
void exibirCarta(Carta carta) {
    printf("Estado: %s\n", carta.estado);

    printf("Código: %d\n", carta.codigo);

    printf("Cidade: %s\n", carta.cidade);

    printf("População: %d\n", carta.populacao);

    printf("Área: %.2f\n", carta.area);

    printf("PIB: %.2f\n", carta.PIB);

    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}
//função de comparar cartas
void compararCartas(Carta carta1, Carta carta2) {
printf("Comparar por:\n");
printf("População\n");
printf("Área\n");
printf("PIB\n");
printf("Pontos turisticos\n");
printf("Número de habitantes\n");

int opcao;
scanf("%d", &opcao);


float valor1, valor2;
switch (opcao){
    case 1: valor1 = carta1.populacao; valor2 = carta2.populacao; break;

    case 2: valor1 = carta1.area; valor2 = carta2.area; break;

    case 3: valor1 = carta1.PIB; valor2 = carta2.PIB; break;

    case 4: valor1 = carta1.pontos_turisticos; valor2 = carta2.pontos_turisticos; break;

    case 5: valor1 = (float)carta1.populacao / carta1.area; valor2 = (float)carta2.populacao / carta2.area; break;

    default: return;
}

if (opcao == 5) {

if (valor1 < valor2) {
   printf("Carta 1 Ganhou!\n");
   exibirCarta(carta1);
} else if (valor1 > valor2){
   printf("Carta 2 Ganhou!\n");
   exibirCarta(carta2);
} else {
    printf("Empate!\n");
}
}else {
  if (valor1 > valor2){
   printf("Carta 1 é Ganhou!\n");
   exibirCarta(carta1);

  }else if (valor1 < valor2){
    printf("Carta 2 Ganhou!\n");
    exibirCata(carta1);
  } else {
    printf("Empate!\n");
  }

}

}
// Menu do Jogo
int main() {

    const int max_cartas = 100;

    Carta cartas[max_cartas];
    int num_cartas = 0, opcao;

    do {

        printf("Menu:\n");
        printf("Cadastrar Carta\n");
        printf("Comparar carta\n");
        printf("Sair;");
        scanf("%d", &opcao);

switch (opcao) {
case 1:
num_cartas = cadastrarCarta(cartas, num_cartas, max_cartas);

break;
case 2:
if (num_cartas < 2) {
    printf("Você precisa de pelo menos duas cartas registradas!\n");
} else {
    int carta1_idx, carta2_idx;
    printf("Índice da carta 1 (0 a %d): ", num_cartas - 1);
    scanf("%d", &carta1_idx);
    printf("Índice da carta 2 (0 a %d): ", num_cartas - 1);
    scanf("%d", &carta2_idx);
    if (carta1_idx >= 0 && carta1_idx < num_cartas && carta2_idx >= 0 && carta2_idx < num_cartas) {
        compararCartas(cartas[carta1_idx], cartas[carta2_idx]);
    } else {
        printf("Índices inválidos!\n");
    }
}
break;

case 3:
printf("Fechando...\n");
break;
default:
printf("Opção indisponivel\n");
}
    }while (opcao != 3);
return 0;

}