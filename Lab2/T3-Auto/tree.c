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

    else if (t->c->year <= c->year)
        t->right = insertByYear(t->right, c);
    else
        t->left = insertByYear(t->left, c);

    return t;
}
Node_tree *insertByBrand(Node_tree *t, Car *c)
{
    if (t == NULL)
    {
        t = create();
        t->c = c;
    }

    else if (strcmp(t->c->brand, c->brand) <= 0)
        t->right = insertByBrand(t->right, c);
    else
        t->left = insertByBrand(t->left, c);

    return t;
}

Node_tree *insertByLicense(Node_tree *t, Car *c)
{
    if (t == NULL)
    {
        t = create();
        t->c = c;
    }

    else if (strcmp(t->c->license_p, c->license_p) <= 0)
        t->right = insertByLicense(t->right, c);
    else
        t->left = insertByLicense(t->left, c);

    return t;
}

void showSimetricByLicense(Node_tree *t)
{
    if (!isEmpty(t))
    {
        showSimetricByLicense(t->left);

        if (strlen(t->c->brand) <= 7)
            printf("%s\t\t-  %s  -  %d\n\n", t->c->brand, t->c->license_p, t->c->year);
        else
            printf("%s\t-  %s  -  %d\n\n", t->c->brand, t->c->license_p, t->c->year);

        showSimetricByLicense(t->right);
    }
}

void showSimetricByBrand(Node_tree *t)
{
    if (!isEmpty(t))
    {
        showSimetricByBrand(t->left);

        if (strlen(t->c->brand) <= 7)
            printf("%s\t\t-  %s  -  %d\n\n", t->c->brand, t->c->license_p, t->c->year);
        else
            printf("%s\t-  %s  -  %d\n\n", t->c->brand, t->c->license_p, t->c->year);

        showSimetricByBrand(t->right);
    }
}

void showSimetricByYear(Node_tree *t)
{
    if (!isEmpty(t))
    {
        showSimetricByYear(t->left);

        if (strlen(t->c->brand) <= 7)
            printf("%s\t\t-  %s  -  %d\n\n", t->c->brand, t->c->license_p, t->c->year);
        else
            printf("%s\t-  %s  -  %d\n\n", t->c->brand, t->c->license_p, t->c->year);

        showSimetricByYear(t->right);
    }
}

Node_tree *removeNodeByLicense(Node_tree *t, Car *c)
{
    if (isEmpty(t))
        return NULL;

    if (strcmp(c->license_p, t->c->license_p) < 0)
    {
        t->left = removeNodeByLicense(t->left, c);
    }

    else if (strcmp(c->license_p, t->c->license_p) > 0)
    {
        t->right = removeNodeByLicense(t->right, c);
    }

    else if (strcmp(c->license_p, t->c->license_p) == 0)
    {
        if ((t->left == NULL) && (t->right == NULL))
        {
            free(t);
            t = NULL;
        }

        else if (t->left == NULL)
        {
            Node_tree *aux = t;
            t = t->right;
            free(aux);
        }

        else if (t->right == NULL)
        {
            Node_tree *aux = t;
            t = t->left;
            free(aux);
        }
        else
        {
            Node_tree *temp = t->left;
            while (temp->right != NULL)
                temp = temp->right;
            t->c = temp->c;

            t->left = removeNodeByLicense(t->left, temp->c);
        }
    }
    return t;
}

Node_tree *removeNodeByBrand(Node_tree *t, Car *c)
{
    if (isEmpty(t))
        return NULL;

    if ((strcmp(c->brand, t->c->brand) >= 0) && (strcmp(c->license_p, t->c->license_p) != 0))
    {
        // printf("dir\n");
        t->right = removeNodeByBrand(t->right, c);
    }

    else if ((strcmp(c->brand, t->c->brand) < 0) && (strcmp(c->license_p, t->c->license_p) != 0))
    {
        // printf("esq\n");
        t->left = removeNodeByBrand(t->left, c);
    }

    else if ((strcmp(c->brand, t->c->brand) == 0) && (strcmp(c->license_p, t->c->license_p) == 0))
    {
        // printf("equal\n");
        if ((t->left == NULL) && (t->right == NULL))
        {
            // printf("sem filhos");
            free(t);
            t = NULL;
        }
        else if (t->left == NULL)
        {
            // printf("filho dir");
            Node_tree *aux = t;
            t = t->right;
            free(aux);
        }
        else if (t->right == NULL)
        {
            // printf("filho esq");
            Node_tree *aux = t;
            t = t->left;
            free(aux);
        }
        else
        {
            // printf("2 filhos");
            Node_tree *temp = t->left;
            while (temp->right != NULL)
                temp = temp->right;
            t->c = temp->c;

            t->left = removeNodeByBrand(t->left, temp->c);
        }
    }
    return t;
}

Node_tree *removeNodeByYear(Node_tree *t, Car *c)
{

    if (isEmpty(t))
        return NULL;

    if (t->c->year <= c->year && (strcmp(c->license_p, t->c->license_p) != 0))
    {
        // printf("dir\n");
        t->right = removeNodeByYear(t->right, c);
    }

    else if (t->c->year > c->year && (strcmp(c->license_p, t->c->license_p) != 0))
    {
        // printf("esq\n");
        t->left = removeNodeByYear(t->left, c);
    }

    else if (t->c->year == c->year && (strcmp(c->license_p, t->c->license_p) == 0))
    {
        // printf("equal\n");
        if ((t->left == NULL) && (t->right == NULL))
        {
            // printf("sem filhos");
            free(t);
            t = NULL;
        }
        else if (t->left == NULL)
        {
            // printf("filho dir");
            Node_tree *aux = t;
            t = t->right;
            free(aux);
        }
        else if (t->right == NULL)
        {
            // printf("filho esq");
            Node_tree *aux = t;
            t = t->left;
            free(aux);
        }
        else
        {
            // printf("2 filhos");
            Node_tree *temp = t->left;
            while (temp->right != NULL)
                temp = temp->right;
            t->c = temp->c;

            t->left = removeNodeByYear(t->left, temp->c);
        }
    }
    return t;
}