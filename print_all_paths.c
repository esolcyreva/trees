
#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Node *head = NULL;

static int get_height(Node **head)
{
    Node *temp = *head;
    int lheight = 0;
    int rheight = 0;
    if (*head == NULL) {
        return 0;
    }
    lheight = get_height(&temp->left);
    rheight = get_height(&temp->right);
    if (lheight > rheight) {
        return lheight + 1;
    } else {
        return rheight + 1;
    }

}

void print_all_paths(Node **head, int sum, int a[], int len) {
    Node *temp = *head;
    if (temp == NULL) {
        return;
    }
    print_all_paths(&temp->left, sum, a, len);
    print_all_paths(&temp->right, sum, a, len);
    sum = sum - temp->data;
    if (sum == 0) {
        int i;
        a[len] = temp->data;
        len++;
        for (i=0 ; i<len ; i++) {
            printf("%d\t",a[i]);
        }
        printf("\n");
    } else if (sum > 0) {
        a[len] = temp->data;
        len++;
        print_all_paths(&temp->left, sum, a, len);
        print_all_paths(&temp->right, sum, a, len);
    }
}

int main()
{
    int sum = 0;
    int height = 0;
    tree_init(&head);
    height = get_height(&head);
    if (head != NULL)
    {
        printf("\nHeight of the tree = %d\n", height);
        int a[height];
        print_all_paths(&head, 45, a, 0);
    }
}
