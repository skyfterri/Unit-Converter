#include <stdio.h>
#include <stdlib.h>

void test_print (float y, float x)
{
     if (x==y)
        {
            printf ("Test Passed. \n");
        }
        else
        {
            printf ("Test Failed. \n");
        }
}
void value_testing (float b, float result, int a)
{
    float x;
    int y=result*100;
            if (b==10 && a==1)
        {
            x=28315;
            test_print(y, x);
        }
            else if (b==10 && a==2)
         {
             x=5000;
             test_print(y, x);
         }
            else if (b==10 && a==3)
         {
             x=-26315;
             test_print(y, x);
         }
            else if (b==10 && a==4)
         {
             x=-44167;
            test_print(y, x);
         }
            else if (b==10 && a==5)
         {
             x=-1222;
             test_print(y, x);
         }
             else if (b==10 && a==6)
         {
             x=26092;
             test_print(y, x);
         }


}

int main()
{
    float result, b;
    int a;
    printf ("Input temperature conversion type. \n");
        printf ("Press 1 for conversion from celsius to kelvin. \n");
        printf ("Press 2 for conversion from celsius to fahrenheit. \n");
        printf ("Press 3 for conversion from kelvin to celsius. \n");
        printf ("Press 4 for conversion from kelvin to fahrenheit. \n");
        printf ("Press 5 for conversion from fahrenheit to celsius. \n");
        printf ("Press 6 for conversion from fahrenheit to kelvin. \n");
        printf ("Press 0 to end. \n");
    while (1)
    {
        printf ("Enter number: \n");
        scanf ("%f",&b);

        printf ("Enter temperature conversion type: \n");
        scanf ("%d",&a);

        switch (a)
        {
            case 0:

            return 0;

            case 1:

                if(b<-273.15)
                {
                    printf ("The lowest possible temperature on the Celsius scale is -273.15 degrees. \n");
                }
                else
                {
                    result=b+273.15;
                    printf("Result= %.2f \n",result);
                }
                break;

            case 2:

            if(b<-273.15)
                {
                    printf ("The lowest possible temperature on the Celsius scale is -273.15 degrees. \n");
                }
                else
                {
                     result= (b*1.8)+32;
                    printf("Result= %.2f \n",result);
                }
                break;

            case 3:

            if(b<0)
                {
                    printf ("The lowest possible temperature on the Kelvin scale is 0 degrees. \n");
                }
                else
                {
                    result=b-273.15;
                    printf("Result= %.2f \n",result);
                }
                break;

            case 4:

            if(b<0)
                {
                    printf ("The lowest possible temperature on the Kelvin scale is 0 degrees. \n");
                }
                else
                {
                     result=((b-273.15)*1.8)+32;
                    printf("Result= %.2f \n",result);
                }
                break;

            case 5:

            if(b<-459.67)
                {
                    printf ("The lowest possible temperature on the Fahrenheit scale is -459.67 degrees. \n");
                }
                else
                {
                     result=(b-32)*5/9;
                    printf("Result= %.2f \n",result);
                }

                break;

            case 6:

            if(b<-459.67)
                {
                    printf ("The lowest possible temperature on the Fahrenheit scale is -459.67 degrees. \n");
                }
                else
                {
                     result=((b-32)*5/9)+273.15;
                    printf("Result= %.2f \n",result);
                }
                break;

            default:

               printf("Invalid input. \n");
        }
        value_testing (b, result, a);
    }

    return 0;
}
