#include "node.h"
#include <stdlib.h>
#include <stdio.h>

Node *head = NULL;

int main()
{
    insert(&head, 17);
    insert(&head, 28);
    insert(&head, 14);
    insert(&head, 38);
    insert(&head, 10);
    insert(&head, 22);
    insert(&head, 1);
    insert(&head, 13);
    insert(&head, 44);
    insert(&head, 30);
    insert(&head, 8);
    printf("Created tree:\n");
    inorder(&head);
    printf("\n");
    printf("Deleting 1 with right child:\n");
    del(&head, 1);
    inorder(&head);
    printf("\n");
    printf("Deleting 13 without children:\n");
    del(&head, 13);
    inorder(&head);
    printf("\n");
    printf("Deleting 14 with left child:\n");
    del(&head, 14);
    inorder(&head);
    printf("\n");
    printf("Deleting 38 with both children:\n");
    del(&head, 38);
    inorder(&head);
    printf("\n");
}
