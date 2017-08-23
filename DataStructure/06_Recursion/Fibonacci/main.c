//
//  main.c
//
//  Created by Lulie on 2017. 7. 17..
//  Copyright © 2017년 Lulie. All rights reserved.
//

#include <stdio.h>

// 재귀 호출을 이용한 피보나치 수열
int fib(int n) {
    int ret = 0;
    
    if (n == 0) {
        ret = 0;
    }
    else if (n == 1) {
        ret = 1;
    }
    else {
        ret = fib(n-1) + fib(n-2);
    }
    
    return ret;
}

// 반복 호출을 이용한 피보나치 수열
int fib_iter(int n) {
    int ret = 0;
    
    if (n < 2) {
        ret = n;
    }
    else {
        int i = 0, temp = 0, current = 1, last = 0;
        
        for(i = 2; i <= n; i++) {
            temp = current;
            current += last;
            last = temp;
        }
        
        ret = current;
    }
    
    return ret;
}


int main(int arc, char **argv) {
    int i = 0, input_value = 10;
    int	result = 0;
    
    printf("------- Recursive Method -------\n");
    for(i = 0; i < input_value; i++) {
        result = fib(i);
        printf("fib( %d ) = %d\n", i, result);
    }
    
    printf("\n------- Iterative Method -------\n");
    for(i = 0; i < input_value; i++) {
        result = fib_iter(i);
        printf("fib( %d ) = %d\n", i, result);
    }
    return 0;
}
