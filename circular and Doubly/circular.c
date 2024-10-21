#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;


void create_cll(int val)
{
    struct node *nn, *tn;
    nn = malloc(sizeof(struct node));
    nn -> data = val;
    nn -> next = NULL;

    if(start == NULL)
    {
        start = nn;
    }
    else
    {
        tn = start;
        while(tn->next!=start)
        {
            tn = tn -> next;
        }
        tn -> next = nn;
    }
    nn -> next = start;
}

void insbeg(int val)
{
    struct node *nn, *tn;
    nn = malloc(sizeof(struct node));
    nn -> data = val;
    nn -> next = start;
    tn = start;
    while(tn -> next!= start)
    {
        tn = tn -> next;
    }
    tn -> next = nn;
    start = nn;
}

void display()
{
    struct node *tn;
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    tn = start;
    while(tn -> next!= start)
    {
        printf("%d\n",tn->data);
        tn = tn -> next;
    }
    printf("%d\n",tn->data);
}

int main()
{
    int choice, val;
    do
    {
        printf("\n***Main Menu**");
        printf("\n1.Create circular Linked List\n2.Insert at Beginning\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to store in circular Linked list:");
                scanf("%d",&val);
                create_cll(val);
                break;
            case 2:
                printf("Enter Value to insert at beginning:");
                scanf("%d",&val);
                insbeg(val);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exited !!");
                break;
            default:
                printf("Invalid choice!!");
        }
    }while(choice!=4);
}