//
//  LinkedList.c
//  LinkedList
//
//  Created by Ryan Chickering on 7/17/20.
//  Copyright © 2020 Ryan Chickering. All rights reserved.
//

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

static struct node* nodeAtIndex(struct LinkedList* linklist, int index){
    struct node* currnode = linklist->head;
    int tracker = 0;
    struct node* nextnode = currnode;
    while(nextnode != NULL && tracker <= index){
        currnode = nextnode;
        nextnode = currnode->next;
        tracker++;
    }
    return currnode;
}

//Method to add a new node to the end of the list
bool add(struct LinkedList* linklist, int val){
    if(linklist->size == 0){
        linklist->head->value = val;
        linklist->size++;
        return true;
    }
    struct node* currnode = nodeAtIndex(linklist, linklist->size);
    struct node* newnode = malloc(sizeof(struct node));
    newnode->value = val;
    newnode->next = NULL;
    currnode->next = newnode;
    linklist->size++;
    return true;
}

struct LinkedList* init(){
    struct LinkedList* linklist = malloc(sizeof(struct LinkedList));
    linklist->head = malloc(sizeof(struct node));
    linklist->head->next = NULL;
    linklist->head->value = 0;
    linklist->size = 0;
    return linklist;
}

//Method that inserts a value into a specified index of a linked list
bool insert(struct LinkedList* linklist, int index, int val){
    struct node* currnode = nodeAtIndex(linklist, index-1);
    struct node* tempnode = currnode->next;
    struct node* newnode = malloc(sizeof(struct node));
    newnode->next = tempnode;
    newnode->value = val;
    currnode->next = newnode;
    linklist->size++;
    return true;
}

//method that delets a node from a linked list
bool delete(struct LinkedList* linklist, int index){
    struct node* currnode = nodeAtIndex(linklist, index-1);
    struct node* delnode = currnode->next;
    currnode->next = delnode->next;
    free(delnode);
    linklist->size--;
    return true;
}

//Method to get the value of an index
int get(struct LinkedList* linklist, int index){
    if(index > linklist->size){
        printf("Index out of bounds!\n");
        return -1;
    }
    struct node* currnode = nodeAtIndex(linklist, index);
    return currnode->value;
}

//[1,3,9,7,14]
//When at a node, save the next node. Turn the currnode's next to point to the previous node. Set currnode to the
//node that was previously next. Repeat.
void reverse(struct LinkedList* linklist){
    struct node* prevnode = linklist->head;
    struct node* currnode = linklist->head->next;
    prevnode->next = NULL;
    while(currnode->next != NULL){
        struct node* nextnode = currnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    currnode->next = prevnode;
    linklist->head = currnode;
}




