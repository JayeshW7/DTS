#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *start = NULL;

void create_sll(int val)
{
    struct Node *nn, *tn;
    nn = malloc(sizeof(struct Node));
    nn -> data = val;
    nn -> next = NULL;

    if(start ==NULL)
    {
        start = nn;
    }
    else
    {
        tn = start;
        while(tn -> next != NULL){
            tn = tn -> next;
        }
        tn -> next = nn;
    }
}

void insbeg(int val)
{
    struct Node *nn;
    nn = malloc(sizeof(struct Node));
    nn -> data = val;
    nn -> next = start;
    start = nn;
}

void insmid(int val, int snv)
{
    struct Node *nn, *tn;
    tn = start;

    while(tn!= NULL)
    {
        if(tn-> data == snv)
        {
            nn = malloc(sizeof(struct Node));
            nn -> data = val;
            nn -> next = tn -> next;
            tn -> next = nn;
            return;
        }
        tn = tn -> next;
    }
    printf("Search Node value is not present in the Linked List\n");
}

void insend(int val)
{
    struct Node *nn, *tn;
    nn = malloc(sizeof(struct Node));
    nn -> data = val;
    nn -> next = NULL;

    if(start == NULL)
    {
        start = nn;
    }
    else
    {
        tn = start;
        while(tn->next != NULL)
        {
            tn = tn -> next;
        }
        tn -> next = nn;
    }
}

void delbeg()
{
    if(start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        start = start -> next;
    }
}

void delmid(int snv)
{
    struct Node *tn = start;
    if(tn == NULL)
    {
        printf("List is Empty\n");
    }
    while(tn-> next!=NULL)
    {
        if(tn->next->data == snv)
        {
            tn -> next = tn->next->next;
            return;
        }
        tn = tn -> next;
    }
    printf("Value not found in the list\n");
}

void delend()
{
    struct Node *tn = start;
    if(tn==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(tn -> next == NULL)
    {
        start = NULL;
        return;
    }
    while(tn->next->next != NULL)
    {
        tn = tn -> next;
    }
    tn -> next = NULL;
}

void display()
{
    struct Node *tn;
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    tn = start;
    while(tn!= NULL)
    {
        printf("%d\n",tn->data);
        tn = tn -> next;
    }
}


int main()
{
    int choice, val, snv;
    do
    {
        printf("\n***Main Menu***");
        printf("\n1.Create Single Linked List\n2.Insert at Beginning\n3.Insert at Mid\n4.Insert at End\n5.Delete Beginning\n6.Delete at mid\n7.Delete at end\n8.Display\n9.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter Value to store in the Linked List:");
                scanf("%d",&val);
                create_sll(val);
                break;
            case 2:
                printf("Enter Value to insert at beginnning:");
                scanf("%d",&val);
                insbeg(val);
                break;
            case 3:
                printf("Enter Value to insert:");
                scanf("%d",&val);
                printf("After Which Node:");
                scanf("%d",&snv);
                insmid(val, snv);
                break;
            case 4:
                printf("Enter Value to insert at the end:");
                scanf("%d",&val);
                insend(val);
                break;
            case 5:
                delbeg();
                break;
            case 6: 
                printf("Enter value to be deleted from the list:");
                scanf("%d",&snv);
                delmid(snv);
                break;
            case 7:
                delend();
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exited!!");
                break;
            default:
                printf("Invalid Choice!!");
                break;
        }
    }while(choice!=9);
}

