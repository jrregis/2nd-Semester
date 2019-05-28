typedef struct lista
{
    float v;
    struct lista *prox;
} Lista;

typedef struct fila
{
    Lista *ini;
    Lista *fim;
} Fila;

Fila *fila_cria(void);
float fila_frente(Fila *f);
int fila_vazia(Fila *f);
void fila_imprime(Fila *f);
void fila_insere(Fila *f, float v);
float fila_remove(Fila *f);
void fila_libera(Fila *f);
Fila *fila_ordernar(Fila *f1, Fila *f2);
