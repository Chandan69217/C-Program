#include<stdio.h>

int main()
{
    unsigned short n,i;
    printf("\nEnter no to Find Square root:-");
    scanf("%u",&n);

    for(i=1;i<=n/2;i++)
    {
        if((i*i)==n)
        {
            printf("\nYour Answer:-%u",i);
            break;
        }
    }
    return(0);
}