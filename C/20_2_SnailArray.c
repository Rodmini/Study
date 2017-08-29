/*
  도전! 프로그래밍3 - 2번
  1. 달팽이 배열을 만들어서 출력하는 프로그램을 작성하기
  2. 사용자로부터 하나의 숫자(n)를 입력받아서 n * n의 길이에 해당하는 달팽이 배열을 출력하자
  ex. 숫자를 입력하시오: 5
  1   2   3   4   5
  16  17  18  19  6
  15  24  25  20  7
  14  23  22  21  8
  13  12  11  10  9
*/

#include <stdio.h>

void SnailArray(int (*arr)[100], int size) {
  int i, j;
  int x = 0, y = -1;
  int value = 1;
  int limit = size;
  int plus = 1;
  while (limit != 0) {
    for (i = 0; i < limit; i++) {
      y += plus;
      arr[x][y] = value++;
    }
    limit--;

    for (j = 0; j < limit; j++) {
      x += plus;
      arr[x][y] = value++;
    }
    plus *= -1;
  }

  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      printf("%3d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  int n;
  printf("숫자를 입력하시오: ");
  scanf("%d", &n);
  int arr[100][100] = {0, };

  SnailArray(arr, n);
  return 0;
}


/* 수행결과
  숫자를 입력하시오: 5
  1   2   3   4   5
  16  17  18  19   6
  15  24  25  20   7
  14  23  22  21   8
  13  12  11  10   9
  Program ended with exit code: 0


  숫자를 입력하시오: 7
  1   2   3   4   5   6   7
  24  25  26  27  28  29   8
  23  40  41  42  43  30   9
  22  39  48  49  44  31  10
  21  38  47  46  45  32  11
  20  37  36  35  34  33  12
  19  18  17  16  15  14  13
  Program ended with exit code: 0
*/
