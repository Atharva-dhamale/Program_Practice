import java.util.Scanner;

class Reverse_String
{

    public static String ReverseString(String str)
    {
        int i=0;
        String s="";

        for(i=str.length()-1;i>=0;i--)
        {
            s=s+str.charAt(i);
        }

        return s;
    }
    public static void main(String A[])
    {
        String str="";
        Scanner sobj=new Scanner(System.in);

        System.out.println("Enter the String : ");
        str=sobj.nextLine();

        System.out.println("Reversed String is : "+ReverseString(str));

        sobj.close();

    }
}