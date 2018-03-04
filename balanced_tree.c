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

static bool is_tree_balanced(Node **head)
{
    Node *temp = *head;
    if (*head == NULL) {
        return true;
    }
    int lheight = get_height(&temp->left);
    int rheight = get_height(&temp->right);
    if (lheight > rheight) {
        if (lheight - rheight <= 1) {
            return true;
        } else {
            return false;
        }
    } else if (lheight <= rheight) {
        if (rheight - lheight <= 1) {
            return true;
        } else {
            return false;
        }
    }


}

int main()
{
    bool balanced = false;
    tree_init(&head);
    balanced = is_tree_balanced(&head);
    if (balanced) {
        printf("\nTree is balanced\n");
    } else {
        printf("\nTree is not balanced\n");
    }
}
