#include<iostream>
#include<vector>
using namespace std;

void rotate_left_90(vector<vector<int>>& key) {
	int n = key.size();
	int m = key[0].size();
  
	vector<vector<int>> temp(m, vector<int>(n, 0));
  
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = key[j][m - i - 1]; //(i, j) -> (j, m - i - 1)
		}
	}
  
	key.resize(m);
	key[0].resize(n);
	key = temp;
  
	return;
}

void rotate_right_90(vector<vector<int>>& key) {
	int n = key.size();
	int m = key[0].size();
  
	vector<vector<int>> temp(m, vector<int>(n, 0));
  
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = key[n - j - 1][i]; //(i, j) -> (n - j - 1, i)
		}
	}
  
	key.resize(m);
	key[0].resize(n);
	key = temp;
  
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> v = { 1, 2, 3, 4, 5, 6 };

	//0번째 인덱스 값 ~ n-1번째 인덱스 값 범위를 1번 왼쪽으로 rotate
	rotate(v.begin(), v.begin() + 1, v.end());
	for (int i : v) cout << i << ' '; //2 3 4 5 6 1
	
	cout << "\n\n";
	
	vector<int> v1 = { 1, 2, 3, 4, 5, 6 };

	//1번째 인덱스 값 ~ 5-1번째 인덱스 값 범위를 2번 왼쪽으로 rotate
	rotate(v1.begin() + 1, v1.begin() + 2, v1.begin() + 5);
	for (int i : v1) cout << i << ' '; //1 3 4 5 2 6

	cout << "\n\n";

	/* 2차원 배열 rotate */
	
	vector<vector<int>> a = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
	};
  
	rotate_right_90(a);
	
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}

	cout << "\n\n";

	rotate_left_90(a);
	
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
