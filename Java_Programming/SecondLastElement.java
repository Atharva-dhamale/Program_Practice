import java.util.Scanner;
class SecondLastElement
{
    static int SecondLastElement(int Arr[])
    {
       int iNo=0;
       
       for(int i=0;i<Arr.length-1;i++)
       {
         iNo=Arr[i];   
       }
       return iNo;
       
    }
    public static void main(String A[])
    {
        int Arr[]=new int[5];
        Scanner sobj=new Scanner(System.in);
        
        System.out.println("Enter the elements in Array");
        for(int iCnt=0;iCnt<Arr.length;iCnt++)
        {
            Arr[iCnt]=sobj.nextInt();
        }
        
        System.out.println("\nThe Second last Element is : "+SecondLastElement(Arr));
    }
}