#include<iostream>

using namespace std;

#pragma pack(1)

template <class T>

class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode *next;

        SinglyCLLnode(T no)
        {
            this->data=no;
            this->next=NULL;
        }
};


template <class T>
class SinglyCLL
{
    private:
            SinglyCLLnode<T> *first;
            SinglyCLLnode<T> *last;
            int iCount;

    public:
            SinglyCLL();

            void InsertFirst(T no);

            void InsertLast(T no);

            void DeleteFirst();

            void DeleteLast();

            void Display();

            int Count();

            void InsertAtPos(T no,int pos);

            void DeleteAtPos(int pos);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Object of Singly Circular LL is created\n";
    this->first=NULL;
    this->last=NULL;
    this->iCount=0;
}

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> *newn=new SinglyCLLnode<T>(no);
    

    if((this->first==NULL)&&(this->last==NULL))
    {
        this->first=this->last=newn;

    }
    else
    {
        newn->next=this->first;
        this->first=newn;
    }
    this->last->next=this->first;
    this->iCount++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> *newn=new SinglyCLLnode<T>(no);
    
    
    if((this->first==NULL)&&(this->last==NULL))
    {
        this->first=this->last=newn;


    }
    else
    {
        this->last->next=newn;
        this->last=newn;  
    }

    this->last->next=this->first;
    this->iCount++;
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    SinglyCLLnode<T> *temp=NULL;

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
        temp=this->first;
        this->first=this->first->next;
        delete temp;  

        this->last->next=this->first;
    }
    
    this->iCount--;
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> *temp=NULL;


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
        temp=first;

        while(temp->next!=last)
        {
            temp=temp->next;
        }
        
        delete last;
        last=temp;

        this->last->next=this->first;
    }
    
    this->iCount--;
}

template <class T>
void SinglyCLL<T>::Display()
{
    SinglyCLLnode<T> *temp=NULL;
    temp=first;

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp=temp->next;
    }while(temp!=first);

    cout<<"\n";

    
}

template <class T>
int SinglyCLL<T>::Count()
{

    return iCount;
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T no,int pos)
{
    SinglyCLLnode<T> *newn=new SinglyCLLnode<T>(no);
    SinglyCLLnode<T> *temp=NULL;
    int iCnt=0;

    if((pos<1)||(pos>this->iCount+1))
    {
        cout<<"Inavlid position";
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

        temp=this->first;

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

        this->last->next=this->first;
        this->iCount++;
    }

}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    int iCnt=0;
    SinglyCLLnode<T> *temp=NULL;
    SinglyCLLnode<T> *target=NULL;

    if((pos<1)||(pos>this->iCount))
    {
        cout<<"Inavlid position";
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
        target=temp->next;
        temp->next=target->next;
        delete target;
        
        this->last->next=this->first;
        this->iCount--;
    }
}

int main()
{

    SinglyCLL<int> *scobj=new SinglyCLL<int>();

    int iRet=0;

    scobj->InsertFirst(43);
    scobj->InsertFirst(93);
    scobj->InsertFirst(27);

    scobj->Display();
    iRet=scobj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    scobj->InsertLast(84);
    scobj->InsertLast(31);
    scobj->InsertLast(25);

    scobj->Display();
    iRet=scobj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    scobj->DeleteFirst();
    

    scobj->Display();
    iRet=scobj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    scobj->DeleteLast();
    
    scobj->Display();
    iRet=scobj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    scobj->InsertAtPos(10,3);
    
    scobj->Display();
    iRet=scobj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    scobj->DeleteAtPos(4);
    

    scobj->Display();
    iRet=scobj->Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    delete scobj;


    return 0;
}