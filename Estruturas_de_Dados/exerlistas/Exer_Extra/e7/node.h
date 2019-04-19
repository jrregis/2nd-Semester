struct node2
{
    int info;
    struct node2 *previous;
    struct node2 *next;
};
typedef struct node2 node2;

node2 *insertNode(node2 *head, int element);
void printNode(node2 *head);
node2 *deleteNode(node2 *head, int element);