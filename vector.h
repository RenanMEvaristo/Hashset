#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "struct.h"
#include "node.h"
#include "util.h"

void vector_resize(vecpeople *vector);
bool verify_vector_size(vecpeople *vector);
void vector_reindex(vecpeople *vector);
void vector_add_data(vecpeople *vector, int index, person *new_person);
void vector_free(vecpeople *vector);
bool vector_search(vecpeople *vector, person *person_search);

#endif