//William Benton Parrish
//CECS 302
//September 1, 2015
//Assignment 1, Question 2

/*Design a class template, OrderedCollection , that stores a collection of Comparable s
(in an array), along with the current size of the collection. Provide public functions
isEmpty , makeEmpty , insert , remove , findMin , and findMax . findMin and findMax return
references to the smallest and largest, respectively, Comparable in the collection.
Explain what can be done if these operations are performed on an empty collection.*/

#include<iostream>
#include<stdlib.h>

/*//Testing Purposes
class ComparableClass{
	private:
		int size;
	public:
		ComparableClass():size(0){}
		int getSize()
		{
			return size;
		}
		void setSize(int entry)
		{
			size=entry;
		}
};
*/
template<typename Comparable>
class OrderedCollection
{
	private:
		int size;
		Comparable* collection;
	public:
		OrderedCollection() : size(0), collection(0)
		{
			collection=(Comparable*)malloc(sizeof(Comparable));
			if(collection==NULL)
			{
				std::cout<<"Memory Allocation Failed!\nDestroying Collection";
				OrderedCollection::~OrderedCollection();
			}
			
		}//Constructor
		~OrderedCollection(){ free(collection);	}//Destructor
		bool isEmpty()
		{
			if(size==0)
				return 1;
			else
				return 0;
		}
		void makeEmpty()
		{
			collection=(Comparable*)realloc(collection, sizeof(Comparable));
			if(collection!=NULL)
				size=0;
			else	
				std::cout<<"Memory Realloc failed!";
			
			
		}
		void insert(Comparable entry)
		{
			collection = (Comparable*)realloc(collection, (sizeof(Comparable)*(size+1))); //Reallocates memory
			if(collection!=NULL)
			{
				collection[size]=entry;
				size++;
			}
			else
				std::cout<<"Memory Realloc failed!";
			
		}
		void remove()
		{
			collection = (Comparable*)realloc(collection, (sizeof(Comparable)*(size-1)));
			if(collection!=NULL)
				size--;
			else
				std::cout<<"Memory Realloc failed!";
			
		}
		Comparable getComparable(int i=0) const
		{
			return collection[i];
		}
		Comparable findMin() const
		{
			int i;
			Comparable tempComp,min;
			for(i=0;i<size;i++)
			{
				tempComp=collection[i];
				if (tempComp.getSize()<min.getSize())
					min=tempComp;
			}
			return min;
		}
		Comparable findMax() const
		{
			int i;
			Comparable tempComp,max;
			for(i=0;i<size;i++)
			{
				tempComp=collection[i];
				if (tempComp.getSize()>max.getSize())
					max=tempComp;
			}
			return max;
		}	
};
/*//Testing Purposes
int main()
{
	OrderedCollection<ComparableClass> oc1;
	return 0;
}
*/
