//William Benton Parrish
//CECS 302
//September 1, 2015
//Assignment 1, Question 3

/*Define a Rectangle class that provides getLength and getWidth . Using the findMax
routines in Figure 1.25, write a main that creates an array of Rectangle and finds the
largest Rectangle first on the basis of area and then on the basis of perimeter.*/
#include<iostream>
using namespace std;

class Rectangle
{
	private:
		int length;
		int width;
	public:
		Rectangle():length(0),width(0)
		{}
		Rectangle(int l,int w):length(l),width(w)
		{}
		int getLength()
		{
			return length;
		}
		int getWidth()
		{
			return width;
		}
		void display()
		{
			cout<<"Width: "<<width<<" Length: "<<length;
		}
};

int main()
{
	
	class Rectangle r1(1,2),r2(10,1),r3(5,3),maxA,maxP;
	
	class Rectangle rectangles[3]={r1,r2,r3};
	for(int i=0;i<3;i++)
	{
		if(((rectangles[i].getLength())*(rectangles[i].getWidth()))>((maxA.getLength())*(maxA.getWidth())))
			maxA=rectangles[i];
		
		if(((rectangles[i].getLength())+(rectangles[i].getWidth()))>((maxP.getLength())+(maxP.getWidth())))
			maxP=rectangles[i];
	}
	cout<<"Max Area: ";
	maxA.display();
	
	cout<<endl<<"Max Perimeter: ";
	maxP.display();
	return 0;
}
