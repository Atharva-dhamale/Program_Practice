#include<iostream>
using namespace std;



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
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }

            
        }
        cout<<"\n";
    }

    printf("\n");
    
    for(i=1;i<=Rows;i++)
    {
        for(j=1;j<=Cols;j++)
        {
            if(i==(Rows/2))
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }

            
        }
        cout<<"\n";
    }

    
    for(i=1;i<=Rows;i++)
    {
        for(j=1;j<=Cols;j++)
        {
            if(i==j || j==Rows-i+1)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<"\n";
    }

    cout<<"\n";
    cout<<"\n";

    for(i=1;i<=Rows;i++)
    {
        for(j=1;j<=Cols;j++)
        {
            if(i+j==Rows+1)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }

            
        }
        cout<<"\n";
    }
}

int main()
{
    int Rows=0;
    int Cols=0;

    cout<<"Enter number of rows : ";
    cin>>Rows;
    cout<<"Enter number of columns : ";
    cin>>Cols;

    Arithmetic_Pattern(Rows,Cols);

    return 0;
}