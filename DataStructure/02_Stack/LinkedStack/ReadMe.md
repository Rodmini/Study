# 연결리스트로 구현한 스택(LinkedStack)
## 1. struct
- 앞에서 배열로 구현한 스택과 달리 **스택의 크기**를 미리 지정하지 않아도 되는 장점!
- 왜? 노드를 추가할 때마다 동적으로 메모리를 할당해주면 되기 때문!
- `currentElementCount`: 현재 노드 개수
- 최대 저장 가능한 노드 개수 maxElementCount가 필요없으므로 Overflow 현상 발생하지 않는다는 장점!
- `pTopElement`: Top 노드에 대한 포인터
- `StackNode`: 노드를 나타내는 구조체. 링크된 다음 노드에 대한 포인터를 저장하는 `pLink`를 추가로 가짐
    + `data`: 값
    + `pLink`: 링크 저장을 위한 포인터
- **LinkedList**와의 구현 차이
    + 스택은 한 쪽 끝에서만 자료를 넣고 뺄 수 있는 구조로 되어있기 때문에 범용적인 리스트의 사용이 오히려 비효율적일 수 있음
        - Top 노드에 접근하기 위해 매 번 리스트 전체를 순회 `O(n)` 해야하므로…
    + 일반적인 리스트와 달리 자료 사이의 링크 방향을 역순으로 설정 => Top 노드로 바로바로 접근 가능
        - Top 노드에 대한 포인터는 항상 마지막에 추가된 자료를 가리키게 된다.
        - 스택에 맨 처음 추가된 노드는 다음노드(pLink)값이 NULL이 된다.<br><br>

## 2. Abstract Data Type

### 2.1 createLinkedStack 스택의 생성
- LinkedStack 메모리 할당 후 memset을 이용하여 현재 노드 개수, top 노드 초기화
- 오류가 발생하지 않는 경우 생성된 리스트 포인터를 반환

### 2.2 pushLS 스택에 새로운 노드를 추가
- 새로운 노드에 대해 메모리 할당 및 초기화
- 입력 파라미터로 받은 데이터를 초기화 한 새 노드에 대입
- 새로운 노드의 다음노드(pLink)를 기존 스택의 top 노드로 설정
    + `pNode->pLink = pStack->pTopElement;`
- LinkedStack의 top 노드(pTopElement)를 새로 추가된 노드로 설정
    + `pStack->pTopElement = pNode;`
- `currentElementCount`값을 1 증가시킴
- 새 노드 추가 성공여부를 `ret`의 TRUE/FALSE 결과값으로 반환

### 2.3 popLS 스택의 탑(top) 노드를 반환
- `isLinkedStackEmpty`을 통해 스택에서 빼낼 노드가 존재하는지 확인
- top 위치에 해당하는 노드를 pReturn 노드에 저장
    + `pReturn = pStack->pTopElement;`
- 현재 top의 위치에 해당하는 노드의 다음 노드(pLink)를 새로운 top으로 변경
    + `pStack->pTopElement = pReturn->pLink;`
- top의 위치에서 빼낸 노드의 다음 노드(pLink)를 NULL로 변경
    + `pReturn->pLink = NULL;`
- `currentElementCount`값을 1 감소시킴
- 스택에서 빼낸 노드 pReturn을 반환
- 최종 변경된 스택이 비어있을 경우 NULL이 반환된다.

### 2.4 peekLS 스택의 탑(top) 노드를 반환
- `isLinkedStackEmpty`을 통해 스택에서 빼낼 노드가 존재하는지 확인
- top 위치를 추가 조작할 필요없이 top 위치에 해당하는 값의 포인터만 반환
- `popLS()`와 달리 메모리 해제할 필요 없음
- 최종 변경된 스택이 비어있을 경우 NULL이 반환된다.

### 2.5 deleteLinkedStack 스택의 삭제(메모리 해제)
- 스택 안의 링크되어 있는 모든 Node들에 대해 메모리 해제
- 스택 구조체 `LinkedStack` 메모리 할당 해제

### 2.6 isLinkedStackFull 스택 공간이 가득차있는지 확인
- 연결리스트로 스택을 구현한 것이므로 항상 `FALSE` 반환함

### 2.7 isLinkedStackEmpty 스택 공간이 비어있는지 확인
- 현재 노드 개수를 저장하는 변수 `currentElementCount`값이 0인지 여부를 통해 스택 Empty 여부 확인가능<br><br>

## 3. 코드 수행결과
```
current el count: 4
[3]-[D]
[2]-[C]
[1]-[B]
[0]-[A]
Pop-[D]
current el count: 3
[2]-[C]
[1]-[B]
[0]-[A]
Peek-[C]
current el count: 3
[2]-[C]
[1]-[B]
[0]-[A]
Program ended with exit code: 0
```
