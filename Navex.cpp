#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#define AZUL "\033[34m"  
#define VERMELHO "\x1b[31m"
#define FUNDOBRANCO "\033[47m"
#define FUNDOPRETO "\033[0;0m" 
#define AMARELO "\033[33m"
#define FUNDOAZUL "\033[44m"
#define FUNDOVERDE "\033[1;42m"

typedef	unsigned int uint;
void montarMapa(char m[20][40],uint parede,uint personagem);
char permitirCaps(uint boneco);
void tutorial(uint nivel);
void infoUsuario(uint cont,uint nivel,uint qtdtiro);
void mostrarMapa(char parede,char tiro,char m[20][40]);


int main(){
	
	char resposta;
	int nivel=0;
	bool vrau=true;
	
	do{

	char m[20][40];
	bool zoop = true;
	uint i,j,t=1,a=10,b=20,c=0,d=39,qtdtiro=1;
	uint sleep=1;
	uint boneco=0,cont=0;
	char parede=219,tiro=175,personagem=254;
	
	tutorial(nivel);
	
	do{
		setbuf(stdin, NULL);
		
		infoUsuario(cont,nivel,qtdtiro);
	
		montarMapa(m,parede,personagem);
									
			Sleep(sleep);
			if(kbhit()) // O usuário digitou?
				boneco = (int)getch();     //Valor de boneco. A = 97; S = 115 ; D = 100; W = 119.
			system("cls");
			
		boneco=permitirCaps(boneco);	
	
		
		switch(boneco){				//Movimentar o boneco
					
				case 97: //A
				
					if(b==1 || b==0)			// COMPARA SE É TETO OU NÃO
						m[a][b] = personagem;
					else
						if(b-2!=0) //Quando somar 2, não pular a parede.
							b = b-2;
							else
								b= b-1;
								m[a][b] = personagem;
					
				
					break;
				
				case 115: //S
				
					if(a==19 || a==20 || a==18)  				// COMPARA SE É TETO OU NÃO
						m[a][b] = personagem;
					else
						m[++a][b] = personagem;
						
					
					break;
					
				case 100: //D
				
					if(b==38 || b==39)				// COMPARA SE É PAREDE OU NÃO
						m[a][b] = personagem;
					else if(b+2!=39) //Quando somar 2, não pular a parede
						b = b+2;
					else
						b=b+1;
						m[a][b] = personagem;
						
					
					break;
					
				case 119: //W
				
					if(a==1)				// COMPARA SE É TETO OU NÃO
						m[a][b] = personagem;
						else
							m[--a][b] = personagem;	
							
							
					break;
					
				case 32: //Space
					m[a][b] = personagem;
						if(qtdtiro!=0){
							for(int t=1;t<39-b;t++){	//Animação do tiro ">>>>>"
								m[a][b+t] = tiro;
						}
					qtdtiro--;
			}
					break;
				
				default:
						m[a][b] = personagem;
					break;
		}
		
		boneco=0;
		





		if(c==0){					//Inimigo gerado em uma linha aleatoria
			srand(time(NULL));
			c = rand()%18+1;
	}
		
		m[c][d] = '#';
		
		if(nivel==0){				//DETERMINANDO A DIFICULDADE DE ACORDO COM O NIVEL
		if(vrau==true){
			qtdtiro=15;
	}
		vrau=false;
			d--;
			
		}else if(nivel==1){
			if(vrau==true){
				qtdtiro=25;
		}
			vrau=false;
				d--;
			
			if(c==0 or c==1){
				c=c+3;
			}else if(c==19 or c==20){
				c=c-3;
			}
				if(zoop==true){
					c=c-2;
					zoop=false;
				}else{
					c=c+2;
					zoop=true;
				}
			
			
			
				
	}else if(nivel>=2){
			if(vrau==true){
				qtdtiro=30;
		}
		
		vrau=false;
		d--;
		if(c!=1 and zoop==true){
				c--;
				
			}else if(c>=1){
				c++;
				zoop=false;
		}
		if(c==18){
			zoop=true;
		}
		
}
		

	
		if(m[c][d-1]==tiro){
			m[c][d+1]= 207;
			d=39; 
			c=0;
			cont++;
	}

	if((d==1 || d==b && c==a) or cont==10){
		boneco=5;
	
	}
		
		mostrarMapa(parede,tiro,m);
		
	

 }while(boneco!=5);
	 if(cont!=10){
		sleep = 300;
		
		printf(VERMELHO"\n            G ");
		Sleep(sleep);
		printf("A ");
		Sleep(sleep);
		printf("M ");
		Sleep(sleep);
		printf("E ");
		Sleep(sleep);
		printf(" O ");
		Sleep(sleep);
		printf("V ");
		Sleep(sleep);
		printf("E ");
		Sleep(sleep);
		printf("R \n\n"FUNDOPRETO);
	
		printf("Voce deseja jogar novamente?(y/n) \n");
		resposta = getch();
		system("cls");
		
		}else{
			system("cls");
			nivel++;
			printf("Startando o nivel %d \n\n",nivel+1);
			Sleep(3000);
			resposta = 'y';
		}
	
		vrau=true;
}while(resposta!='n' and resposta!='N');
	printf("******** OBRIGADO POR JOGAR! ********* \n\n");
	return 0;
}

void montarMapa(char m[20][40],uint parede, uint personagem){
	
	for(int i=0;i<20;i++){		    //CRIAR MAPA
		for(int j=0;j<40;j++){
			if(j==0 || j == 39){
				m[0][j] = ' ';
				m[19][j] = ' ';
			m[i][j] = parede;
				
			}else if(i==0 || i==19){
				m[i][j] = parede;	
				
			}else
			m[i][j] = ' ';
			if(m[i][j] == personagem)
			m[i][j] = personagem;
			m[0][39] = parede;
			m[0][0] = parede;
		}
	}
	
}



char permitirCaps(uint boneco){
		
	if(boneco==87){					
				boneco=119;
			}else if(boneco==65){
				boneco=97;
			}else if(boneco==83){
				boneco=115; 
			}else if(boneco==68){
				boneco=100;
			}
		return boneco;
	}
		
		
		
		
void tutorial(uint nivel){
	if(nivel==0)
	printf("Bem vindo ao jogo, DEFENDA SUA BASE! \n\n");
	printf("Teclas de movimentacao:\n    W \n\n A  S  D\n \n  SPACE\n\n\n");
	printf("O jogo ira comecar em: ");
	for(int temp=3;temp!=0;temp--){
		printf("%d ",temp);
		Sleep(1000);
	}
	
	system("cls");
}



void infoUsuario(uint cont, uint nivel, uint qtdtiro){

		printf("\n\nPontuacao: %d \n",cont);
		printf("Nivel: %d \n",nivel+1);
		printf("Tiros disponiveis:");
		printf(VERMELHO" %d "FUNDOPRETO,qtdtiro);
}



void mostrarMapa(char parede,char tiro,char m[20][40]){
	
	for(int i=0;i<20;i++){				//Mostrar o mapa
			for(int j=0;j<40;j++){
				if(j==0){
					printf(AZUL"%c"FUNDOPRETO,parede);
				}
				printf("%c",m[i][j]);
			}
				printf("\n");
		}
		
}





