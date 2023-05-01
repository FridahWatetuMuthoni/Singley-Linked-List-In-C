// Linked list insertion at specific position in C
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// required for insertAfter
int getSizeOfList(struct Node *node)
{
    int size = 0;

    while (node != NULL)
    {
        node = node->next;
        size++;
    }
    return size;
}

// function to insert after nth node
void insertPosition(int pos, int data, struct Node **head)
{
    int size = getSizeOfList(*head);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Can't insert if position to insert is greater than size of Linked List
    // can insert after negative pos
    if (pos < 0 || pos > size)
        printf("Invalid position to insert\n");

    // inserting first node
    else if (pos == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }

    else
    {
        // temp used to traverse the Linked List
        struct Node *temp = *head;

        // traverse till the nth node
        while (--pos)
            temp = temp->next;

        // assign newNode's next to nth node's next
        newNode->next = temp->next;
        // assign nth node's next to this new node
        temp->next = newNode;
        // newNode inserted b/w 3rd and 4th node
    }
}

void display(struct Node *node)
{

    printf("Linked List : ");

    // as linked list will end when Node is Null
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{

    // creating 4 pointers of type struct Node
    // So these can point to address of struct type variable
    struct Node *head = NULL;
    struct Node *node2 = NULL;
    struct Node *node3 = NULL;
    struct Node *node4 = NULL;

    // allocate 3 nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    node2 = (struct Node *)malloc(sizeof(struct Node));
    node3 = (struct Node *)malloc(sizeof(struct Node));
    node4 = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;    // data set for head node
    head->next = node2; // next pointer assigned to address of node2

    node2->data = 20;
    node2->next = node3;

    node3->data = 30;
    node3->next = node4;

    node4->data = 40;
    node4->next = NULL;

    display(head);

    // Inserts data: 15 after the 1st node
    insertPosition(1, 15, &head);

    // Inserts data: 25 after the 3rd node
    insertPosition(3, 25, &head);

    // Inserts data: 35 after the 5th node
    insertPosition(5, 35, &head);

    // Inserts data: 25 after the 7th node
    insertPosition(7, 45, &head);

    display(head);

    // Invalid: can't insert after -2 pos
    insertPosition(-2, 100, &head);

    // Invalid: Current size 8, trying to enter after 10th pos
    insertPosition(10, 200, &head);

    return 0;
}
