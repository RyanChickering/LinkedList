//
//  LinkedList.h
//  LinkedList
//
//  Created by Ryan Chickering on 7/17/20.
//  Copyright © 2020 Ryan Chickering. All rights reserved.
//

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

#endif /* LinkedList_h */
