/*
 ============================================================================
 
 Description: Singly Linked List
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

//Structure declarations
struct Node
{
	int data;
	struct Node *next;
};
//Function declarations
struct Node* getnode(struct Node*);
void display(struct Node*);
struct Node* create(struct Node*);
struct Node* insert_beg(struct Node*);
struct Node* insert_end(struct Node*);
struct Node* insert_n(struct Node*,int n);
void reverse(struct Node*);
struct Node* Delete(struct Node*,int n);
struct Node* Delete_first(struct Node*);
struct Node* Delete_last(struct Node*);
struct Node* revert(struct Node*);
void reverse(struct Node* head)  
{
	struct Node* temp;
	if(head!=NULL)
	{
		temp=head;
		head=head->next;
		reverse(head);     
		printf("%d-->>",temp->data);
	}
}

int main()
{
	int ch,ch1,ch2;
	struct Node* head=NULL;
	int n;
	do
	{
		printf("\n1.Create\n2.Display\n3.Insert\n"
				"4.Reverse Display\n5.Delete\n6.Revert\n7.Exit\n\n");
		printf("\nPlease enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				head=create(head);
			break;
			case 2:
				display(head);
			break;
			case 3:
				printf("\n1.Insert at the beginning\n"
						"2.Insert at the end\n3.Insert in between\n\n");
				printf("\nPlease enter your choice\n");
				scanf("%d",&ch1);
				switch(ch1)
				{
					case 1:
						head=insert_beg(head);
					break;
					case 2:
						head=insert_end(head);
					break;
					case 3:
						printf("\nPlease enter the position to insert value\n");
						scanf("%d",&n);
						head=insert_n(head,n);
					break;
				}
			break;
			case 4:
				printf("\n");
				reverse(head);
				printf("\n");
			break;
			case 5:
				printf("\n1.Delete the first node\n"
						"2.Delete the last node\n3.Delete in between\n\n");
				printf("\nPlease enter your choice\n");
				scanf("%d",&ch2);
				switch(ch2)
				{
					case 1:
						head=Delete_first(head);
					break;
					case 2:
						head=Delete_last(head);
					break;
					case 3:
						display(head);
						printf("\nPlease enter the position to delete the value\n");
						scanf("%d",&n);
						head=Delete(head,n);
					break;
				}
			break;
			case 6:
				head=revert(head);
			break;
			case 7:
				return (1);
			break;
		}
	}while (1);
}

//Function to display SLL
void display(struct Node* head)  
{
	printf("\n");
	while(head!=NULL)     /
	{
		printf("%d-->>",head->data);
		head=head->next;
	}
	printf("NULL");
	printf("\n");
}

//Function to allocate memory for node
struct Node* getnode(struct Node* node1)    
{
	node1=(struct Node *)malloc(sizeof(struct Node));    
	return (node1);
}

//Function to create a linked list from scratch
struct Node* create(struct Node* head)
{
	struct Node* temp=NULL;
	struct Node* node=NULL;
	int flag=1;

	while(flag==1)
	{
		node=getnode(node);
		printf("\nEnter the value\n");
		scanf("%d",&node->data);
		//printf("\n");

		if(head==NULL)
		{
			head=node;
			temp=head;
		}
		else
		{
			temp->next=node;
			temp=node;
		}
		display(head);
		printf("\nDo you want to continue?\n0-No\t1-Yes\n");
		scanf("%d",&flag);
	}
	return (head);
}

//Function to insert a node at beginning
struct Node* insert_beg(struct Node* head)
{
	struct Node* node=NULL;
	node=getnode(node);
	printf("\nPlease enter the value\n");
	scanf("%d",&node->data);
	node->next=head;
	head=node;
	return (head);
}

//Function to insert a node at end
struct Node* insert_end(struct Node* head)
{
	struct Node* node=NULL;
	struct Node* temp=head;
	node=getnode(node);
	printf("\nPlease enter the value\n");
	scanf("%d",&node->data);
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}

	temp->next=node;
	node->next=NULL;
	return (head);
}

//Function to insert a node in the middle
struct Node* insert_n(struct Node* head,int n)
{
	struct Node* node=NULL;
	int i;
	node=getnode(node);
	printf("\nPlease enter the value\n");
	scanf("%d",&node->data);
	node->next=NULL;
	if(n==1)
	{
		node->next=head;
		head=node;
	}

	struct Node* temp;
	temp=head;

	for(i=0;i<(n-2);i++)
	{
		temp=temp->next;
	}
	node->next=temp->next;
	temp->next=node;

	return (head);
}

//Function to display reverse of Linked list
void reverse(struct Node* head)  
{
	struct Node* temp;
	if(head!=NULL)
	{
		temp=head;
		head=head->next;
		reverse(head);     
		printf("%d-->>",temp->data);
	}
}

//Function to delete from middle
struct Node* Delete(struct Node* head,int n)
{
	int i;
	struct Node* node=NULL;
	struct Node* temp=head;

	if(n==1)
	{
		head=temp->next;
		free (temp);
	}

	for(i=0;i<(n-2);i++)
	{
		temp=temp->next;
	}

	node=temp->next;
	temp->next=node->next;
	free (node);
	return (head);
}

//Function to delete from first
struct Node* Delete_first(struct Node* head)
{

	struct Node* temp=head;

	head=temp->next;
	free (temp);

	return (head);
}

//Function to delete last node
struct Node* Delete_last(struct Node* head)
{
	struct Node* temp=head;
	struct Node* previous=head;

	while((temp->next)->next!=NULL)
	{
		previous=temp;
		temp=temp->next;
	}
	previous->next=NULL;
	free(temp);
	return (head);
}


//Function to revert the complete linked list
struct Node* revert(struct Node* head)
{
	struct Node* temp=NULL;
	struct Node* result=NULL;
	struct Node* current=head;

	while(current!=NULL)
	{
		temp=current->next;
		current->next=result;
		result=current;
		current=temp;
	}
	head=result;
	return (head);
}

OUTPUT 
1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
1

Enter the value
11

11-->>NULL

Do you want to continue?
0-No	1-Yes
1

Enter the value
22

11-->>22-->>NULL

Do you want to continue?
0-No	1-Yes
1

Enter the value
33

11-->>22-->>33-->>NULL

Do you want to continue?
0-No	1-Yes
1

Enter the value
44

11-->>22-->>33-->>44-->>NULL

Do you want to continue?
0-No	1-Yes
0

1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
2

11-->>22-->>33-->>44-->>NULL

1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
4

44-->>33-->>22-->>11-->>

1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
3

1.Insert at the beginning
2.Insert at the end
3.Insert in between


Please enter your choice
1

Please enter the value
10

1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
3

1.Insert at the beginning
2.Insert at the end
3.Insert in between


Please enter your choice
2

Please enter the value
55

1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
3

1.Insert at the beginning
2.Insert at the end
3.Insert in between


Please enter your choice
3

Please enter the position to insert value
3

Please enter the value
30

1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
2

10-->>11-->>30-->>22-->>33-->>44-->>55-->>NULL

1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
5

1.Delete the first node
2.Delete the last node
3.Delete in between


Please enter your choice
1

1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
5

1.Delete the first node
2.Delete the last node
3.Delete in between


Please enter your choice
2

1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
5

1.Delete the first node
2.Delete the last node
3.Delete in between


Please enter your choice
3

11-->>30-->>22-->>33-->>NULL

Please enter the position to delete the value
2

1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
2

11-->>22-->>33-->>NULL

1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
6

1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
2

33-->>22-->>11-->>NULL

1.Create
2.Display
3.Insert
4.Reverse Display
5.Delete
6.Revert
7.Exit


Please enter your choice
7


