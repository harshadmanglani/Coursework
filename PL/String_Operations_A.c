 /*
 ============================================================================

 Description : String Operations without pointers
 ============================================================================
 */

#include <stdio.h>

int slen (char s1[]){
	int len=0;
	while(s1[len]!='\0')
		len++;
	return len;
}

void scpy (char s1[], char s2[]){
	int i=0;
	while(s1[i]!='\0')
		{
		s2[i]=s1[i];
		i++;
		s2[i]='\0';
		}
}

void srev (char s1[]){
	int i=0;
	int len=slen(s1);
	printf(" %d ", len);
		while(i<len/2)
			{
			char temp = s1[i];
			s1[i] = s1[len-i-1];
			s1[len-i-1] = temp;
			i++;
			}
}

int scmp (char s1[], char s2[]){
	int l1=slen(s1), l2=slen(s2),i=0;
	if (l1>l2)
		return 1;
	else if (l1<l2)
		return -1;
	else
	{
		while(s1[i]!='\0')
		{
			if (s1[i]>s2[i])
				return 1;
			else if (s1[i]<s2[i])
				return -1;
			i++;
		}
	}
	return 0;
}

int strpal (char s1[]){
	char s2[50];
	scpy(s1, s2);
	srev(s2);
	return scmp(s1, s2);
}

int strsub (char s1[], char s2[]){
	int i=0,j=0,l1=slen(s1), l2=slen(s2), ctr=0;
	if(l1<l2)
	while(s2[i]!='\0')
	{
		if(s1[0]==s2[i])
		{
			j=0;
			while(s1[j]==s2[i+j])
				j++;

			if(j==l1)
				ctr++;
		}
		i++;
	}
	return ctr;

}

int main(void) {
	char s1[50], s2[50];
	int c=0;
	while(c!=8){
		printf("\n1. Input\n2. Length\n3. Copy\n4. Compare\n5. Reverse\n6. Palindrome\n7. Substring\n8. Quit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &c);
		printf("\n");
		switch(c){
		case 1:{
			printf("Enter your string: ");
			scanf("\n");
			gets(s1);
			printf("\n");
			break;
		}

		case 2:{
			printf("The length of the string is: %d\n",slen(s1));
			break;
		}

		case 3:{
			scpy(s1, s2);
			printf("Your string has been copied.\n\nSource: ");
			puts(s1);
			printf("\nDestination: ");
			puts(s2);
			printf("\n");
			break;
		}

		case 4:{
			printf("Enter the string you want to compare with the original string: ");
			scanf("\n");
			gets(s2);
			int res=scmp(s1, s2);
			if(res==0)
				printf("\nThe strings are equal\n");
			else
				printf("The strings are unequal\n");
			break;
		}

		case 5:{
			srev(s1);
			printf("The reversed string is: ");
			puts(s1);
			printf("\n");
			break;
		}

		case 6:{
			int res=strpal(s1);
			if(res==0)
				printf("The string is palindrome.\n");
			else
				printf("The string is not palindrome.\n");
			break;
		}

		case 7:{
			printf("Enter the substring: ");
			scanf("\n");
			gets(s2);
			int res=strsub(s2, s1);
			if(res>=0)
				printf("\nThe substring has %d occurrences\n",res);
			else
				printf("Substring not found.\n");
			break;
		}

		case 8:break;

		default: printf("Invalid choice\n");

		}
	}
	return 0;
}
























