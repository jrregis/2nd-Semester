struct Node
{
    int info;
    struct Node *prox;
};
typedef struct Node Node;
Node *Create(void);
Node *InputFirstP(Node *l, int info);
Node *Show(Node *l);
Node *ChangeSign(Node *l);
Node *LastElement(Node *l);
Node *InputEnd(Node *l, int info);
void Average(Node *l);
Node *Search(Node *l, int n);