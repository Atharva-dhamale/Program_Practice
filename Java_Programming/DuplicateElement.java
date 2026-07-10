import java.util.Scanner;
class DuplicateElement
{
    static void DuplicateElements(int Arr[])
    {
       
       System.out.println("\nThe duplicate elements are : ");
       for(int i=0;i<Arr.length;i++)
       {
           for(int j=i+1;j<Arr.length;j++)
           {
               if(Arr[i]==Arr[j])
               {
                   System.out.println(Arr[i]);
               }
           }
       }
       
    }
    public static void main(String A[])
    {
        int Arr[]=new int[10];
        Scanner sobj=new Scanner(System.in);
        
        System.out.println("Enter the elements in Array");
        for(int iCnt=0;iCnt<Arr.length;iCnt++)
        {
            Arr[iCnt]=sobj.nextInt();
        }
        
        DuplicateElements(Arr);
    }
}