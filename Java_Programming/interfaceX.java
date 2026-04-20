
interface circle
{
    float pi=3.14f;
    float area(float radius);
    float circumference(float radius);
}
class calculation implements circle
{
    public float area(float radius)
    {
        float ans=pi*radius*radius;
        return ans;
    }
    public float circumference(float radius)
    {
        float ans=2*pi*radius;
        return ans;
    }
}

class interfaceX
{
    public static void main(String A[])
    {
        float fRet=0.0f;

        calculation cobj=new calculation();

        fRet=cobj.area(5.0f);
        System.out.println("Area of circle is : "+fRet);

        fRet=cobj.circumference(7.0f);
        System.out.println("circumference of circle is : "+fRet);
    }
}