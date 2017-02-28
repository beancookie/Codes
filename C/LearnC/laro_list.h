//
// Created by larobyo on 22/02/2017.
//

#ifndef LEARNC_LIST_H
#define LEARNC_LIST_H

typedef struct _node {
    int value;
    struct _node *next;
} Node;

typedef struct _list {
    Node *head;
} List;

void laro_list_add(List *list, int value);

void laro_list_remove(List *list, int value);

void laro_list_list(List *list);

void laro_list_free(List *list);

#endif //LEARNC_LIST_H
