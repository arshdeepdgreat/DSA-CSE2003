#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

struct node
{
    int id, age;
    char name[20];
    struct node *next;
};
struct node *start = NULL;

void insert()
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    printf("\nID: ");
    scanf("%d", &t->id);
    printf("Name: ");
    scanf("%s", t->name);
    printf("Age: ");
    scanf("%d", &t->age);
    count++;
    if (start == NULL)
    {
        start = t;
        start->next = NULL;
    }
    else
    {
        t->next = start;
        start = t;
    }
}

void display()
{
    struct node *t = start;
    if (t == NULL)
        printf("The list is empty\n");
    while (t != NULL)
    {
        printf("ID: %d\tName: %s\tAge: %d\n", t->id, t->name, t->age);
        t = t->next;
    }
}

void del()
{
    int id;
    printf("Enter the ID to delete: ");
    scanf("%d", &id);
    struct node *t = start, *p = NULL;
    int found = 0;
    while (t != NULL)
    {
        if (t->id == id)
        {
            printf("ID found\n");
            if (p == NULL)
                start = NULL;
            else
                p->next = t->next;
            found = 1;
            printf("Element Deleted\n");
            break;
        }
        p = t;
        t = t->next;
    }
    if (found == 0)
        printf("Element not Found\n");
    display();
}

int main()
{
    while (1 == 1)
    {
        printf("1. Insert\n2. Delete by ID\n3. Display\n0. End\n");
        int a;
        scanf("%d", &a);
        switch (a)
        {
        case 1:
        {
            insert();
            break;
        }

        case 2:
        {
            del();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 0:
        {
            exit(0);
        }
        default:
            printf("Invalid Input\n");
        }
    }
    return 0;
}
