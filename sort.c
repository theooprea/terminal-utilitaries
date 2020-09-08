#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void citire(int *n,float ***A,int **vector,int **vector2)
{
	scanf("%d",n);
	int i,j,capacitate;
	float x;
	*vector=(int *)malloc((*n)*sizeof(int));
	*vector2=(int *)malloc((*n)*sizeof(int));
	*A=(float **)malloc((*n)*sizeof(float *));
	int increm=3;
	for(i=0;i<(*n);i++)
	{
		(*A)[i]=(float *)malloc(increm*sizeof(float));
	}
	for(i=0;i<(*n);i++)
	{
		(*vector2)[i]=i;
		capacitate=3;
		j=0;
		while(scanf("%f",&x)==1)
		{
			if(x!=0)
			{
				if(capacitate==j)
				{
					capacitate+=increm;
					(*A)[i]=(float *)realloc((*A)[i],capacitate*sizeof(float));
				}
				(*A)[i][j]=x;
			}
			j++;
			if(x==0)
			{
				j--;
				(*A)[i]=(float *)realloc((*A)[i],j*sizeof(float));
				(*vector)[i]=j;
				break;
			}
		}
	}
}
void schimblinie(float **a, float **b,int *capa,int *capb,int *intrata, int *intratb)
{
	float *p;
	int aux;
	if((*capa)>(*capb))
	{
		*b=(float *)realloc(*b,(*capa)*sizeof(float));
		p=*a;
		*a=*b;
		*b=p;
		*a=(float *)realloc(*a,(*capb)*sizeof(float));
		aux=*capa;
		*capa=*capb;
		*capb=aux;
		aux=*intrata;
		*intrata=*intratb;
		*intratb=aux;
	}
	else
	{
		*a=(float *)realloc(*a,(*capb)*sizeof(float));
		p=*a;
		*a=*b;
		*b=p;
		*b=(float *)realloc(*b,(*capa)*sizeof(float));
		aux=*capa;
		*capa=*capb;
		*capb=aux;
		aux=*intrata;
		*intrata=*intratb;
		*intratb=aux;
	}
}
float medie(float *a,int capa)
{
	int i;
	float suma=0;
	for(i=0;i<capa;i++)
	{
		suma+=a[i];
	}
	float med=suma/capa;
	return med;
}
void sort(float ***A,int **vector,int n,int **vector2)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(medie((*A)[i],(*vector)[i])<medie((*A)[j],(*vector)[j]))
			{
				schimblinie(&(*A)[i],&(*A)[j],&(*vector)[i],&(*vector)[j],&(*vector2)[i],&(*vector2)[j]);
			}
		}
	}
}
void sortintrata(float ***A,int **vector, int n,int **vector2)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(medie((*A)[i],(*vector)[i])==medie((*A)[j],(*vector)[j]))
			{
				if((*vector2)[i]>(*vector2)[j])
				{
					schimblinie(&(*A)[i],&(*A)[j],&(*vector)[i],&(*vector)[j],&(*vector2)[i],&(*vector2)[j]);   
				}
			}
		}
	}
}
void afisare(float **A,int *vector,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("%-10.3f",medie(A[i],vector[i]));
		for(j=0;j<vector[i];j++)
		{
			printf("%.0f ",A[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n,*vector,i,*vector2;
	float **A;
	citire(&n,&A,&vector,&vector2);
	sort(&A,&vector,n,&vector2);
	sortintrata(&A,&vector,n,&vector2);
	afisare(A,vector,n);
	for(i=0;i<n;i++)
	{
		free(A[i]);
	}
	free(A);
	free(vector);
	free(vector2);
	return 0;
}