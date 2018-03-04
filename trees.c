#include "node.h"
#include <stdlib.h>
#include <stdio.h>

Node *head = NULL;

int main()
{
    tree_init(&head);
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
