typedef struct pilha
{
    int num_elements;
    float vet[5];
} pilha;

int pilha_vazia(pilha *p);
pilha *pilha_cria(void);
void pilha_push(pilha *p, float v);
float pilha_pop(pilha *p);
void esvazie(pilha *p);
void imprime(pilha *p);