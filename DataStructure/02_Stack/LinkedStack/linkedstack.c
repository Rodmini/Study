//
//  linkedstack.c
//  LinkedStack
//
//  Created by Lulie on 2017. 7. 7..
//  Copyright © 2017년 Lulie. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"

// create Linked Stack
LinkedStack* createLinkedStack() {
    LinkedStack *pReturn = NULL;
    pReturn = (LinkedStack *)malloc(sizeof(LinkedStack));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(LinkedStack));
    } else {
        printf("Error! Memory Allocation! createLinkedStack()\n");
        return NULL;
    }
    return pReturn;
}


// push
int pushLS(LinkedStack* pStack, StackNode element) {
    int ret = FALSE;
    StackNode *pNode = NULL;
    if (pStack != NULL) {
        pNode = (StackNode *)malloc(sizeof(StackNode));
        if (pNode != NULL) {
            memset(pNode, 0, sizeof(StackNode));
            *pNode = element;
            pNode->pLink = pStack->pTopElement;
            
            pStack->pTopElement = pNode;
            
            pStack->currentElementCount++;
            ret = TRUE;
        } else {
            printf("Error! Memory Allocation! pushLS()\n");
        }
    }
    return ret;
}


// pop
StackNode* popLS(LinkedStack* pStack) {
    StackNode *pReturn = NULL;
    if (pStack != NULL) {
        if (isLinkedStackEmpty(pStack) == FALSE) {
            pReturn = pStack->pTopElement;
            pStack->pTopElement = pReturn->pLink;
            
            pReturn->pLink = NULL;
            
            pStack->currentElementCount--;
        }
    }
    return pReturn;
}


// peek
StackNode* peekLS(LinkedStack* pStack) {
    StackNode *pReturn = NULL;
    if (pStack != NULL) {
        if (isLinkedStackEmpty(pStack) == FALSE) {
            pReturn = pStack->pTopElement;
        }
    }
    return pReturn;
}


// delete Linked Stack
void deleteLinkedStack(LinkedStack* pStack) {
    StackNode *pNode = NULL;
    StackNode *pDelNode = NULL;
    
    if (pStack != NULL) {
        pNode = pStack->pTopElement;
        while (pNode != NULL) {
            pDelNode = pNode;
            pNode = pNode->pLink;
            free(pDelNode);
        }
        free(pStack);
    }
}


// check Stack Full
int isLinkedStackFull(LinkedStack* pStack) {
    int ret = FALSE;
    return ret;
}


// check Stack Empty
int isLinkedStackEmpty(LinkedStack* pStack) {
    int ret = FALSE;
    
    if (pStack != NULL) {
        if (pStack->currentElementCount == 0) {
            ret = TRUE;
        }
    }
    return ret;
}

