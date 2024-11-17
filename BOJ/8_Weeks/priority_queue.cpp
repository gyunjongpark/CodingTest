#include<iostream>
#include<queue> //priority_queue
using namespace std;

struct cmp {
	bool operator() (int a, int b) {
		return a < b; //우선순위 큐에서는 내림차순
	}
};

//우선순위 큐는 정렬순서가 반대로 작용한다
priority_queue<int> pq1; //내림차순

priority_queue<int, vector<int>, less<int>> pq2; //내림차순
//sort(a, a + n, less<int>()); //일반적인 배열에서는 오름차순

priority_queue<int, vector<int>, cmp> pq3; //내림차순

priority_queue<int, vector<int>, greater<int>> pq4; //오름차순
//sort(a, a + n, greater<int>()); //일반적인 배열에서는 내림차순

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 5; i >= 1; i--) {
		pq1.push(i);
		pq2.push(i);
		pq3.push(i);
		pq4.push(i);
	}

	while (!pq1.empty()) {
		cout << pq1.top() << '\n';
		pq1.pop();
	}

	cout << '\n';

	while (!pq2.empty()) {
		cout << pq2.top() << '\n';
		pq2.pop();
	}

	cout << '\n';

	while (!pq3.empty()) {
		cout << pq3.top() << '\n';
		pq3.pop();
	}

	cout << '\n';

	while (!pq4.empty()) {
		cout << pq4.top() << '\n';
		pq4.pop();
	}

	return 0;
}
