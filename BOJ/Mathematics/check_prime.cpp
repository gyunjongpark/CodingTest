#include<iostream>
#include<cmath> //sqrt
#define MAX 10000001 //0 ~ 10^7
using namespace std;

bool chae[MAX]; //소수만 true로 저장될 배열

//에라토스테네스의 체 O(Nlog(logN))
void era(int n) {
	for (int i = 0; i <= n; i++) chae[i] = true; //초기값은 전부 소수로 가정
	
	chae[0] = false; //0과 1은 소수의 정의에 따라 소수가 아니다
	chae[1] = false; //0과 1은 소수의 정의에 따라 소수가 아니다

	for (int i = 2; i <= n; i++) {
		if (!chae[i]) continue; //소수가 아니라면 continue

		for (int j = i + i; j <= n; j += i) {
			chae[j] = false; //소수의 배수(소수가 아닌 수)들을 false로 전환
		}
	}

	return;
}

//소수 하나 판별하기 O(sqrt(N))
bool check(int n) {
	if (n == 1) return 0;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return 0;
	}

	/*
	n이 11일 때를 생각해보자.
	sqrt(11)은 3.xx이므로 만약 11을 4로 나눈다면 무조건 4보다 작은 수와 짝을 지어 11을 완성할 것이다.
	따라서 n이 4보다 작은 자연수 2, 3으로 나눠지는지 확인하는 행위는 11이 4 또는 그 이상의 자연수로 나누어 떨어지는지 확인하는 행위와 정확히 같다.
	일반화하면 n이 sqrt(n)보다 작거나 같은 자연수로 나눠지는지 확인하는 행위는 n이 sqrt(n)보다 큰 자연수로 나눠지는지 확인하는 행위와 정확히 같다.

	결론적으로 sqrt(n)까지의 자연수로 나눠지지 않는다면 sqrt(n)보다 큰 자연수로도 나눠지지 않는 것이므로 sqrt(n)까지만 반복문을 진행하는 것은 합당하다.
	*/

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//에라토스테네스의 체
	era(101); //자연수 100이 소수인지 확인하기 위해 범위를 101로 설정. chae[0 ~ 100]
	if (chae[100]) cout << "yes" << '\n';
	else cout << "no"<<'\n';

	//에라토스테네스의 체는 해당 범위의 소수들을 나열하여 출력하는 것도 가능하다
	for (int i = 2; i <= 100; i++) {
		if (chae[i]) cout << i << ' ';
	}
	cout << '\n';

	//소수 하나 판별하기
	if (check(100)) cout << "yes"; //100이라는 수가 소수인지 판별
	else cout << "no";

	return 0;
}
