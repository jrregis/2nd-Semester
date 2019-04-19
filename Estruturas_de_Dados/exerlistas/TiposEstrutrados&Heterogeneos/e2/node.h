
struct student
{
    int id;
    char name[50];
};
typedef struct student student;
struct node
{
    student info;
    struct node *next;
};
typedef struct node node;
node *Insert(node *l, int id, char *name);
void Show(node *l);