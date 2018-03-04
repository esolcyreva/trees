#include "node.h"
#include <stdio.h>
#include <stdlib.h>

void insert(Node **head, int data)
{
    Node *temp = *head;
    if (*head == NULL) {
        Node *new = malloc(sizeof(Node));
        if (new == NULL) {
            return;
        }
        new->data = data;
        new->left = NULL;
        new->right = NULL;
        *head = new;
        return;
    }
    if (temp->data >= data) {
        insert(&temp->left, data);
    } else {
        insert(&temp->right, data);
    }
}

Node* del(Node **head, int data)
{
    Node *temp = *head;
    if (temp == NULL) {
        return NULL;
    }
    if (temp->data > data) {
        del(&temp->left, data);
    } else if(temp->data < data) {
        del(&temp->right, data);
    } else if (temp->data == data) {
        if (temp->left == NULL && temp->right == NULL) {
            free(temp);
            *head = NULL;
        } else if (temp->right == NULL) {
            Node* curr = NULL;
            curr = temp->left;
            temp->data = curr->data;
            temp->right = curr->right;
            temp->left = curr->left;
            free(curr);
            *head = temp;
        } else if (temp->left == NULL) {
            Node* curr = NULL;
            curr = temp->right;
            temp->data = curr->data;
            temp->left = curr->left;
            temp->right = curr->right;
            free(curr);
            *head = temp;
        } else {
            /* Find the successor */
            Node *curr = temp->right;
            Node *prev = temp;
            while(curr->left != NULL) {
                prev = curr;
                curr = curr->left;
            }
            temp->data = curr->data;
            if (temp->right == curr) {
                temp->right = curr->right;
                free(curr);
                *head = temp;
            } else {
                prev->left = NULL;
                free(curr);
                *head = temp;
            }
        }
    }
}

void inorder(Node **head)
{
    Node *temp = *head;
    if (temp == NULL) {
        return;
    }
    inorder(&temp->left);
    printf("%d\t", temp->data);
    inorder(&temp->right);
}

void tree_init(Node **head)
{
    insert(head, 17);
    insert(head, 28);
    insert(head, 14);
    insert(head, 38);
    insert(head, 10);
    insert(head, 22);
    insert(head, 1);
    insert(head, 13);
    insert(head, 44);
    insert(head, 30);
    insert(head, 8);
    printf("Created tree:\n");
    inorder(head);
    printf("\n");
}


