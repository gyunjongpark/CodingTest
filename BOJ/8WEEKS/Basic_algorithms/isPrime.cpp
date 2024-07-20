#include<iostream>
#include<vector>
#define MAX 1000 // 문제에 제시된 최대 범위
using namespace std;

/*
에라토스테네스의 체 : O(NloglogN)

지정한 범위 내에서 소수의 개수를 묻는 문제가 있고, 전체 MAX 범위에서 전부 접근해야 하는 문제가 있다
후자의 경우 vector를 이용하지 말고 chae 배열 자체를 완성하고 활용하는 것이 효율적이다
*/

bool chae[MAX + 1]; // 최대 범위 MAX까지 담는 배열 chae
int n; // 입력으로 제시되는 범위

vector<int> era(int n) {
	vector<int> v;

	for (int i = 2; i <= n; i++) {
		if (chae[i]) continue; // 이미 지워졌다면 continue
		for (int j = i + i; j <= n; j += i) {
			chae[j] = 1; // i의 배수 지우기(소수만 남기기)
		}
	}

	for (int i = 2; i <= n; i++) {
		if (!chae[i]) v.push_back(i); // 소수라면 push back
	}

	return v;
}

/*----------------------------------*/

/* 어떤 수 하나가 소수인지 판별하기 : O(sqrt(N)) */

int num; // 확인하고 싶은 수

bool checkPrime(int num) {
	if (num <= 1) return 0;
	for (int i = 2; i <= (int)sqrt(num); i++) {
		if (num % i == 0) return 0;
	}
	
	return 1;
}

/*----------------------------------*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//era
	cin >> n;
	vector<int> v = era(n);
	for (int i : v) cout << i << ' ';
	
	cout << '\n';

	//checkPrime
	cin >> num;
	if (checkPrime(num)) cout << "소수입니다!";
	else cout << "소수가 아닙니다!";

	return 0;
}
