#include<iostream>

using namespace std;

#pragma pack(1)

template<class T>
class DoublyCLLnode
{
    public:

        T data;
        struct DoublyCLLnode *next;
        struct DoublyCLLnode *prev;

        DoublyCLLnode(T no)
        {
            this->data=no;
            this->next=NULL;
            this->prev=NULL;
        }
};

template<class T>
class DoublyCLL
{
    private:
            DoublyCLLnode<T> *first;
            DoublyCLLnode<T> *last;
            int iCount;
    public:
            DoublyCLL();

            void InsertFirst(T no);

            void InsertLast(T no);

            void DeleteFirst();

            void DeleteLast();

            void Display();

            int Count();

            void InsertAtPos(T no,int pos);  

            void DeleteAtPos(int pos);

            
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Object of Doubly CL is created\n";
    this->first=NULL;
    this->last=NULL;
    this->iCount=0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn=new DoublyCLLnode<T>(no);

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((this->first==NULL)&&(this->last==NULL))
    {
        this->first=newn;
        this->last=newn;
    }
    else
    {
        newn->next=this->first;
        this->first->prev=newn;
        this->first=newn;

    }
    this->last->next=this->first;
    this->first->prev=this->last;
    this->iCount++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> *newn=new DoublyCLLnode<T>(no);

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((this->first==NULL)&&(this->last==NULL))
    {
        this->first=newn;
        this->last=newn;
    }
    else
    {
        this->last->next=newn;
        newn->prev=this->last;
        this->last=newn;
    }
    this->last->next=this->first;
    this->first->prev=this->last;
    this->iCount++; 
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if((this->first==NULL)&&(this->last==NULL))
    {
        cout<<"Linked list is empty\n";
        return;
    }
    else if(this->first==this->last)
    {
        delete this->first;
        this->first=NULL;
        this->last=NULL;
    }
    else
    {
        this->first=this->first->next;
        delete this->first->prev;
    }
    this->last->next=this->first;
    this->first->prev=this->last;
    this->iCount--; 
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if((this->first==NULL)&&(this->last==NULL))
    {
        cout<<"Linked list is empty\n";
        return;
    }
    else if(this->first==this->last)
    {
        delete this->first;
        this->first=NULL;
        this->last=NULL;
    }
    else
    {
        this->last=this->last->prev;
        delete this->last->next;
    }
    this->last->next=this->first;
    this->first->prev=this->last;
    this->iCount--;
}

template<class T>
void DoublyCLL<T>::Display()
{
    DoublyCLLnode<T> *temp=NULL;
    temp=this->first;

    do
    {
        cout<<"| "<<temp->data<<"| <=>";
        temp=temp->next;
    }while(temp!=this->first);
    cout<<"\n";
}

template<class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyCLL<T>::InsertAtPos(T no,int pos)
{
    DoublyCLLnode<T> *newn=new DoublyCLLnode<T>(no);
    DoublyCLLnode<T> *temp=NULL;
    int iCnt=0;

    if((pos<1)||(pos>iCount+1))
    {
        cout<<"Invalid position";
        return;
    }
    if(pos==1)
    {
        this->InsertFirst(no);
    }
    else if(pos==iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;

        temp=this->first;

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;

        this->last->next=this->first;
        this->first->prev=this->last;
        this->iCount--;
    }
}

template<class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode<T> *temp=NULL;
    int iCnt=0;

    if((pos<1)||(pos>iCount))
    {
        cout<<"Invalid position";
        return;
    }
    if(pos==1)
    {
        this->DeleteFirst();
    }
    else if(pos==iCount)
    {
        this->DeleteLast();
    }
    else
    {

        temp=this->first;

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;

        this->last->next=this->first;
        this->first->prev=this->last;
        this->iCount--;
    }
}


int main()
{
    DoublyCLL<int> *dcobj=new DoublyCLL<int>();

    dcobj->InsertFirst(27);
    dcobj->InsertFirst(93);
    dcobj->Display();
    cout<<"Number of nodes are:"<<dcobj->Count()<<"\n";

    dcobj->InsertLast(84);
    dcobj->InsertLast(31);
    dcobj->Display();
    cout<<"Number of nodes are:"<<dcobj->Count()<<"\n";

    dcobj->DeleteFirst();
    dcobj->Display();
    cout<<"Number of nodes are:"<<dcobj->Count()<<"\n";

    dcobj->DeleteLast();
    dcobj->Display();
    cout<<"Number of nodes are:"<<dcobj->Count()<<"\n";

    dcobj->InsertAtPos(35,3);
    dcobj->Display();
    cout<<"Number of nodes are:"<<dcobj->Count()<<"\n";

    dcobj->DeleteAtPos(2);
    dcobj->Display();
    cout<<"Number of nodes are:"<<dcobj->Count()<<"\n";

    return 0;
}