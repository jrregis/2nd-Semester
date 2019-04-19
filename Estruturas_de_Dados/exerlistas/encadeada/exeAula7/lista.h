struct lista
{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

Lista *lst_cria(void);
Lista *lst_insere(Lista *l, int i);
void lst_imprime(Lista *l);
int lst_vazia(Lista *l);
Lista *busca(Lista *l, int v);
int comprimento(Lista *l);
int maiores(Lista *l, int n);
Lista *ultimo(Lista *l);
Lista *Concat(Lista *l1, Lista *l2);