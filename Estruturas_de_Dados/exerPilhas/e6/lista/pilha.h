typedef struct lista
{
    float info;
    struct lista *prox;
} lista;

typedef struct pilha
{
    lista *prim;
} pilha;

int vazia(pilha *p);
pilha *cria(void);
void push(pilha *p, float v);
void pop(pilha *p);
void imprime(pilha *p);
void concatena(pilha *p, pilha *p1);