#ifndef LSE_H
#define LSE_H
#include <stdbool.h>

typedef struct Car
{
    int year;
    char license_p[8], brand[20];

} Car;

typedef struct Node
{
    Car info;
    struct Node *next;
} Node;

Node *createList(void);
Node *insert_in_order(Node *head, Car c);
bool emptyList(Node *head);
Node *freeList(Node *head);
void show(Node *head);
Car *searchCar(Node *head, char license_p[8]);
Node *removeCar(Node *head, char license_p[8]);
Car createCar(void);

#endif
