struct node
{
    int info;
    struct node *next;
};
typedef struct node node;

node *insertElement(node *l, int element);
void printNode(node *l);
node *separatingNode(node *l, int elemet);