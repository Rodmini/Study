//
//  linkedstack.h
//  LinkedStack
//
//  Created by Lulie on 2017. 7. 7..
//  Copyright © 2017년 Lulie. All rights reserved.
//

#ifndef linkedstack_h
#define linkedstack_h

#define TRUE 1
#define FALSE 0

// struct
typedef struct StackNodeType {
    char data;
    struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType {
    int currentElementCount;
    StackNode* pTopElement;
} LinkedStack;


// function
LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

#endif /* linkedstack_h */
