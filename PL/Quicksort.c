/*================================================================================================

Description: Quicksort implementation
==================================================================================================*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define new printf("\n");

int i;

typedef struct{
long int mobile;
char name[20];
float bill;
}mob;

int temp1, passctr = 0, swapctr, swap = 0;

void Quicksort_recursive(mob arr[], int start, int end)
{	
	if(start>end)
	return;
	swapctr = 0;
	passctr++;
	printf("start: %d\tend: %d\tpass: %d\n", start, end, passctr);
	int pindex = end;
	mob temp;
	for(i = 0; i <= end; i++)
	{
	
		if(strcmp(arr[i].name, arr[pindex].name)>=0)
		continue;

		else if(strcmp(arr[i].name, arr[pindex].name)<0 && pindex>i)
		{
			temp = arr[pindex];
			arr[pindex] = arr[i];
			arr[i] = temp;
			pindex = i;
			swapctr++;
			swap++;
			
			for( i = 0; i < temp1; i++)
			printf("%s\n", arr[i].name);
			new 
		}
	}
	printf("Swaps in this pass: %d\n\n", swapctr);
	Quicksort_recursive(arr, pindex+1, end);
	Quicksort_recursive(arr, start, pindex-1);
}	
	
int main()
{
	mob arr[100];
	int c;
	printf("Enter the number of users you want to create a database for: ");
	scanf("%d", &temp1);
	new
	for( i=0; i<temp1; i++)
	{
		printf("Enter the name: ");
		scanf("\n");
		gets(arr[i].name);
		printf("Enter the mobile number: ");
		scanf("\n%ld", &arr[i].mobile);
		printf("Enter the bill amount: ");
		scanf("%f", &arr[i].bill);
		new
	}
	
	while(c!=2)
	{
		printf("1. Descending order of names by recursive quicksort\n2. Quit\nEnter your choice: ");
		scanf("\n%d", &c);
		switch(c){
		case 1: 
			swap = 0;
			Quicksort_recursive(arr, 0, temp1-1);
			for( i = 0; i < temp1; i++)
			{
				printf("%s\t", arr[i].name);
				printf("%ld\t", arr[i].mobile);
				printf("%.2f\n", arr[i].bill);
			}
			printf("Total number of swaps: %d\n", swap);
			if(swap == temp1/2)
			printf("Worst case, time complexity: O(n^2)\n");
			else if(swap == 0)
			printf("Best case, time complexity: O(nlogn)\n");
			else
			printf("Average case, time complexity: O(nlogn)\n");
			break;
		
			
			case 2:break;
			
			default: 
			    c = 0;
			    break;
		}
	}
	
	return 0;
}
	
