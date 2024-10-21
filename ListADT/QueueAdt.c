//list
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*front=NULL, *rear = NULL;

void Enqueue(int val)
{
    struct node *nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn -> data = val;
    nn -> next = NULL;
    if(front==NULL)
    {
        front = rear = nn;
    }
    else
    {
        rear -> next = nn;
        rear = nn;
    }
    printf("\nInsertion successfull");
}

void Dequeue()
{
    if(front == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *tmp = front;
        front = front -> next;
        printf("Dequeue Element =%d\n",tmp->data);
        free(tmp);
    }
}

void display()
{
    if(front == NULL)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        struct node *tmp = front;
        while(tmp-> next != NULL)
        {
            printf("%d-->",tmp->data);
            tmp = tmp -> next;
        }
        printf("%d-->NULL",tmp->data);
    }
}

void main()
{
    int choice,val;
    do
    {
        printf("\n***Main Menu***");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to be Enqueued:");
                scanf("%d",&val);
                Enqueue(val);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exited!!");
                break;
            default:
                printf("Invalid choice");
                break;
        }
    }while(choice!=4);
}