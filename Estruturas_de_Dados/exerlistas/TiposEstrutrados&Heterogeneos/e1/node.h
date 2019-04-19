struct Node
{
    int id;
    char name[50];
    struct Node *next;
};
typedef struct Node Node;
Node *Print(Node *l);
Node *Insert(Node *l, int id, char name[50]);