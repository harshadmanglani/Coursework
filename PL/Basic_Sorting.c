/*
 ============================================================================
 
 Description : Sorting Algorithms
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100



typedef struct{
	char name[MAX/2];
	int roll;
	float percentage;
}student;

int i;
int valname(char a[]){
	int i = 0;
	while(a[i]!='\0')
	{
		if(a[i]>='A' && a[i]<='z')
			{i++; continue;}
		else
		{
			printf("Please try again: ");
			return 0;
		}
	}
	return 1;
}

int valroll(int a, student s[], int n){
	for(i = 0; i < n; i++)
	{
		if(a==s[i].roll)
		{
			printf("\nRoll number already exists, please try again.\n");
			return 0;
		}
	}
	return 1;
}

void createdatabase (student s[], int n){
	int temp = 0, roll;
	printf("n: %d\n", n);
	
	for(i=0; i<n; i++){
		printf("i: %d\t\t", i);
		while(temp!=1){
		printf("\nEnter the name: ");
		scanf("\n");
		gets(s[i].name);
		temp = valname(s[i].name);
		}
		temp = 0;
        
        
	//	while(temp!=1){
			printf("Enter the roll number: ");
			scanf("\n");
			scanf("%d", &roll);
	//		if(i==0) temp=1;
	//		if(i!=0)
	//		temp = valroll(roll, s, n);
	//
	//	}
		s[i].roll = roll;
	//	temp = 0;

		printf("Enter the percentage: ");
		scanf("\n%f", &s[i].percentage);

	}
}

void display(student s[], int n){
	for(i = 0; i < n; i++)
	{
		printf("%s\t\t%d\t%f%\n", s[i].name, s[i].roll, s[i].percentage);
	}
}

void swap(student *xp, student *yp)  
{  
    student temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  


void bubblesort(student array[], int n){
	int c, d,swapctr=0, temp;
	  for (c = 0 ; c < n; c++)
	  {
	    temp = swapctr;
	    for (d = 0 ; d < n - c; d++)
	    {
	      if (array[d].roll > array[d+1].roll)
	      {swapctr++; swap(&array[d], &array[d+1]);}
	      
	      display(array, n);
	      printf("Number of swaps: %d", swapctr);
	    }
	    if(temp == swapctr)
	    break;
	  }
}

void selectionsort(student array[], int n){
int i, j, min, swapctr = 0;
    
    for (i = 0; i < n-1; i++)  
    {  
        min = i;  
        for (j = i+1; j < n; j++)  
        if (strcmp(array[j].name, array[min].name)>0)  
            min = j;  
  
        swap(&array[min], &array[i]);
		swapctr++;
        display(array, n);
		printf("Number of swaps are: %d", swapctr);
    }  
}

int binarysearch(student array[], int n, int temp){
	bubblesort(array, n);
	return bs(array, 0, n, temp);
}

int bs(student arr[], int start, int end, int temp){
	if(start==end || start-end == 1 || start-end == -1)
	return -1;
	int mid = (start + end)/2;
	if(temp == arr[mid].roll)
	return mid;
	else if(temp > arr[mid].roll)
	bs(arr, mid, end, temp);
	else
	bs(arr, start, mid, temp);
}
void print(){
printf("\n1. Display\n2. Sort by roll number in ascending order\n3. Sort by names in descending order\n4. Binary search for roll number\n5. Quit\n\n");
}

int main(void) {
	int temp, n = 0, c = 0;
	student s[MAX];
	printf("Create a database: \n");
	printf("Enter the number of records you want to add: ");
				scanf("%d", &temp);
				printf("temp: %d", temp);
				printf("\n");

				createdatabase(s, temp);
				n = temp;

				while(c != 6)
					{
						print();
						scanf("%d", &c);

						switch(c){
						case 1:
							display(s, n);
							break;

						case 2:
							printf("Sorting by roll number in ascending order: ");
							bubblesort(s, n);
							break;

						case 3:
							printf("Sorting by names in descending order: ");
							selectionsort(s, n);
							break;

						case 4:
							printf("Enter the roll number you want to search: ");
							scanf("%d", &temp);
							printf("\nRecord found at location: %d",binarysearch(s,n, temp));
							break;

						case 5:
							break;

						default:
							printf("Invalid choice\n");
							c=0;
							break;
						}
					}

	return EXIT_SUCCESS;
}
