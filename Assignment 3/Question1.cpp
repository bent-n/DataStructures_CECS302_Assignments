//William Benton Parrish
//10-11-15
//Assignment 3
//Question 1

//Swap two adjacent elements by adjusting only the links (and not the data) using
//a) Singly linked lists
//b) Doubly linked lists


//a) SLL

template <typename Object>
void SLLswap(Object* nodeAprev)//NodeA immediately followed by NodeB
{
	Object* nodeB=nodeAprev->next->next;	//nodeAprev(next=nodeA)-->nodeA(next=nodeB)-->nodeB(next=NULL)
	Object* nodeA=nodeAprev->next;
	nodeAprev->next=nodeB;					//nodeAprev(next=nodeB)-->nodeA(next=nodeB)-->nodeB(next=NULL)
	nodeA->next=nodeB->next;				//nodeAprev(next=nodeB)-->nodeA(next=NULL)-->nodeB(next=NULL)
	nodeB->next=nodeA;						//nodeAprev(next=nodeB)-->nodeB(next=NodeA)-->nodeB(next=NULL)
	
}

//b) DLL

template<typename Object>
void DLLswap(Object* nodeA) //NodeA immediately followed by NodeB
{
	Object* nodeB=nodeA->next;
	nodeB->prev=nodeA->prev;
	nodeA->next=nodeB->next;
	nodeB->prev->next=nodeB;
	nodeA->next->prev=nodeA;
	nodeB->next=nodeA;
	nodeA->prev=nodeB;
}

