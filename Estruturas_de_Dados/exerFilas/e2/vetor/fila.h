#define N 10 /* número máximo de elementos */
struct fila
{
    int n;   /* número de elementos na fila */
    int ini; /* posição do próximo elemento a ser retirado da fila */
    float vet[N];
};
typedef struct fila Fila;
Fila *fila_cria(void);
void fila_insere(Fila *f, float v);
int fila_vazia(Fila *f);
float fila_retira(Fila *f);
void imprime_fila(Fila *f);
void fila_libera(Fila *f);
void imprime_fila2(Fila *f);
void combina_filas(Fila *f_res, Fila *f1, Fila *f2);