struct node
{
    int info;
    struct node *next;
};
typedef struct node node;
void printNode(node *l);
node *insertElement(node *l, int element);
node *inverseNode(node *l);