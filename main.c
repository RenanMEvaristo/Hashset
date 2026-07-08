#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "util.h"
#include "struct.h"
#include "node.h"
#include "vector.h"
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

    vector_ini(&my_vector);
    person_ini(&my_person);

    strcpy(my_person.name, "A");
    my_person.age = 20;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "AB");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "BA");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "ABC");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "CBA");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "BAC");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "ABCD");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "DCBA");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "ABCDE");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "ABCDEF");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "ABCDEFG");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "ABCDEFGH");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "ABCDEFGHI");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "ABCDEFGHIJ");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "ABCDEFGHIJK");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "ABCDEFGHIJKL");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "ABCDEFGHIJKLM");
    my_person.age = 40;
    add_data(&my_vector, &my_person);

    strcpy(my_person.name, "ABCDEFGHIJKLMN");
    my_person.age = 40;
    add_data(&my_vector, &my_person);
    // para funçao search
    strcpy(my_person.name, "ABCDEFGHIJK");

    vector_search(&my_vector, &my_person);
    
    print_data(&my_vector);
    print_only_nodes(&my_vector);
}
