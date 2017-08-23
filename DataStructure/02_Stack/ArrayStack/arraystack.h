//
//  arraystack.h
//  ArrayStack
//
//  Created by Lulie on 2017. 7. 7..
//  Copyright © 2017년 Lulie. All rights reserved.
//

#ifndef arraystack_h
#define arraystack_h

#define TRUE 1
#define FALSE 0

typedef struct {
    char data;
} ArrayStackNode;

typedef struct ArrayStackType {
    int maxElementCount;
    int currentElementCount;
    ArrayStackNode *pElement;
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int pushAS(ArrayStack* pStack, ArrayStackNode element);
ArrayStackNode* popAS(ArrayStack* pStack);
ArrayStackNode* peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);

#endif /* arraystack_h */
