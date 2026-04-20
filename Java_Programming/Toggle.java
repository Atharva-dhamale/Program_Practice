class Toggle
{
    public static void main(String A[])
    {
        char Arr[]={'a','b','c','d','e','f'};
        char temp='\0';

        for(int i=0;i<Arr.length;i+=2)
        {
            temp=Arr[i];
            Arr[i]=Arr[i+1];
            Arr[i+1]=temp;
        }
        System.out.println(Arr);
    }
}