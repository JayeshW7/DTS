#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start = NULL, *last;

void create_dll(int val)
{
    struct node *nn, *tn;
    nn = malloc(sizeof(struct node));
    nn -> data = val;
    nn -> next = NULL;
    
    if(start == NULL)
    {
        start = nn;
        nn -> prev = NULL;
    }
    else
    {
        tn = start;
        while(tn -> next!=NULL)
        {
            tn = tn -> next;
        }
        tn -> next = nn;
        nn -> prev = tn;
    }
    last = nn;
}

void insbeg(int val)
{
    struct node *nn;
    nn = malloc(sizeof(struct node));
    nn -> data = val;
    nn -> next = start;
    nn -> prev = NULL;
    start -> prev = nn;
    start = nn;
}

void displayforward()
{
    struct node *tn;
    if(start == NULL)
    {
        printf("EMpty\n");
        return;
    }
    tn = start;
    while(tn != NULL)
    {
        printf("%d\n",tn->data);
        tn = tn -> next;
    }
}

void displayreversed()
{
    struct node *tn;
    if(start == NULL)
    {
        printf("Empty\n");
    }
    tn = last;
    while(tn != NULL)
    {
        printf("%d\n",tn->data);
        tn = tn-> prev;
    }
}


int main()
{
    int val, choice;
    do
    {
        printf("\n***Main Menu***");
        printf("\n1.Create Doubly Linked List\n2.Insert At beginning\n3.Display Data in Forward Direction\n4.Display Data in Backward Direction\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter Value to store in Doubly Linked List:");
                scanf("%d",&val);
                create_dll(val);
                break;
            case 2:
                printf("Enter value to insert at the beginning:");
                scanf("%d",&val);
                insbeg(val);
                break;
            case 3:
                displayforward();
                break;
            case 4:
                displayreversed();
                break;
            case 5:
                printf("Exited!!");
                break;
            default:
                printf("Invalid Choice!!");
                break;
        }
    }while(choice!=5);
}