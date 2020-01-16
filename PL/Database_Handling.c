/*
 ============================================================================

 Description : Database handling
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int id=0;
struct date {
	int day, month, year;
};

typedef struct{
	struct date d;
	char name[MAX/2];
	char bgroup[4];
	char address[MAX*2];
	char mono[10];
	char bid[9];
}donor;

int valmono(char a[]){
	for(int i=0;i<10;i++)
	{
		if(a[i]>='0' && a[i]<='9')
		continue;
		else{
			printf("Please try again: \n");
			return 0;
	}}
	return 1;
}

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

int valbgp(char a[]){
	int i = 0;
	while(a[i]!='\0')
	{
		if(a[i]=='A' || a[i]=='B' || a[i]=='+' || a[i]=='-' || a[i]=='O')
			{i++; continue;}
		else
		{
			printf("Please try again: ");
			return 0;
		}
	}
	return 1;
}

void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
    	char temp = *(str+start);
    	*(str+start) = *(str+end);
        *(str+end) = temp;
        start++;
        end--;
    }
}

// Implementation of itoa()
char* itoa(int num, char* str, int base)
{
    int i = 0;
    int isNegative = 0;

    /* Handle 0 explicitly, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}

void createdatabase (donor s[], int n){
	int temp = 0;
	int t;
	char temp1[6] = "BLOOD_"; 
	for(int i=0; i<n; i++){
		t = ++id;
		char te[3];
		while(temp!=1){
		printf("\nEnter the name: ");
		scanf("\n");
		gets(s[i].name);
		temp = valname(s[i].name);
		}
		temp = 0;

		while(temp!=1){
		printf("Enter cell no.: ");
		scanf("\n");
		gets(s[i].mono);
		temp = valmono(s[i].mono);
		}
		temp = 0;

		while(temp!=1){
		printf("Enter blood group: ");
		scanf("\n");
		gets(s[i].bgroup);
		temp = valbgp(s[i].bgroup);
		}
		temp = 0;

		while(temp!=1){
		printf("Enter address: ");
		scanf("\n");
		gets(s[i].address);
		temp = valname(s[i].address);
		}
		temp = 0;

		printf("Enter the date of donation in dd/mm/yyyy format: ");
		scanf("\n%d %d %d",&s[i].d.day,&s[i].d.month,&s[i].d.year);

	//	for(int j = 0;j < 6; j++)
		//s[i].bid[j] = temp1[j];
		//itoa(t, te,10);
		//strcat(s[i].bid, te);
		scanf("\n");
		gets(s[i].bid);	}
}

void add(donor s[], int n){
	int temp = 0;
	int i = n;
	char te[3];
	int t = ++id;
	char temp1[6] = "BLOOD_"; 
		while(temp!=1){

		printf("\nEnter the name: ");
		scanf("\n");
		gets(s[i].name);
		temp = valname(s[i].name);
		}
		temp = 0;

		while(temp!=1){
		printf("Enter cell no.: ");
		scanf("\n");
		gets(s[i].mono);
		temp = valmono(s[i].mono);
		}
		temp = 0;

		while(temp!=1){
		printf("Enter blood group: ");
		scanf("\n");
		gets(s[i].bgroup);
		temp = valbgp(s[i].bgroup);
		}
		temp = 0;

		while(temp!=1){
		printf("Enter address: ");
		scanf("\n");
		gets(s[i].address);
		temp = valname(s[i].address);
		}
		temp = 0;

		printf("Enter the date of donation in dd/mm/yyyy format: ");
		scanf("\n%d %d %d",&s[i].d.day,&s[i].d.month,&s[i].d.year);
		
		for(int j = 0;j < 6; j++)
		s[i].bid[j] = temp1[j];
		itoa(t, te,10);
		strcat(s[i].bid, te);
		printf("

}

void deleterec(donor s[], int i, int *n){
	if(i==-1){
			printf("Operation not possible.\n");
			return;
		}
	for(int j=i; j<(*n-1); j++){
		s[j] = s[j+1];
	}
	printf("Delete successful.\n");
	*n = *n-1;
}

void print(){
	printf("1. Create database\n2. Add record\n3. Update record\n4. Delete record\n5. Display\n6. Quit\n");
}

int search(donor s[], char d[], int n){
	int temp = -1;
	for(int j=0; j<n; j++){
		if(d==s[j].bid)
			return j;
	}
	return temp;
}

void update(int n, donor s[]){
	if(n==-1){
		printf("Operation not possible.\n");
		return;
	}
	printf("\nEnter the name: ");
		scanf("\n");
		gets(s[n].name);
		printf("Enter cell no.: ");
		scanf("\n");
		gets(s[n].mono);
		printf("Enter blood group: ");
		scanf("\n");
		gets(s[n].bgroup);
		printf("Enter address: ");
		scanf("\n");
		gets(s[n].address);
		printf("Enter the date of donation in dd/mm/yyyy format: ");
		scanf("\n%d %d %d",&s[n].d.day,&s[n].d.month,&s[n].d.year);
}

void display(donor s[], int n){
	printf("\n==============================\n");
	printf("SNO   NAME   \tBGRP\tPHONE-NUM.\tUNIQUE-ID\tDATE\n");
	for(int i=0; i<n; i++)
	printf("%d    %s\t%s\t%s\t%s\t\t%d/%d/%d\n", i, s[i].name, s[i].bgroup, s[i].mono, s[i].bid, s[i].d.day, s[i].d.month, s[i].d.year);
}
int main(void){
	donor s[MAX];
	char chi[9];
	int c=0, n=0;
	int temp;
	while(c != 6)
	{
		print();
		scanf("%d", &c);

		switch(c){
		case 1:
			printf("Enter the number of records you want to add: ");
			scanf("%d", &temp);
			printf("\n");
			createdatabase(s, temp);
			n = temp;
			break;

		case 2:
			add(s, n);
			n++;
			break;

		case 3:
			printf("Enter the ID which you want to update: ");
			scanf("\n");
			gets(chi);
			printf("\n");
			update(search(s, chi, n), s);
			break;

		case 4:
			printf("Enter the ID which you want to delete: ");
			scanf("\n");
			gets(chi);
			printf("\n");
			deleterec(s, search(s, chi, n), &n);
			break;

		case 5:
			display(s, n);
			break;

		case 6:
			break;

		default:
			printf("Invalid choice\n");
			c=0;
			break;
		}
	}
return 0;
}
