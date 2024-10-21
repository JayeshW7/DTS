#include<stdio.h>

int STK[5];
int size = 5;
int top = -1;
int choice;
int val;

int isstkfull()
{
    if(top == size-1)
        return 1;
    else 
        return 0;
}

int isstkempty()
{
    if(top==-1)
        return 1;
    else    
        return 0;
}

void push(int val)
{
    if(isstkfull())
    {
        printf("Stack is full cannot Push");
    }
    else
    {
        top++;
        STK[top] = val;
        printf("Value pushed into stack %d",val);
    }
}

int pop()
{
    if(isstkempty())
    {
        printf("Stack is Empty Cannot pop");
        return -1;
    }
    else
    {
        val = STK[top];
        top --;
        return val;
    }   
}

void display()
{
    if(isstkempty())
    {
        printf("Stack is empty, No content to display!");
    }
    else
    {
        printf("Stack Elements are:");
        for(int i=top; i>=0; i--)
        {
            printf("%d ",STK[i]);
        }
    }
}

int main()
{
    do
    {
        printf("\n***MAIN MENU***\n");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to be pushed into stack:\n");
                scanf("%d",&val);
                push(val);
                break;
            case 2:
                val = pop();
                if(val!=-1){
                    printf("Poped Value= %d\n",val);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exited!!");
                break;
            default:
                printf("Invalid Choice!!");
                break;
        }
    }while(choice!=4);
}