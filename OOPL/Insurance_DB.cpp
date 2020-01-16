//roll - 23336
//date of submission - 4th september 2019

/*Design a base class with name,date of birth,blood group and another base class
consisting of the data members such as height and weight.Design one more base
class consisting of the insurance policy number and contact address.The derived
class contains the data members telephone numbers and driving licence number.
Write a menu driven program to carry out the following things:

i. Build a master table
ii. Display
iii. Insert a new entry
iv. Delete entry
v. Edit
vi. Search for a record */

#include<vector>
#include<list>
#include<iostream>
#define tab cout<<"\t";
using namespace std;

class Human{
    string name;
    int dob[3];
    string bgp;
    
    public:
    void getname(){cin>>name;}
    void getdob(){cin>>dob[0]>>dob[1]>>dob[2];}
    void getbgp(){cin>>bgp;}
    void showname(){cout<<name;}
    void showdob(){cout<<dob[0]<<"/"<<dob[1]<<"/"<<dob[2];}
    void showbgp(){cout<<bgp;}
   
};

class Attrs{
    float ht_cms;
    float wt;
    
    public:
    void getht(){cin>>ht_cms;}
    void getwt(){cin>>wt;}
    void showht(){cout<<ht_cms;}
    void showwt(){cout<<wt;}
    
};

class Insurance{
    string policy_no;
    string address;
    
    public:
    void getpol(){cin>>policy_no;}
    void getaddress(){cin>>address;}
    void showpol(){cout<<policy_no;}
    string returnpol(){return policy_no;}
    void showaddress(){cout<<address;}
    
};

class Customer:public Human, public Attrs, public Insurance{
    string telephone;
    string drivers_license;
    
    public:
    void getphone(){cin>>telephone;}
    void getdl(){cin>>drivers_license;}
    void showtelephone(){cout<<telephone;}
    void showdl(){cout<<drivers_license;}
    friend void mastertable(vector <Customer> arr);
    friend int search(vector <Customer> arr, string pol);

};

void mastertable(vector <Customer> arr){
cout<<"SR.\tNAME\tHT\tWT\tDOB\t\t\tBGP\tTELE.\tDRIV_LIC\tPOLICY_NO\tADDRESS\n";
for(int i=0;i<arr.size();i++)
{
    cout<<i; tab
    arr[i].showname(); tab
    arr[i].showht(); tab
    arr[i].showwt(); tab
    arr[i].showdob(); tab tab tab
    arr[i].showbgp(); tab
    arr[i].showtelephone(); tab
    arr[i].showdl(); tab
    arr[i].showpol(); tab
    arr[i].showaddress();
    cout<<endl;
}

}

int search(vector <Customer> arr, string pol){
	int index = -1,temp = 0;
	string tempol;
	vector <Customer>::iterator it;
	it = arr.begin();
	for(it; it!=arr.end(); it++)
	{
		temp++;
		tempol = it->returnpol();
		if(tempol == pol)
		{
			index = temp;
			break;
		}
	}
	return index;
}

void print(){
cout<<"1. Create a database\n2. Add\n3. Display table\n4. Search\n5. Delete";
}

int main()
{
	vector <Customer> arr;
	string tempol;
	Customer temp;
	int c = 0, t, index;
	while(c!=6){
	print();
	cin>>c;
	switch(c){
	    case 1:
		cout<<"Enter the number of customers: ";
		cin>>t;
		for(int i = 0 ; i < t ; i++)
		{
		    temp.getname();
		    temp.getht();
		    temp.getwt();
		    temp.getdob();
		    temp.getbgp();
		    temp.getphone();     
		    temp.getdl();
		    temp.getpol();
		    temp.getaddress();
		    arr.push_back(temp);
		}
		break;
	    case 2:
		    temp.getname();
		    temp.getht();
		    temp.getwt();
		    temp.getdob();
		    temp.getbgp();
		    temp.getphone();     
		    temp.getdl();
		    temp.getpol();
		    temp.getaddress();
		    arr.push_back(temp);
		    break;
	    case 3:
		    mastertable(arr);
		    break;
		    
	    case 4: 
		    cout<<"Enter the policy number to search: ";
		    cin>>tempol;
		    if(search(arr, tempol)>=0) cout<<"\nCustomer record found.\n";
		    else cout<<"Customer record not found\n";
		    break;
	    
	    case 5: 
		    cout<<"Enter the policy number to delete: ";
		    cin>>tempol;
		    index = search(arr, tempol);
		    if(index>=0)
		    {arr.erase(arr.begin()+index); cout<<"\nDeletion successful";}
		    else
		    cout<<"\nOperation not possible. Record not found\n";
		    break;
	    default: break;
		  }
		 }
		 
	    
	return 0;

}
