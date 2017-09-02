/*
  도전! 프로그래밍3 - 4번
  도전 3 예제를 여러 번 실행해보면 출력되는 난수가 규칙적이라는 특성을 발견할 수 있다.
  이 난수들은 프로그램을 여러 번 실행해도 같은 값으로 출력되므로 진짜 난수라 할 수 없다.
  그래서 rand 함수가 반환하는 난수를 가리켜 '의사 난수(pseudo-random number'라 하는 것!
  ANSI 표준에서는 이러한 문제를 어느 정도 해결할 수 있도록 srand라는 함수를 정의하였다.

  #include <stdlib.h>
  void srand(unsigned int seed);  // 발생할 난수의 씨드 값 지정
  이 함수는 하나의 값을 전달받는데 이를 씨드 값(seed)이라 한다.
  씨드 값이 무엇이냐에 따라서 rand 함수가 반환하는 난수의 형태가 달라진다.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int seed, i;
  printf("씨드 값 입력: ");
  scanf("%d", &seed);
  srand(seed);    // 씨앗을 심는다.

  for (i = 0; i < 5; i++) {
    printf("정수 출력: %d \n", rand()%100);     // 열매를 수확한다.
  }
  return 0;
}

/* 수행결과
  씨드 값 입력: 5
  정수 출력: 35
  정수 출력: 45
  정수 출력: 24
  정수 출력: 96
  정수 출력: 56
  Program ended with exit code: 0
*/

/*
  프로그램을 여러 번 실행시켜도 동일한 값이 출력되는 문제는 해결했으나
  프로그램을 실행할 때마다 씨드 값을 일일이 입력받을 수는 없는 일! => '시스템의 현재시간'을 이용하자!
  컴퓨터의 현재시간은 계속 변하기 때문에 매번 다른 씨앗을 얻는 도구로 활용이 가능하다!
  time.h에 선언되어 있는 time 함수는 컴퓨터의 현재시간과 1970년 1월 1일 이후의 시간 차를 초단위로 계산해 반환.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int i;
  srand((int)time(NULL));   // 현재시간을 이용해서 씨드 설정. 단순히 시간정보 반환이 목적이라면 NULL 전달하면 됨
  for (i = 0; i < 5; i++) {
    printf("정수 출력: %d \n", rand()%100);
  }
  return 0;
}

/* 수행결과
  정수 출력: 35
  정수 출력: 24
  정수 출력: 52
  정수 출력: 39
  정수 출력: 89
  Program ended with exit code: 0
*/

/* 리얼 문제 4
  1. 주사위 두 개를 던졌을 때의 결과를 출력하는 프로그램 작성하기
  2. 결과는 예측이 불가능해야 한다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand((int)time(NULL));
  printf("주사위 1의 결과: %d\n", rand()%6 + 1);
  printf("주사위 2의 결과: %d\n", rand()%6 + 1);
  return 0;
}

/* 수행결과
  주사위 1의 결과: 1
  주사위 2의 결과: 5
  Program ended with exit code: 0
*/
