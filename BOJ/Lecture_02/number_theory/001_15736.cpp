#include<iostream>
#include<cmath>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//표 또는 도식화를 활용해 문제 해석->규칙 발견->코드 작성
	cin >> n;
	cout<<(int)sqrt(n);
	
	return 0;
}

/*
예시를 도식화해서 규칙성을 찾아낸다.
규칙성을 수학으로 옮겨 코드 작성
*/
