#include<iostream>
using namespace std;

int a, b;

int main() {
	cin >> a >> b;
	
	printf("%.9f", (double)a / (double)b); //printf : 지정된 형식으로 출력
  
	return 0;
}

//실수형 입력 : scanf(%lf, &a); 변수의 주소 공간(메모리)에 저장될 값을 직접 입력합니다. 변수의 값 자체가 등록, 변경됩니다.
//실수형 출력 : printf(%f, a); 변수 a의 값을 복사해서 출력합니다. 변수가 아닌 변수의 값을 복사하므로 &는 쓰이지 않습니다.
