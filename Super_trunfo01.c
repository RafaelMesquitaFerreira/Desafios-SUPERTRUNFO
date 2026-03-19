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
   float superpoder;

};
struct carta baralho[3]; //quantidade de cartas do jogo


void entrada() //função de entrada, onde recebemos as informações do usuário
{
int i = 0;

 printf("\n------------Bem-vindo ao Super Trunfo------------\n");

   for(i = 0; i < 3; i++) //isso garante que acontecerá para as 3 cartas

{
   printf("\n------------Cadastrando Carta %d ------------\n", i + 1);

   printf("\nDigite o codigo da cidade(Ex 1, 2 ou 3): ");
   scanf("%d",&baralho[i].codigo);

   while( getchar() != '\n'); //um truque para evitar os buffers

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

   printf("\nDigite o nome do estado dessa cidade: ");
   fgets(baralho[i].estado, 49, stdin);

}


}

void processamento() //aqui é a função que processa as informações recebidas
{
int i = 0;

   
   for(i = 0; i < 3; i++) //aqui garante que é para as 3 cartas

{  //aqui iremos evitar divisão por 0
 
   if(baralho[i].area > 0) //caso tenha um valor maior que zero ele faz a conta normalmente
   {
      baralho[i].densidade = baralho[i].populacao / baralho[i].area; 
   }

    
   else // caso não seja nós zeramos o resultado para não quebrar o código
   {
      baralho[i].densidade = 0;
   }
}
   for(i = 0; i < 3; i++)
   {
    if(baralho[i].populacao > 0)
    {
    baralho[i].pibpercapita = baralho[i].pib / baralho[i].populacao;
    }

   

   else
   {

      baralho[i].pibpercapita = 0;

   }
   baralho[i].superpoder = (baralho[i].area) + (1 / (baralho[i].densidade)) + (baralho[i].pib) + (baralho[i].pibpercapita) + (baralho[i].pontoturi) + (baralho[i].populacao);


   }

}



int escolhasaida() // nessa função nós iremos devolver as informações escolhidas
{
   int i = 0;
   int opcao = -1; // -1 para evitar problemas caso tenha mais cartas 
   int encontrou = 0; //declarando variável que nos auxiliará a juntar as informações
   printf("\n------------Escolha sua carta-cidade digitando o codigo------------\n");
  
   do 
   
   {
   for(i =0; i < 3; i++) //novamente isso garante que é para as 3 cartas
   {
   printf("\nNome: %s | Codigo: %d\n" ,baralho[i].cidade ,baralho[i].codigo);
   }

    printf("\nDigite o codigo da cidade que deseja consultar (0 para sair ou 7 para jogar)\n");
   scanf("%d",&opcao); //aqui nós pediremos para ele escolher a carta ou se deseja sair

   if(opcao == 0) break; //encerra se digitar 0
{
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
   printf("\nSuper Poder: %.2f\n",baralho[i].superpoder);
    encontrou = 1; // indica que conseguimos realizar o cruzamento de dados
    break; //para de procurar, pois já achamos a carta
   } 

  }

   }

   if(opcao == 7)
   {
      printf("\n------------Bem-vindo ao SUPER TRUNFO------------\n");

      int ncarta1 = 0;
      int ncarta2 = 0;
      printf("\nNão escreva o codigo, escreva a carta, por exemplo: 1, 2 ou 3!\n");
      printf("\n[Jogador 1]\nEscolha a primeira carta para comparar(ex: 1, 2 ou 3): \n");
      scanf("%d",&ncarta1);
      
      while(getchar() != '\n');

      printf("\n[Jogador 2]\nEscolha a segunda carta para comparar(ex 1, 2 ou 3): \n");
      scanf("%d",&ncarta2);

      if(baralho[ncarta1].superpoder > baralho[ncarta2].superpoder)
     { 
      printf("\nParabens jogador 1, sua carta %s venceu!\n",baralho[i].cidade);
         encontrou = 1;
     }      
      else if (baralho[ncarta2].superpoder > baralho[ncarta1].superpoder)
      {
         printf("\nParabens jogador 2, sua carta %s venceu!\n",baralho[i].cidade);
         encontrou = 1;
      }
      else 
      {
         printf("Ops! Tivemos um empate!");
         encontrou = 1;
      }

   }

    if(encontrou == 0)
    {

      printf("[!] Codigo invalido ou inexistente!\n");

    }


} while(opcao != 0); //aqui criamos um laço de repetição até o usuário decidir sair

 printf("Obrigado pela participacao, Ate breve!"); //mensagem final

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
   
