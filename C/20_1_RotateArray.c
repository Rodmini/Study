/*
  도전! 프로그래밍3 - 1번
  1. 길이가 4 * 4인 int형 배열을 선언
  2. 배열의 요소들을 90도씩 이동시킨 결과를 출력하는 프로그램을 작성하기

  초기화 배열의 요소
  1   2   3   4
  5   6   7   8
  9  10  11  12
 13  14  15  16
*/

#include <stdio.h>
void RotationCall(int (*ptr)[4], int num) {
  if (num == 0) {
    return;
  } else {
    printf("---------------------------- Rotation! -----\n");
    int newArr[4][4] = {0,};
    int i, j;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        newArr[j][3-i] = ptr[i][j];
      }
    }
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        printf("%3d ", newArr[i][j]);
      }
      printf("\n");
    }
    RotationCall(newArr, --num);
  }
}

int main(void) {
  int arr[][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      printf("%3d ", arr[i][j]);
    }
    printf("\n");
  }

  RotationCall(arr, 3); // Rotation을 총 3번 수행한 결과를 출력
  return 0;
}

/* 수행 결과
  1   2   3   4
  5   6   7   8
  9  10  11  12
  13  14  15  16
  ---------------------------- Rotation! -----
  13   9   5   1
  14  10   6   2
  15  11   7   3
  16  12   8   4
  ---------------------------- Rotation! -----
  16  15  14  13
  12  11  10   9
  8   7   6   5
  4   3   2   1
  ---------------------------- Rotation! -----
  4   8  12  16
  3   7  11  15
  2   6  10  14
  1   5   9  13
  Program ended with exit code: 0
*/
