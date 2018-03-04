typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

void insert(Node **, int);
Node* del(Node **, int);
