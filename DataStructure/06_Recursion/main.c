//
//  main.c
//
//  Created by Lulie on 2017. 7. 17..
//  Copyright © 2017년 Lulie. All rights reserved.
//

#include <stdio.h>

int factorial(int n) { // 재귀 호출
    int ret = 0;
    
    if (n <= 1) {
        ret = 1;
    }
    else {
        ret = n * factorial(n - 1);
    }
    
    return ret;
}

int factorial_iter(int n) { // 반복 호출
    int ret = 1;
    int i = 1;
    
    for(i = n; i > 1; i--) {
        ret = ret * i;
    }
    
    return ret;
}

int main(int arc, char **argv) {
    int input_value = 3;
    int	result = 0;
    
    result = factorial(input_value);
    
    printf("%d! = %d\n", input_value, result);
    
    result = factorial_iter(input_value );
    
    printf("%d! = %d\n", input_value, result);
    
    return 0;
}

