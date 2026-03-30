import java.util.Scanner;

class Count_EvenOdd_Digits
{

    public static void CountEvenOddDigits(int No)
    {
        int iCntEven=0;
        int iCntOdd=0;
        int iDigit=0;

        if(No<0)
        {
            System.out.println("Please enter valid input");
            return;
        }

        while(No!=0)
        {
            iDigit=No%10;

            if(iDigit%2==0)
            {
                iCntEven++;
            }
            else
            {
                iCntOdd++;
            }
            No=No/10;
        }

        System.out.println("Count of Even digits are : "+iCntEven);
        System.out.println("Count of Odd digits are : "+iCntOdd);

    }
    public static void main(String A[])
    {
        Scanner sobj=new Scanner(System.in);

        int No=0;
        System.out.println("Enter the number : ");
        No=sobj.nextInt();

        CountEvenOddDigits(No);

        sobj.close();
    }
}