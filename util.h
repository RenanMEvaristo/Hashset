#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int hash_create(person *person);
int get_index(int hash, int capacity);
void print_data(vecpeople *my_vector);
void add_data(vecpeople *vector, person *person_data);
int create_hash_get_index(vecpeople *vector, person *person);
void print_only_nodes(vecpeople *vector);
void copy_vector_elements(vecpeople *vector, vecpeople *copy_vector, int old_cap);
#endif