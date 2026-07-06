#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void add_node_vector(vecpeople *vector, person *new_person, int index);
void create_person_node(vecpeople *vector, person *person_data, int index);
void search_node_vector(vecpeople *vector, int index, person *person_search);
#endif