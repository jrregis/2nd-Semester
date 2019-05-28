#define N 100 // Número máximo de elementos

struct fila
{
    int n;   // Número de elementos na fila
    int ini; // Início da fila (de onde os elementos são retirados)
    float vet[N];
};
typedef struct fila Fila;

Fila *fila_cria(void);
float fila_frente(Fila *f);
int fila_vazia(Fila *f);
void fila_libera(Fila *f);
void fila_imprime(Fila *f);
void fila_insere(Fila *f, float v);
float fila_remove(Fila *f);
Fila *fila_ordernar(Fila *f1, Fila *f2);
