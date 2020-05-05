#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main(void){
	int l,c,tam;
	char mov;
	
	printf("Tamanho da matriz: ");
	scanf("%d",&tam);
	
	char m[tam][tam];
	
	for(l=0;l<tam;l++)
		{
			for(c=0;c<tam;c++)
			{
				m[l][c] = '-';
			}
		}

		m[tam-1][0] = 'O';

		for(l=0;l<tam;l++)
		{
			for(c=0;c<tam;c++)
			{
				printf("%4c",m[l][c]);
			}
			printf("\n");
		}
		fflush(stdin);
		printf("\n");
	
	do
	{	
		
		mov = getch();
		system("cls");
		
		for(l=0;l<tam;l++)
		{
			for(c=0;c<tam;c++)
			{
				if(m[l][c] == 'O')
				{				
					switch(mov)
					{
						case 'W':
						case 'w':
								if(l!=0)
								{	
									m[l][c] = '-';
									m[l-1][c] = 'O';	
									c=l=tam;		
								}		
						break;
				
						case 'S':
						case 's':
								if(l!=tam-1)
								{
									m[l][c] = '-';
									m[l+1][c] = 'O';
									c=l=tam;
								}					
						break;
		
						case 'A':
						case 'a':
								if(c!=0)
								{
									m[l][c] = '-';
									m[l][c] = '-';
									m[l][c-1] = 'O';
									c=l=tam;
								}
						break;
						
						case 'D':
						case 'd':
								if(c!=tam-1)
								{
									m[l][c] = '-';
									m[l][c] = '-';
									m[l][c+1] = 'O';
									c=l=tam;
								}
						break;
						
						case 'q':
								printf("Sair? [Q]");
								scanf("%c",&mov);
						break;
					}
				}
			}
		}
		
		for(l=0;l<tam;l++)
		{
			for(c=0;c<tam;c++)
			{
				printf("%4c",m[l][c]);
			}
		printf("\n");
		}
		
	}while(mov != 'Q'); 

	return (0);
}