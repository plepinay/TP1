#include <stdio.h>
# define N 3

//LEPINAY Pierre
void initialiser_matrice (int mat[N][N])
{
	int i,j,x;

	for(i=0;i<N;i++)
		{		
		for(j=0;j<N;j++)
			{
			mat[i][j]=0-x;
			x++;
			}
		}
}

void affiche_matrice (int mat[N][N])
{
	int i,j;
	for(i=0;i<N;i++)
		{		
		for(j=0;j<N;j++)
			{
			if (mat[i][j]<0)
				printf(" ");
			else if (mat[i][j]==1)
				printf("X");
				else 
					printf("O");				
			}
		printf("\n");
		}
	printf("\n");		
}

void saisie_coordonnees(int n, int mat[N][N])
{	
	int x,y;
	if (n==1)
	{
		printf("joueur A saisie les coordonnées de son pion (X)\n");
		scanf("%i",&x);
		scanf("%i",&y);
		mat[x][y]=1;
	}
	else 
	{
		printf("joueur B saisie les coordonnées de son pion (X)\n");
		scanf("%i",&x);
		scanf("%i",&y);
		mat[x][y]=2;
	}
}

int test_gagne(int mat[N][N])
{
	if (mat[0][0]==mat[0][1]==mat[0][2])
		return 1;
	else 	if (mat[0][0]==mat[1][1]==mat[2][2])
			return 1;
		else 	if (mat[0][0]==mat[1][0]==mat[2][0])
				return 1;
			else 	if (mat[0][2]==mat[1][1]==mat[2][0])
					return 1;
				else 	if (mat[0][2]==mat[1][2]==mat[2][2])
						return 1;
					else 	if (mat[2][0]==mat[2][1]==mat[2][2])
							return 1;
						else 	if (mat[1][0]==mat[1][1]==mat[1][2])
								return 1;
							else 	if (mat[0][1]==mat[1][1]==mat[2][1])
									return 1;
								else return 0;
}

/*void creer_fichier (char nom[20])
{
	printf("entrez le nom du fichier \n");
	scanf("%s",nom);
}

void enregistrement(char nom,int mat[N][N])
{
	FILE * fic1;
	fic1=fopen(nom,"w");
	int i,j;
	for(i=0;i<N;i++)
		{		
		for(j=0;j<N;j++)
			{
			if (mat[i][j]<0)
				fprintf(nom," ");
			else if (mat[i][j]==1)
				fprintf(nom,"X");
				else 
					fprintf(nom,"O");				
			}
		fprintf(nom,"\n");
		}
	fprintf(nom,"\n");		
}*/

int main()
{
	int mat[N][N],joueur,gagne,tour=1;
	//char nom;
	//creer_fichier(nom);
	initialiser_matrice(mat);
	printf("la partie commence\n");

	do{
		joueur=tour%2;
		saisie_coordonnees(joueur,mat);
		affiche_matrice(mat);
		//enregistrement(nom,mat);
		gagne=test_gagne(mat);
		tour++;		
	}while (gagne==0 && tour<10);
	
	if (gagne==1 && joueur==1)
		printf("le joueur A a gagné\n");
	else 	if (gagne==1)
			printf("le joueur B a gagné\n");
		else
		printf("il y a égalité\n");
	
}
