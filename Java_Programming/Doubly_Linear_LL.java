
class node
{
    public int data;
    public node next;
    public node prev;

    public node(int no)
    {
        this.data=no;
        this.next=null;
        this.prev=null;
    }

}

class DoublyLL
{
    private node first;
    private int iCount;

    public DoublyLL()
    {
        System.out.println("Object of Doubly CL is created");
        this.first=null;
        this.iCount=0;
    }

    public void InsertFirst(int no)
    {
        node newn=null;
        newn=new node(no);

        if(this.first==null)
        {
            this.first=newn;
        }
        else
        {
            newn.next=this.first;
            this.first.prev=newn;
            this.first=newn;
        }
        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node temp=null;
        node newn=null;
        newn=new node(no);

        if(this.first==null)
        {
            this.first=newn;
        }
        else
        {
            temp=this.first;

            while(temp.next!=null)
            {
                temp=temp.next;
            }
            temp.next=newn;
            newn.prev=temp;
        }
        this.iCount++;
    }

    public void InsertAtPos(int no,int pos)
    {
        node newn=null;
        newn=new node(no);
        node temp=null;
        int iCnt=0;

        if((pos<1)||(pos>iCount+1))
        {
            System.out.println("Invalid position");
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
            temp.next.prev=newn;
            temp.next=newn;

            this.iCount++;
        }
    }

    public void DeleteFirst()
    {
        if(this.first==null)
        {
            System.out.println("Linked list is empty");
            return;
        }
        else if(this.first.next==null)
        {
            this.first=null;
        }
        else
        {
            this.first=this.first.next;

        }

        System.gc();
        this.iCount--;
    }

    public void DeleteLast()
    {
        node temp=null;

        if(this.first==null)
        {
            System.out.println("Linked list is empty");
            return;
        }
        else if(this.first.next==null)
        {
            this.first=null;
        }
        else
        {
            temp=this.first;

            while(temp.next.next!=null)
            {
                temp=temp.next;
            }
            temp.next=null;
            
        }

        System.gc();
        this.iCount--;
    }

    public void DeleteAtPos(int pos)
    {
        node temp=null;
        int iCnt=0;

        if((pos<1)||(pos>iCount))
        {
            System.out.println("Invalid position");
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
            this.iCount--;
        }  
    }

    public void Display()
    {
        node temp=null;
        

        temp=this.first;

        while(temp!=null)
        {
            System.out.print("| "+temp.data+"|<=>");
            temp=temp.next;
        }
        System.out.println("null");

    }

    public int Count()
    {
        return this.iCount;
    }

}

class Doubly_Linear_LL
{
    public static void main(String Arr[])
    {
        DoublyLL obj=new DoublyLL();
        int iRet=0;

        obj.InsertFirst(84);
        obj.InsertFirst(27);
        obj.InsertFirst(93);

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of nodes in linkedlist are: "+iRet);
        System.out.println();

        obj.InsertLast(31);
        obj.InsertLast(25);
        obj.InsertLast(35);

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of nodes in linkedlist are: "+iRet);
        System.out.println();

        obj.DeleteFirst();

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of nodes in linkedlist are: "+iRet);
        System.out.println();

        obj.DeleteLast();

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of nodes in linkedlist are: "+iRet);
        System.out.println();

        obj.InsertAtPos(43,2);

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of nodes in linkedlist are: "+iRet);
        System.out.println();

        obj.DeleteAtPos(3);

        obj.Display();
        iRet=obj.Count();
        System.out.println("Number of nodes in linkedlist are: "+iRet);
        System.out.println();
    }
}
