#include <stdio.h> //biblioteca de comunicação como o usuário
#include <stdlib.h> //biblioteca de alocação deespaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar usuários no sistema
{
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/sting
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" significa atualiza o arquivo
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //"a" significa atualiza o arquivo
	fprintf(file,nome);  // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" significa atualiza o arquivo
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%S",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //"a" significa atualiza o arquivo
	fprintf(file,sobrenome); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" significa atualiza o arquivo
	fprintf(file,",");
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
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
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); // "r" significa ler o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n ");  	
	}
     	
    while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	} 	
	
	system("pause");
	
 }

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		system("cls");

	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    	printf("### Cartório da EBAC ###\n\n"); //inicio do menu
    	printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - Resgistrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("Opção:"); //Fim do menu
	
    	scanf("%d", &opcao);
	
    	system("cls"); //responsável por limpar a tela
	
	    switch(opcao) //início de seleção
	    {
	    	case 1:
	    	registro(); //chamada de funções
			break;
						
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
    		break;
    		
    		default:
    		printf("Você escolheu deletar nomes!\n");
    		system("pause");
    		break;	
		} //fim de seleção
    	
    	    	
	}
}
