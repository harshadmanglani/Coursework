/*
 ============================================================================

 Description : File Handling using the terminal
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	 FILE *fs,*ft;
	 char ch;
	 if(argc!=3)
	 {
	  printf("Please enter the arguments correctly after restarting the program.");
	  return 1;
	 }
	 fs=fopen(argv[1],"r");
	 if(fs==NULL)
	 {
	  printf("Can't find the source file.");
	  return 1;
	 }

	 ft=fopen(argv[2],"w");

	 while(ch!=EOF)
	 {
	  ch=fgetc(fs);
	  fputc(ch,ft);
	 }

	 fclose(fs);
	 fclose(ft);

	return EXIT_SUCCESS;
}
