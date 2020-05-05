//Esse code funciona como uma espécie de jogo que fiz nos meus estudos de matrizes

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main(void){
	int l,c,tam;
	char mov;
	
	printf("Tamanho da matriz: ");
	scanf("%d",&tam); //determinando o tamanho da matriz
	
	char m[tam][tam]; //algo legal que a matriz e feita em tempo de execução
	
	for(l=0;l<tam;l++)
		{
			for(c=0;c<tam;c++)
			{
				m[l][c] = '-'; //preenche toda a matriz com um unico caracter
			}
		}

		m[tam-1][0] = 'O'; //coloca o 'personagem' na ultima linha da primeira coluna

		for(l=0;l<tam;l++)
		{
			for(c=0;c<tam;c++)
			{
				printf("%4c",m[l][c]); //mostra toda a matriz junto com o personage 'O'
			}
			printf("\n");
		}
		fflush(stdin);
		printf("\n");
	
	do
	{	
		
		mov = getch(); //mov vai receber um caracter do teclado sem eco
		system("cls");
		
		for(l=0;l<tam;l++)
		{
			for(c=0;c<tam;c++)
			{
				if(m[l][c] == 'O') //caso a posição encontrado possua o 'O' entra no switch
				{				
					switch(mov)
					{
						case 'W': /*caso W a posição que continha o '0' vai receber o '-' e a posição acima
						recebe o o '0' caso esteja dentro da matriz. O mesmo vale para todos os outros case*/
						case 'w':
								if(l!=0)//teste para saber se esta dentro da matriz
								{	
									m[l][c] = '-';
									m[l-1][c] = 'O';	
									c=l=tam;		
								}		
						break;
				
						case 'S':
						case 's':
								if(l!=tam-1)//teste para saber se esta dentro da matriz
								{
									m[l][c] = '-';
									m[l+1][c] = 'O';
									c=l=tam;
								}					
						break;
		
						case 'A':
						case 'a':
								if(c!=0)//teste para saber se esta dentro da matriz
								{
									m[l][c] = '-';
									m[l][c] = '-';
									m[l][c-1] = 'O';
									c=l=tam;
								}
						break;
						
						case 'D':
						case 'd':
								if(c!=tam-1)//teste para saber se esta dentro da matriz
								{
									m[l][c] = '-';
									m[l][c] = '-';
									m[l][c+1] = 'O';
									c=l=tam;
								}
						break;
						
						case 'q':
								printf("Sair? [Q]"); //caso a tecla for digitado seja 'q', entra nesse case e /mostra a msg
								scanf("%c",&mov);
						break;
					}
				}
			}
		}
		
		for(l=0;l<tam;l++) //atualiza a matriz depois da tecla ser pressionada
		{
			for(c=0;c<tam;c++)
			{
				printf("%4c",m[l][c]);
			}
		printf("\n");
		}
		
	}while(mov != 'Q');//Q para sair

	return (0);
}