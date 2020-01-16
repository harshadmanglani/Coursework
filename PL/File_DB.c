/*
 ============================================================================
 
 Description : File Handling with databases

 ============================================================================
 */

#include <stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct Date
{
	int day;
	int month;
	int year;
}date;
typedef struct Database
{
	int flag;
	char id[8];
	char d_name[20];
	char mobile_no[11];
	date d;
	char blood_group[4];
}Blood_Bank;

static int d_no=0;
void addData(Blood_Bank b,int n, FILE *fptr);
void displayData(Blood_Bank b,int n, FILE *fptr);
void addRec(Blood_Bank b,int n, FILE *fptr);
int search(Blood_Bank b,int n,FILE *fptr);
void deleteRec(Blood_Bank b,int index,FILE *fptr);
void modifyRec(Blood_Bank b,int index,FILE *fptr);

int main()
{
	int n,loc,index,option,i;
	FILE *fptr;
	Blood_Bank b;
	printf("\nEnter the number of records in the database : ");
	scanf("%d",&n);
	addData(b,n,fptr);
	do
	{
		printf("\nEnter the required option number :\n1.Add Record\t\t2.Search for a record\t3.Modify a record\n4.Delete a record\t5.Display the database\t0.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				addRec(b,n,fptr);
				n++;
				break;
			case 2:
				index=search(b,n,fptr);
				if(index==-1)
				{
					printf("\nRecord not found.");
				}
				else
				{
					printf("\nRecord is found at %d location.\n",index+1);
					//displayData(b+index,1);
				}
				break;
			case 3:
				index=search(b,n,fptr);
				modifyRec(b,index,fptr);
				break;
			case 4:
				index=search(b,n,fptr);
				deleteRec(b,index,fptr);
				n--;
				break;
			case 5:
				fptr=fopen("lol.bin","rb");
				displayData(b,n,fptr);
				fclose(fptr);
				break;
			case 0:
			default:
				break;
		}
	}while(option);
	return 0;
}

void addData(Blood_Bank b,int n,FILE *fptr)
{
	int i;
	char temp[8];
	fptr=fopen("lol.bin","wb");
	for(i=0;i<n;i++)
	{
		printf("\nDonor Name : ");
		scanf(" %[^\n]s",b.d_name);
		printf("\nMobile Number: ");
		scanf(" %[^\n]s",b.mobile_no);
		while(strlen(b.mobile_no)!=10)
		{
			printf("\nThe mobile number must be 10 digits long. Re-enter the mobile number.");
			scanf(" %[^\n]s",b.mobile_no);
		}
		printf("\nDate of Donation : ");
		printf("\nDay : ");
		scanf("%d",&b.d.day);
		while(b.d.day>31 && b.d.day<1)
		{
			printf("\nThe day is invalid. Re-enter it.");
			scanf("%d",&b.d.day);
		}
		printf("\nMonth : ");
		scanf("\n%d",&b.d.month);
		while(b.d.month>12 && b.d.month<1)
		{
			printf("\nThe month is invalid. Re-enter it.");
			scanf("%d",&b.d.month);
		}
		printf("\nYear : ");
		scanf("\n%d",&b.d.year);
		printf("\nBlood Group : ");
		scanf(" %[^\n]s",b.blood_group);
		d_no++;
		strcpy(b.id,"BLDD");
		sprintf(temp,"%03d",d_no);
		strcat(b.id,temp);
		b.flag=1;
		fwrite(&b,sizeof(Blood_Bank),1,fptr);
	}
	fclose(fptr);
}

void addRec(Blood_Bank b,int n,FILE *fptr)
{
	int i;
	char temp[8];
	fptr=fopen("lol.bin","ab");
	printf("\nDonor Name : ");
	scanf(" %[^\n]s",b.d_name);
	printf("\nMobile Number: ");
	scanf(" %[^\n]s",b.mobile_no);
	while(strlen(b.mobile_no)!=10)
{
	printf("\nThe mobile number must be 10 digits long. Re-enter the mobile number.");
	scanf(" %[^\n]s",b.mobile_no);
	}
	printf("\nDate of Donation : ");
	printf("\nDay : ");
	scanf("\n%d",&b.d.day);
	while(b.d.day>31 && b.d.day<1)
	{
		printf("\nThe day is invalid. Re-enter it.");
		scanf("\n%d",&b.d.day);
	}
	printf("\nMonth : ");
	scanf("\n%d",&b.d.month);
	while(b.d.month>12 && b.d.month<1)
	{
		printf("\nThe month is invalid. Re-enter it.");
		scanf("%d",&b.d.month);
	}
	printf("\nYear : ");
	scanf("\n%d",&b.d.year);
	printf("\nBlood Group : ");
	scanf(" %[^\n]s",b.blood_group);
	d_no++;
	strcpy(b.id,"BLDD");
	sprintf(temp,"%03d",d_no);
	strcat(b.id,temp);
	b.flag=1;
	fwrite(&b,sizeof(Blood_Bank),1,fptr);
	fclose(fptr);
}

int search(Blood_Bank b,int n,FILE *fptr)
{
	char *id;
	int i=-1,option;
	fptr=fopen("lol.bin","rb");
	printf("\nEnter the category by which you wish to search.\n1.ID number\t2.Name of donor\n3.Mobile Number.\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			printf("\nEnter the ID number to search by : ");
			id=(char*)malloc(8*sizeof(char));
			scanf(" %[^\n]s",id);
			for(i=0;i<n;i++)
			{
				fread(&b,sizeof(Blood_Bank),1,fptr);
				if(!strcmp(id,b.id))
				{
					fclose(fptr);
					return i;
				}
			}
			free(id);
			break;
		case 2:
			printf("\nEnter the name of the donor\n");
			id=(char*)malloc(20*sizeof(char));
			scanf(" %[^\n]s",id);
			for(i=0;i<n;i++)
			{
				fread(&b,sizeof(Blood_Bank),1,fptr);
				if(!strcmp(id,b.d_name))
				{
					fclose(fptr);
					return i;
				}
			}
			free(id);
			break;
		case 3:
			printf("\nEnter the mobile number of the donor\n");
			id=(char*)malloc(11*sizeof(char));
			scanf(" %[^\n]s",id);
			for(i=0;i<n;i++)
			{
				fread(&b,sizeof(Blood_Bank),1,fptr);
				if(!strcmp(id,b.mobile_no))
				{
					fclose(fptr);
					return i;
				}
			}
			free(id);
			break;
	}
	fclose(fptr);
	return -1;
}

void modifyRec(Blood_Bank b,int index,FILE *fptr)
{
	int option;
	int i;
	int status;
	fptr=fopen("lol.bin","rb");
	FILE *temp=fopen("temp.bin","wb");
	for(i=0;!feof(fptr);i++)
	{
		fread(&b,sizeof(Blood_Bank),1,fptr);
		if(i==index)
		{
			printf("\nEnter the category by which you wish to update.\n1.Name of Donor\t2.Mobile Number\n");
			scanf("%d",&option);
			switch(option)
			{
			case 1:
				printf("\nName of donor is %s. Enter the new name.\n",b.d_name);
				scanf(" %[^\n]s",b.d_name);
				break;
			case 2:
				printf("\nMobile number of donor is %s. Enter the new mobile number.\n",b.mobile_no);
				scanf(" %[^\n]s",b.mobile_no);
				break;
			default:
				break;
			}	
		}
		fwrite(&b,sizeof(Blood_Bank),1,temp);
	}
	/*status =remove("lol.bin");
	if (status == 0)
    	printf("File deleted successfully.\n");
	else
	{
    	printf("Unable to delete the file\n");
    	perror("Following error occurred");
	}*/
	rename("lol.bin","deleted.bin");
	rename("temp.bin","lol.bin");
	fclose(fptr);
	fclose(temp);
}

void deleteRec(Blood_Bank b,int index,FILE *fptr)
{
	int i;
	int status;
	fptr=fopen("lol.bin","rb");
	FILE *temp=fopen("temp.bin","wb");
	for(i=0;!feof(fptr);i++)
	{
		fread(&b,sizeof(Blood_Bank),1,fptr);
		if(i==index)
		{
			b.flag=0;	
		}
		fwrite(&b,sizeof(Blood_Bank),1,temp);
	}
	status =remove("lol.bin");
	if (status == 0)
    	printf("File deleted successfully.\n");
	else
	{
    	printf("Unable to delete the file\n");
    	perror("Following error occurred");
	}
	rename("temp.bin","lol.bin");
	fclose(fptr);
	fclose(temp);
}

void displayData(Blood_Bank b,int n,FILE *fptr)
{
	int i=0;
	fptr=fopen("lol.bin","rb");
	printf("------------------------------------------------------------------------------------");
	printf("\n|   ID    |\tName\t| Mobile Number |   Date   | Blood Group |");
	printf("\n------------------------------------------------------------------------------------");
	for(i=0;i<n;i++)
	{
		fread(&b,sizeof(Blood_Bank),1,fptr);
		if(b.flag)
		{
			printf("\n| %s |%s\t\t| %s    | %02d/%02d/%02d | %s\t\t |\n",b.id,b.d_name,b.mobile_no,b.d.day,b.d.month,b.d.year,b.blood_group);
		}
	}
	printf("\n------------------------------------------------------------------------------------");
	fclose(fptr);
}
