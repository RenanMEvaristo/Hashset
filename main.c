#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// #define DEBUG_METAL

#include "util.h"
#include "struct.h"
#include "node.h"
#include "vector.h"
#include "stopwatch.h"

#define ELEMENTS 100
/*
- entender como hashset funciona
- implementar um hashset para uma struct com sei lá, 2 ou 3 fields
- compilar código com otimizações e fazer uma função main que aceita 2 argumentos...
 1 vai ser o nome de uma função de hash e 1 vai ser numero deelmentos pra inserir... dai o código gera uma quantidad de elmeentos aleatorios,
 liga cronometro, enfia no hashset, desliga cronometro
e printa tempo que demorou... dai tenta recuperar elementos do hashset... cronometrado again
*/

int main()
{

    vecpeople my_vector;

    person my_person;

#ifdef DEBUG_METAL
    printf("ESTOU LIGADO\n\n");
#endif

    srand((unsigned int)time(NULL));

    vector_ini(&my_vector);
    person_ini(&my_person);

    // for (int j = 0; j < ELEMENTS; j++)
    // {
    for (int i = 0; i < ELEMENTS; i++)
    {
        generate_random_data(&my_person);
        add_data(&my_vector, &my_person);
    }

    Stopwatch sw = stopwatch_start();
    generate_random_data(&my_person);
    add_data(&my_vector, &my_person);
    stopwatch_stop(&sw);
    float time = stopwatch_ms(&sw);
    save_time_to_file("Insercao_1_item_Vector_100_Elements_NAIVE", time);
    // para funçao search

    Stopwatch sw2 = stopwatch_start();
    strcpy(my_person.name, "DCBA");

    vector_search(&my_vector, &my_person);
    stopwatch_stop(&sw2);
    float time2 = stopwatch_ms(&sw2);
    save_time_to_file("Pesquisa_1_item_Vector_100_Elements_NAIVE", time2);

    // }
    print_data(&my_vector);
    print_only_nodes(&my_vector);
    printf("VECTOR SIZE -> %d\n\n", my_vector.size);
}
