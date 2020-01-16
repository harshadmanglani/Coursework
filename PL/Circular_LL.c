/*

=========================================================================================
Description:

Implement polynomial expressions using CLL and perform
1. Addition of polynomials
2. Multiplication of polynomials
3. Evaluation of polynomials
=======================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#define nl printf("\n");

typedef struct poly
{
	int exp, coef;
	struct poly *next;
}node;

node* getnode(node* ptr, int co, int ex)			//helper function
{
	ptr = (node*)malloc(sizeof(struct poly));
	ptr->exp = ex;
	ptr->coef = co;
	ptr->next = NULL;
	return ptr;
}

node* insert(node* head, int co, int ex)			//function to insert as per order of powers
{
	node* temp;
	node* curr = head;
	temp = getnode(temp, co, ex);
	
	if(head == NULL)
	{
		if(ex == 8)
		printf("\n1\n");
		head = temp;
		temp->next = head;
		return head;
	}
	else if(ex >= head->exp)
	{
		if(ex > head->exp)
		{
			if(ex == 8)
	printf("\n2\n");
			temp->next = head;
			do
			{
				curr = curr->next;
			}while(curr->next!=head);
			curr->next = temp;
			head = temp;
		}
		else
		{
		if(ex == 8)
	printf("\n3\n");
		head->coef += co;
		}
	}
		
	else
	
	{
		do
		{
			curr = curr->next;
		}while(curr->next!=head && ex < curr->next->exp);
		
		if(curr->next!=head)
		{
			if(curr->next->exp == ex)
			{
				curr->next->coef += co;
			}
		
			else
			{
				temp->next = curr->next;
				curr->next = temp;
			}
		}
		
		else
		{
			if(curr->exp == ex)
			{
				curr->coef+=co;
				return head;
			}
			curr->next = temp;
			temp->next = head;
		}
	}
	return head;
	
}

void displayobj(int co, int ex)				//helper function to display
{
	if(co == 0)
	return;
	
	else if(ex == 0)
	printf("+ %d ", co);
	
	else if(ex == 1)
	printf("+ %dx ", co);
	
	else if(co==1)
	printf("+ x^%d ", ex);
	 
	else
	printf("+ %dx^%d ", co, ex);
	
}

void display(node* head)				//display function for cll
{
	node* curr = head;
	printf("f(x) = ");
	do
	{
		displayobj(curr->coef, curr->exp);
		curr = curr->next;
	}while(curr!=head);
	nl
}

void add(node* p1, node* p2, node* res)			//addition of two polynomials
{
	node *t1 = p1, *t2 = p2, *t3;
	/*
	
	shortcut method
	
	do
	{
		res = insert(res, t1->coef, t1->exp);
		t1 = t1->next;
	}while(t1!=p1);
	do
	{
		res = insert(res, t2->coef, t2->exp);
		t2 = t2->next;
	}while(t2!=p2);	
	nl
	t3 = NULL;
	t2 = NULL;
	t2 = res;
	do
	{
		t3 = insert(t3, t2->coef, t2->exp);
		t2 = t2->next;
	}while(t2!=res);	
	
	*/
	
	do
	{
		do
		{
			if(t1->exp > t2->exp)
			{
				res = insert(res, t1->coef, t1->exp);
				t2 = t2->next;
			}
			else if(t1 == t2)
			{
				res = insert(res, t1->coef + t2->coef, t2->exp);
				t1 = t1->next;
				t2 = t2->next;
			}
			else
			{
			    res = insert(res, t2->coef, t2->exp);
				t2 = t2->next;
			}
		}while(t2!=p2);
	}while(t2!=p2);
				
	printf("The addition of the two polynomials is: \n");
	display(res);
	nl
}

void mult(node *p1, node *p2, node *res)		//multilpication of two polynomials
{
	nl
	node *t1 = p1, *t2 = p2;
	do
	{
		t2 = p2;
		do
		{
			res = insert(res, t1->coef*t2->coef, t1->exp+t2->exp);
			t2 = t2->next;
		}while(t2!=p2);
		t1 = t1->next;
	}while(t1!=p1);
	
	t1 = t2 = res;
	res = NULL;
	do
	{
		res = insert(res, t1->coef, t1->exp);
		t1 = t1->next;
	}while(t1!= t2);
	
	printf("The multiplication of the two polynomials is: \n");
	display(res);
}

int power(int x, int p)
{
	if(p==0)
	return 1;
	int f=x, i = 0;
	for(i=1; i<p; i++)
	f = f*x;
	return f;
}
void eval(node* p, int x)
{
	node* t = p;
	int result = 0;
	do
	{
		result += t->coef*power(x, t->exp);
		nl
		t = t->next;
	}
	while(t!=p);
	printf("f(%d) = %d", x, result);
}
	
int main()
{
	node *p1 = NULL, *p2 = NULL, *res = NULL;
	int c = 0;
	int temp[4];
	
	while(c!=5)
	{
		printf("\n1. Input\n2. Add\n3. Multiply\n4. Evaluate\n5. Quit\nEnter: ");
		scanf("%d", &c);
		switch(c)
		{
			case 1:
			if(p1!=NULL)
			{
				free(p1); free(p2); free(res);
				p1 = p2 = res = NULL;
			}
			printf("Enter the number of terms for the first polynomial: ");
			scanf("%d", &temp[0]);
			for(temp[1]=0; temp[1]<temp[0]; temp[1]++)
			{
				printf("Enter the coefficient and power: ");
				scanf("%d%d", &temp[2], &temp[3]);
				p1 = insert(p1, temp[2], temp[3]);
			}
			display(p1);
			nl
			nl
			printf("Enter the number of terms for the second polynomial: ");
			scanf("%d", &temp[0]);
			for(temp[1]=0; temp[1]<temp[0]; temp[1]++)
			{
				printf("Enter the coefficient and power: ");
				scanf("%d%d", &temp[2], &temp[3]);
				p2 = insert(p2, temp[2], temp[3]);
			}
			display(p2);
			nl
			nl
			break;
			
			case 2:
			if(p1==NULL || p2=NULL)
			{
				printf("Please give input first.\n");
				break;
			}
			if(res!=NULL)
			{	
				free(res);
				res = NULL;
			}
			add(p1, p2, res);
			break;
			
			case 3:
			if(p1==NULL || p2=NULL)
			{
				printf("Please give input first.\n");
				break;
			}
			if(res!=NULL)
			{	
				free(res);
				res = NULL;
			}
			mult(p1, p2, res);
			break;
			
			case 4:
			if(p1==NULL || p2=NULL)
			{
				printf("Please give input first.\n");
				break;
			}
			printf("Enter a value for x: ");
			scanf("%d", &temp[0]);
			nl
			printf("The evaluation for the first polynomial is: ");
			eval(p1, temp[0]);
			printf("\nThe evaluation for the second polynomial is: ");
			eval(p2, temp[0]);
			break;
			
			case 5:
			if(p1==NULL || p2=NULL)
			{
				break;
			}
			free(p1);
			free(p2);
			break;
			
			default:
			printf("\nInvalid choice\n");
			c = 0;
			break;
		}
	}	
	return 0;
}		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	

