#include <stdio.h>
#include <stdlib.h>
#define max 10
void insert();
void disp();
void del();
int queue[max];
int rear = -1;
int front = -1;
main()
{
    int choice;
    while (1)
    {
        printf("1=insert\n");
        printf("2=delete\n");
        printf("3=display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            disp();
            break;
        default:
            printf("invalid choice");
        }
    }
}
void insert()
{
    int add_item;
    if (rear == max - 1)
        printf("queue overflow \n");
    else
    {
        if (front == -1)
            front = 0;
        printf("insert the element");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue[rear] = add_item;
    }
}
void del()
{
    if (front == -1 || front > rear)
    {
        printf("queue underflow");
    }
    else
    {
        printf("deleted %d\n", queue[front]);
        front = front + 1;
    }
}
void disp()
{
    int i;
    if (front == -1)
        printf("queue empty");
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d \n", queue[i]);
    }
}