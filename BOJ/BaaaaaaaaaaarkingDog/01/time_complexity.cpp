//시간 복잡도 : N = 25 이하 ->O(2^N), 500 이하 -> O(N^3)
//시간 복잡도 : 100만 이하 -> O(NlogN), 1000만 이하 -> O(N)

//공간 복잡도 : 512MB = 1.2억 개의 int

#include<iostream>
using namespace std;

int func1(int n) { //O(N)
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			ret += i;
		}
	}
	return ret;
}

int func2(int arr[], int n) { //O(n^2)
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == 100) return 1;
		}
	}
	return 0;
}

int func3(int n) { //O(sqrt(N))
	for (int i = 1; i < n; i++) {
		if (i * i == n) return 1;
	}
	return 0;
}

int func4(int n) { //O(logN)
	int ret = 1;
	for (int i = 2; i <= n; i*=2) {
		ret = i;
	}
	return ret;
}

void test1() {
	cout << "****** func1 test ******\n";
	int n[3] = { 16, 34567, 27639 };
	int ans[3] = { 60, 278812814, 178254968 };
	for (int i = 0; i < 3; i++) {
		int result = func1(n[i]);
		cout << "TC #" << i << '\n';
		cout << "expected : " << ans[i] << " result : " << result;
		if (ans[i] == result) cout << " ... Correct!\n";
		else cout << " ... Wrong!\n";
	}
	cout << "*************************\n\n";
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

void test3() {
	cout << "****** func3 test ******\n";
	int n[3] = { 9, 693953651, 756580036 };
	int ans[3] = { 1, 0, 1 };
	for (int i = 0; i < 3; i++) {
		int result = func3(n[i]);
		cout << "TC #" << i << '\n';
		cout << "expected : " << ans[i] << " result : " << result;
		if (ans[i] == result) cout << " ... Correct!\n";
		else cout << " ... Wrong!\n";
	}
	cout << "*************************\n\n";
}

void test4() {
	cout << "****** func4 test ******\n";
	int n[3] = { 5, 97615282, 1024 };
	int ans[3] = { 4, 67108864, 1024 };
	for (int i = 0; i < 3; i++) {
		int result = func4(n[i]);
		cout << "TC #" << i << '\n';
		cout << "expected : " << ans[i] << " result : " << result;
		if (ans[i] == result) cout << " ... Correct!\n";
		else cout << " ... Wrong!\n";
	}
	cout << "*************************\n\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	test1();
	test2();
	test3();
	test4();
	return 0;
}
