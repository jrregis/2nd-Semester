struct node
{
    char info[50];
    struct node *next;
};
typedef struct node node;

void printNode(node *l);
node *insertElement(node *l, char *text);
node *copyNode(node *l);