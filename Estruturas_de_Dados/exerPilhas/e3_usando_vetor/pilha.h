typedef struct pilha
{
    int n;
    float vet[5];
} pilha;

int pilha_vazia(pilha *p);
pilha *pilha_cria(void);
void pilha_push(pilha *p, float v);
float pilha_pop(pilha *p);
void pilha_libera(pilha *p);
int num_obj(pilha *p);
float topo(pilha *p);