#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "util.h"
#include "node.h"
#include "vector.h"
#include "stopwatch.h"
#include <time.h>

int hash_create(person *ptr_person)
{

    int str_size = (int)strlen(ptr_person->name);

    int hash = (str_size + 5) + ptr_person->age;
    // printf("Debug HASH: %d | Func hash_create\n", hash);
    return hash;
}

int get_index(int hash, int capacity)
{

    int index = hash % capacity;
    // printf("Debug INDEX: %d | Func Getindex\n", index);
    return index;
}

int create_hash_get_index(vecpeople *vector, person *ptr_person)
{

    int hash = hash_create(ptr_person);
    int index = get_index(hash, vector->capacity);
    return index;
}

void print_data(vecpeople *my_vector)
{

    int i = 0;

    for (i = 0; i < my_vector->capacity; i++)
    {

        printf("Name: %31s | Age: %2d | Index: %3d\n", my_vector->data[i].name, my_vector->data[i].age, i);
    }
}

void add_data(vecpeople *vector, person *person_data)
{

    // printf("---------DEBUG: Person->data.name -> %s\n", person_data->name);
    // printf("---------------------------------------------\n\n");
    // printf("DEbug INDEX: %d | Func add_data\n", index);
    // printf("DEBUG ADD DATA NAME-> %s\n", person_data->name);
    // printf("DEBUG VECTOR CAPACITY -ADD_DATA -> %d\n", vector->capacity);
    bool verify = verify_vector_size(vector);
    if (verify == true)
    {
        vecpeople temp;
        // printf("DEBUG: VERIFY VECTOR SIZE TRUE\n");
        vector_ini_resize(&temp, vector->capacity * 2);
        copy_vector_elements(vector, &temp, vector->capacity);
    }

    int index = create_hash_get_index(vector, person_data);

    if (strcmp(vector->data[index].name, "") == 0)
    {
        // printf("Debug add data | name vazio -> VERDADEIRO\n\n");
        vector_add_data(vector, index, person_data);
    }
    else
    {
        // printf("Debug create person node | func add_data name vazio -> FALSO\n\n");
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

        if (strcmp(aux_person[i].name, "") != 0)
        {

            person clear_person = vector->data[i];
            clear_person.next = NULL;
            add_data(copy_vector, &clear_person);

            person *old_node = vector->data[i].next;

            while (old_node != NULL)
            {

                person *next_person_node = old_node->next;

                person clear_node = *old_node;
                clear_node.next = NULL;

                add_data(copy_vector, &clear_node);

                old_node = next_person_node;
            }
        }
    }
    printf("DEBUG RESIZE: POP MOVED %d", copy_vector->size);

    *vector = *copy_vector;
}

void print_only_nodes(vecpeople *vector)
{
    if (vector == NULL)
    {
        fprintf(stderr, "Error: print_only_nodes() received a NULL vector.\n");
        exit(EXIT_FAILURE);
    }

    if (vector->data == NULL)
    {
        fprintf(stderr, "Error: print_only_nodes() received a vector with NULL data.\n");
        exit(EXIT_FAILURE);
    }

    person *temp = vector->data;

    for (int i = 0; i < vector->capacity; i++)
    {
        person *node = temp[i].next;

        while (node != NULL)
        {
            printf("DEBUG ONLY NODE INDEX[%d] | NAME -> %s\n",
                   i,
                   node->name);

            node = node->next;
        }
    }
}
void generate_random_data(person *p)
{

    static const char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int name_length = (rand() % 29) + 2;

    for (int i = 0; i < name_length; i++)
    {
        int index = rand() % (int)strlen(alphabet);
        p->name[i] = alphabet[index];
    }

    p->name[name_length] = '\0';

    p->age = (rand() % 100) + 1;
}

void save_time_to_file(const char *label, double time_ms)
{

    FILE *file = fopen("benchmarks.txt", "a");

    if (file == NULL)
    {
        printf("Erro ao abrir arquivo de logs!\n");
        return;
    }

    fprintf(file, "Operacao: %-20s | Tempo: %10.4f ms\n", label, time_ms);

    fclose(file);
}
