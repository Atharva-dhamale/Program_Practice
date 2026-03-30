import java.util.Scanner;

class Count_Digits
{

    public static int CountDigits(int No)
    {
        int iCnt=0;

        if(No<0)
        {
            return -1;
        }

        while(No!=0)
        {
            iCnt++;
            No=No/10;
        }

        return iCnt;
    }
    public static void main(String A[])
    {
        Scanner sobj=new Scanner(System.in);
        
        int No=0;
        int iRet=0;

        System.out.println("Enter the number : ");
        No=sobj.nextInt();

        iRet=CountDigits(No);

        if(iRet==-1)
        {
            System.out.println("Invalid input");
        }
        else
        {
            System.out.println("Count of digits is :"+iRet);
        }

        sobj.close();
    }
}