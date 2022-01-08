#include<iostream>
using namespace std;

// NODE For Single Link List ,Stack ,Queue
template<typename T>
struct snode
{
    T data;
    struct snode *next;
};

// NODE For Double Link List
template<typename T>
struct dnode
{
	T data;
	struct dnode *next;
	struct dnode *prev;
};


// CLASS DECLARATION

template<class T>
class SinglyLL
{
private:
    snode<T> *first;
    int size;
    
public:
    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();	
    
};


template<class T>
class SinglyCL
{
	private:
	   snode<T>* first;
	   snode<T>* last;
	   int size;
	   
    public:
	   SinglyCL();
	   void InsertFirst(T);
	   void InsertLast(T);
	   void InsertAtPos(T,int);
	   void DeleteFirst();
	   void DeleteLast();
	   void DeleteAtPos(int);
	   void Display();
	   int Count();
};

template<typename T>
class DoublyLL
{
	private:
	dnode<T> *first;
	int size;
	
	public:
	DoublyLL();
	void InsertFirst(T);
	void InsertLast(T);
    void InsertAtPos(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
	
};

template<class T>
class DoublelyCL
{
  private:
    dnode<T>* first;
	dnode<T>* last;
	int size;
	
  public:
     DoublelyCL();
	 void Display();
	 int Count();
	 void InsertFirst(T);
	 void InsertLast(T);
	 void InsertAtPos(T,int ipos);
	 void DeleteFirst();
	 void DeleteLast();
	 void DeleteAtPos(int ipos);
	
};


template<class T>
class Stack
{
	private:
		snode<T>* first;
		int size;
		
	public:
		Stack();	
		void push(T no);
		int pop();
	    void Display();
		int Count ();
	
	
};

template<class T>
class Queue
{
	private:
		snode<T>* first;
		int size;
		
	public:
		Queue();
		void enqueue(T no);
		int dequeue();
	    void Display();
		int Count ();
	
	
};

// Function Of Single Linear Link List

template<class T>
 SinglyLL<T>:: SinglyLL()
    {
        first = NULL;
        size = 0;
    }
	
    template<class T>
    void SinglyLL<T>:: InsertFirst(T no)
    {
         snode<T>* newn = new  snode<T>;  // newn = (Psnode)malloc(sizeof(snode))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn->next = first;
            first = newn;
        }
        size++;
    }
	
    template<class T>
    void SinglyLL<T>::InsertLast(T no)
    {
         snode<T>* newn = new snode<T>;  // newn = (Psnode)malloc(sizeof(snode))
    
         newn->data = no;
         newn->next = NULL;
        
        if(first == NULL)
        {
            first = newn;
        }
        else
        {
             snode<T>* temp = first;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        size++;
    }
	
    template<class T>
    void SinglyLL<T>::InsertAtPos(T no, int ipos)
    {
		 if(ipos<1 && ipos>(size+1))
		   {
			   return ;
		   }
		   if(ipos==1)
		   {
			   InsertFirst(no);
		   }
		   else if(ipos==size+1)
		   {
			   InsertLast(no);
		   }
		   else
		   {
			   snode<T>* newn=new snode<T>;
			   int i=0;
			   snode<T>* temp=first;
			   newn->data=no;
			   newn->next=NULL;
			   
			   for(i=1;i<ipos-1;i++)
			   {
				   temp=temp->next;
			   }
			   
			   newn->next=temp->next;
			   temp->next=newn;
			   
			   size++;
		   }
		
		
		
		
		
	}
    template<class T>
    void SinglyLL<T>::DeleteFirst()
    {
         snode <T>* temp = first;
        
        if(first != NULL)
        {
            first = first->next;
            delete temp;
            
            size--;
        }
    }
	
    template<class T>
    void SinglyLL<T>::DeleteLast()
    {
         snode <T>* temp = first;
        
        if(first == NULL)
        {
            return;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }
	
	template<class T>
    void SinglyLL<T>::DeleteAtPos(int ipos)
    {
		 if(ipos<1 && ipos>(size))
		   {
			   return ;
		   }
		   if(ipos==1)
		   {
			   DeleteFirst();
		   }
		   else if(ipos==size)
		   {
			   DeleteLast();
		   }
		   else
		   {
			   
			   int i=0;
			   snode<T>* targeted=NULL;
			   snode<T>* temp=first;
			  
			   
			   for(i=1;i<ipos-1;i++)
			   {
				   temp=temp->next;
			   }
			   targeted=temp->next;
			   temp->next=targeted->next;
			   delete targeted;
			   
			   
			   size--;
		   }
		
		
		
	}
    
	template<class T>
    void SinglyLL<T>::Display()
    {
         snode<T> * temp = first;
        
        while(temp!= NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }
	
    template<class T>
    int SinglyLL<T>::Count()
    {
        return size;
    }
  
  
  
  
 // Function Of Single Circular Link List
 
 template<class T>
SinglyCL<T>::SinglyCL()
	   {
		   first=NULL;
		   last=NULL;
		   size=0;
	   }
	   
template<class T>
	void SinglyCL<T> :: Display()
	   {
		   snode<T>* temp=first;
		   if(first==NULL && last==NULL)
		   {
			   return;
		   }
		   do
		   {
			   cout<<temp->data<<" ";
			   temp=temp->next;
		   }while(temp != last->next);
			   cout<<endl;
	   }
	 
template<class T>
	   int SinglyCL<T> ::Count()
	   {
		  return size; 
	   }
	   
template<class T>
	   void SinglyCL<T> ::InsertFirst(T no)
	   {
		   snode<T>* newn=new snode<T>;
		   
		   newn->data=no;
		   newn->next=NULL;
		   if(first==NULL && last==NULL)
		   {
			   first=newn;
			   last=newn;
		   }
		   else
		   {
			   newn->next=first;
			   first=newn;
		   }
		   last->next=first;
		   size++;
	   }
	      
template<class T>
	   void SinglyCL<T> ::InsertLast(T no)
	   {
		    snode<T>* newn=new snode<T>;
		   
		   newn->data=no;
		   newn->next=NULL;
		   if((first==NULL)&& (last==NULL))
		   {
			   first=newn;
			   last=newn;
		   }
		   else
		   {
			   last->next=newn;
			   last=newn;
		   }
		   last->next=first;
		   size++;
	   }
	   
template<class T>
	    void SinglyCL <T>:: DeleteFirst()
	   {
		   if(first==NULL && last==NULL)
		   {
			   return;
		   }
		   else if(first==last)
		   {
			   delete first;
			   first=NULL;
			   last=NULL;
		   }
		   else
		   {
			   first=first->next;
			   delete last->next;
			   last->next=first;
		   }
		   size--;
	   }
	   
template<class T>
	    void SinglyCL<T> ::DeleteLast()
	   {   
	       snode<T>* temp=first;
		   if(first==NULL && last==NULL)
		   {
			   return;
		   }
		   else if(first==last)
		   {
			   delete first;
			   first=NULL;
			   last=NULL;
		   }
		   else
		   {
			   while(temp->next != last)
			   {
				   temp=temp->next;
			   }
			   delete last;
			   last=temp;
			   last->next=first;
		   }
		   size--;
	   }
	   
template<class T>
	    void SinglyCL <T>::InsertAtPos(T no,int ipos)
	   {
		   if(ipos<1 && ipos>(size+1))
		   {
			   return ;
		   }
		   if(ipos==1)
		   {
			   InsertFirst(no);
		   }
		   else if(ipos==size+1)
		   {
			   InsertLast(no);
		   }
		   else
		   {
			   snode<T>* newn=new snode<T>;
			   int i=0;
			   snode<T>* temp=first;
			   newn->data=no;
			   newn->next=NULL;
			   
			   for(i=1;i<ipos-1;i++)
			   {
				   temp=temp->next;
			   }
			   
			   newn->next=temp->next;
			   temp->next=newn;
			   
			   size++;
		   }
	   }
	   
template<class T>
	    void SinglyCL<T> ::DeleteAtPos(int ipos)
	   {
		    if(ipos<1 && ipos>(size))
		   {
			   return ;
		   }
		   if(ipos==1)
		   {
			   DeleteFirst();
		   }
		   else if(ipos==size)
		   {
			   DeleteLast();
		   }
		   else
		   {
			   
			   int i=0;
			   snode<T>* targeted=NULL;
			   snode<T>* temp=first;
			  
			   
			   for(i=1;i<ipos-1;i++)
			   {
				   temp=temp->next;
			   }
			   targeted=temp->next;
			   temp->next=targeted->next;
			   delete targeted;
			   
			   
			   size--;
		   }
	   }


//Function of Double Linear Link  List


template<class T>
DoublyLL <T>::DoublyLL()
	{
	 first=NULL;
	 size=0;
	}
	
template<class T>
void DoublyLL <T>::InsertFirst(T ino)
{
	
	dnode<T>* newn=new dnode<T>;
	
	newn->data=ino;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(first==NULL)
	{
		first=newn;
	}
	else
	{
		newn->next=first;
		first->prev=newn;
		first=newn;
	}
	size++;
}

template<class T>
void DoublyLL <T>::InsertLast(T ino)
{

	dnode<T>* newn=new dnode<T>;
	dnode<T>* temp=first;
	newn->data=ino;
	newn->next=NULL;
	newn->prev=NULL;
	
	if((first==NULL))
	{
		first=newn;
	}
	else
	{
		while(temp->next !=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		newn->prev=temp;
	}
	size++;
}

template<class T>
void DoublyLL <T>::DeleteFirst()
{   
    dnode<T>* temp=first;
	if(first != NULL)
	{
		first=first->next;
		delete(temp);
		if(first !=NULL)
		{
		 first->prev=NULL;
		}
	}
	size--;
}

template<class T>
void DoublyLL <T>::DeleteLast()
{
	dnode<T>* temp=first;
	if(first==NULL)
	{
		return;
	}
	else if(first->next==NULL)
	{ 
		delete(first->next);
		first=NULL;
	}
	else
	{
	while(temp->next->next != NULL)
	{
		temp=temp->next;
	}
	delete(temp->next);
	temp->next=NULL;
	
	}
	size--;
}

template<class T>
void DoublyLL <T>::InsertAtPos(T ino,int ipos)
{

	dnode<T>* newn=NULL;
	dnode<T>* temp=first;
	
	int i=0;
	if((ipos<1) ||(ipos>size+1))
	{
		return;
	}
	
	if(ipos==1)
	{
		InsertFirst(ino);
	}
	else if(ipos==size+1)
	{
		InsertLast(ino);
	}
	else
	{
		dnode<T>* newn=new dnode<T>;
		
		newn->data=ino;
		newn->next=NULL;
		
		for(i=1;i<ipos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn->next;
		temp->next=newn;
		newn->prev=temp;
		size++;
	}
}

template<class T>
void DoublyLL <T>::DeleteAtPos(int ipos)
{

	dnode<T>* temp=first;
	dnode<T>* targeted;
	int i=0;
	if((ipos<1) ||(ipos>size))
	{
		return;
	}
	
	if(ipos==1)
	{
		DeleteFirst();
	}
	else if(ipos==size)
	{
		DeleteLast();
	}
	else
	{
		
		
		for(i=1;i<ipos-1;i++)
		{
			temp=temp->next;
		}
		targeted=temp->next;
		temp->next=targeted->next;
		targeted->next->prev=temp;
		delete targeted;
		size--;
	}
}
	
template<class T>
 void DoublyLL <T>:: Display()
{
	dnode<T>* temp=first;
	while(temp!=NULL)
	{    
        
		cout<<"|"<<temp->data<<"|->";
		temp=temp->next;
	}
}

template<class T>
 int DoublyLL <T>:: Count()
{   
   
	return size;
}


// Function Of Double Circular Link List

template<class T>
DoublelyCL<T>::DoublelyCL()
	 {
		 first=NULL;
		 last=NULL;
		 size=0;
	 }

template<class T>
void DoublelyCL<T>::InsertFirst(T no)
{
	dnode<T>* newn=new dnode<T>;
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(first==NULL && last==NULL)
	{
		first=newn;
		last=newn;
	}
	else
	{
		newn->next=first;
		first->prev=newn;
		first=newn;
	}
	last->next=first;
	first->prev=last;
	size++;
}

template<class T>
void DoublelyCL<T>::InsertLast(T no)
{
	dnode<T>* newn=new dnode<T>;
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(first==NULL && last==NULL)
	{
		first=newn;
		last=newn;
	}
	else
	{
	    last->next=newn;
		newn->prev=last;
		last=newn;
	}
	last->next=first;
	first->prev=last;
	size++;
}

template<class T>
void DoublelyCL<T>::Display()
{
	dnode<T>* temp=first;
	
	for(int i=1;i<=size;i++)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"\n";
}

template<class T>
int  DoublelyCL<T>::Count()
{
	dnode<T>* temp=first;
	int icnt=0;
	for(int i=1;i<=size;i++)
	{
		icnt++;
		temp=temp->next;
	}
	return icnt;
	cout<<"\n";
}

template<class T>
void DoublelyCL<T>::DeleteFirst()
{
	if(first==NULL && last==NULL)
	{
		return;
	}
	else if(first==last)
	{
		delete first;
		first=NULL;
		last=NULL;
	}
	else
	{   
         
		first=first->next;
		delete last->next;
        last->next=first;
	    first->prev=last;
	}
    size--;	
}

template<class T>
void DoublelyCL<T>::DeleteLast()
{
	if(first==NULL && last==NULL)
	{
		return;
	}
	else if(first==last)
	{
		delete first;
		first=NULL;
		last=NULL;
	}
	else
	{   
         last=last->prev;
		 delete last->next;
		 last->next=first;
	     first->prev=last;
     }
	 size--;
	
}

template<class T>
void DoublelyCL<T>::InsertAtPos(T no,int ipos)
{
	dnode<T>* temp=first;
	int i=0;
	if(ipos<1 && ipos>size+1)
	{
	    return;
	}
	
	if(ipos==1)
	{
		InsertFirst(no);
	}
	else if (ipos==size+1)
	{
		InsertLast(no);
	}
	else
	{   
         dnode<T>* newn=new dnode<T>;
		 newn->data=no;
	     newn->next=NULL;
	     newn->prev=NULL;
		for(i=1;i<ipos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
		size++;
	}
	

	
}

template<class T>
void DoublelyCL<T>::DeleteAtPos(int ipos)
{
	dnode<T>* temp=first;
	dnode<T>* targeted=NULL;
	int i=0;
	if(ipos<1 && ipos>size)
	{
	    return;
	}
	
	if(ipos==1)
	{
		DeleteFirst();
	}
	else if (ipos==size)
	{
		DeleteLast();
	}
	else
	{   
        
		for(i=1;i<ipos-1;i++)
		{
			temp=temp->next;
		}
		targeted=temp->next;
		temp->next=targeted->next;
		targeted->next->prev=temp;
		delete targeted;
		size--;
	}
	

	
}

//Function of Stack
template<class T>
Stack <T>::Stack()
{
	first=NULL;
	size=0;	
}
		
template<class T>		
void Stack<T>::push(T no)
{
	snode<T>* newn=new snode<T>;
	
	newn->data=no;
	newn->next=NULL;
	
	if(first==NULL)
	{
		first=newn;
	}
	else
	{
		newn->next=first;
		first=newn;
	}
	size++;
}

template<class T>
int Stack<T>::pop()
{
	snode<T>* temp=first;
	int ino=temp->data;
	if(first !=NULL)
	{
		first=first->next;
		delete temp;
	}
	
	size--;
	return ino;
}

template<class T>
void Stack<T>::Display()
{
	snode<T>* temp=first;
	
	while(temp !=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	
}

template<class T>
int  Stack<T>::Count()
{
	snode<T>* temp=first;
	int icnt=0;
	while(temp !=NULL)
	{
		icnt++;
		temp=temp->next;
	}
	return icnt;
}

//Function of Queue
template<class T>
Queue<T>::Queue()
{
	first=NULL;
	size=0;
}
		
template<class T>
void Queue<T>::enqueue(T no)
{
	snode<T>* newn=new snode<T>;
	snode<T>* temp=first;
	newn->data=no;
	newn->next=NULL;
	
	if(first==NULL)
	{
		first=newn;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
	size++;
}

template<class T>
int Queue<T>::dequeue()
{
	snode<T>* temp=first;
	int ino=temp->data;
	if(first !=NULL)
	{
		first=first->next;
		delete temp;
	}
	
	size--;
	return ino;
}

template<class T>
void Queue<T>::Display()
{
	snode<T>* temp=first;
	
	while(temp !=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	
}

template<class T>
int  Queue<T>::Count()
{
	snode<T>* temp=first;
	int icnt=0;
	while(temp !=NULL)
	{
		icnt++;
		temp=temp->next;
	}
	return icnt;
}

int main()
{
	
	return 0;
}