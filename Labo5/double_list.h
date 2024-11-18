#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} DoubleList;

DoubleList* create_list();
void insert_start(DoubleList* list, int data);
void insert_append(DoubleList* list, int data);
void insert_position(DoubleList* list, int data, int position);
void delete_node(DoubleList* list, int data);
Node* search_node(DoubleList* list, int data);
void print_forward(DoubleList* list);
void print_backward(DoubleList* list);
void free_list(DoubleList* list);

#endif
