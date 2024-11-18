#include <stdio.h>
#include "double_list.h"

int main() {
    DoubleList* list = create_list(); // Inicializar una lista vacía

    // Insertar valores iniciales
    insert_append(list, 1);
    insert_append(list, 2);
    insert_append(list, 3);
    insert_append(list, 4);

    printf("Lista inicial:\n");
    print_forward(list);

    // Secuencia de operaciones en la lista
    insert_append(list, 100); // Agregar al final
    insert_start(list, 15); // Agregar al inicio
    insert_position(list, 10, 1); // Agregar en la posición 1
    insert_position(list, 30, 3); // Agregar en la posición 3
    insert_append(list, 50); // Agregar al final

    printf("\nLista después de los ingresos:\n");
    print_forward(list);

    // Eliminar el primer nodo con el valor 10
    delete_node(list, 10);

    printf("\nLista después de eliminar el primer nodo con el valor de 10:\n");
    print_forward(list);

    // Prueba de la función search_node
    printf("\nResultados de búsqueda:\n");
    Node* foundNode = search_node(list, 15); // Buscar el nodo con valor 15
    if (foundNode) {
        printf("Nodo con valor 15 encontrado.\n");
    } else {
        printf("Nodo con valor 15 no encontrado.\n");
    }

    foundNode = search_node(list, 50); // Buscar el nodo con valor 50
    if (foundNode) {
        printf("Nodo con valor 50 encontrado.\n");
    } else {
        printf("Nodo con valor 50 no encontrado.\n");
    }

    // Funciones de impresión
    printf("\nLista hacia adelante:\n");
    print_forward(list); // Imprimir la lista hacia adelante
    printf("\nLista hacia atrás:\n");
    print_backward(list); // Imprimir la lista hacia atrás

    // Liberar la lista
    free_list(list);

    return 0;
}
