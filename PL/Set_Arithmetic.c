/*
 ============================================================================

 Description : Perform the following set operations on arrays with and without
 	 	 	 	 using pointers:
 	 	 	 	 1. Union
 	 	 	 	 2. Intersection
 	 	 	 	 3. Difference
 	 	 	 	 4. Symmetric Difference
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int inputn1(){					//size of A
	int n1;
	printf("Enter the number of elements in the first set (max 10): \n");
	scanf("%d",&n1);
	return n1;
}

int inputn2(){				//size of B
	int n2;
	printf("Enter the number of elements in the second set (max 10): \n");
	scanf("%d",&n2);
	return n2;
}

void inputa(int* a, int n1){			//elements of A
	printf("Enter the elements in the first set: \n");
	for(int i=0;i<n1;i++)
		scanf("%d",&a[i]);
	//return a;
}

void inputb(int* b, int n2){			//elements of A
	printf("Enter the elements in the second set: \n");
	for(int i=0;i<n2;i++)
		scanf("%d",&b[i]);
	//return b;
}

int common(int a, int* c, int n){			//returns 1 if int a is not found in the array c of size n

	for(int i=0;i<n;i++)
	{
		if(a==c[i])
		{
			return 100;
			break;
		}
	}
	return 1;
}

void uni(int *a, int* b, int n1, int n2, int flag){		//union of two sets a and b, serves the facility for union of symm difference sets as well

	int c[20],n=0;

	for(int i=0;i<n1;i++){
		if(n1>=1)
		if(common(a[i], c, n)==1)				//push non repeated elements of A in union C
		{
			c[n]=a[i];
			n++;
		}
	}
	for(int i=0;i<n2 && i<n1;i++){
		if(common(b[i], c, n)==1)			//push non repeated elements of A and B in union C
		{
			c[n]=b[i];
			n++;
		}
	}
	if(flag==1)
	printf("The elements of the union set are: { ");
	if(flag==2)
	printf("The elements of the symmetric difference set are: { ");
	for(int i=0;i<n;i++)
		printf("%d ",c[i]);
	printf("}\n");
}

void inter(int *a, int *b, int n1, int n2){				//intersection of sets A and B

	int c[20],n=0;

	for(int i=0;i<n1;i++)
		for(int j=0;j<n2;j++)
		{
			if(a[i]==b[j])
			{
				if(common(a[i], c, n)==1)		//pushes common but non repeated elements from A and B into C
				{
					c[n]=a[i];
					n++;
				}
			}
		}
	printf("The elements of the intersection set are: { ");
	for(int i=0;i<n;i++)
		printf("%d ", c[i]);
	printf("}\n");

}

void diff(int* a, int* b, int n1, int n2, int flag){
	int c[20], n=0;
	for(int i=0;i<n1 && i<n2;i++)
	if(common(a[i], b, n2)==1)				//checks for elements existing in A but not in B
			if(common(a[i], c, n)==1)		//pushes after checking non repeated elements in C
			{
				c[n]=a[i];
				n++;
			}


	if(flag!=3){
	if(flag==1)
	printf("The elements of the subtraction A-B are: { ");
	if(flag==2)
	printf("The elements of the subtraction B-A are: { ");
	for(int i=0;i<n;i++)
		printf("%d ",c[i]);
	printf("}\n");
	}

	}

void symmdiff(int* a, int* b, int n1, int n2){
	int c[20], n=0;
	for(int i=0;i<n1 && i<n2;i++)
		if(common(a[i], b, n2)==1)
			if(common(a[i], c, n)==1)
			{
				c[n]=a[i];
//			printf("%d ",c[n]);
				n++;
			}

//printf("\n");

	int d[20], m=0;
	for(int i=0;i<n1 && i<n2;i++)
		if(common(b[i], a, n1)==1)
	if(common(b[i], d, m)==1)
			{
				d[m]=b[i];
		//		printf("%d  ", d[m]);
				m++;
			}
//same logic for differences of A-B and B-A without function calling
uni(c, d, n, m, 2);				//calling union for A-B and B-A

}

int main(void) {
	int n1,n2,c=0;
	int a[10],b[10];
	for(int i=0;i<10;i++)
	{
		a[i]=0;
		b[i]=0;
	}
while(c!=7)
{
	printf("Enter your choice from the following options:\n1. Give input\n2. Union\n3. Intersection\n4. Difference(A-B)\n5. Difference(B-A)\n6. Symmetric Difference\n7. Quit\n");
	printf("!!!! WARNING: TO AVOID PERFORMING OPERATIONS ON NULL SET, PLEASE GIVE INPUT BEFORE PERFORMING ANY OPERATION. !!!!\n");
	scanf("%d", &c);
	switch(c) {
	case 1:{
		n1=inputn1();
		n2=inputn2();
		inputa(a, n1);
		inputb(b, n2);
		break;
	}

	case 2:{
		uni(a, b, n1, n2, 1);
		break;
	}

	case 3:{
		inter(a, b, n1, n2);
		break;
	}

	case 4:{
		diff(a, b, n1, n2, 1);
		break;
	}

	case 5:{
		diff(b, a, n2, n1, 2);
		break;
	}

	case 6:{
		symmdiff(a, b, n1, n2);
		break;
	}

	case 7:
		break;

	default: printf("Invalid choice. Please try again.\n");
	}
}
	return 0;

}
