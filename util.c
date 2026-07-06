#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "util.h"
#include "node.h"

int hash_create(person *person)
{

    int str_size = strlen(person->name);

    int hash = (str_size + 1);
    printf("Debug HASH: %d | Func hash_create\n", hash);
    return hash;
}

int get_index(int hash, int capacity)
{

    int index = hash % capacity;
    printf("Debug INDEX: %d | Func Getindex\n", index);
    return index;
}

void print_data(vecpeople *my_vector)
{

    int i = 0;

    for (i = 0; i < my_vector->capacity; i++)
    {

        printf("Name: %10s | Age: %2d | Index: %2d\n", my_vector->data[i].name, my_vector->data[i].age, i);
    }
}

void add_data(vecpeople *vector, person *person_data)
{

    int hash = hash_create(person_data);
    int index = get_index(hash, vector->capacity);
    printf("DEbug INDEX: %d | Func add_data\n", index);

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
}