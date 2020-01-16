/*
==========================================================================================================

Description:
Implement Generalized Linked List to create and display the book index.
==========================================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#define max 40

typedef struct node
{
    struct node *next;
    int flag;
    union
    {
        char data[max];
        struct node *dlink;
    }u;
}node;

node *create_node(void)
{
    node *new=(node *)malloc(sizeof(node));
    new->next=NULL;
    new->u.dlink=NULL;
    return new;
}

node *creategll(node *head,char str[])
{
    int i=0,j;
    node *p=NULL;
    while(str[i]!='\0')
    {
        if(str[i]=='(' && i==0)
        {
            head=create_node();
            p=head;
        }
        else
        {
            p->next=create_node();
            p=p->next;
        }
        i++;
        j=0;
        while(str[i]!=',' && str[i]!='(' && str[i]!=')')
        {
            p->u.data[j]=str[i];
            i++;
            j++;
        }
        p->u.data[j]='\0';
        p->flag=0;
        if(str[i]=='(')
        {
            p->next=create_node();
            p=p->next;
            p->flag=1;
            p->u.dlink=creategll(NULL,&str[i]);
            while(str[i]!=')')
                i++;
            i++;
        }

        if(str[i]==')')
            return head;
    }
}

void show(node *p)
{
    while(p!=NULL)
    {
        if(p->flag==0)
        {
            printf("%s\n", p->u.data);
        }
        else
        {
            show(p->u.dlink);
        }
        p=p->next;
    }
}

int main(void)
{
    node *head=NULL;
    char str[200];
    printf("Enter the Input: \n");
    scanf("%s", str);
    head=creategll(head,str);
    show(head);
}

/*
(1.Unit1-01(1.1subtopic-02,1.2subtopic-04,1.3subtopic-07),2.Unit2-10(2.1subtopic-11(2.1.1sub-12,2.1.2sub-14,2.1.3sub-16),2.2subtopic-18),3.Unit3-20)
*/



