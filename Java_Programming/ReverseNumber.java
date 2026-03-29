import java.util.Scanner;

class ReverseNumber
{

    public static int ReverseNumber(int No)
    {
        int iDigit=0;
        int Rev=0;

        while(No!=0)
        {
            iDigit=No%10;
            Rev=Rev*10+iDigit;
            No=No/10;
        }

        return Rev;
    }

    public static void main(String A[])
    {
        int No=0;
        Scanner sobj=new Scanner(System.in);

        System.out.println("Enter the number : ");
        No=sobj.nextInt();

        System.out.println("Before reverse the number is : "+No);

        System.out.println("After reverse the number is : "+ReverseNumber(No));

        sobj.close();
        
    }
}