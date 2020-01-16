/*
Complex numbers - arithmetic
*/

#include <iostream>
#include <algorithm>

using namespace std;

class complex{
	float real;
	float imaginary;
	
	public:
	complex(){real = 0.0; imaginary = 0.0;}
	complex(float a, float b){this->real = a; this->imaginary = b;}
	
	complex operator+(complex A)
	{complex C; C.real = real + A.real; C.imaginary = imaginary + A.imaginary; return C; }
	
	friend complex add(complex A, complex B);
    friend complex sub(complex A, complex B);

	complex multiply(complex B);
    complex divide(complex B);
    
    friend ostream &operator<<(ostream &output, complex A)
	{
	output<<A.real<<" + i( " <<A.imaginary<<" )"<<endl;
	return output;
	}
    
   };

   
   complex add(complex A, complex B)
   {
   complex C;
   C.real = B.real + A.real;
   C.imaginary = B.imaginary + A.imaginary;
   return C;
   }
   
   complex sub(complex A, complex B)
   {
   complex C;
   C.real = B.real - A.real;
   C.imaginary = B.imaginary - A.imaginary;
   return C;
    }
   
   complex complex::multiply(complex B)
   {
          complex C;
          C.real = real*B.real - imaginary*B.imaginary;
          C.imaginary = imaginary*B.real + B.imaginary*real;
          return C;
   }
   
   complex complex::divide(complex B)
   {
       complex B1;
       B1.real = B.real;
       B1.imaginary = (-1)*B.imaginary;
       complex C;
       C = this->multiply(B1);
	   return C;
   }
   
int main()
{
    complex A(12, -13);    //paramterized constructor
    complex B(13, 14);	//paramterized constructor
    cout<<A;			//overloaded << operator
    cout<<A+B;			//overloaded + operator
    cout<<add(A, B);		//friend function
    cout<<sub(A, B);		//friend function
    cout<<A.multiply(B);	//member function
    cout<<A.divide(B);	//member function
}

   
   
   
   
   
   
   
   
   
   
