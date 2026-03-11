#include <stdio.h>

struct carta //criando um molde para as cartas

{
   int codigo;
   char cidade[50];
   float populacao;
   float pib;
   float area;
   int pontoturi;
   char estado[50];
   float pibpercapita;
   float densidade;

};
struct carta baralho[3]; //quantidade de cartas do jogo


void entrada() //função de entrada, onde recebemos as informações do usuário
{
int i = 0;

 printf("\n------------Bem-vindo ao Super Trunfo------------\n");

   for(i = 0; i < 3; i++) //isso garante que acontecerá para as 3 cartas

{
   printf("\n------------Cadastrando Carta %d ------------\n", i + 1);

   printf("\nDigite o codigo da cidade: ");
   scanf("%d",&baralho[i].codigo);
   
   while( getchar() != '\n'); //um truque para evitar os buffers

   printf("\nDigite o nome da cidade: ");
   fgets(baralho[i].cidade, 49, stdin); //aqui usei fgets para caso tenha espaço no nome

   printf("\nDigite a populacao da cidade: ");
   scanf("%f",&baralho[i].populacao);
   
   printf("\nDigite o PIB da cidade: ");
   scanf("%f",&baralho[i].pib);

   printf("\nDigite a area da cidade: ");
   scanf("%f",&baralho[i].area);

   printf("\nDigite a quantidade de pontos turisticos da cidade: ");
   scanf("%d",&baralho[i].pontoturi);

   while( getchar() != '\n');

   printf("\nDigite o nome do estado dessa cidade: ");
   fgets(baralho[i].estado, 49, stdin);
}


}

void processamento() //aqui é a função que processa as informações recebidas
{
int i = 0;

   if(baralho[i].area > 0) // caso seja um valor positivo e maior que zero efetuamos a conta
   {
   for(i = 0; i < 3; i++) 
   {
      baralho[i].densidade = baralho[i].populacao / baralho[i].area; 
   }

   }
    
   else // caso não seja nós zeramos o resultado para não quebrar o código
   {
      baralho[i].densidade = 0;
   }

   if(baralho[i].populacao > 0)
   {
    for(i = 0; i < 3; i++)
    {
    baralho[i].pibpercapita = baralho[i].pib / baralho[i].populacao;
    }

   }

   else
   {

      baralho[i].pibpercapita = 0;

   }

}



int escolhasaida() // nessa função nós iremos devolver as informações escolhidas
{
   int i = 0;
   int opcao = -1; // -1 para evitar alguns erros caso o código tenha mais cartas
   int encontrou = 0; //declarando variável que nos auxiliará a juntar as informações
   printf("\n------------Escolha sua carta-cidade digitando o codigo------------\n");
  
   do 
   
   {
   for(i =0; i < 3; i++) //novamente isso garante que é para as 3 cartas
   {
   printf("\nNome:%s | Codigo:%d\n" ,baralho[i].cidade ,baralho[i].codigo);
   }

    printf("\nDigite o codigo da cidade que deseja consultar (0 para sair)\n");
   scanf("%d",&opcao); //aqui nós pediremos para ele escolher a carta ou se deseja sair

   if(opcao == 0) break; //encerra se digitar 0

   for(i = 0; i < 3; i++)
{
   if(opcao == baralho[i].codigo) // se o código bater com o que foi digitado teremos: 
    //aqui mostramos os atributos para a carta que o usuário decidir 
   {

   printf("\n------------Atributos de %s------------\n",baralho[i].cidade);
   printf("\nNome: %s\n",baralho[i].cidade);
   printf("\nEstado(UF): %s",baralho[i].estado);
   printf("\nPopulacao: %.2f habitantes\n",baralho[i].populacao);
   printf("\nPIB: %.2f dolares\n",baralho[i].pib);
   printf("\nArea: %.2f (km^2)\n",baralho[i].area);
   printf("\nPIBperCapita: %.2f\n",baralho[i].pibpercapita);
   printf("\nDensidade demografica: %.2f\n",baralho[i].densidade);
   printf("\nPontos turisticos: %d\n",baralho[i].pontoturi);
    encontrou = 1; // indica que conseguimos realizar o cruzamento de dados
    break; //para de procurar, pois já achamos a carta
   } 

  }

    if(encontrou == 0)
    {

      printf("[!] Codigo invalido ou inexistente!\n");

    }


} while(opcao != 0); //aqui criamos um laço de repetição até o usuário decidir sair

return 0;

}

    int main() //agora iremos para a função principal
    
{
    //escolhendo por as funções nessa ordem o código funciona normalmente
   entrada();
   processamento();
   escolhasaida();

   return 0;

}
   
