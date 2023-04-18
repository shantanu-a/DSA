#include "linkedlist.h"
#include <stdio.h>

static node *create_node_for_list(process p);
// Check header files for documentation/ function description
process_linked_list *create_empty_process_linked_list() {
    process_linked_list* list=(process_linked_list*)malloc(sizeof(process_linked_list));
    list->size=0;
    list->head=NULL;
    return list;
    // COMPLETE!
}

bool add_first_to_linked_list(process_linked_list *list, process p) {
    return add_at_index_linked_list(list, 0, p);
}

bool add_last_to_linked_list(process_linked_list *list, process p) {
    return add_at_index_linked_list(list, list->size, p);
}

bool add_at_index_linked_list(process_linked_list *list, size_t index, process p) {
   if(index>list->size){
    return false;
   }

   node* n=create_node_for_list(p);

   if(list->size==0){
    list->head=n;
    n->next=NULL;
    n->previous=list->head;
    list->size++;
    return true;
   }

   node* temp=list->head;
   while(--index){
    temp=temp->next;
   }
   
   temp->next=n;
   n->previous=temp;
   n->next=NULL;
   list->size++;
   return true;
   // COMPLETE!
}

bool remove_first_linked_list(process_linked_list *list, process *p) {
    if (list->size == 0) {
        return false;
    }
    node* temp=list->head;

    if(list->size==1){
        free(temp);
        list->head=NULL;
        list->size--;
        return true;
    }

    list->head=temp->next;
    (temp->next)->previous=list->head;
    list->size--;
    free(temp);
    return true;
   // COMPLETE!
}

bool remove_last_linked_list(process_linked_list *list, process *p) {
    if (list->size == 0) {
        return false;
    }

    node* temp=list->head;
    int size=list->size;
    while(--size){
        temp=temp->next;
    }

    temp->previous=NULL;
    free(temp);
    list->size--;
    return true;
   // COMPLETE!
}

size_t get_size_linked_list(process_linked_list *list) {
    return list->size;
}

void print_linked_list(process_linked_list *list) {
    node *tracker = list->head;
    for (int i = 0; i < list->size; ++i) {
        printf("%d => ", tracker->process->pid);
        tracker = tracker->next;
    }
    printf("%s", "\n");
}

static node *create_node_for_list(process p) {
    process *to_add_process = malloc(sizeof(process));
    if (!to_add_process) {
        return NULL;
    }
    *to_add_process = p;
    node *new_node = malloc(sizeof(node));
    if (!new_node) {
        return NULL;
    }
    new_node->process = to_add_process;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}


void destroy_linked_list(process_linked_list *list) {
    node *current = list->head->next;
    for (int i = 0; i < list->size; ++i) {
        node *next = current->next;
        free(current->process);
        current = next;
    }
    free(list->head);
    free(list);
}

