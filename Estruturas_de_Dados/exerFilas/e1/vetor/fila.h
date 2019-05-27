typedef struct fila
{
    int n;
    int ini;
    float vet[10];
} fila;

fila *fila_cria(void);
void fila_retira(fila *f);
void fila_insere(fila *f, float v);
void imprime(fila *f);
