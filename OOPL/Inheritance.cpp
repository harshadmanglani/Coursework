/*
Inheritance
*/

#include<iostream>
using namespace std;

class Human{
	string name;
	int age;
	string bgp;
	
	public:
		Human(){age = 0; name = bgp = '\0';	}
		void getname(){cin>>name;}
		void getage(){cin>>age;}
		void getbgp(){cin>>bgp;}
		string showname(){return name;}
		int showage(){return age;}
		string showbgp(){return bgp;}
};

class Student{
	string degree;
	float percentage;
	
	public:
		Student(){percentage = 0; degree = '\0';	}
		void getdeg(){cin>>degree;}
		void getper(){cin>>percentage;}
		string showdeg(){return degree;}
		float showper(){return percentage;}
};

class Employee{
	int exp;
	string skill;
	
	public:
		Employee(){exp = 0; skill = '\0';	}
		void getexp(){cin>>exp;}
		void getskill(){cin>>skill;}
		int showexp(){return exp;}
		string showskill(){return skill;}
};

class Biodata: private Human, private Student, private Employee{
	public:
		Biodata(){;}
		void create();
		void display();
};

void Biodata::create(){
	cout<<"Kindly enter the employee details.";
	cout<<"\nName: " ; getname();
	cout<<"\nAge: "; getage();
	cout<<"\nBlood group: "; getbgp();
	cout<<"\nDegree: "; getdeg();
	cout<<"\nPercentage: "; getper();
	cout<<"\nExperience: "; getexp();
	cout<<"\nSkill level: "; getskill();
}

void Biodata::display(){
	cout<<"\n==================================================\n";
	cout<<"EMPLOYEE BIODATA"<<endl;
	cout<<"\nName: "<<showname();
	cout<<"\nAge: "<<showage();
	cout<<"\nBlood group: "<<showbgp();
	cout<<"\nDegree: "<<showdeg();
	cout<<"\nPercentage: "<<showper();
	cout<<"\nExperience: "<<showexp()<<" years";
	cout<<"\nSkill level: "<<showskill();
	cout<<"\n==================================================\n";
}

int main(){
	Biodata emp;
	emp.create();
	emp.display();
	return 0;
}
