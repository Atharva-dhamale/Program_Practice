#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;

    ArrayX(int No);
    ~ArrayX();

    void Accept();
    void Display();

    bool CheckSorted();

    void SelectionSort();
    
};

ArrayX :: ArrayX(int No)
{
    cout<<"Inside Constructor\n";
    iSize=No;
    Arr=new int[iSize];
    Sorted=true;
}
ArrayX :: ~ArrayX()
{
    cout<<"Inside Destructor\n";
    delete []Arr;

}

void ArrayX :: Accept()
{
    int iCnt=0;

    cout<<"Enter the elements :\n";
    cin>>Arr[iCnt];

    for(iCnt=1;iCnt<iSize;iCnt++)
    {
        cin>>Arr[iCnt];

        if(Arr[iCnt-1]>Arr[iCnt])
        {
            Sorted=false;
        }
    }

    //Sorted=CheckSorted();
}
void ArrayX :: Display()
{
    int iCnt=0;

    cout<<"Elements of the array are:\n";
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}



bool ArrayX :: CheckSorted()
{
    int i=0;
    bool bFlag=true;

    for(i=0;i<iSize-1;i++)
    {
        if(Arr[i]>Arr[i+1])
        {
            bFlag=false;
            break;
        }
    }
    return bFlag;
}


// 21 15 18 16 11

void ArrayX :: SelectionSort()
{
    int i=0,j=0;
    int index=0;
    int temp=0;

    if(Sorted==true)            //Important filter
    {
        return;
    }

    for(i=0;i<iSize;i++)          //Outer loop
    {
        index=i;

        for(j=i;j<iSize;j++)
        {
            if(Arr[index]>Arr[j])
            {
                index=j;
            }
        }

        temp=Arr[i];
        Arr[i]=Arr[index];
        Arr[index]=temp;

        cout<<"\nData after Pass : "<<i+1<<"\n";
        Display();
    }
    Sorted=true;
}


int main()
{
    int iValue=0;
    
    cout<<"Enter the number of elements:";
    cin>>iValue;

    ArrayX aobj(iValue);
    aobj.Accept();

    cout<<"Data before sorting\n";
    aobj.Display();

    aobj.SelectionSort();
    cout<<"Data after sorting\n";
    aobj.Display();


    return 0;
}
