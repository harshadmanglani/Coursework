/*
Exception handling
*/

#include<iostream>
using namespace std;

class Divider{
	double a,b;
	public:
		Divider(){a=0; b=0;}
		void set(){cout<<"Enter a and b: "; cin>>a>>b; cout<<endl;}
		double divide(){
			if(b==0)
			throw "Division by zero error!\n";
			
			return (a/b);
		}
};

int main()
{
	Divider div;
	div.set();
	try{
	double a = div.divide();
	cout<<"a/b = "<<a<<endl;
	}
	catch(const char* msg){cout<<msg;}
	return 0;
}


/*output

Enter a and b: 1 0

Division by zero error!

*/
