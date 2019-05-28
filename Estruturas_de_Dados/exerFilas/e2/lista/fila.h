typedef struct lista
{
    float info;
    struct lista *prox;
} lista;

typedef struct fila
{
    lista *ini;
    lista *fim;
} fila;

int vazia(fila *f);
fila *fila_cria(void);
void fila_insere(fila *f, float v);
float fila_retira(fila *f);
void imprime(fila *f);
void combina_filas(fila *f0, fila *f1, fila *f2);
