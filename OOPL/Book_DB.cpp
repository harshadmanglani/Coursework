/* 
Create a CPP program with database functionality for storing book records for a libary
*/


#include <iostream>
#include <string>
using namespace std;

static int transactions=0;

class book{					//book class definition
	int* stock;
	int* ISBN;
	float* price;
	char* name;
	char* author;
	char* publisher;
	static int succ_trans, unsucc_trans;
	static float bill;
	int retstock(){return *stock; }
	int retisb(){return *ISBN; }
	int retprice(){return *price;}
	
public:
	book();
	void add(char nm[50], char au[50], char pub[50], int *st, float *pr, int *ISN);
	float purchase(int ISB, int qty, book arr[100], int size);
	int search(book arr[100], int s, int c, int ISB);
	int update(book arr[100], int size, int ISB, int qty);
	~book();

};
int book::succ_trans;
int book::unsucc_trans;
float book::bill;

book::book(){
	ISBN=new int;
	stock=new int;
	price=new float;
	name=new char[50];
	author=new char[50];
	publisher=new char[50];
}

book::~book(){
	delete ISBN;
	delete stock;
	delete price;
	delete[] name;
	delete[] author;
	delete[] publisher;
}
	
void book::add(char nm[50], char au[50], char pub[50], int *st, float *pr, int *ISN){
	name=nm;
	author=au;
	publisher=pub;
	stock=st;
	price=pr;
	ISBN=ISN;
}

int book::search(book arr[100], int s, int c=3, int ISB=0){
if(c!=3)
{
	cout<<"Enter your choice:\n1. Search by title\n2. Search by author\n3. Search by ISBN\n";	
	cin>>c;
}
int index;
switch(c){
	case 1:
		index=-1;
		char nm[50];
		cout<<"Enter the tile of the book"<<endl;
		cin>>nm;
		for(int i=0;i<s;i++)
		if(nm==arr[i].name)
		{
			index=i;
			break;
		}
		if(index!=-1)
		{
			cout<<"Book successfully found"<<endl;
			return index;
		}
		cout<<"Book not found"<<endl;
		return index;
		break;

	case 2:	
		index=-1;
		cout<<"Enter the name of the author"<<endl;
		cin>>nm;
		for(int i=0;i<s;i++)
		if(nm==arr[i].author)
		{
			index=i;
			break;
		}
		if(index!=-1)
		{
			cout<<"Book successfully found"<<endl;
			return index;
		}
		cout<<"Book not found"<<endl;
		return index;
		break;	

	case 3:
		
		index=-1;
		if(ISB==0)
		{
			cout<<"Enter the ISBN"<<endl;			
			cin>>ISB;
		}
		for(int i=0;i<s;i++)
		if(ISB==arr[i].retisb())
		{
			index=i; 
			break;
		}
		if(index!=-1)
		{
			cout<<"Book successfully found"<<endl;
			return index;
		}
		cout<<"Book not found"<<endl;
		return index;
		break;
	
	default: cout<<"Invalid choice for book search."<<endl;
		break;

	}
}

int book::update(book arr[100], int size, int ISB, int qty=0)
{	
	int temp;
	int index=arr[0].search(arr, size, 3, ISB);
	if(index==-1)
	{
		return index;
	}
	else
	{	
		if(qty==0){
			cout<<"Enter the new stock of the book"<<endl;
			cin>>temp;			
			*(arr[index].stock)=temp;
		}	
		else{
			if(arr[index].retstock()>=qty)
			arr[index].stock=arr[index].stock-qty;
			else 
			return -1;
		}
		cout<<"Stock successfully updated"<<endl;	
	}
return index;
}

float book::purchase(int ISB, int qty, book arr[100], int size){

	int index=arr[0].update(arr, size, ISB, qty);
	if(index!=-1){
		cout<<"Transaction successful"<<endl;
		bill+=qty*arr[index].retprice();
		succ_trans++;
	}
	else
	{
		cout<<"Transaction unsuccessful"<<endl;
		unsucc_trans++;
	}
return bill;
}

void print(){
;
}

int main() {
	
	string n1, n2, n3; int stock, isbn; float price;
	book arr[100];
	int c=0, i=0, qty=0;

while(c!=5){
	print();
	cin>>c;
	switch(c){
		case 1:{
			cout<<"Enter the details of the book you want to enter: \n";
			cout<<"Enter the title: "; cin>>n1;
			cout<<"Enter the author: "; cin>>n2;
			cout<<"Enter the publisher: "; cin>>n3;
			cout<<"Enter the ISBN: "; cin>>isbn;
			cout<<"Enter the stock: "; cin>>stock;
			cout<<"Enter the price: "; cin>>price;
			arr[i].add(n1, n2, n3, stock, price, isbn);
			i++;
			break; 
			}
		
		case 2:{
		arr[i].search(arr, i);
		break;
		}
		
		case 3:{
			cout<<"Enter the information to be updated: \n";
			cout<<"Enter the ISBN: "; int isbn; cin>>isbn;
			arr[i].update(arr, i);
			break;
			}
		
		case 4:{
			cout<<"Enter the ISBN of the book you want to buy: ";int isbn; cin>>isbn;
			cout<<"Enter the quantity of the book: "; cin>>qty;
			arr[i].purchase(isbn, qty, arr, i);
			break;
			}
		
		case 5: break;
		
		default: cout<<"Invalid choice.\n";
		
	}
}
			
return 0;

}
