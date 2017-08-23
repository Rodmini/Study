//
//  arraystack.c
//  ArrayStack
//
//  Created by Lulie on 2017. 7. 7..
//  Copyright © 2017년 Lulie. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"

// create new stack
ArrayStack* createArrayStack(int size) {
    ArrayStack *pReturn = NULL;
    
    if (size > 0) {
        pReturn = (ArrayStack *)malloc(sizeof(ArrayStack));
        if (pReturn != NULL) {
            memset(pReturn, 0, sizeof(ArrayStack));
            pReturn->maxElementCount = size;
        } else {
            printf("Error! Memory allocation, createArrayStack()\n");
            return NULL;
        }
        
        pReturn->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * size);
        
        if (pReturn->pElement != NULL) {
            memset(pReturn->pElement, 0, sizeof(ArrayStackNode) * size);
        } else {
            printf("Error! Memory allocation2, createArrayStack()\n");
            free(pReturn);
            return NULL;
        }
    } else {
        printf("Error! The size of Stack should be more than 0\n");
        return NULL;
    }
    
    return pReturn;
}


// stack push
int pushAS(ArrayStack* pStack, ArrayStackNode element) {
    int ret = FALSE;
    if (pStack != NULL) {
        if (isArrayStackFull(pStack) == FALSE) {
            pStack->pElement[pStack->currentElementCount] = element;
            pStack->currentElementCount++;
            ret = TRUE;
        } else {
            printf("Error! Stack is FUll! pushAS()\n");
        }
    }
    return ret;
}


// stack pop
ArrayStackNode* popAS(ArrayStack* pStack) {
    ArrayStackNode *pReturn = NULL;
    if (pStack !=NULL) {
        if (isArrayStackEmpty(pStack) == FALSE) {
            pReturn = (ArrayStackNode *)malloc(sizeof(ArrayStackNode));
            if (pReturn != NULL) {
                *pReturn = pStack->pElement[pStack->currentElementCount - 1];
                pStack->currentElementCount--;
            } else {
                printf("Error! Memory Allocation! popAS()\n");
            }
        }
    }
    return pReturn;
}


// stack peek
ArrayStackNode* peekAS(ArrayStack* pStack) {
    ArrayStackNode* pReturn = NULL;
    if (pStack != NULL) {
        if (isArrayStackEmpty(pStack) == FALSE) {
            pReturn = &(pStack->pElement[pStack->currentElementCount - 1]);
        }
    }
    return pReturn;
}


// delete array stack
void deleteArrayStack(ArrayStack* pStack) {
    if (pStack != NULL) {
        if (pStack->pElement != NULL) {
            free(pStack->pElement);
        }
        free (pStack);
    }
}


// check arraystack full
int isArrayStackFull(ArrayStack* pStack) {
    int ret = FALSE;
    if (pStack != NULL) {
        if (pStack->currentElementCount == pStack->maxElementCount) {
            ret = TRUE;
        }
    }
    return ret;
}


// check arraystack empty
int isArrayStackEmpty(ArrayStack* pStack) {
    int ret = FALSE;
    if (pStack != NULL) {
        if (pStack->currentElementCount == 0) {
            ret = TRUE;
        }
    }
    return ret;
}




