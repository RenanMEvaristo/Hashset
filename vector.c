#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "struct.h"
#include "node.h"
#include "util.h"
#include "vector.h"

bool verify_vector_size(vecpeople *vector)
{
    // printf("DEBUG: verify vector size:\n\n");
    // printf("DEBUG: vector size -> %d\n", vector->size);
    // printf("DEBUG: vector capacity -> %d\n", vector->capacity);

    if (vector->size == vector->capacity)
    {

        // printf("Debug vector resize entrou \n\n");
        return true;
    }
    return false;
}

void vector_reindex2(vecpeople *vector, vecpeople *copy_vector, int old_cap)
{

    copy_vector_elements(vector, copy_vector, old_cap);
}

void vector_add_data(vecpeople *vector, int index, person *new_person)
{
    // printf("---------------------------------------------\n\n");
    // printf("Debug INDEX: %d | func Vetor_add\n", index);
    // printf("DEBUG: VECTOR ADD_DATA NAME -> %s\n", new_person->name);
    vector->data[index] = *new_person;
    vector->size++;
    printf("DEBUG VECTOR ADD DATA SIZE -> %d\n", vector->size);
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
    // printf("---------------------------------------------\n\n");
    // printf("Debug Name: %s | Func Vector_search data[index]\n", vector->data[index].name);
    // printf("Debug Name: %s | Func vector_search person->name\n", person_search->name);

    if (strcmp(vector->data[index].name, person_search->name) == 0)
    {

        // printf("found on vector!\n\n");
        // printf("---------------------------------------------\n\n");
        return true;
    }

    search_node_vector(vector, index, person_search);
    // printf("---------------------------------------------\n\n");
    return false;
}
