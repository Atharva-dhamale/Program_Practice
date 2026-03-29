import java.util.Scanner;

class Prime
{

    public static boolean ChkPrime(int No)
    {
        int iCnt=0;
        boolean bFlag=true;

        for(iCnt=2;iCnt<=No/2;iCnt++)
        {
            if((No%iCnt)==0)
            {
                bFlag=false;
            }
        }

        return bFlag;
    }

    public static void main(String A[])
    {
        int No=0;
        boolean bRet=false; 
        Scanner sobj=new Scanner(System.in);

        System.out.println("Enter the number : ");
        No=sobj.nextInt();

        bRet=ChkPrime(No);

        if(bRet)
        {
            System.out.println(No+" is prime number");
        }
        else
        {
            System.out.println(No+" is not prime number");
        }
        
        sobj.close();
    }
}