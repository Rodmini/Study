# 배열로 구현한 스택(ArrayStack)
## 1. struct
- C의 배열을 이용한 것이므로 생성할 때 반드시 **스택의 크기**를 지정해주어야 한다.
- `maxElementCount`: 최대 노드 개수
- `currentElementCount`: 현재 노드 개수
- `pElement`: 원소 저장을 위한 배열 포인터
- **Top** : (currentElementCount - 1)번째 노드<br><br>
## 2. Abstract Data Type

### 2.1 createArrayStack 스택의 생성
- `size`: 배열의 크기 입력 파라미터 값이 0보다 큰지 확인
- ArrayStack 메모리 할당 후 memset을 이용하여 초기화
- 입력받은 size만큼의 크기를 갖는 원소를 저장하는 배열 메모리 할당 후 초기화
- 오류가 발생하지 않는 경우 생성된 배열 포인터를 반환

### 2.2 pushAS 스택에 새로운 노드를 추가
- 입력받은 파라미터의 유효성 검증
- `isArrayStackFull`을 통해 스택에 노드를 추가할 여유공간이 있는지 확인
    + 배열에 새로운 원소를 추가
    + `currentElementCount`값을 1 증가시킴으로서 **top**의 위치를 변경
- 새 노드를 추가했는지 여부를 `ret`의 TRUE/FALSE 결과값으로 반환

### 2.3 popAS 스택의 탑(top) 노드를 반환
- 입력받은 파라미터의 유효성 검증
- `isArrayStackEmpty`을 통해 스택에서 빼낼 노드가 존재하는지 확인
- top 위치에 해당하는 노드를 pReturn 배열 포인터에 저장
- `currentElementCount`값을 1 감소시킴으로서 **top**의 위치를 변경
- 저장된 배열 포인터 pReturn을 반환

### 2.4 peekAS 스택의 탑(top) 노드를 반환
- 입력받은 파라미터의 유효성 검증
- `isArrayStackEmpty`을 통해 스택에서 빼낼 노드가 존재하는지 확인
- top 위치를 추가 조작할 필요없이 top 위치에 해당하는 값의 포인터만 반환

### 2.5 deleteArrayStack 스택의 삭제(메모리 해제)
- 스택의 노드 정보를 담고 있는 `pElement`의 메모리 할당 해제
- 스택 구조체 `ArrayStack` 메모리 할당 해제

### 2.6 isArrayStackFull 스택 공간이 가득차있는지 확인
- `currentElementCount`값과 `maxElementCount`값이 동일한지를 체크함으로서 스택 Full 여부 확인가능

### 2.7 isArrayStackEmpty 스택 공간이 비어있는지 확인
- `currentElementCount`값이 0인지 여부를 통해 스택 Empty 여부 확인가능<br><br>

## 3. 코드 수행결과
```
stack size: 6, current el count: 4
  [5]- [Empty]
  [4]- [Empty]
  [3]-[D]
  [2]-[C]
  [1]-[B]
  [0]-[A]
Pop value-[D]
stack size: 6, current el count: 3
  [5]- [Empty]
  [4]- [Empty]
  [3]- [Empty]
  [2]-[C]
  [1]-[B]
  [0]-[A]
peek value-[C]
stack size: 6, current el count: 3
  [5]- [Empty]
  [4]- [Empty]
  [3]- [Empty]
  [2]-[C]
  [1]-[B]
  [0]-[A]
Program ended with exit code: 0
```
