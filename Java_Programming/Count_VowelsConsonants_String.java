import java.util.Scanner;

class Count_VowelsConsonants_String
{

    public static void CountVowelsConsonants(String str)
    {
        int i=0;
        int vCount=0;
        int cCount=0;
        char ch;

        for(i=0;i<str.length();i++)
        {
            ch = Character.toLowerCase(str.charAt(i));

            if(ch >= 'a' && ch <= 'z')
            {
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                {
                    vCount++;
                }
                else
                {
                    cCount++;
                }
            }
        }

        System.out.println("Count of vowels is : "+vCount);
        System.out.println("Count of consonants is : "+cCount);

    }
    public static void main(String A[])
    {
        String str="";
        Scanner sobj=new Scanner(System.in);

        System.out.println("Enter the String : ");
        str=sobj.nextLine();

        CountVowelsConsonants(str);

        sobj.close();

    }
}