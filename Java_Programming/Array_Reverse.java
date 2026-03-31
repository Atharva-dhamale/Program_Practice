import java.util.Scanner;

class Array_Reverse
{
    public static int[] ReverseArray(int Arr[])
    {
        int i=0;
        int start=0;
        int end=0;
        int temp=0;

        end=Arr.length-1;

        while(start<end)
        {
            temp=Arr[start];
            Arr[start]=Arr[end];
            Arr[end]=temp;

            start++;
            end--;
        }

        return Arr;
    }
    public static void main(String A[])
    {
        Scanner sobj=new Scanner(System.in);

        int No=0;
        int i=0;
        int iRet[]=new int[0];
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


        System.out.print("Reverse Array : ");
        iRet=ReverseArray(Arr);
        for(int value:iRet)
        {
            System.out.print(value+" ");
        }
        System.out.println();

        sobj.close();
    }
}