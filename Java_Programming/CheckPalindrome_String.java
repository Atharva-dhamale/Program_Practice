import java.util.Scanner;

class CheckPalindrome_String
{

    public static Boolean CheckPalindrome(String str)
    {
        int i=0;
        String s="";

        for(i=str.length()-1;i>=0;i--)
        {
            s=s+str.charAt(i);
        }

        return str.equals(s);
    }
    public static void main(String A[])
    {
        String str="";
        Boolean bRet=false;

        Scanner sobj=new Scanner(System.in);

        System.out.println("Enter the String : ");
        str=sobj.nextLine();

        bRet=CheckPalindrome(str);
        
        if(bRet)
        {
            System.out.println("String is Palindrome");
        }
        else
        {
            System.out.println("String is not Palindrome");
        }

        sobj.close();

    }
}