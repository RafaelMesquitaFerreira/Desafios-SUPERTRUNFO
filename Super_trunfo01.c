#include <stdio.h>

struct carta //criando um molde para as cartas

{
   int numeracao;
   char cidade[50];
   float populacao;
   float pib;
   float area;
   int pontoturi;
   char pais[50];
   float pibpercapita;
   float densidade;
   float superpoder;

};
struct carta baralho[13]; //quantidade de cartas do jogo

void manual() //Instruções de como jogar
{
    int prosseguir = 0;
    do 
    {

    printf("\n------------Manual de instrucoes------------\n");
    printf("\n[1] Cada jogador devera cadastrar ao menos 1 carta.\n");
    printf("\n[2] A informacao PIB devera ser colocada em dolares.\n");
    printf("\n[3] A informacao Area devera ser colocada em km^2.\n");
    printf("\n[4] As informacoes de PIB per Capita e Densidade demografica serao calculados automaticamente!\n");
    printf("\n[5] Ao escolher o modo de jogo, o jogador devera escolher sua carta escrevendo a numeracao.\n");
    printf("\n[6] O superpoder de sua carta sera definido por: (populacao)+(PIB em dolares)+(area em km^2)+(quantidade de pontos turisticos)+(PIB per Capita)+(1/densidade demografica)\n");
    printf("\n[7] Ganha o jogador que tiver o maior superpoder!\n");
    printf("\n[8] Cada jogador nao pode ver o cadastramento do outro!\n");

    printf("\nDica: Tente pensar em uma cidade que reuna números grandes!\n");

    printf("\nAperte 1 para prosseguir\n");
    scanf("%d",&prosseguir);
    }
while(prosseguir != 1);


}


void entrada() //feita somente para dar boas vindas
{
 
 printf("\n------------Bem-vindo ao Super Trunfo------------\n");
 
}

int processamento(int valor); //aqui eu crio uma função vazia, que logo em cadastramento eu irei utiliza-lá

int listagem(int ganhador); // também crio uma função vazia para utiliza-lá logo mais

void cadastramento() /*função de cadastrar as cartas, onde recebemos as informações do  
usuário*/
{
 

int i = 0;

   for(i = 0; i < 2; i++) //isso garante que acontecerá para todas as cartas

{
 baralho[i].numeracao = i + 1;

   printf("\n------------Cadastrando Carta %d ------------\n", baralho[i].numeracao);

   printf("\nNumeracao da sua carta: %d \n", baralho[i].numeracao);

   printf("\nDigite o nome da cidade: ");
   fgets(baralho[i].cidade, 49, stdin); //aqui usei fgets para caso tenha espaço no nome
   
   printf("\nDigite a populacao da cidade: ");
   scanf("%f",&baralho[i].populacao);
   
   while( getchar() != '\n'); 

   printf("\nDigite o PIB da cidade (em dolares): ");
   scanf("%f",&baralho[i].pib);

   while(getchar() != '\n');

   printf("\nDigite a area da cidade: ");
   scanf("%f",&baralho[i].area);

   while(getchar() != '\n');

   printf("\nDigite a quantidade de pontos turisticos da cidade: ");
   scanf("%d",&baralho[i].pontoturi);
   
   while(getchar() != '\n');

   printf("\nDigite o nome do pais dessa cidade: ");
   fgets(baralho[i].pais, 49, stdin);
   
   processamento(baralho[i].numeracao); //aqui garante que (somente) cada carta escrita será processada

}   

}

int processamento(int valor) //aqui é a função que processa as informações recebidas
{

    int indice = valor - 1;

  //aqui iremos evitar divisão por 0
 
   if(baralho[indice].area > 0) //caso tenha um valor maior que zero ele faz a conta normalmente
   {
      baralho[indice].densidade = baralho[indice].populacao / baralho[indice].area; 
   }

    
   else // caso não seja nós zeramos o resultado para não quebrar o código
   {
      baralho[indice].densidade = 0;
   }
   
    if(baralho[indice].populacao > 0)
    {
    baralho[indice].pibpercapita = baralho[indice].pib / baralho[indice].populacao;
    }

   

   else
   {

      baralho[indice].pibpercapita = 0;

   }
   baralho[indice].superpoder = (baralho[indice].area) + (1 / (baralho[indice].densidade)) + (baralho[indice].pib) + (baralho[indice].pibpercapita) + (baralho[indice].pontoturi) + (baralho[indice].populacao); //aqui eu crio a variável superpoder, vence a carta que tiver o maior superpoder



}

void gameEngine()

{
      printf("\n------------Bem-vindo ao Modo de jogo------------\n");

      int ncarta1 = 0;
      int ncarta2 = 0;
      printf("\nEscreva o numero de sua carta, por exemplo: 1, 2, 3 etc...\n");
      printf("\n[Jogador 1]\nEscolha a sua carta: \n");
      scanf("%d",&ncarta1);
      
      while(getchar() != '\n');

      printf("\n[Jogador 2]\nEscolha a sua carta: \n");
      scanf("%d",&ncarta2);

      int i1 = ncarta1 - 1; //subtraio 1 pois o indice é menor que a numeração
      int i2 = ncarta2 - 1;

      if(baralho[i1].superpoder > baralho[i2].superpoder)
     { 
      
   printf("\nParabens jogador 1, sua carta %s venceu!\n",baralho[i1].cidade);
     
   printf("\nO superpoder da carta do jogador 1: %.2f  ganha a do jogador 2: %.2f\n",baralho[i1].superpoder,baralho[i2].superpoder);
         listagem(i1);
      }      
      else if (baralho[i2].superpoder > baralho[i1].superpoder)
      {
     printf("\nParabens jogador 2, sua carta %s venceu!\n",baralho[i2].cidade);
  
  printf("\nO superpoder da carta do jogador 2: %.2f  ganha a do jogador 1: %.2f\n",baralho[i2].superpoder,baralho[i1].superpoder);
  listagem(i2);   
}
   else 
   {
    
    printf("\nOps, tivemos um empate, parabens aos 2 jogadores!\n%.2f = %.2f\n",baralho[i1].superpoder , baralho[i2].superpoder);
    
    
   }
   
   }
   
int listagem(int ganhador)
{
 int i = ganhador;
 
   printf("\n------------Atributos do Vencedor: %s------------\n",baralho[i].cidade);
   printf("\nNome: %s\n",baralho[i].cidade);
   printf("\nNumeracao: %d \n",baralho[i].numeracao);
   printf("\nPais: %s",baralho[i].pais);
   printf("\nPopulacao: %.2f habitantes\n",baralho[i].populacao);
   printf("\nPIB: %.2f dolares\n",baralho[i].pib);
   printf("\nArea: %.2f (km^2)\n",baralho[i].area);
   printf("\nPIBperCapita: %.2f\n",baralho[i].pibpercapita);
   printf("\nDensidade demografica: %.2f\n",baralho[i].densidade);
   printf("\nPontos turisticos: %d\n",baralho[i].pontoturi);
   printf("\nSuperpoder: %.2f\n",baralho[i].superpoder);


 
 }
   
int menu() // aqui será o menu, onde teremos 4 opções
 {
   int opcao = -1; // -1 para evitar problemas caso tenha mais cartas 
  
   do 
   
   {

   printf("\n------------Menu------------\n");



    printf("\nCadastrar [1]\nJogar [2]\nSair [0]\nEscolha: \n");
    scanf("%d",&opcao); //aqui nós pediremos para ele escolher o que deseja fazer ou se deseja sair

    while(getchar() != '\n');

   if(opcao == 0) break; //encerra se digitar 0
   
   switch(opcao)
{
 case 1:
 cadastramento();
 break;
 
 case 2:
 gameEngine();
 break;
 
 
 default:
 printf("Opcao invalida, erro!");
 break;
 
}
  
   
} while(opcao != 0); //aqui criamos um laço de repetição até o usuário decidir sair

 printf("Obrigado pela participacao, Ate breve!"); //mensagem final

return 0;

}

    int main() //agora iremos para a função principal
    
{
    entrada();
    manual();
    menu();
   return 0;

}
