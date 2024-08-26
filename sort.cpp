#include<iostream>
#include<vector>
using namespace std;

void select_sort(vector<int>& v) { //O(N^2)
	int temp, idx;

	for (int i = 0; i < v.size(); i++) {
		int minVal = 9999;
		
		for (int j = i; j < v.size(); j++) {
			if (minVal > v[j]) {
				minVal = v[j];
				idx = j;
			}
		}

		temp = v[i];
		v[i] = v[idx];
		v[idx] = temp;
	}

	for (int i : v) cout << i << ' ';
	cout << '\n';

	return;
}

void bubble_sort(vector<int>& v) { //O(N^2)
	int temp;

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size() - i - 1; j++) {
			if (v[j] > v[j + 1]) {
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}

	for (int i : v) cout << i << ' ';
	cout << '\n';

	return;
}

void insert_sort(vector<int>& v) { //O(N^2)
	int temp;

	for (int i = 0; i < v.size() - 1; i++) {
		int j = i;

		while (j >= 0 && v[j] > v[j + 1]) {
			temp = v[j];
			v[j] = v[j + 1];
			v[j + 1] = temp;
			j--;
		}
	}

	for (int i : v) cout << i << ' ';
	cout << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> v = { 1,4,2,5,3,7,6,8,9 };

	select_sort(v);
	bubble_sort(v);
	insert_sort(v);

	return 0;
}
