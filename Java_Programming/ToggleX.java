class ToggleX
{
    public static void main(String A[])
    {
        char Arr[]={'a','b','c','d','e','f'};
        char temp='\0';

        for(int i=0;i<Arr.length;i+=3)
        {
            temp=Arr[i];
            Arr[i]=Arr[i+2];
            Arr[i+2]=temp;
        }
        System.out.println(Arr);
    }
}