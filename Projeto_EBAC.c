  #include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respossavel por cuidar das string

int registro()//fun��o responsalvel por cadastro
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//$s refere-se a string
	
	strcpy(arquivo, cpf); //Responsalvel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // criar o arquivo e o W significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
    file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}
int consulta()
{
	setlocale(LC_ALL, "PORTUGUESE"); //Definindo a l�nguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");// R significa ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
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
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	{
		printf("Usu�rio deletado com sucesso!.\n\n");
		system ("pause");
	}
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n\n");
		system("pause");
	}
    
}      

int main()
    {
	int opcao=0; //Definindo vari�eis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
        system("cls");//responsalvel por limpar a tela
			
	    setlocale(LC_ALL, "PORTUGUESE"); //Definindo a l�nguagem

	    printf("\t Cart�rio da EBAC\n\n"); //In�cio do menu
	    printf("Escolha a op��o desejada no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n ");
	    printf("Op��o: "); //Fim do menu

        scanf("%d", &opcao); //Armazenando a escolha do usu�rio
    
        system("cls");
        
        
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();//Consulta de dados do sistema
		    break;
		    
		    case 3:
		    deletar();//Deletar dados do sistema
	    	break;
	    	
	    	
	    	default:
	        printf("Essa op��o n�o esta disponivel\n\n");
		    system("pause");
		    break;
		    
		}
	
    }
}
