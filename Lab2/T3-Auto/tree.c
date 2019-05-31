#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"
#include "lse.h"

bool isEmpty(Node_tree *t)
{
    return t == NULL;
}

Node_tree *create(void)
{
    Node_tree *t = (Node_tree *)malloc(sizeof(Node_tree));

    t->left = NULL;
    t->right = NULL;
    t->c = NULL;

    return t;
}

Node_tree *destroyTree(Node_tree *t)
{
    if (!isEmpty(t))
    {
        destroyTree(t->left);
        destroyTree(t->right);
        free(t);
    }
    return NULL;
}

Node_tree *search(Node_tree *t, char license[8])
{
    if (t == NULL)
        return NULL;
    else if (strcmp(license, t->c->license_p) < 0)
        return search(t->left, license);
    else if (strcmp(license, t->c->license_p) > 0)
        return search(t->right, license);
    else
        return t;
}

Node_tree *insertByYear(Node_tree *t, Car *c)
{
    if (t == NULL)
    {
        t = create();
        t->c = c;
    }

    else if (t->c->year >= c->year)
        t->left = insertByYear(t->left, c);
    else
        t->right = insertByYear(t->right, c);

    return t;
}
Node_tree *insertByBrand(Node_tree *t, Car *c)
{
    if (t == NULL)
    {
        t = create();
        t->c = c;
    }

    else if (strcmp(t->c->brand, c->brand) >= 0)
        t->left = insertByBrand(t->left, c);
    else
        t->right = insertByBrand(t->right, c);

    return t;
}

Node_tree *insertByLicense(Node_tree *t, Car *c)
{
    if (t == NULL)
    {
        t = create();
        t->c = c;
    }

    else if (strcmp(t->c->license_p, c->license_p) >= 0)
        t->left = insertByLicense(t->left, c);
    else
        t->right = insertByLicense(t->right, c);

    return t;
}

void showSimetricByLicense(Node_tree *t)
{
    if (!isEmpty(t))
    {
        showSimetricByLicense(t->left);
        printf("MARCA: %s\nPLACA: %s\nANO: %d\n\n", t->c->brand, t->c->license_p, t->c->year);
        showSimetricByLicense(t->right);
    }
}

void showSimetricByBrand(Node_tree *t)
{
    if (!isEmpty(t))
    {
        showSimetricByBrand(t->left);
        printf("MARCA: %s\nPLACA: %s\nANO: %d\n\n", t->c->brand, t->c->license_p, t->c->year);
        showSimetricByBrand(t->right);
    }
}

void showSimetricByYear(Node_tree *t)
{
    if (!isEmpty(t))
    {
        showSimetricByYear(t->left);
        printf("MARCA: %s\nPLACA: %s\nANO: %d\n\n", t->c->brand, t->c->license_p, t->c->year);
        showSimetricByYear(t->right);
    }
}