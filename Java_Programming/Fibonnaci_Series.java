import java.util.Scanner;

class Fibonnaci_Series
{

    public static void Fibonnaci(int No)
    {
        int a=0;
        int b=1;
        int next=0;

        for(int iCnt=1;iCnt<=No;iCnt++)
        {
            System.out.print(a+" ");
            next=a+b;
            a=b;
            b=next;
        }
        System.out.println();
    }

    public static void main(String A[])
    {
        int No=0;
        Scanner sobj=new Scanner(System.in);

        System.out.println("Enter the number : ");
        No=sobj.nextInt();

        Fibonnaci(No);

        sobj.close();
        
    }
}