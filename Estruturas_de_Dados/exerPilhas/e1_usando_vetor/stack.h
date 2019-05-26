#define N 3

typedef struct Pilha
{
    int n;
    float vet[N];
} Pilha;

int pilha_vazia(Pilha *p);
Pilha *pilha_cria(void);
void pilha_push(Pilha *p, float v);
float pilha_pop(Pilha *p);
void pilha_libera(Pilha *p);
void imprime(Pilha *p);