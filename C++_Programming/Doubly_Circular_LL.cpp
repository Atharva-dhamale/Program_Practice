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

class DoublyCL
{
    private:
            PNODE first;
            PNODE last;
            int iCount;
    public:
            DoublyCL()
            {
                cout<<"Object of Doubly CL is created\n";
                this->first=NULL;
                this->last=NULL;
                this->iCount=0;
            }

            void InsertFirst(int no)
            {
                PNODE newn=new NODE;

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

            void InsertLast(int no)
            {
               PNODE newn=new NODE;

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

            void DeleteFirst()
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

            void DeleteLast()
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

            void Display()
            {
                PNODE temp=NULL;
                temp=this->first;

                do
                {
                    cout<<"| "<<temp->data<<"| <=>";
                    temp=temp->next;
                }while(temp!=this->first);
                cout<<"\n";
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

            void DeleteAtPos(int pos)
            {
                PNODE temp=NULL;
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

            
    };

int main()
{
    DoublyCL obj;
    int iRet=0;

    obj.InsertFirst(27);
    obj.InsertFirst(93);

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj.InsertLast(84);
    obj.InsertLast(31);

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

    obj.InsertAtPos(35,3);

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj.DeleteAtPos(2);

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    return 0;
}