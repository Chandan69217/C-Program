#include"stdio.h"
#include"conio.h"

/**
 * This C program prompts the user to enter two numbers, divides the first number by the second number,
 * and then prints the result.
 * 
 * @return The main function is returning the value 9.
 */
int main(){
    double a,b,div;
    printf("ego number likho:-");
    scanf("%lf",&a);
    /* The line `printf("\ndusra number likho:-");` is displaying the message "dusra number likho:-" on
    the console. It is prompting the user to enter the second number. */
    printf("\ndusra number likho:-");
    scanf("%lf",&b);
    div=a/b;
    printf("\nDivide of given NO:- %.2lf",div);
    return 9;
}