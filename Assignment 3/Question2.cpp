//William Benton Parrish
//10-11-15
//Assignment 3
//Question 2

//Write a program to solve the Joesephus problem for general values of M and N. Try to make it as efficient as possible

#include <iostream>
#include<ctime>
using namespace std;

class Node{
	
	friend class DLCList;
	public:
		int getVal()
		{
			return val;
		}
	private:
		Node(int v=0,Node* prev=0,Node* next=0)
		{
			val=v;
			this->prev=prev;
			this->next=next;
		}
		Node* prev;
		Node* next;
		int val;
	
};

class DLCList//Double linked circular list
	
	{
		public:
		
		class Iterator{
			public:
				
				friend class DLCList;
				Iterator()
				{
					current=0;
				}
				Iterator(Node* begin)
				{
					current=begin;
				}
				Iterator* operator=(Node* begin)
				{
					current=begin;
					return this;
				}
				Iterator* operator+(int c)
				{
					for(int i=0;i<c;i++)
					{
						current=current->next;
					}
					return this;
				}
				
				Iterator* getIterator()
				{
					return itr;
				}
				Node* getCurrent()
				{
					return current;
				}
			private:
				Node* current;
				Iterator* itr;
		};
		DLCList()
		{
			head=0;
			tail=0;
		}
		~DLCList()
		{
			remove();
		}
		
		void append(int v)
		{
			Node* newNode= new Node(v,tail,head);
			
			
			
			
			if(head==0)
			{
				head=newNode;
				head->next=newNode;
				head->prev=newNode;
				tail=head;
			}
			else
			{
			
			head->prev=newNode;
		
			
			
			tail->next=newNode;
		
			tail=newNode;	
		
			}
		}
		void remove(int v)
		{
			Node* nodeCheck=head;
		//	cout<<endl<<"test1";
			while(nodeCheck->val!=v)
			{
				nodeCheck=nodeCheck->next;
			}
		//	cout<<endl<<"test2";
			nodeCheck->prev->next=nodeCheck->next;
			nodeCheck->next->prev=nodeCheck->prev;
			if(nodeCheck==head)
			{
				head=nodeCheck->next;
			}
			if(nodeCheck==tail)
			{
				tail=nodeCheck->prev;
			}
			delete nodeCheck;
		}
		void remove(Node* v)
		{
			Node* nodeCheck=head;
		//	cout<<endl<<"test1";
			while(nodeCheck!=v)
			{
				nodeCheck=nodeCheck->next;
			}
		//	cout<<endl<<"test2";
			nodeCheck->prev->next=nodeCheck->next;
			nodeCheck->next->prev=nodeCheck->prev;
			if(nodeCheck==head)
			{
				head=nodeCheck->next;
			}
			if(nodeCheck==tail)
			{
				tail=nodeCheck->prev;
			}
			delete nodeCheck;
		}
		void display()
		{
			Node* nodeRead=head->next;
			int i=1;
			cout<<endl<<"Head: "<<head->val;
			while(nodeRead!=head && nodeRead!=tail)
			{
				cout<<endl<<"   "<<i<<": "<<nodeRead->val;
				nodeRead=nodeRead->next;
				i++;
			}
			cout<<endl<<"Tail: "<<tail->val;
		}
		bool justOne()
		{
			if(head==tail)
				return 1;
			return 0;
		}
		void remove()
		{
			Node* nodeRemove = head;
			while (nodeRemove)
			{
				Node* temp = nodeRemove;
				nodeRemove = nodeRemove->next;
				delete temp;
			} // end while
			head = tail = 0;
		}
		Node* getHead()
		{
			return head;
		}
		private:
			Node* head;
			Node* tail;
	};
	
	


int main()
{
	
	clock_t init, final;

	init = clock();
	int numPeople=20;//N
	int numPass=15;//M
	DLCList jList;
	
	
	for(int i=0; i<numPeople; i++)//Populate list
	{
		jList.append(i);	
	}
	//jList.display();
	DLCList::Iterator jItr(jList.getHead());


	while(!jList.justOne()) //Removal
	{
		jItr+numPass;
		jList.remove(jItr.getCurrent());
		
		cout<<endl;
		jList.display();
		
	}
	cout<<endl<<"Player: "<<jList.getHead()->getVal()+1<< " WINS!";
	
	
	
	
	

	
	final = clock() - init;
	cout << endl<<endl<<"Time: "<<(double) final << endl;
	
	
}
