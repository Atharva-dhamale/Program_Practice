#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first,int no)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

    if(*first==NULL)
    {
        *first=newn;
    }
    else
    {
        newn->next=*first;
        *first=newn;
    }
}

void InsertLast(PPNODE first,int no)
{
    PNODE temp=NULL;
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

    if(*first==NULL)
    {
        *first=newn;
    }
    else
    {
       temp=*first;
       
       while(temp->next!=NULL)
       {
        temp=temp->next;
       }
       temp->next=newn;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE target=NULL;

    if(*first==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    else if((*first)->next==NULL)
    {
        free(*first);
        *first=NULL;
    }
    else
    {
        target=*first;
        *first=(*first)->next;
        free(target);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp=NULL;

    if(*first==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    else if((*first)->next==NULL)
    {
        free(*first);
        *first=NULL;
    }
    else
    {
        temp=*first;

        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

void Display(PNODE first)
{

    while(first!=NULL)
    {
        printf("| %d |->",first->data);
        first=first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCnt=0;

    while(first!=NULL)
    {
        iCnt++;
        first=first->next;
    }
    return iCnt;
}

void InsertAtPos(PPNODE first,int no,int pos)
{
    PNODE temp=NULL;
    PNODE newn=NULL;
    int iSize=0;

    iSize=Count(*first);
    

    if((pos<1)||(pos>iSize+1))
    {
        printf("Inavlid position\n");
        return;
    }
    if(pos==1)
    {
        InsertFirst(first,no);
    }
    else if(pos==iSize+1)
    {
        InsertLast(first,no);
    }
    else
    {
        newn=(PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;
        int iCnt=0;

        temp=*first;

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}

bool Search(PNODE head,int no)
{
    while(head!=NULL)
    {
        if(head->data==no)
        {
            return true;
        }

        head=head->next;
    } 
}

void DeleteAtPos(PPNODE first,int pos)
{
    PNODE temp=NULL;
    PNODE target=NULL;
    int iSize=0;
    int iCnt=0;

    iSize=Count(*first);
    

    if((pos<1)||(pos>iSize))
    {
        printf("Inavlid position\n");
        return;
    }
    if(pos==1)
    {
        DeleteFirst(first);
    }
    else if(pos==iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp=*first;

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        target=temp->next;
        temp->next=temp->next->next;
        free(target);
        
    }
}

int main()
{
    PNODE head=NULL;
    int iRet=0;

    InsertFirst(&head,27);
    InsertFirst(&head,93);

    InsertLast(&head,25);
    InsertLast(&head,35);

    Display(head);

    iRet=Search(head,25);

    if(iRet==true)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found\n");
    }
    

    

    return 0;
}