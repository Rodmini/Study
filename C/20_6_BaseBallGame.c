/*
  도전! 프로그래밍3 - 6번
  1. 숫자 맞추기 게임 (야구 게임) 프로그램 작성하기
  2. 컴퓨터는 0에서 9사이의 숫자 중에서 서로 다른 세 개의 숫자를 고르고, 사용자는 이것을 맞춰야 한다.
  3. 중요한 것은 숫자의 순서까지 정확히 맞춰야 한다는 것이다.
  4. 단, 사용자가 예상한 숫자를 입력할 때마다 컴퓨터는 입력된 숫자와 컴퓨터 자신의 숫자가 얼마나 비슷한지를 알려줘야 한다.
  5. 예를 들어, 컴퓨터의 숫자가 1 4 9 이고, 사용자 입력 숫자가 4 0 9일 경우, 두 개의 숫자 4와 9가 일치한다.
    여기서 9는 숫자와 위치까지 일치하지만 (1 strike), 4는 숫자만 일치한다 (1 ball) ==> 1strike, 1ball
  6. 만약 사용자가 1 4 9를 입력할 경우, 3strike, 0ball이 되어서 프로그램은 종료가 된다.
  7. 이 때 몇 번 만에 3 strike를 얻어냈는지에 대해서도 출력해주자.

  ex.
    Start Game!
    3개의 숫자 선택: 1 2 8
    1번째 도전 결과: 1strike, 1ball!!
    3개의 숫자 선택: 3 0 8
    2번째 도전 결과: 2strike, 0ball!!
    3개의 숫자 선택: 2 0 8
    3번째 도전 결과: 3strike, 0ball!!

    Game Over!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand((int)time(NULL));
  int bot_num[3] = {rand()%10, rand()%10, rand()%10};
  printf("bot num : %d %d %d \n", bot_num[0], bot_num[1], bot_num[2]);
  printf("Start Game!\n");
  int user_num[3] = {0, };
  int i, j, challenge = 0;
  int strike, ball;

  do {
    strike = 0, ball = 0;
    printf("3개의 숫자 선택: ");
    scanf("%d %d %d", &user_num[0], &user_num[1], &user_num[2]);
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        if (user_num[i] == bot_num[j]) {
          if (i == j) {
            strike++;
          } else {
            ball++;
          }
        }
      }
    }
    printf("%d번째 도전 결과: %dstrike, %dball!!\n", ++challenge, strike, ball);
  } while (strike < 3);

  printf("Game Over!\n");
  return 0;
}

/* 수행결과
  bot num : 8 7 2
  Start Game!
  3개의 숫자 선택: 8 0 1
  1번째 도전 결과: 1strike, 0ball!!
  3개의 숫자 선택: 8 2 9
  2번째 도전 결과: 1strike, 1ball!!
  3개의 숫자 선택: 8 2 7
  3번째 도전 결과: 1strike, 2ball!!
  3개의 숫자 선택: 8 7 2
  4번째 도전 결과: 3strike, 0ball!!
  Game Over!
  Program ended with exit code: 0
*/
