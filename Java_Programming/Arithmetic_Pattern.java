import java.util.Scanner;

class Arithmetic_Pattern
{
    public void Arithmetic_Pattern(int Rows,int Cols)
    {
        int i=0;
        int j=0;

        if(Rows!=Cols)
        {
            System.out.println("Invalid number of rows or columns");
            return;
        }

        for(i=1;i<=Rows;i++)
        {
            for(j=1;j<=Cols;j++)
            {
                if((i==(Cols/2)+1) ||((j==(Rows/2)+1)))
                {
                    System.out.print("*");
                }
                else
                {
                    System.out.print(" ");
                }

                
            }
            System.out.println("");
        }

        System.out.println("");
        
        for(i=1;i<=Rows;i++)
        {
            for(j=1;j<=Cols;j++)
            {
                if(i==(Rows/2))
                {
                    System.out.print("*");
                }
                else
                {
                    System.out.print(" ");
                }

                
            }
            System.out.println("");
        }

        
        for(i=1;i<=Rows;i++)
        {
            for(j=1;j<=Cols;j++)
            {
                if(i==j || j==Rows-i+1)
                {
                    System.out.print("*");
                }
                else
                {
                    System.out.print(" ");
                }
            }
            System.out.println("");
        }

        System.out.println("");
        System.out.println("");

        for(i=1;i<=Rows;i++)
        {
            for(j=1;j<=Cols;j++)
            {
                if(i+j==Rows+1)
                {
                    System.out.print("*");
                }
                else
                {
                    System.out.print(" ");
                }

                
            }
            System.out.println("");
        }
    }

    public static void main(String A[])
    {
        int Rows=0;
        int Cols=0;

        Scanner sobj=new Scanner(System.in);

        System.out.println("Enter number of rows : ");
        Rows=sobj.nextInt();
        System.out.println("Enter number of columns : ");
        Cols=sobj.nextInt();
        Arithmetic_Pattern aobj=new Arithmetic_Pattern();

        aobj.Arithmetic_Pattern(Rows,Cols);

    }
}
