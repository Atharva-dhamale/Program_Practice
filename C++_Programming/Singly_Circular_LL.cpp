#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyCL
{
    private:
            PNODE first;
            PNODE last;
            int iCount;

    public:
            SinglyCL()
            {
                cout<<"Object of Singly Circular LL is created\n";
                this->first=NULL;
                this->last=NULL;
                this->iCount=0;
            }

            void InsertFirst(int no)
            {
                PNODE newn=new NODE;
                
                newn->data=no;
                newn->next=NULL;

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

            void InsertLast(int no)
            {
                PNODE newn=new NODE;
                
                
                newn->data=no;
                newn->next=NULL;

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

            void DeleteFirst()
            {
                PNODE temp=NULL;

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
            void DeleteLast()
            {
                PNODE temp=NULL;


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
            void Display()
            {
                PNODE temp=NULL;
                temp=first;

                do
                {
                    cout<<"| "<<temp->data<<" |->";
                    temp=temp->next;
                }while(temp!=first);

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
                    delete target;
                    
                    this->last->next=this->first;
                    this->iCount--;
                }
            }
};

int main()
{

    SinglyCL obj;

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

    obj.InsertAtPos(10,3);
    
    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";

    obj.DeleteAtPos(4);
    

    obj.Display();
    iRet=obj.Count();
    cout<<"Number of nodes are:"<<iRet<<"\n";




    return 0;
}