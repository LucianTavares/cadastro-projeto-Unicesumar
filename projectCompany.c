#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

#define MaxProject 200

typedef struct project{
	
	int code, creationYear, teamSize, deliveryTime;
	char title[50];
	char description[200];
	char status[20];
	char managerResponsible[50];
	char designatedTeam[30];
}project_basis;

int cont = 0;
int opcao = 0;

void menu(){
		printf("cls");
		printf("Selecione uma opcaoo abaixo para realizar a busca:\n");
		printf("1 - Cadastrar projeto\n");
		printf("2 - Todos os Projetos\n");
		printf("3 - Projetos com Status A Fazer\n");
		printf("4 - Projeto com Status Fazendo\n");
		printf("5 - Projeto com Status Concluido\n");
		printf("6 - Projeto por codigo\n");
		printf("7 - Projeto por Titulo\n");
		printf("8 - Projeto por Ano de inicio\n");
		printf("9 - Sair\n\n");
		printf("Digite a opcao desejada: ");
}
void cadastrarProjeto(project_basis cadastro[MaxProject]);
void todosProjetos(project_basis cadastro[MaxProject]);
void buscarStatusAFazer(project_basis cadastro[MaxProject]);
void buscarStatusFazendo(project_basis cadastro[MaxProject]);
void buscarStatusConcluido(project_basis cadastro[MaxProject]);
void buscarCodigo(project_basis cadastro[MaxProject]);
void buscarTitulo(project_basis cadastro[MaxProject]);
void buscarAnoInicio(project_basis cadastro[MaxProject]);


int main() {
	setlocale(LC_ALL, "Portuguese");
	struct project cadastro[MaxProject];
	
	int buscar, acum, i, j, localizar;

	do{
	menu();
	scanf("%d", &opcao);
	fflush(stdin);
	printf("\n");
	
		switch(opcao) {
			
			case 1: 	
				cadastrarProjeto(cadastro);
				break;
			case 2:
				todosProjetos(cadastro);
				break;
			case 3: 
				buscarStatusAFazer(cadastro);
				break;
			case 4: 
				buscarStatusFazendo(cadastro);
				break;
			case 5: 
				buscarStatusConcluido(cadastro);
				break;
			case 6:
				buscarCodigo(cadastro);
				break;
			case 7:
				buscarTitulo(cadastro);
				break;
			case 8:
				buscarAnoInicio(cadastro);
				break;
			case 9:
				printf("\nSaindo da Aplicação\n");
				system("Pause");
				break;
			default:
				printf("\nEscolha errada!!\n");
				system("Pause");
		}	
	}while(opcao != 5);
	return(0);
}	

void cadastrarProjeto(project_basis cadastro[MaxProject]){		
	system("cls");
	char resp = 's';
	
	while(resp == 's' && cont < MaxProject){
		cont++;
		printf("===========================================\n");
		printf("   ||	CADASTRO DE PROJETO	||\n");
		printf("===========================================\n");
			
		printf("O codigo do projeto sera: %d\n", cont);
		cadastro[cont].code = cont;
		printf("-------------------------------------------\n");
		
		printf("Digite o Titulo: ");
		fflush(stdin);
		gets(cadastro[cont].title);
		printf("-------------------------------------------\n");
		
		printf("Digite a descicao: ");
		fflush(stdin);
		gets(cadastro[cont].description);
		printf("-------------------------------------------\n");
		
		printf("Digite o ano: ");
		fflush(stdin);
		scanf("%d", &cadastro[cont].creationYear);
		printf("-------------------------------------------\n");
		
		printf("Digite o Status ");
		fflush(stdin);
		gets(cadastro[cont].status);
		printf("-------------------------------------------\n");
		
		printf("Digite o primeiro nome do Gerente Responsavel: ");
		fflush(stdin);
		gets(cadastro[cont].managerResponsible);
		printf("-------------------------------------------\n");
		
		printf("Digite a equipe responsavel: ");
		fflush(stdin);
		gets(cadastro[cont].designatedTeam);
		printf("-------------------------------------------\n");
		
		printf("Digite o tamanho da equipe: ");
		fflush(stdin);
		scanf("%d", &cadastro[cont].teamSize);
		printf("-------------------------------------------\n");
		
		printf("Digite o tempo estimado de entrega em meses: ");
		fflush(stdin);
		scanf("%d", &cadastro[cont].deliveryTime);
		printf("-------------------------------------------\n\n");	
		system("cls");
			
			if(cont < MaxProject) {
				printf("Cadastrar novo projeto ? [s] -> Sim / [n] -> Nao: \n");
				fflush(stdin);
				scanf("%c", &resp);	
			}else{
				printf("Limite de projetos cadastrados atingido!");
				resp = 'n';
			}
	}
}			

void todosProjetos(project_basis cadastro[MaxProject]){
	system("cls");
	printf("===========================================\n");
	printf("   ||	TODOS PROJETOS	||\n");
	printf("===========================================\n");
	int linha = 1;
	
	if(cont >= 1){
		while(linha <= cont) {
			printf("\n%d %s %s %d %s %s %s %d %d\n", cadastro[linha].code, cadastro[linha].title, 
			cadastro[linha].description, cadastro[linha].creationYear, cadastro[linha].status, 
			cadastro[linha].managerResponsible, cadastro[linha].designatedTeam, 
			cadastro[linha].teamSize, cadastro[linha].deliveryTime);
		linha++;
		}
	}else{
		printf("\nSem projetos cadastrados\n");
	}
	system("Pause");
}
	
void buscarStatusAFazer(project_basis cadastro[MaxProject]){
	system("cls");
	printf("===========================================\n");
	printf("   ||	PROJETOS A FAZER	||\n");
	printf("===========================================\n");
	int achou = 0;
	int i = 0;
	
	while((achou == 0) && (i <= cont)){
		if(strcmp(cadastro[i].status, "A Fazer") == 0){
			printf("\n%d %s %s %d %s %s %s %d %d\n", cadastro[i].code, cadastro[i].title, 
			cadastro[i].description, cadastro[i].creationYear, cadastro[i].status, 
			cadastro[i].managerResponsible, cadastro[i].designatedTeam, 
			cadastro[i].teamSize, cadastro[i].deliveryTime);
			 achou = 1;
			 system("Pause");
		}
		i++;
	}
		if(achou == 0){
			printf("\nNenhum projeto cadastrados com Status A Fazer\n");
			system("Pause");
		}
}

void buscarStatusFazendo(project_basis cadastro[MaxProject]){
	system("cls");
	printf("===========================================\n");
	printf("   ||	PROJETOS FAZENDO	||\n");
	printf("===========================================\n");
	int achou = 0;
	int i = 0;
	
	while((achou == 0) && (i <= cont)){
		if(strcmp(cadastro[i].status, "Fazendo") == 0){
			printf("\n%d %s %s %d %s %s %s %d %d\n", cadastro[i].code, cadastro[i].title, 
			cadastro[i].description, cadastro[i].creationYear, cadastro[i].status, 
			cadastro[i].managerResponsible, cadastro[i].designatedTeam, 
			cadastro[i].teamSize, cadastro[i].deliveryTime);
			 achou = 1;
			 system("Pause");
		}
		i++;
	}
		if(achou == 0){
			printf("\nNenhum projeto cadastrados com Status Fazendo\n");
			system("Pause");
		}
}

void buscarStatusConcluido(project_basis cadastro[MaxProject]){
	system("cls");
	printf("===========================================\n");
	printf("   ||	PROJETOS CONCLUIDO	||\n");
	printf("===========================================\n");
	int achou = 0;
	int i = 0;
	
	while((achou == 0) && (i <= cont)){
		if(strcmp(cadastro[i].status, "Concluido") == 0){
			printf("\n%d %s %s %d %s %s %s %d %d\n", cadastro[i].code, cadastro[i].title, 
			cadastro[i].description, cadastro[i].creationYear, cadastro[i].status, 
			cadastro[i].managerResponsible, cadastro[i].designatedTeam, 
			cadastro[i].teamSize, cadastro[i].deliveryTime);
			 achou = 1;
			 system("Pause");
		}
		i++;
	}
		if(achou == 0){
			printf("\nNenhum projeto cadastrados com Status Concluido\n");
			system("Pause");
		}
}

void buscarCodigo(project_basis cadastro[MaxProject]){
	system("cls");
	int codigo;
	printf("===========================================\n");
	printf("   ||	BUSCA POR CODIGO	||\n");
	printf("===========================================\n");
	printf("\nDigite o codigo do projeto: ");
	scanf("%d", &codigo);
	int achou = 0;
	int i = 0;
	
	while((achou == 0) && (i <= cont)){
		if(codigo == cadastro[i].code){
			printf("\n%d %s %s %d %s %s %s %d %d\n", cadastro[i].code, cadastro[i].title, 
			cadastro[i].description, cadastro[i].creationYear, cadastro[i].status, 
			cadastro[i].managerResponsible, cadastro[i].designatedTeam, 
			cadastro[i].teamSize, cadastro[i].deliveryTime);
			 achou = 1;
			 system("Pause");
		}
		i++;
	}
		if(achou == 0){
			printf("\nNenhum projeto cadastrados com este codigo\n");
			system("Pause");
		}	
}

void buscarTitulo(project_basis cadastro[MaxProject]){
	system("cls");
	char titulo[30];
	printf("===========================================\n");
	printf("   ||	BUSCA PELO TITULO	||\n");
	printf("===========================================\n");
	printf("\nDigite o titulo do projeto: ");
	fflush(stdin);
	gets(titulo);
	int achou = 0;
	int i = 0;
	
	while((achou == 0) && (i <= cont)){
		if(strcmp(cadastro[i].title, titulo) == 0){
			printf("\n%d %s %s %d %s %s %s %d %d\n", cadastro[i].code, cadastro[i].title, 
			cadastro[i].description, cadastro[i].creationYear, cadastro[i].status, 
			cadastro[i].managerResponsible, cadastro[i].designatedTeam, 
			cadastro[i].teamSize, cadastro[i].deliveryTime);
			 achou = 1;
			 system("Pause");
		}
		i++;
	}
		if(achou == 0){
			printf("\nNenhum projeto cadastrados com este titulo\n");
			system("Pause");
		}	
}

void buscarAnoInicio(project_basis cadastro[MaxProject]){
	system("cls");
	int ano;
	printf("===========================================\n");
	printf("   ||	BUSCA PELO ANO DE INICIO	||\n");
	printf("===========================================\n");
	printf("\nDigite o codigo ano de inicio do projeto: ");
	scanf("%d", &ano);
	int achou = 0;
	int i = 0;
	
	while((achou == 0) && (i <= cont)){
		if(ano == cadastro[i].creationYear){
			printf("\n%d %s %s %d %s %s %s %d %d\n", cadastro[i].code, cadastro[i].title, 
			cadastro[i].description, cadastro[i].creationYear, cadastro[i].status, 
			cadastro[i].managerResponsible, cadastro[i].designatedTeam, 
			cadastro[i].teamSize, cadastro[i].deliveryTime);
			 achou = 1;
			 system("Pause");
		}
		i++;
	}
		if(achou == 0){
			printf("\nNenhum projeto cadastrados com este ano de inicio\n");
			system("Pause");
		}	
}

