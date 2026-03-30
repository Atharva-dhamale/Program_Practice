import java.util.Scanner;

class Replace_Digit
{

    public static int ReplaceDigit(int No)
    {
        int iDigit=0;
        int Number=0;
        int iMult=1;

        if(No<0)
        {
            return -1;
        }

        while(No!=0)
        {
            iDigit=No%10;
            
            if(iDigit==0)
            {
                iDigit=1;
            }
            
            Number=Number+(iDigit*iMult);
            iMult=iMult*10;

            No=No/10;
        }

        return Number;

    }
    public static void main(String A[])
    {
        Scanner sobj=new Scanner(System.in);

        int No=0;
        int iRet=0;

        System.out.println("Enter the number : ");
        No=sobj.nextInt();

        iRet=ReplaceDigit(No);

        if(iRet==-1)
        {
            System.out.println("Invalid input");
        }
        else
        {
            System.out.println(iRet);
        }

        sobj.close();
    }
}