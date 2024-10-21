#include<stdio.h>
int val;
int front = 0;
int rear = -1;
int size = 5;
int que[5];
int choice;

int isquefull()
{
    if(rear == (size-1))
        return 1;
    else
        return 0;
}

int isqueempty()
{
    if(rear<=0 || front> rear)
        return 1;
    else
        return 0;
}

void enqueue(int val)
{
    if(isquefull())
    {
        printf("Queue is Full, Cannot Enqueue");
    }
    else
    {
        rear ++;
        que[rear] = val;
    }
}

int dequeue()
{
    if(isqueempty())
    {
        printf("Queue is Empty, Cannot Dequeue");
        return -1;
    }
    else
    {
        val = que[front];
        front ++;
        return val;
    }
}

void display()
{
    if(isqueempty())
    {
        printf("Queue is Empty");
    }
    else
    {
        for(int i=front; i<=rear; i++)
        {
            val = que[i];
            printf("%d\n", val);
        }
    }
}

int main()
{
    do
    {
        printf("\n***Main Menu***");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to be Enqeueued:");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                val = dequeue();
                if(val!=-1)
                {
                    printf("Dequeued val =%d\n",val);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exited!!");
                break;
            default:
                printf("Invalid choice!!");
        }
    }while(choice!=4);
}