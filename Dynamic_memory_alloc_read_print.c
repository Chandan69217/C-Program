#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"malloc.h"

struct node
{
    int info;
    node *next;
};
node *start = NULL;

void insert()
{
    node *t,*cur;
    t = (node *)calloc(1,sizeof(node));
    printf("\nEnter a value:-");
    scanf("%d",&t->info);
    t->next=NULL;
    if(start == NULL)
    { 
        start = t;
    }
    else
    {
    cur = start;
    while(cur->next!=NULL)
    {
        cur = cur->next;
    }
    cur->next = t;
    }
}

void del()
{
    int x;
    node *cur,*prev;
    printf("\nEnter no to Delete:-");
    scanf("%d",&x);
    cur = prev = start;
    while(cur!=NULL)
    {
        if(cur->info==x)
        {
            break;
        }
        prev = cur;
        cur=cur->next;
    }
    if(cur==NULL)
    {
	printf("\n%d is not present",x);
	return;
    }
    if(prev==cur)
    start = cur->next;
    else
    {
	printf("\n%d is Deleted",x);
	prev->next = cur->next;
	free(cur);
    }
}

void search()
{
    node *cur;
    int x;
    printf("\nEnter no to find:-");
    scanf("%d",&x);
    cur=start;
    while(cur!=NULL)
    {
        if(cur->info==x)
        {
            break;
        }
    }
    if(cur==NULL)
    {
        printf("\n%d is not Present",x);
    }
    else
    {
        printf("\n%d is Present",x);
    }
}

void update()
{
    node *cur;
    int x;
    printf("\nEnter no to find:-");
    scanf("%d",&x);
    cur=start;
    while(cur!=NULL)
    {
        if(cur->info==x)
        {
            break;
        }
    }
    if(cur==NULL)
    {
        printf("\n%d is not Present",x);
    }
    else
    {
        printf("\nEnter new value:-");
        scanf("%d",cur->info);
        printf("\n%d is Updated by %d",x,cur->info);
    }
}

void display()
{
    node *cur;
    printf("\nContent of Link List\n");
    cur=start;
    while(cur!=NULL)
    {
       printf("%d  ",cur->info);
       cur = cur->next;
    }
}

void main()
{
    int ch;
  do
  { clrscr();
    printf("\n1.Insert\n2.Display\n3.Delete\n4.Update\n5.Search\n0.Exit");
    printf("\nEnter your choice:-");
    scanf("%d",&ch);
    switch(ch)
    {
        case 0: exit(0);
        case 1: insert(); break;
        case 2: display(); break;
        case 3: del();     break;
        case 4: update(); break;
        case 5: search(); break;
    }
    getch();
  } while (2);
  
}
