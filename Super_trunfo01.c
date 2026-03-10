#include <stdio.h>

struct carta //criando o modelo das cartas 


{

int codigo;
char nome[10];
float populacao;
float pib;
float area;

//variáveis derivadas das outras

float densidade;
float pibpercapita;

};


int main() 

{



struct carta baralho[3];
int codigodebusca; //variável criada para buscar o codigo do país
int i; //variável criada para auxiliar a função "for"
int encontrado;//irá nos ajudar a confirmar o código

//cadastrando

for(i = 0; i < 3; i++) /*isso faz com que considere para cada um 
dos casos que satisfazem a condição dos parenteses*/

{
	
	printf("\n-------------Cadastrando carta: %d -------------\n", i + 1); /*i+1 para ser 1
	pois a contagem inicia em 0*/
	
	printf("Digite o codigo do pais: ");
	scanf("%d", &baralho[i].codigo);
	
	printf("Digite o nome do pais: ");
	scanf("%s", baralho[i].nome);
	
	printf("Digite a populacao do pais (em unidades): ");
	scanf("%f", &baralho[i].populacao);
	
	printf("Digite o PIB do pais (em dolares): ");
	scanf("%f", &baralho[i].pib);
	
	printf("Digite a area do pais (em km2): ");
	scanf("%f", &baralho[i].area);
	 
    //cálculo de variáveis derivadas
    
    baralho[i].densidade = baralho[i].populacao / baralho[i].area;
    
    baralho[i].pibpercapita = baralho[i].pib / baralho[i].populacao;
    
    
}

    //consultar cartas
    
    do
{
		printf("\n-------------Consulta de cartas SUPER TRUNFO-------------\n");
		printf("Cartas disponiveis: \n");
		for(i = 0; i < 3; i++)
		{

    printf("%d | %s\n", baralho[i].codigo,baralho[i].nome);
    //isso nos dá a lista de países e aí podemos escolher qual queremos ver
} 

	printf("\nDigite o codigo para ver os atributos: (ou 0 para sair)\n");
	scanf("%d", &codigodebusca);
	
    if(codigodebusca != 0)
    {
		encontrado = 0; //incializando variável
		
		for (i = 0; i < 3; i++) // isso nos garante que acontece com qualquer carta
		{
    if (baralho[i].codigo == codigodebusca)
    {
		printf(">>>>>>>>>Atributos<<<<<<<<<\n");
		printf("Nome: %s\n",baralho[i].nome);
		printf("Populacao: %.2f\n",baralho[i].populacao);
		printf("PIB: %.2f\n",baralho[i].pib);
		printf("Area: %.2f\n",baralho[i].area);
		printf("Densidade demografica: %.2f\n",baralho[i].densidade);
		printf("PIBperCapita: %.2f\n",baralho[i].pibpercapita);
		encontrado = 1; //mostra que teve um código válido
		
		
		
	}

}

      if (!encontrado) //mostra que o código não foi encontrado
      {
		  
		  printf("\nERRO, CODIGO INVALIDO! TENTE NOVAMENTE\n");
	  }
      

}



} while (codigodebusca != 0); /*enquanto código de busca for diferente 
de 0 ele finaliza o programa*/ 

   printf("\nPrograma encerrado, ate breve!\n");
   
   return 0;



}
