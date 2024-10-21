//list
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*top = NULL;

void push(int val)
{
    struct node *nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn -> data = val;
    if(top == NULL)
    {
        nn -> next = NULL;
    }
    else
    {
        nn -> next = top;
    }
    top = nn;
    printf("\nInsertion Succesfull");
}

void pop()
{
    if(top == NULL)
        printf("Stack is Empty\n");
    else
    {
        struct node *tmp = top;
        printf("Deleted ELement:%d",tmp -> data);
        top = tmp -> next;
        free(tmp);
    }
}

void display()
{
    if(top == NULL)
        printf("Stack is Empty\n");
    else
    {
        struct node *tmp = top;
        while(tmp->next != NULL)
        {
            printf("%d-->",tmp -> data);
            tmp = tmp -> next;
        }
        printf("%d-->NULL",tmp ->data);
    }
}

int main()
{
    int choice, val;
    do
    {
        printf("\n***Main Menu***");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter Value to push into the stack:");
                scanf("%d",&val);
                push(val);
                break;
            case 2:
                pop();
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