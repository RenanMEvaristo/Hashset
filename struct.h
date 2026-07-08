#ifndef STRUCT_H
#define STRUCT_H

typedef struct node_person
{

    char name[20];
    int age;
    struct node_person *next;

} person;

typedef struct
{

    person *data;
    int size;
    int capacity;

} vecpeople;

void vector_ini(vecpeople *vector);
void person_ini(person *new_person);
void vector_ini_resize(vecpeople *vector, int vec_cap);

#endif