/*
 ============================================================================

 Description : Sparse Matrices Arithmetic
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int r,c,data;
}S_Mat;
void createSparseMatrix1(S_Mat *m1,int n);
void createSparseMatrix2(S_Mat *m1, int **temp);
void displaySparseMatrix(S_Mat *m1);
void simpleTranspose(S_Mat *m1, S_Mat *m2);
void fastTranspose(S_Mat *m1, S_Mat *m2);
void addMatrix(S_Mat *m1, S_Mat *m2,S_Mat *m3);
void swap(int* a, int* b);
void bubble_sort(S_Mat *m1);
int main()
{
	S_Mat *m1,*m2,*m3;
	int option,n,r,c,**temp,i;
	do
	{
		printf("\nEnter the option number corresponding to the required operation\n");
		printf("1.Add data directly\t2.Add data manually\n3.Simple Transpose \t4.Fast Transpose \n5.Add Matrices\t6.Display\n0.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			//free(m1);
			printf("\nEnter the number of elements : ");
			scanf("%d",&n);
			m1=(S_Mat*)malloc((n+1)*sizeof(S_Mat));
			createSparseMatrix1(m1,n);
			break;
		case 2:
			//free(m1);
			printf("\nEnter the number of rows and columns : ");
			scanf("%d %d",&r,&c);
			temp=(int**)malloc(r*sizeof(int*));
            for ( i = 0; i < r; ++i)
                temp[i]=(int*)malloc(c*sizeof(int));
            m1=(S_Mat*)malloc(((r*c)+1)*sizeof(S_Mat));
            m1[0].r=r;
			m1[0].c=c;
            createSparseMatrix2(m1,temp);
            free(temp);
            break;
		case 3:
			printf("\n");
			m2=(S_Mat*)malloc((m1[0].data+1)*sizeof(S_Mat));
			simpleTranspose(m1,m2);
			//free(m2);
			break;
        case 4:
        	printf("\n");
        	m2=(S_Mat*)malloc((m1[0].data+1)*sizeof(S_Mat));
        	fastTranspose(m1,m2);
			//free(m2);
        	break;
        case 5:
        	m3=(S_Mat*)malloc((m1[0].data+1)*sizeof(S_Mat));
        	temp=(int**)malloc(r*sizeof(int*));
        	for ( i = 0; i < m1[0].r; ++i)
        		temp[i]=(int*)malloc(c*sizeof(int));
        	m2=(S_Mat*)malloc((m1[0].data+1)*sizeof(S_Mat));
        	m2[0].r=m1[0].r;
        	m2[0].c=m1[0].c;
        	printf("\nEnter the second matrix of same dimensions: ");
        	createSparseMatrix2(m2,temp);
        	addMatrix(m1,m2,m3);
        	displaySparseMatrix(m3);
        	printf("\n%d\n",m3[0].data);
        	free(temp);
        	break;
		case 6:
			//printf("%d\n",m1[0].data);
			displaySparseMatrix(m1);
			break;
		}
	}while(option);
	free(m1);
	free(m2);
	return 0;
}
void createSparseMatrix1(S_Mat *m1,int n)
{
	int i,r,c,data;
	m1[0].data=n;
	printf("%d\n",m1[0].data);
	printf("\nEnter the number of rows and columns : ");
	scanf("%d %d",&m1[0].r,&m1[0].c);
	for(i=1;i<n+1;i++)
	{
		m1[i].data=0;
	}
	for(i=1;i<n+1;i++)
	{
		printf("\nElement %d : ",i);
		scanf("%d %d %d",&r,&c,&data);
		if(m1[i].data==0)
		{
			m1[i].r=r;
			m1[i].c=c;
			m1[i].data=data;
		}
		else
		{
			printf("\nLocation already filled.");
			i--;
		}
	}
}
void createSparseMatrix2(S_Mat *m1, int **temp)
{
	int i,j,k=1,total=0;

	for ( i = 0; i < m1[0].r ; ++i)
	{
		for (j = 0; j < m1[0].c; ++j)
		{
			scanf("%d",&temp[i][j]);
			if(temp[i][j]!=0)
			{
				total++;
				m1[k].r=i;
				m1[k].c=j;
				m1[k].data=temp[i][j];
				m1[0].data=k;
				k++;
			}
			if(total>(m1[0].r*m1[0].c)/2)
			{
				total=-1;
				break;
			}
		}
		if(total==-1)
		{
			printf("\nThis matrix cannot be a sparse matrix.");
			return;
		}
	}
}
void simpleTranspose(S_Mat *m1, S_Mat *m2)
{
	int i;
	for ( i = 0; i <=m1[0].data; ++i)
	{
		m2[i]=m1[i];
	}
	bubble_sort(m2);
	for ( i = 1; i <=m2[0].data; ++i)//swap rows and columns
	{
		swap(&m2[i].r,&m2[i].c);
	}
	displaySparseMatrix(m1);
	displaySparseMatrix(m2);
}
void fastTranspose(S_Mat *m1, S_Mat *m2)
{
	int i;
	m2[0]=m1[0];
	int quantity[m1[0].c];
	int position[m1[0].c];
	for ( i = 1; i < m1[0].data; ++i)
	quantity[m1[i].c]++;

	position[0]=1;
	for ( i = 1; i < m1[0].c; ++i)
	position[i]=position[i-1]+quantity[i-1];

	for ( i = 1; i <= m1[0].data; ++i)//swap rows and columns
	swap(&m1[i].r,&m1[i].c);

	for ( i = 1; i <= m1[0].data; ++i)
	m2[(position[m1[i].r])++]=m1[i];
		
	for ( i = 1; i <= m1[0].data; ++i)//swap rows and columns
	swap(&m1[i].r,&m1[i].c);
		
	displaySparseMatrix(m1);
	displaySparseMatrix(m2);
}
void addMatrix(S_Mat *m1, S_Mat *m2,S_Mat *m3)
{
	int i=1,k=1,j=1;
	m3[0]=m1[0];
	while(i<=m1[0].data && j<=m2[0].data)
	{
		if(m1[i].r==m2[j].r && m1[i].c==m2[j].c)
		{
			m3[k]=m1[i];
			m3[k].data+=m2[j].data;
			i++;j++;k++;
		}
		else if(m1[i].r==m2[j].r && m1[i].c<m2[j].c)
		{
			m3[k]=m1[i];
			i++;k++;
		}
		else if(m1[i].r==m2[j].r && m1[i].c>m2[j].c)
		{
			m3[k]=m2[j];
			j++;k++;
		}
		else if(m1[i].r<m2[j].r)
		{
			m3[k]=m1[i];
			i++;k++;
		}
		else if(m1[i].r>m2[j].r)
		{
			m3[k]=m2[j];
			j++;k++;
		}
	}
	while(i<=m1[0].data)
	{
		m3[k]=m1[i];
		i++;k++;
	}
	while(j<=m2[0].data)
	{
		m3[k]=m2[j];
		j++;k++;
	}

	m3[0].data=k-1;

}
void displaySparseMatrix(S_Mat *m1)
{
	int i;
	printf("\n-------------------------");
	printf("\n| Row   |Column | Data  |");
	//Bubble Sort
	printf("\n-------------------------");
	for(i=0;i<=m1[0].data;i++)
	{
		//Bubble Sort
		printf("\n| %d\t| %d\t| %d\t|",m1[i].r,m1[i].c,m1[i].data);
	}
	//Bubble Sort
	printf("\n-------------------------");
}
void bubble_sort(S_Mat *m1)//Function to perform bubble sort with printing passes
{
	int i,j,swaps=0,n,k;
	n=m1[0].data;
	for(i=1;i<n;i++)
	{
		swaps = 0;//number of passes is i
		for(j=2;j<=n-i+1;j++)
		{
			if(m1[j].c<m1[j-1].c)
			{
				swaps++;
				S_Mat temp = m1[j-1];
				m1[j-1] = m1[j];
				m1[j] = temp;
			}
		}
		if(swaps == 0)
			break;
	}
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

