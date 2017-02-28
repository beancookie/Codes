//
// Created by larobyo on 22/02/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "laro_list.h"

void laro_list_add(List *list, int value)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    // search the last node
    Node *last_node = list->head;
    if (last_node) {
        while (last_node->next) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    } else {
        list->head = new_node;
    }
}

void laro_list_remove(List *list, int value)
{
    Node *pre_node, *curr_node;
    for (curr_node = list->head; curr_node; pre_node = curr_node, curr_node = curr_node->next) {
        if (curr_node->value == value) {
            if (pre_node)
                // remove current node
                pre_node->next = curr_node->next;
            else
                list->head = curr_node->next;
            free(curr_node);
            break;
        }
    }
}

void laro_list_list(List *list)
{
    for (Node *iter = list->head; iter; iter = iter->next)
        printf("%d ", iter->value);
}

void laro_list_free(List *list)
{
    Node *curr_node, *next_node;
    for (curr_node = list->head; curr_node; curr_node = next_node) {
        next_node = curr_node->next;
        free(curr_node);
    }
}