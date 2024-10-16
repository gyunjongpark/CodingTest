//단순한 자료형 변수, 구조체, 벡터(call by value)로 생성된 메모리의 값을 변경하는 함수 작성 시에는 참조자(&)나 포인터 연산이 필요하다.
//배열의 경우 call by reference이므로 참조자 필요없다.

#include<iostream>
using namespace std;

struct Shark {
	int y, x, dir;
};
Shark shark;

//구조체의 값이 '복사'되는 것 뿐이므로 실제 값은 변하지 않는다
void changeShark1(Shark shark) {
	shark.y = 0;
	shark.x = 0;
	shark.dir = 0;

	return;
}

//값이 변한다(참조자 연산)
void changeShark2(Shark& shark) {
	shark.y = 0;
	shark.x = 0;
	shark.dir = 0;

	return;
}

//값이 변한다(포인터 연산)
void changeShark3(Shark* shark) {
	(*shark).y = 0;
	(*shark).x = 0;
	(*shark).dir = 0;

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	shark.y = 1;
	shark.x = 1;
	shark.dir = 1;

	changeShark1(shark);
	changeShark2(shark);
	changeShark3(&shark);

	cout << shark.y << '\n';
	cout << shark.x << '\n';
	cout << shark.dir << '\n';

	shark.y = 2;
	shark.x = 2;
	shark.dir = 2;

	cout << shark.y << '\n';
	cout << shark.x << '\n';
	cout << shark.dir << '\n';

	return 0;
}
