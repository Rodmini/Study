/*
  도전! 프로그래밍3 - 3번
  1. 난수란 임의의, 정해지지 않은, 무엇이 될지 모르는 수를 의미한다.
  # include <stdlib.h>
  int rand(void);     // 의사 난수 (pseudo-random number)를 반환

  2. 이 예제를 활용하여 0이상 99이하의 난수를 총 5개 생성하는 프로그램 작성하기
  힌트 : %연산자를 적절히 활용하면 된다.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i;
  printf("난수의 범위: 0부터 %d까지 \n", RAND_MAX); // 생성될 수 있는 난수의 최댓값

  printf("0이상 99이하의 난수를 총 5개 생성하기\n");
  for (i = 0; i < 5; i++) {
    printf("난수 출력: %d \n", rand()%100);
  }
  return 0;
}

/* 수행결과
  난수의 범위: 0부터 2147483647까지
  0이상 99이하의 난수를 총 5개 생성하기
  난수 출력: 7
  난수 출력: 49
  난수 출력: 73
  난수 출력: 58
  난수 출력: 30
  Program ended with exit code: 0
*/
