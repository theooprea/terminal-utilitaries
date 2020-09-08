#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void citire(int *n, char *del, char *outdel, int v[][100],int *m,char ***A)
{
	char coloane[200],read[201];
	fgets(del,10,stdin);
	del[strlen(del)-1]='\0';
	scanf("%d",n);
	getchar();
	fgets(coloane,200,stdin);
	coloane[strlen(coloane)-1]='\0';
	int i=0;
	char *p;
	p=strtok(coloane,",");
	while(p!=NULL)
	{
		int a=atoi(p);
		(*v)[i]=a;
		i++;
		p=strtok(NULL,",");
	}
	fgets(outdel,10,stdin);
	outdel[strlen(outdel)-1]='\0';
	scanf("%d",m);
	getchar();
	*A=(char**)malloc((*m)*sizeof(char*));
	for(i=0;i<(*m);i++)
	{
		fgets(read,201,stdin);
		read[strlen(read)-1]='\0';
		(*A)[i]=(char*)malloc((strlen(read)+1)*sizeof(char));
		strcpy((*A)[i],read);
	}
}
int einvector(int a, int *v,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(*(v+i)==a) return 1;
	}
	return 0;
}
void linie(char *linie, char *del, char *outdel,int *v,int n)
{
	char sir[1000];
	sir[0]='\0';
	char *p;
	int i=0;
    int ok=0;
	p=strtok(linie,del);
	while(p!=NULL)
	{
		i++;
		if(einvector(i,v,n)==1)
		{
			strcat(sir,outdel);
			strcat(sir,p);
            ok=1;
		}
		p=strtok(NULL,del);
	}
    if(ok==0) printf("\n");
    else printf("%s\n",sir+strlen(outdel));
}
int main()
{
	char del[10],outdel[10],**A;
	int n,m,i;
	int v[100];
	citire(&n,del,outdel,&v,&m,&A);
	strcat(del," ");
	for(i=0;i<m;i++)
	{
		linie(A[i],del,outdel,v,n);
	}
	for(i=0;i<m;i++)
	{
		free(A[i]);
	}
	free(A);
	return 0;
}
