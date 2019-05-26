#ifndef TREE_H
#define TREE_H
#include "lse.h"

typedef struct Node_tree
{
    Node **info;
    Node_tree *left;
    Node_tree *right;

} Node_tree;

#endif