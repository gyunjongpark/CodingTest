#include<iostream>
#include<cmath> //sqrt
#define MAX 10000001 //0 ~ 10^7
using namespace std;

bool chae[MAX];

//에라토스테네스의 체 O(Nlog(logN))
void era(int n) { 
	for (int i = 2; i <= n; i++) chae[i] = true; //초기에는 전부 소수라고 가정

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
	
    return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//에라토스테네스의 체
	era(100); //2부터 100까지의 수 중에서 소수 판별. 심지어 출력도 가능

	for (int i = 2; i <= 100; i++) {
		if (chae[i]) cout << i << ' ';
	}
	cout<<'\n';

	//소수 하나 판별하기
	//100이라는 수가 소수인지 판별
	if(check(100)) cout<<"yes";
	else cout<<"no";

	return 0;
}
