#include<iostream>
#include<vector>
#include<cmath> //sqrt
#define MAX 10000001
using namespace std;

bool isPrime[MAX];
vector<int> v;

//에라토스테네스의 체를 이용해서 isPrime 배열 완성하기
void era(int n) { //O(Nlog(logN))
    for (int i = 2; i <= n; i++) isPrime[i] = 1; //처음에는 모든 수를 true 처리

    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue; //소수가 아니라면 continue

        for (int j = i + i; j <= n; j += i) {
            isPrime[j] = 0; //소수의 배수들을 false 처리
        }
    }

    //소수를 벡터에 저장
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) v.push_back(i);
    }
    
    return;
}

//수 하나가 소수인지 아닌지 판별하기
bool check(int n) { //O(sqrt(N))
    if (n <= 1) return 0;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //에라토스테네스의 체
    int n;
    cin >> n;

    era(n); //O(Nlog(logN))

    for (int i : v) cout << i << '\n'; //저장된 vector 출력

    //하나의 수만 소수 판별
    int m;
    cin >> m;

    if (check(m)) { //O(sqrt(N))
        cout << "true";
    }
    else cout << "false";

    return 0;
}
