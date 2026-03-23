class node
{
    public int data;
    public node next;

    public node(int no)
    {
        this.data=no;
        this.next=null;
    }
}

class SinglyCL
{
    private node first;
    private node last;
    private int iCount;

    public SinglyCL()
    {
        System.out.println("Object of Singly Circular is created");
        this.first=null;
        this.last=null;
        this.iCount=0;
    }


    void InsertFirst(int no)
    {
        node newn=null;
        newn=new node(no);

        if((this.first==null)&&(this.last==null))
        {
            this.first=newn;
            this.last=newn;
        }
        else
        {
            newn.next=this.first;
            this.first=newn;
        }
        this.last.next=this.first;
        this.iCount++;
    }

    void InsertLast(int no)
    {
        node newn=null;
        newn=new node(no);
        

        if((this.first==null)&&(this.last==null))
        {
            this.first=newn;
            this.last=newn;
        }
        else if(this.first==this.last)
        {
            this.first.next=newn;
            this.last=newn;
        }

        else
        {
            this.last.next=newn;
            this.last=newn;
        }
        this.last.next=this.first;
        this.iCount++;
    }

    void DeleteFirst()
    {
        if((this.first==null)&&(this.last==null))
        {
            System.out.println("Linked list is empty");
            return;
        }
        else if(this.first==this.last)
        {
            this.first=null;
            this.last=null;
        }
        else
        {
            this.first=this.first.next;
        }
        System.gc();
        this.last.next=this.first;
        this.iCount--;

    }

    void DeleteLast()
    {
        node temp=null;

        if((this.first==null)&&(this.last==null))
        {
            System.out.println("Linked list is empty");
            return;
        }
        else if(this.first==this.last)
        {
            this.first=null;
            this.last=null;
        }
        else
        {
            temp=this.first;

            while(temp.next!=last)
            {
                temp=temp.next;
            }
            this.last=temp;
            temp.next=null;

        }
        System.gc();
        this.last.next=this.first;
        this.iCount--;
    }

    void Display()
    {
        node temp=null;

        temp=this.first;

        do
        {
            System.out.print("| "+temp.data+"|->");
            temp=temp.next;
        }while(temp!=this.first);
        System.out.println();
    }

    int Count()
    {
        return iCount;
    }

    void InsertAtPos(int no,int pos)
    {
        node newn=null;
        newn=new node(no);
        node temp=null;
        int iCnt=0;

        if((pos<1)||(pos>iCount+1))
        {
            System.out.println("Inavlid position");
            return;
        }
        if(pos==1)
        {
            this.InsertFirst(no);
        }
        else if(pos==iCount+1)
        {
            this.InsertLast(no);
        }
        else
        {
            temp=this.first;

            for(iCnt=1;iCnt<pos-1;iCnt++)
            {
                temp=temp.next;
            }
            newn.next=temp.next;
            temp.next=newn;

            this.last.next=this.first;
            this.iCount++; 
        }
    }

    void DeleteAtPos(int pos)
    {
        int iCnt=0;
        node temp=null;

        if((pos<1)||(pos>iCount))
        {
            System.out.println("Inavlid position");
            return;
        }
        if(pos==1)
        {
            this.DeleteFirst();
        }
        else if(pos==iCount)
        {
            this.DeleteLast();
        }
        else
        {
            temp=this.first;

            for(iCnt=1;iCnt<pos-1;iCnt++)
            {
                temp=temp.next;
            }
            temp.next=temp.next.next;

            System.gc();
            this.last.next=this.first;
            this.iCount--; 
        }
    }

}

class Singly_Circular_LL
{
    public static void main(String A[])
    {
        SinglyCL obj=new SinglyCL();
        int iRet=0;


        obj.InsertFirst(84);
        obj.InsertFirst(27);
        obj.InsertFirst(93);

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of nodes are :"+iRet+"\n");

        obj.InsertLast(31);
        obj.InsertLast(25);
        obj.InsertLast(35);

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of nodes are :"+iRet+"\n");

        obj.DeleteFirst();

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of nodes are :"+iRet+"\n");

        obj.DeleteLast();

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of nodes are :"+iRet+"\n");

        obj.InsertAtPos(13,3);

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of nodes are :"+iRet+"\n");

        obj.DeleteAtPos(4);

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of nodes are :"+iRet+"\n");

        
    }
}