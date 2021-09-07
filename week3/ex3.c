#include<stdlib.h>
#include<stdio.h>

typedef struct
{
    int data;
    struct newNode *next;
} newNode;

void print_list(newNode *start)
{
    if(start != NULL)
    {
        newNode *temp = start->next;
        while(temp != NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}

void insert_node(newNode *start, int data)
{
    if(start != NULL)
    {
        newNode *node = (newNode*) malloc(sizeof(newNode));
        node->data = data;
        node->next = NULL;
        newNode *temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void delete_node(newNode *start, int data)
{
    if(start != NULL)
    {
        int i = 0;
        newNode *temp = start;
        newNode *prev = start;
        newNode *next_temp = start;
        while (temp != NULL)
        {
            next_temp = next_temp->next;
            if(temp->data == data && i != 0)
            {
                temp->next = NULL;
                prev->next = next_temp;
            }
            if(i++ >= 1)
            {
                prev = prev->next;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    newNode *initial_node = (newNode*) malloc(sizeof(newNode));
    insert_node(initial_node, 1);
    insert_node(initial_node, 2);
    insert_node(initial_node, 3);
    printf("Initial structure:\n");
    print_list(initial_node);
    insert_node(initial_node, 4);
    printf("Insert node:\n");
    print_list(initial_node);
    delete_node(initial_node, 4);
    printf("Delete node:\n");
    print_list(initial_node);
    return 0;
}