#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyLL
{
    private:
            PNODE first;
            int iCount;

    public:
            DoublyLL()
            {
                cout<<"Object of Doubly Linear LL is created\n";
                this->first=NULL;
                this->iCount=0;
            }

            void InsertFirst(int no)
            {
                PNODE newn=new NODE;
                
                newn->data=no;
                newn->next=NULL;
                newn->prev=NULL;

                if(this->first==NULL)
                {
                    this->first=newn;
                }
                else
                {
                    newn->next=this->first;
                    this->first=newn;
                }
                this->iCount++;
            }

            void InsertLast(int no)
            {
                PNODE newn=new NODE;
                PNODE temp=NULL;
                
                newn->data=no;
                newn->next=NULL;
                newn->prev=NULL;

                if(this->first==NULL)
                {
                    this->first=newn;
                }
                else
                {
                    temp=first;

                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=newn;
                    newn->prev=temp;
                }
                this->iCount++;
            }

            void DeleteFirst()
            {

                if(this->first==NULL)
                {
                    cout<<"Linked list is empty\n";
                    return;
                }
                else if(this->first->next==NULL)
                {
                    delete this->first;
                    this->first=NULL;
                }
                else
                {
                    this->first=this->first->next;
                    delete this->first->prev;
                    this->first->prev=NULL;
                }
                this->iCount--;
            }
            void DeleteLast()
            {
                PNODE temp=NULL;


                if(this->first==NULL)
                {
                    cout<<"Linked list is empty\n";
                    return;
                }
                else if(this->first->next==NULL)
                {
                    delete this->first;
                    this->first=NULL;
                }
                else
                {
                    temp=first;

                    while(temp->next->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    
                    delete temp->next;
                    temp->next=NULL;

                }
                this->iCount--;
            }
            void Display()
            {
                PNODE temp=NULL;
                temp=first;

                while(temp!=NULL)
                {
                    cout<<"| "<<temp->data<<" |<=>";
                    temp=temp->next;
                }
                cout<<"NULL\n";
            }

            int Count()
            {

                return iCount;
            }

            void InsertAtPos(int no,int pos)
            {
                PNODE newn=new NODE;
                PNODE temp=NULL;
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
                    newn->data=no;
                    newn->next=NULL;
                    newn->prev=NULL;

                    temp=this->first;

                    for(iCnt=1;iCnt<pos-1;iCnt++)
                    {
                        temp=temp->next;
                    }
                    newn->next=temp->next;
                    newn->next->prev=newn;
                    temp->next=newn;

                    this->iCount++;
                }

            }

            void DeleteAtPos(int pos)
            {
                int iCnt=0;
                PNODE temp=NULL;
                PNODE target=NULL;

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
                    target->next->prev=temp;
                    delete target;
                    
                    this->iCount--;
                }
            }
};

int main()
{

    DoublyLL obj;

    int iRet=0;

    obj.InsertFirst(43);
    obj.InsertFirst(93);
    obj.InsertFirst(27);

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj.InsertLast(84);
    obj.InsertLast(31);
    obj.InsertLast(25);

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj.DeleteFirst();
    

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj.DeleteLast();
    
    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj.InsertAtPos(10,5);
    
    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj.DeleteAtPos(5);
    

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";




    return 0;
}