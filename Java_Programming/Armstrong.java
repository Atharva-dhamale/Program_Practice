import java.util.Scanner;

class Armstrong
{

    public static boolean ChkArmStrong(int No)
    {
        int Num=0;
        int Frequency=0;
        int iDigit=0;
        int iCnt=0;
        int Result=0;
        int Pow=0;

        Num=No;

        while(No!=0)
        {
            No=No/10;
            Frequency++;
        }

        No=Num;

        while(No!=0)
        {
            iDigit=No%10;
            Pow=1;

            for(iCnt=1;iCnt<=Frequency;iCnt++)
            {
                Pow=Pow*iDigit;
            }

            Result=Result+Pow;

            No=No/10;
        }

        return (Num==Result);
    }

    public static void main(String A[])
    {
        int No=0;
        boolean bRet=false; 
        Scanner sobj=new Scanner(System.in);

        System.out.println("Enter the number : ");
        No=sobj.nextInt();

        bRet=ChkArmStrong(No);

        if(bRet)
        {
            System.out.println(No+" is ArmStrong number");
        }
        else
        {
            System.out.println(No+" is not ArmStrong number");
        }

        sobj.close();
        
    }
}