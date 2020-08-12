//
//  LinkedList.h
//  LinkedList
//
//  Created by Ryan Chickering on 7/17/20.
//  Copyright © 2020 Ryan Chickering. All rights reserved.
//

#include <stdbool.h>

#ifndef LinkedList_h
#define LinkedList_h

//Struct for the nodes in the linked list.
struct node {
    int value;
    struct node* next;
};


struct LinkedList {
    struct node* head;
    int size;
};

bool add(struct LinkedList* linklist, int val);

struct LinkedList* init(void);

bool insert(struct LinkedList* linklist, int index, int val);

bool delete(struct LinkedList* linklist, int index);

int get(struct LinkedList* linklist, int index);

#endif /* LinkedList_h */
