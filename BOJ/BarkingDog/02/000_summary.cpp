#include<iostream>
using namespace std;

int a[10] = { 1, };

struct Shark {
	int y, x;
};
Shark shark = { 1,1 };

//배열
void changearr(int arr[]) {
	arr[0] = 10;

	return;
}

//단순한 자료형 변수, 구조체, 벡터(call by value)를 인자로 사용해 메모리 내 값을 변경하는 함수는 참조자(&)나 포인터 연산이 필요하다
void changestruct1(Shark shark) {
	shark.y = 10;
	shark.x = 10;

	return;
}

void changestruct2(Shark& shark) {
	shark.y = 10;
	shark.x = 10;

	return;
}

void changestruct3(Shark* shark) {
	(*shark).y = 20;
	(*shark).x = 20;

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	changearr(a); //call by reference. a[0]을 10으로 변경
	cout << a[0] << '\n'; //10

	changestruct1(shark); //call by value. 값이 변경되지 않는다.
	cout << shark.y << ' ' << shark.x << '\n'; //1 1

	changestruct2(shark); //call by reference. 참조자 연산을 통한 값의 변경
	cout << shark.y << ' ' << shark.x << '\n'; //10 10

	changestruct3(&shark); //call by reference. 포인터 연산을 통한 값의 변경
	cout << shark.y << ' ' << shark.x << '\n'; //20 20

	return 0;
}
