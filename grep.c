#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void citire(char *s,int *n,char ***A)
{
	char sir[201];
	int i;
	fgets(s,31,stdin);
	s[strlen(s)-1]='\0';
	scanf("%d",n);
	getchar();
	*A=(char**)malloc((*n)*sizeof(char*));
	for(i=0;i<(*n);i++)
	{
		fgets(sir,201,stdin);
		sir[strlen(sir)-1]='\0';
		(*A)[i]=(char*)malloc((strlen(sir)+1)*sizeof(char));
		strcpy((*A)[i],sir);
	}

}
void linie(char *s, char **linie)
{
	char aux[201];
	char aux2[201];
	int k=strlen(s);
	int i;
	int ok=0;
	for(i=0;i<strlen(*linie)-1;i++)
	{
		if(s[0]==(*linie)[i])
		{
			strcpy(aux,(*linie)+i);
			aux[k]='\0';
			if(strcmp(aux,s)==0)
			{
				*linie=(char*)realloc((*linie),(strlen(*linie)+11)*sizeof(char));
				strcpy(aux2,(*linie)+i+k);
				(*linie)[i]='\0';
				strcat((*linie),"\e[0;31m");
				strcat((*linie),s);
				strcat((*linie),"\e[m");
				strcat((*linie),aux2);
				i+=10;
				ok=1;
			}
		}
	}
	if(ok==1)
	{
		printf("%s\n",*linie);
	}
}
int main()
{
	char **A, s[31];
	int n,i;
	citire(s,&n,&A);    //citeste sirul de cautat, numarul de linii apoi liniile
	for(i=0;i<n;i++)
	{
		linie(s,&A[i]);
	}
	for(i=0;i<n;i++)
	{
		free(A[i]);
	}
	free(A);
	return 0;
}