

/
*
Inheritance and virtual functions
*/


#include <iostream>

using namespace std;

// Base class
class Shape {
	 protected:
      int width;
      int height;
      
   public:
	  virtual void displayArea()=0;     //pure virtual function
      void setWidth() {
	  cout<<"Enter parameter 2: "; cin>>width; cout<<endl;
      }
      void setHeight() {
	  cout<<"Enter parameter 1: "; cin>>height; cout<<endl;
      }
};

// Derived class
class Rectangle: public Shape
{
   public:
      void displayArea() {
         double area = (width * height);
         cout<< " \n Area of the rectangle is " << area<<endl;
      }
};

class Circle :public Shape
{
public:
    void displayArea()
    {
        double area = 3.14*width*width;
        cout<< " \n Area of the circle is " << area<<endl;
    }
};

class Triangle :public Shape
{
public:
    void displayArea()
    {
        double area = 0.5*height*width;
        cout << " \n Area of the triangle is "<< area<<endl;
    }
};

int main(void) {
	int c = 0;
	Shape* p;
	while(c!=4){
		cout<<"\n\n1. Rectangle\n2. Traingle\n3. Circle\n4. Quit\n";
		cout<<"Enter your choice: ";
		cin>>c;
		cout<<endl;
		switch(c){
			case 1:
				p = new Rectangle();
				p->setHeight();
				p->setWidth();
				p->displayArea();
				delete p;
				break;
				
			case 2:
				p = new Triangle();
				p->setHeight();
				p->setWidth();
				p->displayArea();
				delete p;
				break;
				
			case 3:
				p = new Circle();
				p->setWidth();
				p->displayArea();
				delete p;
				break;
				
			case 4:
				break;
		}
	}
   
   return 0;
}
