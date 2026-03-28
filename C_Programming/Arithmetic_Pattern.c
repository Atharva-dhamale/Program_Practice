#include<stdio.h>


void Arithmetic_Pattern(int Rows,int Cols)
{
    int i=0;
    int j=0;

    if(Rows!=Cols)
    {
        printf("Invalid number of rows or columns\n");
        return;
    }

    for(i=1;i<=Rows;i++)
    {
        for(j=1;j<=Cols;j++)
        {
            if((i==(Cols/2)+1) ||((j==(Rows/2)+1)))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }

            
        }
        printf("\n");
    }

    printf("\n");
    
    for(i=1;i<=Rows;i++)
    {
        for(j=1;j<=Cols;j++)
        {
            if(i==(Rows/2))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }

            
        }
        printf("\n");
    }

    
    for(i=1;i<=Rows;i++)
    {
        for(j=1;j<=Cols;j++)
        {
            if(i==j || j==Rows-i+1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");

    for(i=1;i<=Rows;i++)
    {
        for(j=1;j<=Cols;j++)
        {
            if(i+j==Rows+1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }

            
        }
        printf("\n");
    }
}

int main()
{
    int Rows=0;
    int Cols=0;

    printf("Enter number of rows : ");
    scanf("%d",&Rows);
    printf("Enter number of columns : ");
    scanf("%d",&Cols);

    Arithmetic_Pattern(Rows,Cols);

    return 0;
}