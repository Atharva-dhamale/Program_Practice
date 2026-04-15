#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first,int no)
{
    PNODE newn=NULL;

    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(*first==NULL)
    {
        *first=newn;
    }
    else
    {
        newn->next=*first;
        newn->prev=NULL;
        *first=newn;

    }
}

void InsertLast(PPNODE first,int no)
{
    PNODE newn=NULL;
    PNODE temp=NULL;

    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

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
        newn->prev=temp;
    }
}



void DeleteFirst(PPNODE first)
{
    PNODE temp=NULL;

    if(*first==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    else
    {
        temp=*first;

        *first=temp->next;
        (*first)->prev=NULL;
        free(temp);
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
    PNODE temp=NULL;
    temp=first;

    while(temp!=NULL)
    {
        printf("| %d |->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    PNODE temp=first;
    int iCnt=0;

    while(temp!=NULL)
    {
        iCnt++;
        temp=temp->next;
    }
    return iCnt;
}


void InsertAtPos(PPNODE first,int no,int pos)
{
    PNODE newn=NULL;
    PNODE temp=NULL;
    int iCnt=0;
    int i=0;

    iCnt=Count(*first);

    if(pos<0 || pos>iCnt+1)
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos==1)
    {
        InsertFirst(first,no);
    }
    else if(pos==iCnt+1)
    {
        InsertLast(first,no);
    }
    else
    {
        newn=(PNODE)malloc(sizeof(NODE));

        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;

        temp=*first;

        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        newn->prev=temp;
        temp->next=newn;
    }
}


void DeleteAtPos(PPNODE first,int pos)
{
    PNODE temp=NULL;
    PNODE container=NULL;
    int iCnt=0;
    int i=0;

    iCnt=Count(*first);

    if(pos<0 || pos>iCnt)
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos==1)
    {
        DeleteFirst(first);
    }
    else if(pos==iCnt)
    {
        DeleteLast(first);
    }
    else
    {

        temp=*first;

        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        container=temp->next;
        temp->next=container->next;
        temp->prev=container->prev;
        free(container);

    }
}

int main()
{
    PNODE head=NULL;
    int iRet=0;

    InsertFirst(&head,27);
    InsertFirst(&head,93);
    InsertLast(&head,84);
    InsertLast(&head,25);
    InsertLast(&head,35);
    InsertAtPos(&head,31,4);
    DeleteFirst(&head);
    DeleteLast(&head);
    DeleteAtPos(&head,3);
    Display(head);
    iRet=printf("Total number of nodes are : %d\n",Count(head));

    return 0;
}