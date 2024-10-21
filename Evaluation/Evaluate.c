#include<stdio.h>
#include<ctype.h>
int STK[20];
int top = -1;

void push(int val)
{
    STK[++top] = val;
}

int pop()
{
    return STK[top--];
}

int main()
{
    char exp[20];
    char *e;
    int n1,n2,n3,num;
    printf("Enter the expression:");
    scanf("%s",exp);
    e = exp;
    while(*e!='\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
                case '+':
                    n3 = n2 + n1;
                    break;
                case '-':
                    n3 = n2 - n1;
                    break;
                case '*':
                    n3 = n2 * n1;
                    break;
                case '/':
                    n3 = n2 / n1;
                    break;
            }
            push(n3);
        }e++;
    }
    printf("\nResult of Expression %s = %d\n",exp,pop());
    return 0;
}