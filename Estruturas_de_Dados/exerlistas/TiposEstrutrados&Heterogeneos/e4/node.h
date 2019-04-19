struct teacher
{
    int id;
    char name[50];
    float salary;
};
typedef struct teacher teacher;

struct student
{
    int id;
    char name[50];
};
typedef struct student student;

struct nodeHet
{
    int type;
    void *info;
    struct listaHet *next;
};
typedef struct nodeHet nodeHet;
nodeHet *InsertT(nodeHet *l, int id, float salary, char *name);
nodeHet *InsertS(nodeHet *l, int id, char *name);
void Print(nodeHet *l);
