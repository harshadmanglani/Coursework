
/*
File handling, storing information in a database
*/


#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
class Student
{
	char name[20];
	char mob[11];// Dont use strings, convert it all into char arrays. https://isocpp.org/wiki/faq/serialization
	double percentage;
public:
	Student()
	{
		percentage=0;
	}
	void addData(int n, char *filename)
	{
		fstream f1(filename, ios::app);
		for (int i = 0; i < n; ++i)
		{
			cout<<"\nEnter the name of the student : ";
			cin>>name;
			cout<<"\nEnter the mobile number of the student : ";
			cin>>mob;
			cout<<"\nEnter the percentage of the student : ";
			cin>>percentage;
			f1.write((char*)this,sizeof(Student));
		}
		f1.close();
	}
	int searchRec(char *filename,char *name)
	{
		fstream f1(filename, ios::in);
		f1.read((char*)this,sizeof(Student));
		for (int i = 0; f1 ; ++i)
		{
			if(!strcmp(this->name,name))
			{
				f1.close();
				return i;
			}
			f1.read((char*)this,sizeof(Student));
		}
		f1.close();
		return -1;
	}
	int deleteRec(char *filename,char *name)
	{
		int flag=0,i;
		fstream f1(filename, ios::in);
		fstream f2("temp.txt", ios::out);
		f1.read((char*)this,sizeof(Student));
		for ( i = 0; f1 ; ++i)
		{
			if(strcmp(this->name,name))
			{
				f2.write((char*)this,sizeof(Student));
				flag++;
			}
			f1.read((char*)this,sizeof(Student));
		}
		f1.close();
		f2.close();
		remove(filename);
		rename("temp.txt",filename);
		if(flag==i)
			return -1;
		else
			return 0;
	}
	int modifyRec(char *filename,char *name)
	{
		int flag=0,option,i;
		fstream f1(filename, ios::in);
		fstream f2("temp.txt", ios::out);
		f1.read((char*)this,sizeof(Student));
		for ( i = 0; f1 ; ++i)
		{
			if(!strcmp(this->name,name))
			{
				flag--;
				cout<<"\nDo you wish to modify\n1.Name\t2.Mobile Number\t3.Percentage\n";
				cin>>option;
				switch(option)
				{
				case 1:
					cout<<"\nEnter the new name : ";
					cin>>name;
					break;
				case 2:
					cout<<"\nEnter the new mobile number : ";
					cin>>mob;
					break;
				case 3:
					cout<<"\nEnter the new percentage : ";
					cin>>percentage;
					break;
				}
			}
			f2.write((char*)this,sizeof(Student));
			flag++;
			f1.read((char*)this,sizeof(Student));
		}
		f1.close();
		f2.close();
		remove(filename);
		rename("temp.txt",filename);
		if(flag==i)
			return -1;
		else
			return 0;
	}
	void displayData(char *filename)
	{
		fstream f1(filename, ios::in);
		cout<<"-------------------------------------------\n";
		cout<<"| "<<left<<setw(15)<<"Name "<<left<<setw(12)<<"| Mobile  "<<left<<setw(10)<<"| Percentage |\n";
		cout<<"-------------------------------------------\n";
		f1.read((char*)this,sizeof(Student));
		for (int i = 0; f1 ; ++i)
		{
			cout<<"| "<<left<<setw(15)<<name<<"| "<<left<<setw(10)<<mob<<"| "<<left<<setw(11)<<percentage<<"|\n";
			f1.read((char*)this,sizeof(Student));
		}
		cout<<"-------------------------------------------\n";
		f1.close();
	}
};
int main(int argc, char const *argv[])
{
	Student s1;
	int option,n,index;
	char filename[10], name[20];
	if(argc==1)
		strcpy(filename,"data.txt");
	else
		strcpy(filename,argv[1]);
	cout<<"\nEnter the number of Records : ";
	cin>>n;
	remove(filename);//Removes the previously made file as addRec opens in only append mode
	s1.addData(n,filename);
	do
	{
		cout<<"\nEnter your choice :\n1.Add Record\t2.Search Record\n3.Delete Record\t4.Modify Record\n5.Display Record\t0.Exit\n";
		cin>>option;
		switch(option)
		{
		case 1:
			s1.addData(1,filename);
			break;
		case 2://Case to Add a record
			cout<<"\nEnter Name of student to search : ";
			cin>>name;
			index=s1.searchRec(filename,name);
			if(index==-1)
				cout<<"\nRecord not found.\n";
			else
				cout<<"\nRecord found at "<<index+1<<" location.\n";
			break;
		case 3://Case to delete a record
			cout<<"\nEnter Name of student to delete : ";
			cin>>name;
			index=s1.deleteRec(filename,name);
			if(index==0)
				cout<<"\nRecord deleted successfully.\n";
			else
				cout<<"\nRecord not found.\n";
			break;
		case 4://Case to modify a record
			cout<<"\nEnter Name of student to modify : ";
			cin>>name;
			index=s1.modifyRec(filename,name);
			if(index==0)
				cout<<"\nRecord modified  successfully.\n";
			else
				cout<<"\nRecord not found.\n";
			break;
		case 5://Case to display data
			s1.displayData(filename);
			break;
		case 0:
		default:
			break;
		}

	}while(option);
	return 0;
}

