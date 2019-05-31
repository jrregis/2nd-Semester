#ifndef TREE_H
#define TREE_H
#define BY_LICENSE 1
#define BY_YEAR 2
#define BY_BRAND 3
#include "lse.h"

typedef struct Node_tree
{
    Car *c;
    struct Node_tree *left;
    struct Node_tree *right;

} Node_tree;

Node_tree *create(void);
Node_tree *destroyTree(Node_tree *t);
Node_tree *insertByLicense(Node_tree *t, Car *c);
Node_tree *insertByBrand(Node_tree *t, Car *c);
Node_tree *insertByYear(Node_tree *t, Car *c);
Node_tree *search(Node_tree *t, char license[8]);
void showSimetricByLicense(Node_tree *t);
void showSimetricByBrand(Node_tree *t);
void showSimetricByYear(Node_tree *t);

#endif