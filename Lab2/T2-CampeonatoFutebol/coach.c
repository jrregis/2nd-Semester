#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"

Coach *createCoach(char name[50], int id_coach)
{
    Coach *c = (Coach *)malloc(sizeof(Coach));

    c->id_coach = id_coach;
    strcpy(c->name, name);

    return c;
}