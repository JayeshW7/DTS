#include<stdio.h>
#include<string.h>

int size = 10;
int top = -1;
char STK[10];
char val;

int isstkfull()
{
    if(top == (size-1))
        return 1;
    else
        return 0;
}

int isstkempty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(char val)
{
    if (isstkfull())
        printf("Stack is full\n");
    else
        top++;
        STK[top] = val;
}

char pop()
{
    if (isstkempty())
    {
        printf("Stack is empty\n");
    }
    else    
    {
        val = STK[top];
        top --;
    }
    return val;
}   

char stktop()
{
    if (isstkempty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        val = STK[top];
    }
    return val;
}

int pri(char ch)
{
    switch (ch)
    {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return -1;  
    }
}

int main()
{
    char infix[10], postfix[10];
    int len, i, p = 0;
    char ip, pp, next;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    len = strlen(infix);
    
    for (i = 0; i < len; i++)
    {
        ip = infix[i];
        switch (ip)
        {
            case '(': 
                push(ip);
                break;
            case ')': 
                while ((next = pop()) != '(')
                {
                    postfix[p++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (!isstkempty() && pri(ip) <= pri(stktop()))
                {
                    postfix[p++] = pop();
                }
                push(ip);
                break;
            default: 
                postfix[p++] = ip;
                break;
        }
    }

    while (!isstkempty())
    {
        postfix[p++] = pop();
    }

    postfix[p] = '\0';  
    printf("\nPostfix expression: %s\n", postfix);

    return 0;
}
