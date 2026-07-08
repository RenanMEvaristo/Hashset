#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

void vector_ini(vecpeople *vector)
{

    vector->capacity = 10;
    vector->size = 0;
    vector->data = malloc(vector->capacity * sizeof(person));

    if (vector->data == NULL)
    {

        printf("error: memory alocation");
        exit(1);
    }

    int i = 0;
    for (i = 0; i < vector->capacity; i++)
    {

        person_ini(&vector->data[i]);
    }
}

void vector_ini_resize(vecpeople *vector, int vec_cap)
{

    vector->capacity = vec_cap;
    vector->size = 0;
    vector->data = malloc(vector->capacity * sizeof(person));

    if (vector->data == NULL)
    {

        printf("error: memory alocation");
        exit(1);
    }

    int i = 0;
    for (i = 0; i < vector->capacity; i++)
    {

        person_ini(&vector->data[i]);
    }
}

void person_ini(person *new_person)
{

    strcpy(new_person->name, "");
    new_person->age = 0;
    new_person->next = NULL;
}
