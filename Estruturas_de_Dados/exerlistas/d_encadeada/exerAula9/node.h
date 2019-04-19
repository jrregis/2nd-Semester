struct Node2
{
    int info;
    struct Node2 *prev;
    struct Node2 *next;
};
typedef struct Node2 Node2;

Node2 *Create(void);
Node2 *Show(Node2 *l);
Node2 *LastElement(Node2 *l);
Node2 *InsertEnd(Node2 *l, int n);
Node2 *DeletePrev(Node2 *l, int n);
Node2 *InsertIni(Node2 *l, int n);
Node2 *Delete(Node2 *l, int n);