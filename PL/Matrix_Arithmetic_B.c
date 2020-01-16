/*
 ============================================================================

 Description : Matrix Arithmetic with pointers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void printr2(){
	printf("Enter the number of rows in the second matrix (max 10): \n");
}
void printc2(){
	printf("Enter the number of columns in the second matrix (max 10): \n");
}
void printr1(){
	printf("Enter the number of rows in the first matrix (max 10): \n");
}
void printc1(){
	printf("Enter the number of columns in the first matrix (max 10): \n");
}
void printb(){
	printf("Enter the elements of the second matrix: \n");
}
void printa(){
	printf("Enter the elements of the first matrix: \n");
}

void print_menu(){
	printf("1. Give input\n2. Addition\n3. Multiplication\n4. Transpose\n5. Saddle Point\n6. Exit\n");
}




int input_num(){
	//number of rows/columns
	int n1;
	scanf("%d",&n1);
	return n1;
}

void input_matrix(int *a, int r, int c){			//input function for elements of the matrix

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		scanf("%d",&*(a+i*c+j));
}


void add(int **a, int **b, int r, int c){
	int arr[10][10];

	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			{*(*(arr+i))+j)=*(*(a+i)+j)+*(*(b+i)+j);}
	printf("The resultant addition matrix is: \n");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(*(*(arr+i))+j)<10)printf("0");
			printf("%d ",*(*(arr+i)+j));
		}
		printf("\n");
	}
}

void multiplication(int **a, int **b, int r1, int c1, int r2, int c2){
	int arr[10][10];

	for(int i=0;i<r1;i++)
		for(int j=0;j<c2;j++)
			for(int k=0;k<r1;k++)
			{
				*(arr+i*c2+j)+=*(a+i*c1+k)*(*(b+k*c2+j));
				//printf("arr[%d][%d] = a[%d][%d]*b[%d][%d]\n",i,j,i,k,k,j);
			}
	printf("The resultant multiplication matrix is: \n");
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			if(*(arr+i*c2+j)<10)printf("0");
			printf("%d ",*(arr+i*c2+j));
		}
		printf("\n");
	}
}

void transpose(int *a, int r, int c){

	int arr[10][10];
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			*(arr+i*c+j)=a[j][i];
		}

	printf("The resultant transpose matrix is: \n");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(*(arr+i*c+j)<10)printf("0");
			printf("%d ",*(arr+i*c+j));
		}
		printf("\n");
	}
}
int min(int *arr, int r1, int c){
	int index=0,ele=*(arr+r1*c+0);
	for(int i=0;i<c;i++)
	{
		if(*(arr+r1*c+i)<ele)
		{
		index=i;
		ele=*(arr+r1*c+i);
		}
}
	return index;
}
void sp(int *a, int r, int c)
{
	int x=0 , y=0, flag1=1;

	for(int i=0;i<r;i++){
			int index=min(a, i, c);
			if(index>=0)
			{
				for(int j=0;j<r;j++){
					if((*(a+j*c+index))>(*(a+j*c+index) || j==i))
					{
						continue;
					}
					else
					{
						flag1=0;
						break;
					}
				}
			if(flag1==1){
				x=i; y=index;
				break;
				}
			}
	}
	if(flag1==1)
		{printf("The saddle point is at index: x=%d, y=%d\n",x,y);
	printf("The value of the saddle point is: %d\n",*(a+x*c+y));}

	else
		printf("A saddle point does not exist.\n");
}

int main(void) {

	int c=0, r1=10, c1=10, r2=10, c2=10;
	int a[10][10], b[10][10];

	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++){
		(*(a+i*c+j))=0;
		(*(b+i*c+j))=0;
	}

	while(c!=6){
			print_menu();
		scanf("%d", &c);
		switch(c) {
		case 1:{
			printr1();
			r1=input_num();
			printc1();
			c1=input_num();
			printr2();
			r2=input_num();
			printc2();
			c2=input_num();

			printa();
			input_matrix(a, r1, c1);
			printb();
			input_matrix(b, r2, c2);
			break;
				}

		case 2:{
			if(r1!=r2 || c1!=c2)
				printf("Performing the operation isn't possible since matrix parameters are invalid.\n");
			else
			{
				add(a, b, r1, c1);
			}
			break;
		}
		case 3:{
			if(c1!=r2)
				printf("Performing the operation isn't possible since matrix parameters are invalid.\n");
			else{
				multiplication(a, b, r1, c1, r2, c2);
			}
			break;
		}

		case 4:{
			if(r1!=c1)
				printf("Transpose of matrix 1 is not possible\n");
			else
			{printf("For the first matrix: \n");
			transpose(a, r1, c1);}
			if(r2!=c2)
				printf("Transpose of matrix 2 is not possible.\n");
			else{
			printf("For the second matrix: \n");
			transpose(b, r2, c2);}
			break;
		}

		case 5:{
			printf("For the first matrix: \n");
			sp(a, r1, c1);
			printf("For the second matrix: \n");
			sp(b, r2, c2);
			break;
		}

		case 6:break;

		default: printf("Invalid choice.\n");
					c=0;
	}
 }
	return EXIT_SUCCESS;
}
