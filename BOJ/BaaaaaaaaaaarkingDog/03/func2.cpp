#include<iostream>
using namespace std;

int func2(int arr[], int N) { //O(N)
	int cnt[101];

	fill(&cnt[0], &cnt[0] + 101, 0);

	for (int i = 0; i < N; i++) {
		if (cnt[100 - arr[i]] == 1) { //짝이 있다면
			return 1;
		}
			
		cnt[arr[i]] = 1;
	}

	return 0;
}

void test2() {
	cout << "****** func2 test ******\n";
	int arr[3][4] = { {1,52,48}, {50,42}, {4,13,63,87} };
	int n[3] = { 3, 2, 4 };
	int ans[3] = { 1, 0, 1 };
	for (int i = 0; i < 3; i++) {
		int result = func2(arr[i], n[i]);
		cout << "TC #" << i << '\n';
		cout << "expected : " << ans[i] << " result : " << result;
		if (ans[i] == result) cout << " ... Correct!\n";
		else cout << " ... Wrong!\n";
	}
	cout << "*************************\n\n";
}

int main() {
	test2();

	return 0;
}
