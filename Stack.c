#include"stdio.h"
#include"conio.h"
#include"stdlib.h"

#define size 7
int info[size];
int top=-1;

void push()
{ if(top==size-1)
  {printf("\nStack is Full");
   return;
  }
  printf("\nEnter a no:-");
  scanf("%d",&info[++top]);
}


void pop()
{
  if(top==-1)
  { printf("\nStack is Empty");
    return;
  }
  printf("\nPoped no:-%d",info[top]);
  top--;
}

void peep()
{   int i;
    if(top==-1)
    { printf("\nStact is Empty");
      return;
    }
    printf("\nContent of Stack\n");
    for(i=top;i>=0;i--)
    { printf("%d  ",info[i]);
    }    
}



void rev_peep()
{   int i;
    if(top==-1)
    { printf("\nStact is Empty");
      return;
    }
    printf("\nContent of Stack Reversly\n");
    for(i=0;i<=top;i++)
    { printf("%d  ",info[i]);
    }    
}

void main()
{ 
    int ch;
do
{
  printf("\n1.Push\n2.Pop\n3.Peep\n4.Reverse Peep\n0.Exit");
  printf("\nEnter Your Choice:-");
  scanf("%d",&ch);
switch(ch)
{ 
    case 0: exit(0);
    case 1: push(); break;
    case 2: pop(); break;
    case 3: peep(); break;
    case 4: rev_peep(); break;
} 
} while (2);

}