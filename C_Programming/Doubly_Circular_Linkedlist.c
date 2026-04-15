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

void InsertFirst(PPNODE first,PPNODE last,int no)
{
    PNODE newn=NULL;

    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((*first==NULL) && (*last==NULL))
    {
        *first=newn;
        *last=newn;
    }
    else
    {
        newn->next=*first;
        *first=newn;
    }

    (*last)->next=(*first);
}

void InsertLast(PPNODE first,PPNODE last,int no)
{
    PNODE newn=NULL;

    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if((*first==NULL) && (*last==NULL))
    {
        *first=newn;
        *last=newn;
    }
    else
    {
        (*last)->next=newn;
        newn->prev=*last;
        *last=(*last)->next;
    }

    (*last)->next=(*first);
}



void DeleteFirst(PPNODE first,PPNODE last)
{
    PNODE temp=NULL;

    if((*first==NULL) && (*last==NULL))
    {
        printf("Linked list is empty\n");
        return;
    }
    else if(*first==*last)
    {
        free(*first);
        *first=NULL;
        *last=NULL;
    }
    else
    {
        temp=*first;

        *first=temp->next;
        free(temp);
        (*first)->prev=NULL;

        (*last)->next=(*first);
    }
    
}


void DeleteLast(PPNODE first,PPNODE last)
{
    PNODE temp=NULL;

    if((*first==NULL) && (*last==NULL))
    {
        printf("Linked list is empty\n");
        return;
    }
    else if(*first==*last)
    {
        free(*first);
        *first=NULL;
        *last=NULL;
    }

    else
    {
        temp=*first;

        while(temp->next!=(*last))
        {
            temp=temp->next;
        }

        free(*last);
        *last=temp;

        (*last)->next=(*first);
    }
    

}


void Display(PNODE first,PNODE last)
{
    if(first==NULL||last==NULL)
    {
        printf("Empty Linked list\n");
        return;
    }

    do
    {
        printf("| %d |->",first->data);
        first=first->next;
    }while(first!=last->next);
    printf("\n");
}

int Count(PNODE first,PNODE last)
{

    if(first==NULL||last==NULL)
    {
        return 0;
    }

    int iCnt=0;


    do
    {
        iCnt++;
        first=first->next;
    }while(first!=last->next);

    return iCnt;
}


void InsertAtPos(PPNODE first,PPNODE last,int no,int pos)
{
    PNODE newn=NULL;
    PNODE temp=NULL;
    int iCnt=0;
    int i=0;

    iCnt=Count(*first,*last);

    if(pos<1 || pos>iCnt+1)
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos==1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos==iCnt+1)
    {
        InsertLast(first,last,no);
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

        (*last)->next = (*first);   
    }
    
}


void DeleteAtPos(PPNODE first,PPNODE last,int pos)
{
    PNODE temp=NULL;
    PNODE container=NULL;
    int iCnt=0;
    int i=0;

    iCnt=Count(*first,*last);

    if(pos<1 || pos>iCnt)
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos==1)
    {
        DeleteFirst(first,last);
    }
    else if(pos==iCnt)
    {
        DeleteLast(first,last);
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
        container->next->prev=temp;
        free(container);

        (*last)->next = (*first);
    }
}

int main()
{
    PNODE head=NULL;
    PNODE tail=NULL;

    InsertFirst(&head,&tail,27);
    InsertFirst(&head,&tail,93);
    InsertLast(&head,&tail,84);
    InsertLast(&head,&tail,25);
    InsertLast(&head,&tail,35);
    InsertAtPos(&head,&tail,31,4);
    DeleteFirst(&head,&tail);
    DeleteLast(&head,&tail);
    DeleteAtPos(&head,&tail,2);
    Display(head,tail);
    printf("Total number of nodes are : %d\n",Count(head,tail));

    return 0;
}