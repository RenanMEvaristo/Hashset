#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "util.h"
#include "node.h"
#include "vector.h"

int hash_create(person *person)
{

    int str_size = strlen(person->name);

    int hash = (str_size + 1);
    // printf("Debug HASH: %d | Func hash_create\n", hash);
    return hash;
}

int get_index(int hash, int capacity)
{

    int index = hash % capacity;
    // printf("Debug INDEX: %d | Func Getindex\n", index);
    return index;
}

int create_hash_get_index(vecpeople *vector, person *person)
{

    int hash = hash_create(person);
    int index = get_index(hash, vector->capacity);
    return index;
}

void print_data(vecpeople *my_vector)
{

    int i = 0;

    for (i = 0; i < my_vector->capacity; i++)
    {

        printf("Name: %20s | Age: %2d | Index: %2d\n", my_vector->data[i].name, my_vector->data[i].age, i);
    }
}

void add_data(vecpeople *vector, person *person_data)
{

    int index = create_hash_get_index(vector, person_data);
    // printf("---------------------------------------------\n\n");
    printf("DEbug INDEX: %d | Func add_data\n", index);
    printf("DEBUG ADD DATA NAME-> %s\n", person_data->name);
    printf("DEBUG VECTOR CAPACITY -ADD_DATA -> %d\n", vector->capacity);
    if (strcmp(vector->data[index].name, "") == 0)
    {
        printf("Debug add data | name vazio -> VERDADEIRO\n\n");
        vector_add_data(vector, index, person_data);
    }
    else
    {
        printf("Debug create person node | func add_data name vazio -> FALSO\n\n");
        create_person_node(vector, person_data, index);
    }
    // printf("---------------------------------------------\n\n");
}

void copy_vector_elements(vecpeople *vector, vecpeople *copy_vector, int old_cap)
{

    int i = 0;
    person *aux_person = vector->data;
    for (i = 0; i < old_cap; i++)
    {

        bool verify = verify_node_exist(vector, i);
        printf("DEBUG VERIFY NODE EXIST | COPY ELEMENTS -> %d\n", verify);
        if (verify == true)
        {
            printf("DEBUG COPY VETOR ELEMENTS == TRUE\n");
            add_data(copy_vector, aux_person[i].next);
            printf("DEBUG COPY VECTOR ELEMENTS NODE NAME -> %s | INDEX: %d", aux_person[i].next->name, i);
        }
        add_data(copy_vector, &aux_person[i]);
    }
    printf("DEBUG PRINT VECTOR\n");
    print_data(vector);
    printf("DEBUG COPY VECTOR ELEMENTS\n");
    print_data(copy_vector);
    vector = copy_vector;
}

void print_only_nodes(vecpeople *vector)
{

    int i = 0;
    person *temp = vector->data;

    for (i = 0; i < vector->capacity; i++)
    {

        printf("DEBUG ONLY NODE INDEX[%d] | NAME -> %s\n", i, temp[i].next->name);
    }
}
