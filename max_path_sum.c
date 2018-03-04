#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Node *head = NULL;

static int
max_path_sum(Node **head)
{
    Node *temp = *head;
    int left = 0; int right = 0;
    if (temp == NULL) {
        return 0;
    }
    left = max_path_sum(&temp->left) + temp->data;
    right = max_path_sum(&temp->right) + temp->data;
    if (left > right) {
        return left;
    } else {
        return right;
    }

}

int main()
{
    int sum = 0;
    tree_init(&head);
    sum = max_path_sum(&head);
    printf("\nMax Path Sum = %d\n", sum);
}
