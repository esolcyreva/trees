#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Node *head = NULL;

static Node* search(Node **head, int data)
{
    Node *temp = *head;
    if (*head == NULL) {
        return NULL;
    }

    if (temp->data == data) {
        return *head;
    } else if (temp->data > data) {
        return search(&temp->left, data);
    } else {
        return search(&temp->right, data);
    }
}

static bool
route_exists(Node **head, Node **find)
{
    Node *temp = *head;
    if (*head == NULL) {
        return false;
    }
    if (temp->data == (*find)->data) {
        return true;
    } else if (temp->data > (*find)->data) {
        return route_exists(&temp->left, find);
    } else {
        return route_exists(&temp->right, find);
    }
}

int main()
{
    tree_init(&head);
    Node *first_node = search(&head, 17);
    Node *second_node = search(&head, 28);
    if (first_node == NULL || second_node == NULL) {
        return;
    }
    printf("\nLooking for route between %d and %d\n", first_node->data, second_node->data);
    if (route_exists(&first_node, &second_node)) {
        printf("\nRoute exist between %d and %d\n", first_node->data, second_node->data);
    } else {
        printf("\nRoute does not exist between %d and %d\n", first_node->data, second_node->data);
    }
}
