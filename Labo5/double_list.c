#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

// Crear una nueva lista doblemente enlazada
DoubleList* create_list() {
    DoubleList* list = (DoubleList*)malloc(sizeof(DoubleList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Insertar un nodo al inicio de la lista
void insert_start(DoubleList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    new_node->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = new_node;
    } else {
        list->tail = new_node; // Si la lista estaba vacía, el nuevo nodo es también el tail
    }
    list->head = new_node;
}

// Agregar un nuevo nodo al final de la lista
void insert_append(DoubleList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        new_node->prev = NULL;
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Insertar un nodo en una posición específica
void insert_position(DoubleList* list, int data, int position) {
    if (position == 0) {
        insert_start(list, data);
        return;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    Node* current = list->head;

    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        // Si la posición es mayor que el tamaño de la lista, lo agregamos al final
        insert_append(list, data);
        free(new_node);
    } else {
        new_node->next = current->next;
        new_node->prev = current;
        current->next = new_node;

        if (new_node->next != NULL) {
            new_node->next->prev = new_node;
        } else {
            list->tail = new_node; // Actualizar tail si se inserta al final
        }
    }
}

// Eliminar un nodo basado en el contenido del data
void delete_node(DoubleList* list, int data) {
    Node* current = list->head;

    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->head = current->next; // Si es el primer nodo
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev; // Si es el último nodo
            }

            free(current);
            return; // Solo eliminar el primer nodo encontrado
        }
        current = current->next;
    }
}

// Buscar un nodo basado en su data
Node* search_node(DoubleList* list, int data) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return current; // Retorna el nodo encontrado
        }
        current = current->next;
    }
    return NULL; // Retorna NULL si no se encuentra
}

// Imprimir la lista hacia adelante
void print_forward(DoubleList* list) {
    Node* current = list->head;
    while (current != NULL) {
	        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Imprimir la lista hacia atrás
void print_backward(DoubleList* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Liberar la memoria de la lista
void free_list(DoubleList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
