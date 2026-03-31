import java.util.Scanner;

class Array_DisplayReverse
{
    public static void ReverseDisplay(int Arr[])
    {
        int i=0;
        
        System.out.print("Reverse Display : ");
        for(i=Arr.length-1;i>=0;i--)
        {
            System.out.print(Arr[i]+" ");
        }
        System.out.println();
    }
    public static void main(String A[])
    {
        Scanner sobj=new Scanner(System.in);

        int No=0;
        int i=0;
        System.out.print("Enter number of elemnts : ");
        No=sobj.nextInt();

        int Arr[]=new int[No];

        System.out.println("Enter the "+No+" element : ");

        for(i=0;i<No;i++)
        {
            Arr[i]=sobj.nextInt();

            if(Arr[i]<0)
            {
                System.out.println("Input must be non negative");
                return;
            }
        }

        System.out.print("Original Array : ");

        for(int value:Arr)
        {
            System.out.print(value+" ");
        }
        System.out.println();

        ReverseDisplay(Arr);

        sobj.close();
    }
}