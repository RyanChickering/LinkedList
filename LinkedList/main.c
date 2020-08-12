//
//  main.c
//  LinkedList
//
//  Created by Ryan Chickering on 7/17/20.
//  Copyright © 2020 Ryan Chickering. All rights reserved.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

int main(int argc, const char * argv[]) {
    struct LinkedList* list = init();
    int array[] = {1, 3, 9, 7, 12, 14};
    for(int i = 0; i < sizeof(array)/sizeof(int); i++){
        add(list, array[i]);
    }
    for(int i = 0; i < list->size; i++){
        printf("%i, ", get(list, i));
    }
    delete(list, 4);
    printf("\n");
    for(int i = 0; i < list->size; i++){
        printf("%i, ", get(list, i));
    }
    insert(list, 3, 2);
    printf("\n");
    for(int i = 0; i < list->size; i++){
        printf("%i, ", get(list, i));
    }
    free(list);
    return 0;
}
