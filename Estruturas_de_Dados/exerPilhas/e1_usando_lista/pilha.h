typedef struct lista
{
    float info;
    struct lista *prox;
} lista;

typedef struct pilha
{
    lista *prim;
} pilha;
void imprime(pilha *p);
float pilha_pop(pilha *p);
void pilha_push(pilha *p, float v);
pilha *pilha_cria(void);
int pilha_vazia(pilha *p);