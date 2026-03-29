import java.util.Scanner;

class Palindrome
{

    public static boolean ChkPalindrome(int No)
    {
        int iDigit=0;
        int Rev=0;
        int Num=0;

        Num=No;

        while(No!=0)
        {
            iDigit=No%10;
            Rev=Rev*10+iDigit;
            No=No/10;
        }

        return Rev==Num;
    }

    public static void main(String A[])
    {
        int No=0;
        boolean bRet=false;
        Scanner sobj=new Scanner(System.in);

        System.out.println("Enter the number : ");
        No=sobj.nextInt();

        bRet=ChkPalindrome(No);

        if(bRet)
        {
            System.out.println(No+" is palindrome number");
        }
        else
        {
            System.out.println(No+" is not a palindrome number");
        }

        sobj.close();
        
    }
}