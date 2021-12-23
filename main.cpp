#include <iostream>
#include <locale.h> 
#include <stdio.h>


//INICIALIZANDO FUNCOES
void inicio();
void jogo();
void perguntas();
void perdeu();
void venceu();
void querDica(int i);
void confereResposta(char r, int i);


// INICIALIZANDO VETORES
const char  * vetorPerguntas[3] = {"dawd", "fawf", "fawf"};
const char * vetorCorrecao[3] = {"dawd", "awdad", "dawd"};
const char * vetorDicas[3] = {"afdwdaw", "FDAWD", "FDdaw"};

//vetorPerguntas[0] = "\n\tQual seu nome?\n\tA)Fefo\n\tB)Felipe";
//vetorCorrecao[0] = "A";
//vetorDicas[0] = "aaaaaaaaaaaaa";
//
//vetorPerguntas[1] = "\n\tQual seu idade?\n\tA)Fefo\n\tB)Felipe";
//vetorCorrecao[1] = "B";
//vetorDicas[1] = "aaaaaaaaaaaaa";
//
//vetorPerguntas[2] = "\n\tQual seu nome?\n\tA)Fefo\n\tB)Felipe";
//vetorCorrecao[2] = "A";
//vetorDicas[2] = "aaaaaaaaaaaaa";

// INCIANDO NUMERO DE VIDAS
int vidas = 3;

// INCIANDO PONTUAÇÃO
int pontos = 0;

// INCIANDO NUMERO DE DICAS
int dicas = 3;


int main() {
	
	setlocale(LC_ALL, "Portuguese"); // --> SETLOCALE serve para exibir acentuação no texto
	jogo();
	return 0;
}

void inicio(){
    
    char nome[50];

        system("cls");

        printf(".______    _______ .___  ___.    ____    ____  __  .__   __.  _______    ______ \n");
        printf("|   _  \  |   ____||   \/   |    \   \  /   / |  | |  \ |  | |       \  /  __  \ \n");
        printf("|  |_)  | |  |__   |  \  /  |     \   \/   /  |  | |   \|  | |  .--.  ||  |  |  | \n");
        printf("|   _  <  |   __|  |  |\/|  |      \      /   |  | |  . `  | |  |  |  ||  |  |  | \n");
        printf("|  |_)  | |  |____ |  |  |  |       \    /    |  | |  |\   | |  '--'  ||  `--'  | \n");
        printf("|______/  |_______||__|  |__|        \__/     |__| |__| \__| |_______/  \______/ \n");

        printf("\nEsse é o QUESTION GAME!\n");
        printf("Digite seu nome para começarmos: ");
        scanf("%s", nome);

        printf("Então bora começar %s", nome, "!!\n");
        system("pause"); 
        system("cls");
}


void jogo(){
    int opcao;

    do{
    inicio();
    
    perguntas();
	
	printf("Digte: \n");
        printf("\t1 - Para continuar jogando\n");
        printf("\t0 - Para sair do jogo");
    
	}while(opcao);
}


void perguntas(){
char resposta;
	
	for(int i = 0; i <= 30; i++){
		//EXIBINDO PERGUNDA COM ALTERNATIVAS
		printf("%b", vetorPerguntas[i]);
		
		//VERIFICANDO SE QUER DICA
		querDica(i);
		
		//ARMAZENANDO RESPOSTA DO USUARIO
		scanf("%b", resposta);
		
		//CONFERINDO RSEPOSTA
		confereResposta(resposta, i);
	}
	
	venceu();
}

void confereResposta(char r, int i){
		if(r == vetorCorrecao[i]){
			if(vetorPerguntas[i] <= 10){
				pontos += 5;
			}else if(vetorPerguntas[i] <= 20){
				pontos += 10;
			}else{
				pontos += 15;
			}
		}else{
			vidas--;
		if(vidas <= 0){
			perdeu();
		}
	}
}


void querDica(int i){
	int querDica;
	
	//O USUARIO QUER USAR SUA DICA?
		printf("\n\tAperte 1 para usar sua dica\n\tAperte 0 para não usar a dica");
		scanf("%d", querDica);
		
		//CASO QUEIRA USAR SUA DICA
		if(querDica){
			//SE NÃO HÁ MAIS DICAS
			if(dicas <= 0){
				printf("Não há mais dicas para ser usada :(");
			}else{
			//USA UMA DICA
			printf("%b", vetorDicas[i]);
			dicas--;
			}
		}
}

void venceu(){
		printf("\t\t____    ____   ______     ______  _______    ____    ____  _______ .__   __.   ______  _______  __    __\n");
        printf("\t\t\   \  /   /  /  __  \   /      ||   ____|   \   \  /   / |   ____||  \ |  |  /      ||   ____||  |  |  |\n");
        printf("\t\t \   \/   /  |  |  |  | |  ,----'|  |__       \   \/   /  |  |__   |   \|  | |  ,----'|  |__   |  |  |  |\n");
        printf("\t\t  \      /   |  |  |  | |  |     |   __|       \      /   |   __|  |  . `  | |  |     |   __|  |  |  |  |\n");
        printf("\t\t   \    /    |  `--'  | |  `----.|  |____       \    /    |  |____ |  |\   | |  `----.|  |____ |  `--'  |\n");
        printf("\t\t    \__/      \______/   \______||_______|       \__/     |_______||__| \__|  \______||_______| \______/\n\n\n\n");
}

void perdeu(){
		printf("\t\t____    ____   ______     ______  _______    .______    _______ .______       _______   _______  __    __ \n");
        printf("\t\t\   \  /   /  /  __  \   /      ||   ____|   |   _  \  |   ____||   _  \     |       \ |   ____||  |  |  |\n");
        printf("\t\t \   \/   /  |  |  |  | |  ,----'|  |__      |  |_)  | |  |__   |  |_)  |    |  .--.  ||  |__   |  |  |  |\n");
        printf("\t\t  \      /   |  |  |  | |  |     |   __|     |   ___/  |   __|  |      /     |  |  |  ||   __|  |  |  |  |\n");
        printf("\t\t   \    /    |  `--'  | |  `----.|  |____    |  |      |  |____ |  |\  \----.|  '--'  ||  |____ |  `--'  |\n");
        printf("\t\t    \__/      \______/   \______||_______|   | _|      |_______|| _| `._____||_______/ |_______| \______/ \n\n\n\n");

        printf("\t\t.___________. _______ .__   __. .___________. _______\n");
        printf("\t\t|           ||   ____||  \ |  | |           ||   ____|\n");
        printf("\t\t`---|  |----`|  |__   |   \|  | `---|  |----`|  |__   \n");
        printf("\t\t    |  |     |   __|  |  . `  |     |  |     |   __|  \n");
        printf("\t\t    |  |     |  |____ |  |\   |     |  |     |  |____ \n");
        printf("\t\t    |__|     |_______||__| \__|     |__|     |_______|\n\n");

        printf("\t\t.__   __.   ______   ____    ____      ___      .___  ___.  _______ .__   __. .___________. _______ \n");
        printf("\t\t|  \ |  |  /  __  \  \   \  /   /     /   \     |   \/   | |   ____||  \ |  | |           ||   ____|\n");
        printf("\t\t|   \|  | |  |  |  |  \   \/   /     /  ^  \    |  \  /  | |  |__   |   \|  | `---|  |----`|  |__   \n");
        printf("\t\t|  . `  | |  |  |  |   \      /     /  /_\  \   |  |\/|  | |   __|  |  . `  |     |  |     |   __|  \n");
        printf("\t\t|  |\   | |  `--'  |    \    /     /  _____  \  |  |  |  | |  |____ |  |\   |     |  |     |  |____ \n");
        printf("\t\t|__| \__|  \______/      \__/     /__/     \__\ |__|  |__| |_______||__| \__|     |__|     |_______|\n\n\n\n");
}
