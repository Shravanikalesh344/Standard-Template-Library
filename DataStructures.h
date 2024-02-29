#include<iostream>
using namespace std;


template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
    struct node *rchild;
    struct node *lchild;
};

template <class T>
class SinglyLL
{
    private:
        struct node<T> * first;
        int Count;

    public:
        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
        void EvenEle();
        void OddEle();
        void CountEven();
        void CountOdd();
        void MaxEle();
        void MinEle();
        void Perfect();
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside constructor\n";
    first = NULL;
    Count = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = first;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct node<T> * temp = first;

    cout<<"Elements of the SinglyLinear linked list are : \n";
    
    while(temp != NULL) // Type 1
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp ->next;
    }
    cout<<"NULL \n";
}

template <class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T> * temp = first;

        first = first->next;
        delete temp;
    }
    Count--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T> * temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no,int ipos)
{
    if((ipos < 1) || (ipos > Count+1))
    {
        return;
    }
     
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;

        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }
     
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        struct node<T> * targatednode = temp->next;
        temp->next = temp->next->next;
        delete targatednode;

        Count--;
    }
}

template<class T>
void SinglyLL<T> :: EvenEle()
{
    struct node <T> * temp = first;
    cout<<"Even Elements From LinkedList Are :"<<"\n";
    while(temp != NULL)
    {
        if((temp->data %2)==0)
        {
            cout<<"|"<<temp->data<<"|"<<"->";
        }
        temp = temp->next;
    }
    cout<<"NULL\n";
    
}

template<class T>
void SinglyLL<T> :: OddEle()
{
    struct node <T> * temp = first;
    cout<<"Odd Elements From LinkedList Are :"<<"\n";
    while(temp != NULL)
    {
        if((temp->data %2)!=0)
        {
            cout<<"|"<<temp->data<<"|"<<"->";
        }
        temp = temp->next;
    }
    cout<<"NULL\n";
    
}

template<class T>
void SinglyLL<T> :: CountEven()
{
    struct node <T> * temp = first;
    int eCnt = 0;
   
    while(temp != NULL)
    {
        if((temp->data %2)==0)
        {
           eCnt++;
        }
        temp = temp->next;
    }
    cout<<"Number of Even Elements From Singly Linear LinkedList Are :"<<eCnt<<"\n";
    
}

template<class T>
void SinglyLL<T> :: CountOdd()
{
    struct node <T> * temp = first;
    int iCnt = 0;
    while(temp != NULL)
    {
        if((temp->data %2)!=0)
        {
           iCnt++;
        }
        temp = temp->next;
    }
    cout<<"Number of Odd Elements From Singly Linear LinkedList Are :"<<iCnt<<"\n";
    
}

template<class T>
void SinglyLL<T> :: MaxEle()
{
    struct node <T> * temp = first;
    int Max = temp->data;
    while(temp != NULL)
    {
        if(temp->data > Max)
        {
           Max = temp->data;
        }
        temp = temp->next;
    }
    cout<<"Maximum Element From Singly Linear LinkedList is:"<<Max<<"\n";
    
}

template<class T>
void SinglyLL<T> :: MinEle()
{
    struct node <T> * temp = first;
    int Min = temp->data;
    while(temp != NULL)
    {
        if(temp->data < Min)
        {
           Min = temp->data;
        }
        temp = temp->next;
    }
    cout<<"Minimum Element From Singly Linear LinkedList is:"<<Min<<"\n";
    
}

template<class T>
void SinglyLL<T> :: Perfect()
{
    struct node <T> * temp = first;
    cout<<"Perfect Elements From Singly Linear LinkedList Is:"<<"\n";
     int iCnt = 0;
     int iSum = 0;
    while(temp != NULL)
    {
       
       if(temp->data % (temp->data / 2 )== 0)
       {
            cout<<"|"<<temp->data<<"|"<<"\n";
            temp = temp->next;
       }
       else 
       {
        temp = temp->next;
       }
    
    }
   
    cout<<"NULL\n";
}

template <class T>
class SinglyCL
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        int Count;

    public:
        SinglyCL();

        void InsertFirst(T no);
        
        void InsertLast(T no);
        
        void Display();
       
        int CountNode();

        void DeleteFirst();

        void DeleteLast();

        void InsertAtPos(T no ,int iPos);

        void DeleteAtPos(int iPos);
        
};

template<class T>
SinglyCL<T> ::SinglyCL()
{
   
    first = NULL;
    last = NULL;
    
    Count = 0;
}

template<class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;

    if((first == NULL)&&(last == NULL))
    {
        first = newn;
        last = newn;
    }
    else 
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    Count++;
}

template<class T>
void SinglyCL<T> ::InsertLast(T no)
{
    struct node<T> * newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;

    if((first == NULL)&&(last == NULL))
    {
        first = newn;
        last = newn;
    }
    else 
    {
        last->next = newn;
        last = newn;
    }
    last->next = first;
    Count++;

}

template<class T>
void SinglyCL<T> :: Display()
{
    struct node<T> *head = first;
    struct node<T> *tail = last;
    cout<<"Elements in the Singly Circular LinkedList are :";

    if((head != NULL)&&(tail != NULL))
    {
        do 
        {
            cout<<"|"<<head->data<< "| ->";
            head = head->next;
        }while(head != tail->next);

       
    }
}

template<class T>
int SinglyCL<T> :: CountNode()
{ 
    return Count; 

}

template<class T>
void SinglyCL<T> ::DeleteFirst()
{
    if((first == NULL)&&(last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else 
    {
        struct node<T> * head = first;
        first = first->next;
        delete head;
    }
    last->next = first;
    Count--;

}

template<class T>
void SinglyCL<T> :: DeleteLast()
{
     if((first == NULL)&&(last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else 
    {
        struct node<T> * head = first;
        while(head->next != last)
        {
            head = head->next;
        }   
        delete last;
        last = head;
        last->next = first;
        Count--;

    }

}

template<class T>
void SinglyCL<T> :: InsertAtPos(T no , int iPos)
{
    if((iPos < 1)||(iPos > Count+1))
    {
        cout<<"Invalid Position";
    }
    else if(iPos == 1) 
    {
        InsertFirst(no);
    }
    else if(iPos > Count+1)
    {
        InsertLast(no);
    }
    else 
    {
        struct node<T> * newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        struct node<T> * head = first;

        for(int iCnt = 1 ; iCnt < iPos -1; iCnt++)
        {
                head = head->next;
        }
        newn->next = head->next;
        head->next = newn;
        
    }
    Count++;
}

template<class T>
void SinglyCL<T> :: DeleteAtPos(int iPos)
{
    if((iPos < 1)||(iPos > Count))
    {
        cout<<"Invalid Position";
    }
    else if(iPos == 1) 
    {
        DeleteFirst();
    }
    else if(iPos > Count)
    {
        DeleteLast();
    }
    else 
    {
        struct node<T> * head = first;
        for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
        {
            head = head->next;
        }
        struct node<T> * Targetednode = head->next;
        head->next = head->next->next;
        delete Targetednode;

    }   
    Count--;
}       

template <class T>
class DoublyLL
{
    private:
        struct node<T> * first;
        int Count;
    
    public :

        DoublyLL();
       void InsertFirst(T no);
       void InsertLast(T no);
       void Display();
       int CountNode();
       void InsertAtPos(T no , int iPos);
       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPos(int iPos);

};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    first = NULL;
    Count = 0;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else 
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    Count++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct node<T> * newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else 
    {
        struct node<T> * head = first;
        while(head->next != NULL)
        {
            head = head->next;
        }
        head->next = newn;
        newn->prev = head;

    }
    Count++;
}

template <class T>
void DoublyLL<T> :: Display()
{
    struct node<T> * head = first;
    cout<<"Elements in the Doubly Linear LinkedList are :";

    while(head != NULL)
    {
        cout<<"|"<<head->data<<"| ->";
        head = head->next;
    }
    cout<<"NULL";
}

template <class T>
int DoublyLL<T> :: CountNode()
{
    return Count;
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
     if(first == NULL)   // empty LL
    {
        return;
    }
    else if((first -> next == NULL) && (first -> prev == NULL)) // Single node
    {                                                               // #    
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T> * head = first;
        head = head -> next;
        delete head -> prev;
        head -> prev = NULL;
    }
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    if(first == NULL)   // empty LL
    {
        return;
    }
    else if((first -> next == NULL) && (first -> prev == NULL)) // Single node
    {                                                               // #    
        delete first;
        first = NULL;
    }
    else 
    {
        struct node<T> * head = first;
        while(head->next->next !=NULL)
        {
            head = head->next;
        }
        delete head->next;
        head->next = NULL;

    }
    Count--;

}

template <class T>
void DoublyLL<T> :: InsertAtPos(T no,int iPos)
{
    if((iPos < 1)&&(iPos > Count+1))
    {
        cout<<"Invalid Position";
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos >Count+1)
    {
        InsertLast(no);
    }
    else 
    {
        struct node<T> * newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        struct node<T> * head = first;

        for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
        {
            head = head->next;
        }
        newn->next = head->next;
        head->next->prev = newn;
        newn->prev = head;
        head->next = newn;
    }

}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    if((iPos < 1)&&(iPos > Count))
    {
        cout<<"Invalid Position";
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos >Count)
    {
        DeleteLast();
    }
    else 
    {
        struct node<T> * head = first;
        for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
        {
            head = head->next;
        }
        head->next = head->next->next;
        delete head->next->prev;
        head->next->prev = head;

    }
    Count--;
}

template <class T>
class DoublyCL
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        int Count;

    public:
        DoublyCL();

        void InsertFirst(T no);
        
        void InsertLast(T no);
        
        void Display();
       
        int CountNode();

        void DeleteFirst();

        void DeleteLast();

        void InsertAtPos(T no ,int iPos);

        void DeleteAtPos(int iPos);
        
};

template <class T>
DoublyCL<T> :: DoublyCL()
{
    first = NULL;
    last = NULL;
    
    Count = 0;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = NULL;
    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL)&&(last == NULL))
    {
        first = newn;
        last = newn;
    }
    else 
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;
    Count++;

}

template <class T>
void DoublyCL<T> ::InsertLast(T no)
{
   
    struct node<T> * newn = NULL;
    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    struct node<T> * tail = last;
    struct node<T> * head = first;

    if((head == NULL)&&(tail == NULL))
    {
        first = newn;
        last = newn;
    }
    else 
    {
        
        newn->prev = tail;
        tail->next = newn;
        tail = newn;
    }
    tail->next = head;
    head->prev = tail;
    Count++;
    
}

template <class T>
void DoublyCL<T> :: Display()
{
    struct node<T> * head = first;
    struct node<T> * tail = last;
  cout<<"Elements in the Doubly  Circular LinkedList is :"<<"\n";


    if(head != NULL && tail != NULL)
    {
        do
        {
           cout<<"|"<<head->data<<"| <=>";
            head = head->next;
        }while(head != tail->next);
    }
    
}

template <class T>
int DoublyCL<T> :: CountNode()
{ 
    return Count; 
}

template <class T>
void DoublyCL<T> ::DeleteFirst()
{
   if((first == NULL) && (last == NULL))    // LL is empty
    {
        return;
    }
    else if(first == last)   // LL contains single node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than one node
    {
        struct node<T> * head = first;
        struct node<T> * tail = last;

        head = head->next;
        delete tail->next;    // free((*Head)->prev);
        head->prev = tail;
        tail->next = head;
    }
    Count--;
    

}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if((first == NULL) && (last == NULL))    // LL is empty
    {
        return;
    }
    else if(first == last)   // LL contains single node
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than one node
    {
        struct node<T> * head = first;
        struct node<T> * tail = last;   
        tail = tail->prev;
        delete tail->next;
        tail->next = head;
        head->prev = tail;
        
    }
    Count--;
}

template <class T>
void DoublyCL<T> :: InsertAtPos(T no , int iPos)
{
    if((iPos < 1)||(iPos > Count+1))
    {
        cout<<"Invalid Position";
        return;
    }
   else if(iPos==1)
    {
        InsertFirst(no);
    }
    else if(iPos > Count+1)
    {
        InsertLast(no);
    }
    else 
    {
        struct node<T> * newn = new struct node<T>;
        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL;
        struct node<T> * head = first;
        struct node<T> * tail = last;

        for(int iCnt=1 ; iCnt < iPos-1;iCnt++)
        {
            head = head->next;
        }
        newn->next = head->next;
        head->next->prev = newn;
        head->next = newn;
        newn->prev = head;
    }
    Count++;
}

template <class T>
void DoublyCL<T> :: DeleteAtPos(int iPos)
{
    if((iPos < 1)||(iPos > Count))
    {
        cout<<"Invalid Position";
    }
    else if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos > Count)
    {
        DeleteLast();
    }
    else 
    {
        struct node<T> * head = first;
        struct node<T> * tail = last;
        for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
        {
            head = head->next;
        }
        head->next=  head->next->next;
        delete head->next->prev;
        head->next->prev = head;

    }
    Count--;
}

template <class T>
class Stack
{
    private:
    struct node <T> * first;
   
    public:
    Stack();

    void Push(T no);

    void Display();

    void Pop();
    

    
};

template <class T>
Stack<T> :: Stack()
{
    first = NULL;
   
}

template <class T>
void Stack<T> :: Push(T No)
{
    struct node <T> *newn = NULL;
    newn =  new struct node <T>;
    newn->data = No;
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
    
}

template <class T>
void Stack<T> :: Display()
{
    cout<<"Elements in the Stack are :\n";
    struct node <T> * head = first;
    while(head != NULL)
    {
        cout<<"|"<<head->data<<"|"<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
}


template <class T>
void Stack<T> :: Pop()
{
   if(first == NULL)
   {
        cout<<"Stack is Empty";
        return;
   }
   else if(first->next == NULL)
   {
        delete first;
        first = NULL;
   }
   else
   {
        struct node <T> * temp = first;
        first = first->next;
        delete temp;       
    }
   
}
template<class T>
class Queue
{
    private:
        struct node <T> * first;
    public:
     
        Queue();

        void Enqueue(T No);

        void Display();

        void  Dequeue();

         void EvenEle();
        void OddEle();
        void CountEven();
        void CountOdd();
        void MaxEle();
        void MinEle();
        void Perfect();
};

template <class T>
Queue<T>:: Queue()
{ 
    first = NULL;
}

template <class T>
void Queue<T> :: Enqueue(T No)
{
     struct node <T> * temp = first;

     struct node <T> * newn = new  struct node <T>;
    newn->data = No;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn; 
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

template <class T>
void Queue<T> :: Display()
{
     struct node <T> * temp = first;

    cout<<"Queue is :\n";
    while(temp->next !=  NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"->";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
void Queue<T> :: Dequeue()
{
    
     struct node <T> * temp = first;

    if(first == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        first = first->next;

        delete(temp);
    }
}

template<class T>
void Queue<T> :: EvenEle()
{
    struct node <T> * temp = first;
    cout<<"Even Elements From LinkedList Are :"<<"\n";
    while(temp != NULL)
    {
        if((temp->data %2)==0)
        {
            cout<<"|"<<temp->data<<"|"<<"->";
        }
        temp = temp->next;
    }
    cout<<"NULL\n";
    
}

template<class T>
void Queue<T> :: OddEle()
{
    struct node <T> * temp = first;
    cout<<"Odd Elements From LinkedList Are :"<<"\n";
    while(temp != NULL)
    {
        if((temp->data %2)!=0)
        {
            cout<<"|"<<temp->data<<"|"<<"->";
        }
        temp = temp->next;
    }
    cout<<"NULL\n";
    
}

template<class T>
void Queue<T> :: CountEven()
{
    struct node <T> * temp = first;
    int eCnt = 0;
   
    while(temp != NULL)
    {
        if((temp->data %2)==0)
        {
           eCnt++;
        }
        temp = temp->next;
    }
    cout<<"Number of Even Elements From Singly Linear LinkedList Are :"<<eCnt<<"\n";
    
}

template<class T>
void Queue<T> :: CountOdd()
{
    struct node <T> * temp = first;
    int iCnt = 0;
    while(temp != NULL)
    {
        if((temp->data %2)!=0)
        {
           iCnt++;
        }
        temp = temp->next;
    }
    cout<<"Number of Odd Elements From Singly Linear LinkedList Are :"<<iCnt<<"\n";
    
}

template<class T>
void Queue<T> :: MaxEle()
{
    struct node <T> * temp = first;
    int Max = temp->data;
    while(temp != NULL)
    {
        if(temp->data > Max)
        {
           Max = temp->data;
        }
        temp = temp->next;
    }
    cout<<"Maximum Element From Singly Linear LinkedList is:"<<Max<<"\n";
    
}

template<class T>
void Queue<T> :: MinEle()
{
    struct node <T> * temp = first;
    int Min = temp->data;
    while(temp != NULL)
    {
        if(temp->data < Min)
        {
           Min = temp->data;
        }
        temp = temp->next;
    }
    cout<<"Minimum Element From Singly Linear LinkedList is:"<<Min<<"\n";
    
}

template<class T>
void Queue<T> :: Perfect()
{
    struct node <T> * temp = first;
    cout<<"Perfect Elements From Singly Linear LinkedList Is:"<<"\n";
     int iCnt = 0;
     int iSum = 0;
    while(temp != NULL)
    {
       
       if(temp->data % (temp->data / 2 )== 0)
       {
            cout<<"|"<<temp->data<<"|"<<"\n";
            temp = temp->next;
       }
       else 
       {
        temp = temp->next;
       }
    
    }
   
    cout<<"NULL\n";
}

template <class T>
class BST
{
    public:
        struct node<T> * first;
    public:
    BST();
    void Insert(T no);
    void Inorder(struct node<T> * temp);
    void Preorder(struct node<T> * temp);
    void Postorder(struct node<T> * temp);
    void search();
    void SearchEven(struct node<T> * temp);
    void LeafNode(struct node<T> * temp);
    void ParentNode(struct node<T> * temp);
    void SearchOdd(struct node<T> * temp);
};

template <class T>
BST<T> :: BST()
{
    first = NULL;
}

template <class T>
void BST<T> :: Insert(T no)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = first;

    newn = (struct node<T> *)malloc(sizeof(struct node<T>));
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(1)
        {
            if(no == first->data)
            {
                cout<<"Duplicate Entry Is Not Allowed In BST"<<"\n";
                break;
            }
            else if(no > first->data)
            {
                if(first->rchild == NULL)
                {
                    first->rchild= newn;
                    break;
                }
                first = first->rchild;
            }
            else if(no < first->data)
            {
                if(first->lchild == NULL)
                {
                    first->lchild = newn;
                    break;
                }
                first = first->lchild;
            }
        }
    }
} 

template <class T>
void BST<T> ::  Inorder(struct node<T> * temp)
{
   // temp = first;
    if(temp != NULL)
    {
        Inorder(temp->lchild);
        cout<<temp->data<<"\n";
        Inorder(temp->rchild);
    }
}

template <class T>
void BST<T> :: Preorder(struct node<T> * temp)
{
  // temp = first;
    if(temp != NULL)
    {
        cout<<temp->data<<"\n";
        Preorder(temp->lchild);
        Preorder(temp->rchild);
    }
}

template <class T>
void BST<T> :: Postorder(struct node<T> * temp)
{
   // temp = first;
    if(temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        cout<<temp->data<<"\n";
    }
}

template <class T>
void BST<T> :: search()
{
    T no;
    
    cout<<"Enter the value to search in BST ?"<<"\n";
    cin>>no;

    if(first == NULL)
    {
        cout<<"BST is empty !!";
        
        
    }
    while(first != NULL)
    {
        if(first->data == no)
        {
           cout<<"Data Found"<<"\n";
           break;
        }
        else if(no > first->data)
        {
            first = first->rchild;
        }
        else if(no < first->data)
        {
            first = first->lchild;
        }
    }
    
 
}

template<class T>
void BST<T> :: SearchEven(struct node<T> * temp)
{

    if(temp != NULL)
    {
        if((temp->data % 2)== 0)
        {
            cout<<temp->data<<"\n";
           
        }
        SearchEven(temp->lchild);
        SearchEven(temp->rchild);
    }
   
}

template<class T>
void BST<T> :: LeafNode(struct node<T> * temp)
{
    if(temp != NULL)
    {
        if((temp->lchild == NULL)&&(temp->rchild == NULL))
        {
            cout<<"Leaf Nodes Are :"<<"\n";
            cout<<temp->data<<"\n";
        }
        LeafNode(temp->lchild);
        LeafNode(temp->rchild);
    }
   
}


template<class T>
void BST<T>:: ParentNode(struct node<T> * temp)
{
    if(temp != NULL)
    {
        if((temp->lchild != NULL)||(temp->rchild != NULL))
        {
            cout<<"Parent Nodes Are :"<<"\n";
            cout<<temp->data<<"\n";
        }
        ParentNode(temp->lchild);
        ParentNode(temp->rchild);
    }
}

template<class T>
void BST<T> :: SearchOdd(struct node<T> * temp)
{
    
    if(temp != NULL)
    {
        if((temp->data % 2)!= 0)
        {
            cout<<temp->data<<"\n";
        }
        SearchOdd(temp->lchild);
        SearchOdd(temp->rchild);
    }
    
}

template <class T>
class Array
{
    private:
        T * Arr;
        int iSize;

    public:


        void Accept(int X)       // Member function
        {
            iSize = X;
            Arr = new T[iSize];
            int iCnt = 0;
            cout<<"Please enter the elements : "<<endl;
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cin>>Arr[iCnt];
            }
        }

        void Display(int X)      // Member function
        {
            cout<<"Elements of the array are : "<<endl;
            int iCnt = 0;
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<endl;
        }
        void LinearSearch(int X)
        {
            T value;
            cout<<"Enter the Value you Want to Search"<<"\n";
            cin>>value;
            int iCnt = 0;
            for(iCnt = 0 ; iCnt < iSize ; iCnt++)
            {
                if(Arr[iCnt] == value)
                {
                    cout<<"Element Found!!"<<"\n";
               }
                
            }

        }
         void BinarySearch(int X)
        {
            T value;
            cout<<"Enter the Value you Want to Search"<<"\n";
            cin>>value;

            int start = 0 , end = 0 ,mid = 0; 
            end = iSize-1;

            while(start <= end)
            {
                mid = start+(end-start)/2;

                if(Arr[mid] == value)
                {
                    cout<<"Element Found\n";
                    break;
                }
                else if(Arr[mid] < start)
                {
                    start = mid +1;
                }
                else if(Arr[mid] > end)
                {
                    end = mid -1;
                }
            }
        }
        void BiDirectionalSearch(int X)
        {
            T value;
            cout<<"Enter the Value you Want to Search"<<"\n";
            cin>>value; 

            int start = 0 , end = 0;
            end = iSize-1;

            while(start <= end)
            {
                if((Arr[start] == value)||(Arr[end]==value))
                {
                    cout<<"Element Found"<<"\n";
                    break;
                }
                start++;
                end--;
            } 
        }
        
}; 

#include<iostream>
using namespace std;

template <class T>
class ArrayOps
{
    private:
        T * Arr;
        int iSize;

    public:


        void Accept(int X)       // Member function
        {
            iSize = X;
            Arr = new T[iSize];
            int iCnt = 0;
            cout<<"Please enter the elements : "<<endl;
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cin>>Arr[iCnt];
            }
        }

        void Display(int X)      // Member function
        {
            cout<<"Elements of the array are : "<<endl;
            int iCnt = 0;
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<endl;
        }
        void SearchEle(int X)
        {
            T value;
            cout<<"Enter the Value you Want to Search"<<"\n";
            cin>>value;
            int iCnt = 0;
            for(iCnt = 0 ; iCnt < iSize ; iCnt++)
            {
                if(Arr[iCnt] == value)
                {
                    cout<<"Element Found!!"<<"\n";
               }
                
            }
        }
        void Summation(int X)
        {
            int iCnt = 0;
            T Sum = 0; 
            for(iCnt = 0 ; iCnt < iSize ; iCnt++)
            {
                Sum = Sum + Arr[iCnt];
            }
            cout<<"Sum Of All Array Elements Is :"<<Sum<<"\n";
        }
        void Factor(int X)
        {
            T value = 0;
            cout<<"Enter the number to find the factors:"<<"\n";
            cin>>value;

            int iCnt = 0;

            for(iCnt = 1 ; iCnt <= value/2 ; iCnt++)
            {
                if((value % iCnt)==0)
                {
                    cout<<iCnt<<"\t";
                }
            }
            cout<<"\n";
        }
        void Factorial(int X)
        {
            T value = 0;
            cout<<"Enter the number to find the factorial:"<<"\n";
            cin>>value;

            int iCnt = 0;
            T Fact = 1;
            for(iCnt = 1; iCnt <= value ; iCnt++)
            {
                Fact = Fact * iCnt;
            }
            cout<<"Factorial of "<<value<<" is "<<Fact<<"\n";
        }
        void Mul(int X)
        {
            T Mul = 1;
            int iCnt = 0;
            for(iCnt = 0 ; iCnt  < iSize ; iCnt++)
            {
                Mul =  Mul * Arr[iCnt];
            }
            cout<<"Multiplication of all array elements is:"<<Mul<<"\n";
        }
        void MaxEle(int X)
        {
            int iCnt = 0;
            T MaxEle = Arr[iCnt];

            for(iCnt = 0 ; iCnt < iSize ; iCnt++)
            {
                if(Arr[iCnt] > MaxEle)
                {
                    MaxEle = Arr[iCnt];
                }
            }
            cout<<"Max Element From Aray is:"<<MaxEle<<"\n";
        }
        void MinEle(int X)
        {
            int iCnt = 0;
            T MinEle = Arr[iCnt];

            for(iCnt = 0 ; iCnt < iSize ; iCnt++)
            {
                if(Arr[iCnt] < MinEle)
                {
                    MinEle = Arr[iCnt];
                }
            }
            cout<<"Max Element From Aray is:"<<MinEle<<"\n";
        }
        void isPrime(int X)
        {
            T value = 0;
            int iCnt = 0;
            bool bFlag = true;
            cout<<"Enter the number to check it is prime or not:"<<"\n";
            cin>>value;   

            for(iCnt = 2 ; iCnt < iSize ; iCnt++)
            {
                if((value % iCnt)==0)
                {
                    bFlag = false;
                }
            }
            if(bFlag == true)
            {
                cout<<"Number is prime"<<"\n";
            }
            else 
            {
                cout<<"Number is Not Prime"<<"\n";
            }
        }
        void PrimeNo(int X)
        {
            int i = 0 , j = 0;
            bool bFlag = true;
            cout<<"Prime Elements From Array Are :"<<"\n";
            for(i = 0 ; i < iSize ; i++)
            {
                 bool bFlag = true;
                for(j = 2 ; j < Arr[i] ; j++)
                {
                    
                    if((Arr[i] % j)==0)
                    {
                        bFlag = false;
                        break;
                    }
                }
                if(bFlag == true)
                {
                    cout<<Arr[i]<<"\n";
                }
            }
        }
        void PerfectNo(int X)
        {
            
            int i = 0 , j = 0;
            cout<<"Perfect Numbers From Array Are :"<<"\n";
            for(i = 0 ;  i < iSize ; i++)
            {
                int iSum = 0;
                for(j = 1 ; j <= Arr[i]/2 ; j++)
                {
                    if((Arr[i] % j)==0)
                    {
                        iSum = iSum + j;
                    }
                }
                if(Arr[i] == iSum)
                {
                    cout<<Arr[i]<<"\n";
                }
            }
        }
            void EvenEle(int X)
            {
                int iCnt = 0;
                cout<<"Even Elements from array are:"<<"\n";
                for(iCnt = 0; iCnt < iSize ; iCnt++)
                {
                    if((Arr[iCnt] % 2)==0)
                    {
                        cout<<Arr[iCnt]<<"\n";
                    }
                }
            }
            void OddEle(int X)
            {
                int iCnt = 0;
                cout<<"Odd Elements from array are:"<<"\n";
                for(iCnt = 0; iCnt < iSize ; iCnt++)
                {
                    if((Arr[iCnt] % 2)!=0)
                    {
                        cout<<Arr[iCnt]<<"\n";
                    }
                }
            }



        
        
};  // End of class

 #include<iostream>
using namespace std;

template <class T>
class ArraySorting
{
    private:
        T * Arr;
        int iSize;

    public:


        void Accept(int X)       // Member function
        {
            iSize = X;
            Arr = new T[iSize];
            int iCnt = 0;
            cout<<"Please enter the elements : "<<endl;
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cin>>Arr[iCnt];
            }
        }

        void Display(int X)      // Member function
        {
            cout<<"Elements of the array are : "<<endl;
            int iCnt = 0;
            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<endl;
        }
          
        void BubbleSort(int X)
        {
            int i = 0 , j = 0;
            T temp = 0;
            bool bRet = false;
            for(i = 0 ; i < iSize-1 ; i++)
            {
                for(j = 0 ; j < iSize-i-1 ; j++)
                {
                    if(Arr[j] > Arr[j+1])
                    {
                        temp = Arr[j];
                        Arr[j] = Arr[j+1];
                        Arr[j+1] = temp;
                        bRet = true;
                    }
                }
                if(bRet == false)
                {
                    break;
                }
            }
             cout<<"|"<<"After Bubble Sort"<<"|"<<"\n";
             Display(5);
            
        }
        void SelectionSort(int X)
        {
            int i = 0 , j = 0 ;
            T temp;
            int iMin_index = 0;

            for(i = 0 ; i < iSize-1 ;i++)
            {
                iMin_index = i;
                for(j = i+1 ; j < iSize ; j++)
                {
                     if(Arr[iMin_index] > Arr[j])
                     {
                        iMin_index = j;
                     }
                }
                if(i != iMin_index)
                {
                    temp = Arr[i];
                    Arr[i] = Arr[iMin_index];
                    Arr[iMin_index] = temp;
                }

            }
            cout<<"|"<<"After Selection Sort"<<"|"<<"\n";
            Display(5);
        }
        void InsertionSort(int X)
        {
            int i = 0 , j = 0;
            int selected = 0;

            for(i = 1 ; i < iSize ; i++)
            {
                for(j = i-1 , selected = Arr[i] ; ((j >= 0)&&(Arr[j] > selected));j--)
                {
                    Arr[j+1] = Arr[j];
                }
                Arr[j+1] = selected;

            }
            cout<<"|"<<"After Insertion Sort"<<"|"<<"\n";
            Display(5);
        }
           
        
        
        
};  // End of class

