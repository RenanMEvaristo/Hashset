#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "struct.h"
#include "node.h"
#include "util.h"

void vector_resize(vecpeople *vector)
{

    vector->capacity = vector->capacity * 2;

    person *temp = realloc(vector->data, vector->capacity * sizeof(person));

    if (temp == NULL)
    {

        printf("Error:memory allocation\n");
        return;
    }

    vector->data = temp;

    printf("Debug: Expand vector new cap -> %d\n", vector->capacity);
}

bool verify_vector_size(vecpeople *vector)
{
    printf("DEBUG: verify vector size:\n\n");
    printf("DEBUG: vector size -> %d\n", vector->size);
    printf("DEBUG: vector capacity -> %d\n", vector->capacity);

    if (vector->size == vector->capacity)
    {

        printf("Debug vector resize entrou \n\n");
        vector_resize(vector);
        printf("new vector capacity %d\n\n", vector->capacity);
        return true;
    }
    return false;
}

// void vector_reindex(vecpeople *vector)
// {

//     int i = 0;

//     person *person = vector->data;

//     for (i = 0; i < vector->capacity; i++)
//     {

//         int hash = hash_create(vector->data[i].name);
//         int index = get_index(hash, vector->capacity);
//         add_data(vector, person[i].name);
//     }
// }

void vector_add_data(vecpeople *vector, int index, person *new_person)
{

    printf("Debug INDEX: %d | func Vetor_add\n", index);
    vector->data[index] = *new_person;
    vector->size++;

    printf("Debug: verify size vector | func vector_add_data\n\n");
    bool verify = verify_vector_size(vector);

    printf("verify vector size | is full ->  %d\n\n", verify);
    printf("Debug vector size: %d | func vector_add_data\n", vector->size);
    if (verify == true)
    {
        printf("Debug | entrou no vector reindex\n\n");
        vector_reindex(vector);
    }
}

void vector_free(vecpeople *vector)
{

    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
}

bool vector_search(vecpeople *vector, person *person_search)
{

    int hash = hash_create(person_search);
    int index = get_index(hash, vector->capacity);
    printf("Debug Name: %s | Func Vector_search data[index]\n", vector->data[index].name);
    printf("Debug Name: %s | Func vector_search person->name\n", person_search->name);

    if (strcmp(vector->data[index].name, person_search->name) == 0)
    {

        printf("found on vector!\n\n");
        return true;
    }

    search_node_vector(vector, index, person_search);
    return false;
}
