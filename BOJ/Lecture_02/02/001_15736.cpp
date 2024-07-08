#include<iostream>
#include<cmath> //sqrt
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cout<<(int)sqrt(n);
	
	return 0;
}

/*
깃발의 변화가 있으려면 각 깃발의 뒤집은 횟수가 홀수여야 한다
1부터 n까지 수 중에서 약수의 개수가 홀수인 수 c를 찾는다

a*b=1*c에서 a=b를 만족하는 c는 항상 약수의 개수가 홀수이다
a(b)가 소인수 분해가 된다 하더라도 a=b이므로 대칭적인 짝을 이루기 때문에
a*b=1*c에서 a=b를 만족하는 c의 약수의 개수는 항상 홀수를 유지한다(소인수 분해가 되어도 홀수에서 +2씩 추가)

따라서 a*b=1*c에서 a=b조건을 만족하는 수 c를 구하면 모든 경우의 수를 관통할 수 있다
즉, n의 제곱근을 구하면 n까지의 c의 갯수를 구할 수 있다
*/
