#include <stdio.h> //biblioteca de comunica��o como o usu�rio
#include <stdlib.h> //biblioteca de aloca��o deespa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar usu�rios no sistema
{
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/sting
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" significa atualiza o arquivo
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //"a" significa atualiza o arquivo
	fprintf(file,nome);  // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" significa atualiza o arquivo
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%S",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //"a" significa atualiza o arquivo
	fprintf(file,sobrenome); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" significa atualiza o arquivo
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //"a" significa atualiza o arquivo
	fprintf(file,cargo);  // salvo o valor da variavel
	fclose(file); //fecha o arquivo
		
	system("pause");	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); // "r" significa ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n ");  	
	}
     	
    while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	} 	
	
	system("pause");
	
 }

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		system("cls");

	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    	printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
    	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Resgistrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("Op��o:"); //Fim do menu
	
    	scanf("%d", &opcao);
	
    	system("cls"); //respons�vel por limpar a tela
	
	    switch(opcao) //in�cio de sele��o
	    {
	    	case 1:
	    	registro(); //chamada de fun��es
			break;
						
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
    		break;
    		
    		default:
    		printf("Voc� escolheu deletar nomes!\n");
    		system("pause");
    		break;	
		} //fim de sele��o
    	
    	    	
	}
}
