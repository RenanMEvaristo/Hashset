#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "struct.h"
#include "node.h"
#include "util.h"

// int vector_resize(vecpeople *vector)
// {

//     int old_cap = vector->capacity;
//     vector->capacity = vector->capacity * 2;

//     person *temp = realloc(vector->data, vector->capacity * sizeof(person));

//     if (temp == NULL)
//     {

//         printf("Error:memory allocation\n");
//         return 1;
//     }

//     vector->data = temp;
//     int i = 0;
//     for (i = old_cap + 1; i < vector->capacity; i++)
//     {

//         person_ini(&vector->data[i]);
//     }

//     return old_cap;
//     printf("Debug: Expand vector new cap -> %d\n", vector->capacity);
// }

bool verify_vector_size(vecpeople *vector)
{
    // printf("DEBUG: verify vector size:\n\n");
    // printf("DEBUG: vector size -> %d\n", vector->size);
    // printf("DEBUG: vector capacity -> %d\n", vector->capacity);

    if (vector->size == vector->capacity)
    {

        printf("Debug vector verify size entrou \n\n");
        return true;
    }
    return false;
}

// void vector_reindex(vecpeople *vector, int old_cap)
// {

//     vecpeople temp;
//     vector_ini_resize(&temp, vector->capacity);
//     printf("DEBUG: TEMP CAPACITY ->%d\n", temp.capacity);
//     person *aux_person = vector->data;
//     printf("---------------------------------------------\n\n");
//     printf("DEBUG: Iniciou o reindex\n\n");
//     int i = 0;

//     printf("DEBUG: TAMANHO OLD CAP -> %d\n\n", old_cap);
//     printf("DEBUG: TAMANHO VECTOR CAPACITY NO REINDEX -> %d\n", vector->capacity);

//     for (i = 0; i < old_cap; i++)
//     {

//         int index = create_hash_get_index(vector, &aux_person[i]);
//         while (strcmp(aux_person[index].name, "") == 0)
//         {
//             printf("DEBUG: VECTOR REINDEX | entrou no while index++\n");
//             index++;
//         }

//         bool verify = verify_node_exist(vector, index);
//         if (verify == true)
//         {
//             printf("DEBUG: verify == true | existe nó\n");
//             person *temp = vector->data[i].next;
//             add_data(vector, temp);
//         }

//         temp.data[index] = aux_person[i];
//         printf("DEBUG: VECTOR REINDEX | Name: %s | INDEX %d\n", temp.data[index].name, index);
//         printf("---------------------------------------------\n\n");
//     }
//     printf("DEBUG TEMP REINDEX\n\n");
//     print_data(&temp);

//     printf("DEBUG VECTOR=TEMP REINDEX\n\n");
//     vector->data = temp.data;
//     print_data(vector);
//     printf("---------------------------------------------\n\n");
// }

void vector_reindex2(vecpeople *vector, vecpeople *copy_vector, int old_cap)
{

    /*void resize(...) {
    create_new_and_bigger();
    copy_elementos_from_old_to_new();
    delete_old();
    set_old_to_new();
    }*/

    copy_vector_elements(vector, copy_vector, old_cap);
}

void vector_add_data(vecpeople *vector, int index, person *new_person)
{
    // printf("---------------------------------------------\n\n");
    // printf("Debug INDEX: %d | func Vetor_add\n", index);
    // printf("DEBUG: VECTOR ADD_DATA NAME -> %s\n", new_person->name);
    vector->data[index] = *new_person;
    vector->size++;

    bool verify = verify_vector_size(vector);
    if (verify == true)
    {
        vecpeople temp;
        vector_ini_resize(&temp, vector->capacity * 2);
        printf("DEBUG VECTOR ADD DATA | TEMP CAPACITY %d\n", temp.capacity);
        copy_vector_elements(vector, &temp, vector->capacity);
    }

    // printf("Debug: verify size vector | func vector_add_data\n\n");
    // bool verify = verify_vector_size(vector);

    // printf("verify vector size | is full ->  %d\n\n", verify);
    // printf("Debug vector size: %d | func vector_add_data\n", vector->size);
    // if (verify == true)
    // {
    //     // printf("DEBUG: Entrou verify do vector_add_data == true\n\n");
    //     int old_cap = vector_resize(vector);
    //     // printf("Debug | entrou no vector reindex\n\n");
    //     vector_reindex2(vector, old_cap);
    // }
    // printf("---------------------------------------------\n\n");
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
    printf("---------------------------------------------\n\n");
    printf("Debug Name: %s | Func Vector_search data[index]\n", vector->data[index].name);
    printf("Debug Name: %s | Func vector_search person->name\n", person_search->name);

    if (strcmp(vector->data[index].name, person_search->name) == 0)
    {

        printf("found on vector!\n\n");
        printf("---------------------------------------------\n\n");
        return true;
    }

    search_node_vector(vector, index, person_search);
    printf("---------------------------------------------\n\n");
    return false;
}
