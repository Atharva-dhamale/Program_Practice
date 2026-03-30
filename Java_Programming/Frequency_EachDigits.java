import java.util.Scanner;

class Frequency_EachDigits
{

    public static void FrequencyEachDigits(int No)
    {
        int Arr[]=new int[10];
        int iDigit=0;
        int iCnt=0;

        if(No<0)
        {
            System.out.println("Please enter valid input");
            return;
        }

        while(No!=0)
        {
            iDigit=No%10;
            Arr[iDigit]++;
            No=No/10;
        }

        for(iCnt=0;iCnt<10;iCnt++)
        {
            if(Arr[iCnt]!=0)
            {
                System.out.println("Frequency of digit "+iCnt+" is : "+Arr[iCnt]);
            }
        }

    }
    public static void main(String A[])
    {
        Scanner sobj=new Scanner(System.in);

        int No=0;
        System.out.println("Enter the number : ");
        No=sobj.nextInt();

        FrequencyEachDigits(No);

        sobj.close();
    }
}