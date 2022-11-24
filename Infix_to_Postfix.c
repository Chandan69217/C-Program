#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"string.h"

#define size 10
char info[size];
int top = -1;

void push(char x)
{
    info[++top]=x;
}

char pop()
{
    char x;
    x = info[top--];
    return(x);
}

int check_operand(char x)
{
    if(x == '+'||x == '-'||x == '*'||x == '/'||x == '%'||x =='^')
    {
        return(0);
    }
    else
    return(1);
}

int check_priority(char x)
{
    switch(x)
    {
        case '+':
        case '-':return(1);
        case '*':
        case '/':
        case '%':return(2);
        case '^':return(3);
    }
}

void convert(char infix[],char postfix[])
{
    int l = strlen(infix);
    int i,j=0;
    for(i=0;i<l;i++)
    {
        if(check_operand(infix[i])==1)
        {
            postfix[j++]=infix[i];
        }
        else
        {
            if(top==-1)
            {
                push(infix[i]);
            }
            else
            {
                while(check_priority(info[top])>=check_priority(infix[i])&&top!=-1)
                {
                    postfix[j++]=pop();
                }
                push(infix[i]);
            }
        }
    }
        while(top!=-1)
        {
            postfix[j++]=pop();
        }
        postfix[j]='\0';
}

int main()
{
    char infix[100],postfix[100];
    printf("\nEnter a Infix Expression:-");
    fflush(stdin);
    gets(infix);
    convert(infix,postfix);
    printf("\nInfix Expression:-%s\nPostfix Expression:-%s",infix,postfix);
    return(0);
}