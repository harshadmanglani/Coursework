

/*
File Handling using the terminal
*/



#include <iostream>
#include<string>
#include<cstring>
#include<fstream>

using namespace std;
int main(int argc, char const *argv[])
{
	string line;
	char filename[10];
	if(argc==1)
		strcpy(filename,"data.txt");
	else
		strcpy(filename,argv[1]);
		

	ofstream f1(filename);

	while(1)
    {
    	getline(cin, line); 
    	if(line=="\n")
    		break;
    	f1<<line<<"\n";
    }

    f1.close();
    
    ifstream f2("data.txt");
     while(f2)
    {
    	getline(f2, line); 
    	cout<<line<<"\n";
    }
    f2.close();
    
	return 0;
}
