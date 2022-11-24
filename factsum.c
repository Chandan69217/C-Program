#include"stdio.h"

int main()
{
    int n,i,j;
    static int s; 

    printf("\nHow Many Terms:-");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {   int p=1;
        for(j=i;j>1;j--)
        {
            p = p*j;
        }
        s=s+p;
    }
    printf("\nSum of Series:-%d",s);
    return(0);
}