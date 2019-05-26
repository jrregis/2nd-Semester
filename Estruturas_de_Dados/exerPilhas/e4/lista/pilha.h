typedef struct lista
{
    float info;
    struct lista *prox;
} lista;

typedef struct pilha
{
    lista *prim;
} pilha;

int pilha_vazia(pilha *p);
pilha *pilha_cria(void);
void pilha_push(pilha *p, float v);
void pilha_pop(pilha *p);
void imprime(pilha *p);
void pilha_esvazia(pilha *p);
