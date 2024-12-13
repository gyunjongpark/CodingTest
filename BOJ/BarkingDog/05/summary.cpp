/*
스택의 시간복잡도

스택은 구조적으로 맨 위의 데이터만 볼 수 있는 자료구조이다
일반적으로 참조, 탐색에 O(N), 삽입, 삭제에 O(1)의 시간복잡도를 가진다

물론, 특정 idx의 데이터에 대해 삽입, 삭제를 수행해야 한다면 O(N)이 소요된다

참조와 탐색: O(N)
삽입과 삭제: O(1). 최악의 경우 특정 인덱스 또는 값까지 참조 혹은 탐색을 진행해야 하므로 O(N)

pair 또는 struct 자료형을 담을 수 있는 스택에 대한 사고가 유연해야 한다
*/
