#include"stdio.h"
#include"conio.h"
#include"Stdlib.h"

char day[7]={"Sunday","Monday","Tuesday","Wednesday","Thrusday","Friday","Satuarday"};
char month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int Month_code[12]={0,3,3,6,1,4,6,2,5,0,3,5};
int rem_code[4]={6,4,2,0};

struct Date
{ 
    int day,month,year;
};

Date read()
{ Date d;
  printf("\nEnter Date(dd/mm/yy):-");
  scanf("%d/%d/%d",&d.day,&d.month,&d.year);
  return(d);
}


void cal_day( Date d)
{ 
    int sum,y1,y2,r1,r2;
    y1=d.year/100;
    r1=y1%4;
    y2=d.year%100;
    r2=d.year/4
    sum=d.day+moth_code[(d.month-1)]+rem_code[r1]+y2+r2;
    sum=sum%7;
    if(sum==0)
    printf("\n%s",day[sum]);
    else
    printf("\n%s",day[sum+1]);
}
    
void main()
{  Date date1;
   date1= read();
   cal_day(date1);
   getch(); 
}