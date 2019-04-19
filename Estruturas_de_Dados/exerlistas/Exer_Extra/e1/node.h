struct node
{
    int info;
    struct node *next;
};
typedef struct node node;

node *insertElement(node *l, int element);
node *Create(void);
void print(node *l);
node *deleteElement(node *l, int element);