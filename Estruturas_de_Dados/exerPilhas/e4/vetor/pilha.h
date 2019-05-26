typedef struct pilha
{
    int num_elements;
    float vet[5];
} pilha;

int pilha_vazia(pilha *p);
pilha *pilha_cria(void);
void pilha_push(pilha *p, float v);
void pilha_pop(pilha *p);
void pilha_esvazia(pilha *p);
void imprime(pilha *p);