import java.util.Scanner;

class Sum_EvenDigits
{

    public static int SumEvenDigits(int No)
    {
        int SumEven=0;
        int iDigit=0;

        if(No<0)
        {
            System.out.println("Please enter valid input");
            return -1;
        }

        while(No!=0)
        {
            iDigit=No%10;

            if(iDigit%2==0)
            {
                SumEven=SumEven+iDigit;
            }
            
            No=No/10;
        }

        return SumEven;

    }
    public static void main(String A[])
    {
        Scanner sobj=new Scanner(System.in);

        int No=0;
        int iRet=0;

        System.out.println("Enter the number : ");
        No=sobj.nextInt();

        iRet=SumEvenDigits(No);

        if(iRet==-1)
        {
            System.out.println("Invalid input");
        }
        else
        {
            System.out.println("Sum of Even digits is :"+iRet);
        }

        sobj.close();
    }
}