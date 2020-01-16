
/*Problem Definition - Create A Class Named Weather Report That Holds A Daily Weather Report
                     with data members day of month,high temperature,low temperature,amount
                     of rain,amount of snow. Use different type of constructor to initialize
                     object also include a function that prompts the user and sets value for
                     each field so that you can overwrite the default values.Write a menu driven
                     program in C++ with options to enter data and generate monthly report that
                     displays average of each attribute(The constructor initializes the fields
                     with default values - 99 for day of month, 999 for high temperature,
                     -999 for low temperature and 0 for amount of rain and amount snow). */

#include <iostream>
#include <iomanip>
using namespace std;

class wrt{
	static float avg_sn, avg_rn, avg_ht, avg_lt;
	float amt_sn, amt_rn, ht, lt;
	int day;
public:
	wrt(){day=99; amt_sn=0.0; amt_rn=0.0; ht=999.0; lt=-999.0;}
	float as(){return avg_sn;}						//returns static values
	float ar(){return avg_rn;}						//of all later to be used averages
	float ah(){return avg_ht;}
	float al(){return avg_lt;}
	void update(int tem);
	void calculate();
	void display();
};

float wrt::avg_sn=0;
float wrt::avg_rn=0;
float wrt::avg_ht=0;
float wrt::avg_lt=0;

void wrt::calculate(){							//adds actual updated values of user to static variables
	if(ht!=999){
		avg_sn+=amt_sn;
		avg_rn+=amt_rn;
		avg_ht+=ht;
		avg_lt+=lt;
		}
}

void wrt::update(int temp){						//updates values for a particular day where temp is temporary value
	cout<<"Update the values for high temperature,low temperature, amount of snow, amount of rain respectively: "<<endl;
	cin>>ht>>lt>>amt_sn>>amt_rn;
	day=temp;
}

void wrt::display(){							//displays values of an object in proper format
	cout<<setw(9)<<day<<setw(7)<<ht<<setw(7)<<lt<<setw(7)<<amt_sn<<setw(7)<<amt_rn<<"\n";
}

void print(){								//menu printer function
	cout<<"Enter your choice from the following\n";
	cout<<"1. Update report\n2. View updated report\n3. Exit\n";
}

int main(){

	int n=0, c=0;
	wrt arr[30];
	    cout<<"------------WEATHER REPORT---------------"<<endl;
		cout<<setw(5)<<"Sr No"<<setw(7)<<"Day"<<setw(7)<<"HiTe"<<setw(7)<<"LoTe"<<setw(7)<<"Snow"<<setw(7)<<"Rain"<<endl;
		cout<<"-----------------------------------------"<<endl;

	for(int i=0; i<30; i++){
		if(i<=8)
		cout<<0;
		cout<<i+1;
		arr[i].display();
	}
		//cout<<endl<<" Avg_HT  Avg_LT  Avg_Sn  Avg_Rn  \n";
		cout<<"AVG";
		cout<<setw(15)<<(arr[0].ah()/n)<<setw(7)<<(arr[0].al()/n)<<setw(7)<<(arr[0].as()/n)<<setw(7)<<(arr[0].ar()/n)<<endl;
		cout<<"========================================"<<endl;

	while(c!=3){
		print();
		cin>>c;
		switch(c){

		case 1: int temp;
		cout<<"Enter the day for which you want to enter the report: ";
		cin>>temp;
		cout<<endl;
		n++;
		arr[temp-1].update(temp);
		break;

		case 2:
		   	    cout<<"------------WEATHER REPORT---------------"<<endl;
		cout<<setw(5)<<"Sr No"<<setw(7)<<"Day"<<setw(7)<<"HiTe"<<setw(7)<<"LoTe"<<setw(7)<<"Snow"<<setw(7)<<"Rain"<<endl;
		cout<<"-----------------------------------------"<<endl;

	for(int i=0; i<30; i++){
		if(i<=8)
		cout<<0;
		cout<<i+1;
		arr[i].display();
	}
		//cout<<endl<<" Avg_HT  Avg_LT  Avg_Sn  Avg_Rn  \n";
		cout<<"AVG";
		cout<<setw(15)<<(arr[0].ah()/n)<<setw(7)<<(arr[0].al()/n)<<setw(7)<<(arr[0].as()/n)<<setw(7)<<(arr[0].ar()/n)<<endl;
		cout<<"========================================"<<endl;

			break;

		case 3: break;

		default: cout<<"Invalid choice"<<endl;
		}
	}
	return 0;
}

