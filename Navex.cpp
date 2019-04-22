#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define PRETO "\033[30m"
#define AZUL "\033[34m"  
#define VERMELHO      "\x1b[31m"
#define CINZA     "\e[0;37m"
#define BRANCO "\033[37m"
#define VERDE "\033[32m"
#define BRANCO "\033[37m"
#define FUNDOBRANCO "\033[47m"
#define FUNDOPRETO "\033[0;0m" 
#define AMARELO "\033[33m"
#define FUNDOAZUL "\033[44m"
#define FUNDOVERDE "\033[1;42m"



int main(){
	system("color 0A");
	char resposta;
	int nivel=0;
	
	do{
	
	char m[20][40];
	int i, j,a=10,b=20,t=1,c=0,d=39;
	int sleep = 100;
	int boneco,cont=0;
	char parede = 219,tiro=175,inimigo;
	int temp = 3;
	printf("Bem vindo ao jogo, DEFENDA SUA BASE! \n\n");
	printf("Teclas de movimentacao:\n    W \n\n A  S  D\n\n");
	printf("O jogo ira começar em: ");
	while(temp!=0){
		printf("%d ",temp);
	
		Sleep(1000);
		temp--;
	}
	
	sleep=(sleep-(nivel*90));
	system("cls");
	do{
		printf("\n\nPontuacao: %d \n",cont);
		printf("Nivel: %d",nivel+1);
		
		

	for(i=0;i<20;i++){		    //CRIAR MAPA
		for(j=0;j<40;j++){
			if(j==0 || j == 39){
				m[0][j] = ' ';
				m[19][j] = ' ';
			m[i][j] = parede;
				
			}else if(i==0 || i==19){
				m[i][j] = parede;	
				
			}else
			m[i][j] = ' ';
			if(m[i][j] == '*')
			m[i][j] ='*';
			m[0][39] = parede;
			m[0][0] = parede;
			
			
		} 
	}
		
			Sleep(sleep);
			if(kbhit()) // O usuário digitou?
			boneco = (int)getch();     //Valor de boneco. A = 97; S = 115 ; D = 100; W = 119.
			system("cls");
			
			
		
				switch(boneco){				//Movimentar o boneco
					
				
				case 97: //A
				
					if(b==1 || b==0)			// COMPARA SE É TETO OU NÃO
						m[a][b] = '*';
					else
						if(b-2!=0) //Quando somar 2, não pular a parede.
							b = b-2;
					else
					b= b-1;
					m[a][b] = '*';
					
					
					break;
				
				case 115: //S
				
					if(a==19 || a==20 || a==18)  				// COMPARA SE É TETO OU NÃO
						m[a][b] = '*';
					else
						m[++a][b] = '*';
					break;
				case 100: //D
				
					if(b==38 || b==39)				// COMPARA SE É PAREDE OU NÃO
						m[a][b] = '*';
					else if(b+2!=39) //Quando somar 2, não pular a parede
						b = b+2;
					else
						b=b+1;
						m[a][b] = '*';
					break;
				case 119: //W
				
					if(a==1)				// COMPARA SE É TETO OU NÃO
						m[a][b] = '*';
						else
							m[--a][b] = '*';	
					break;
				case 32: //Space
					m[a][b] = '*';
					while(t<39-b){
					m[a][b+t] = tiro;
					t++;
				}
					break;
					default:
						m[a][b] = '*';
				
		}
		
		boneco=0; //Fazer o boneco andar apenas 1 casa a cada tecla pressionada.
		t=1;
		
		
		
		srand(time(NULL));
		if(c==0)
			c = rand()%18+1;
			
		m[c][d] = '#';
		d--;
		if(m[c][d-1]==tiro){
			m[c][d+1]= ' ';
			d=39; 
			c=0;
			cont++;
	}
if((d==1 || d==b && c==a) or cont ==10){
	boneco=5;
	
}
		
		for(i=0;i<20;i++){				//Mostrar o mapa
			for(j=0;j<40;j++){
				printf("%c",m[i][j]);
			}
				printf("\n");
		}
		

 }while(boneco!=5);
 if(cont!=10){
	sleep = 300;
	printf("\nG ");
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
	printf("R \n\n");

	printf("Voce deseja jogar novamente?(y/n) \n");
	resposta = getch();
}else{
	system("cls");
	nivel++;
	printf("Startando o nivel %d \n\n",nivel+1);
	Sleep(3000);
	resposta = 'y';
}

}while(resposta!='n');
	return 0;
}

