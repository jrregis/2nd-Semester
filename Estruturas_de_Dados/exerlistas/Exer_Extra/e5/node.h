struct node
{
    char info[50];
    struct node *next;
};
typedef struct node node;

void printNode(node *l);
node *insertNode(node *l, char *text);
int equalInfoNode(node *l, node *l2);