#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "node.h"
#include "vector.h"

void add_node_vector(vecpeople *vector, person *new_person, int index)
{

    person *temp = &vector->data[index];

    while (temp->next != NULL && strcmp(temp->name, new_person->name) != 0)
    {
        printf("DEBUG ADD NODE VECTOR -> PULOU PARA O NEXT\n");
        temp = temp->next;
    }

    temp->next = new_person;
    new_person->next = NULL;
    vector->size++;
    printf("DEBUG ADD NODE VECTOR, ADICIONOU O NÓ\n");
}

void create_person_node(vecpeople *vector, person *person_data, int index)
{
    printf("DEBUG: ENTROU CREATE PERSON NODE\n\n");
    person *new_person = malloc(sizeof(person));
    *new_person = *person_data;
    // printf("---------------------------------------------\n\n");
    // printf("Debug create person\n\n");
    // printf("Name: %s | Age: %d\n\n", new_person->name, new_person->age);
    add_node_vector(vector, new_person, index);
    printf("---------------------------------------------\n\n");
}

void search_node_vector(vecpeople *vector, int index, person *person_search)
{

    person *temp = &vector->data[index];
    // printf("---------------------------------------------\n\n");
    // printf("Debug print node vector entrou\n");

    int count = 0;
    while (temp->next != NULL)
    {
        // printf("Debug: while print node vector\n\n");
        if (strcmp(temp->next->name, person_search->name) == 0)
        {

            printf("Name found on node!\n");
            printf("Name: %s\n\n", temp->next->name);
            return;
        }
        temp = temp->next;
        count++;
    }

    printf("DEBUG INDEX NODE: %d", count);
    printf("Name not found!\n");
    // printf("Debug | fora while\n");
    // printf("---------------------------------------------\n\n");
}

bool verify_node_exist(vecpeople *vector, int index)
{

    person *temp = vector->data;

    if (temp[index].next != NULL)
    {
        printf("DEBUG: Node found\n");
        return true;
    }
    else
    {
        printf("DEBUG: node not found\n");
        return false;
    }
}