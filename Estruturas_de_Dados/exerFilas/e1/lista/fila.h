typedef struct lista
{
    float info;
    struct lista *prox;
} lista;

/* estrutura da fila */
typedef struct fila
{
    lista *ini;
    lista *fim;
} fila;

fila *fila_cria(void);
void fila_insere(fila *f, float v);
void fila_retira(fila *f);
void imprime(fila *f);