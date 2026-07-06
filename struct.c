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
}

void person_ini(person *new_person)
{

    strcpy(new_person->name, "");
    new_person->age = 0;
    new_person->next = NULL;
}