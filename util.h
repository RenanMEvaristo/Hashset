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
#endif