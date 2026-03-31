import java.util.Scanner;

class Array_MinMax_Elemnts
{
    public static void MinMax_Elements(int Arr[])
    {
        int i=0;
        int iMin=0;
        int iMax=0;

        iMin=Arr[i];

        for(i=0;i<Arr.length;i++)
        {
            if(Arr[i]>iMax)
            {
                iMax=Arr[i];
            }
            else if(Arr[i]<iMin)
            {
                iMin=Arr[i];
            }
        }

        System.out.println("Minumum element is : "+iMin);
        System.out.println("Maximum element is : "+iMax);
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

        MinMax_Elements(Arr);

        sobj.close();
    }
}