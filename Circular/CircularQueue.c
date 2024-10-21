#include<stdio.h>
#define max 6
int queue[max];
int front = -1;
int rear = -1;
int val;
int choice;

void enqueue(int val)
{
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = val;
    }
    else if((rear+1)%max == front)
    {
        printf("Queue is overflow");
    }
    else
    {
        rear = (rear+1)%max;
        queue[rear] = val;
    }
}

int dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is Empty");
        return -1;
    }
    else if(front == rear)
    {
        printf("Dequeued Element = %d\n",queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Deqeued Element = %d\n", queue[front]);
        front = (front+1)%max;
    }
}

void display()
{
    int i = front;
    if(front=-1 && rear ==-1)    
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("\n Elements are:\n");
        while(i<=rear)
        {
            printf("%d\n",queue[i]);
            i=(i+1)%max;
        }
    }
}

int main()
{
    do
    {
        printf("\n***Main Menu***");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter Value to be Enqueued:");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exited!!");
                break;
            default:
                printf("Invalid Choice!!!");
                break;
        }
    }while(choice!=4);
}