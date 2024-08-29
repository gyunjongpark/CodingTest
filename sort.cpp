#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

vector<int> v = { 1,4,2,5,3 };

void select_sort(vector<int>& v) {
	int temp, idx;

	for (int i = 0; i < v.size(); i++) {
		int minVal = INT_MAX;

		for (int j = i; j < v.size(); j++) {
			if (minVal > v[j]) {
				minVal = v[j];
				idx = j;
			}
		}

		//swap(v[i], v[idx]);
		temp = v[i];
		v[i] = v[idx];
		v[idx] = temp;
	}

	for (int i : v) cout << i << ' ';

	cout << '\n';

	return;
}

void bubble_sort(vector<int>& v) {
	int temp;

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size() - i - 1; j++) {
			if (v[j] > v[j + 1]) {
				//swap(v[j], v[j + 1]);
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

void insert_sort(vector<int>& v) {
	int temp;

	for (int i = 0; i < v.size() - 1; i++) {
		int j = i;

		while (j >= 0 && v[j] > v[j + 1]) {
			//swap(v[j], v[j + 1]);
			//j--;
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

void quick_sort(vector<int>& v, int s_idx, int e_idx) {
	if (s_idx >= e_idx) return; //원소가 1개인 경우 return

	int pivot = s_idx;
	int i = s_idx + 1, j = e_idx;
	int temp;

	while (i <= j) { //엇갈릴 때까지 반복
		while (i <= e_idx && v[i] <= v[pivot]) i++;
		while (j > s_idx && v[j] >= v[pivot]) j--;

		if (i > j) { //엇갈렸다면 pivot 위치의 값과 j 위치의 값을 교체
			//swap(v[j], v[pivot]);
			temp = v[j];
			v[j] = v[pivot];
			v[pivot] = temp;
		}
		else { //엇갈리지 않았다면 i 위치의 값과 j 위치의 값을 교체
			//swap(v[i], v[j]);
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}

	quick_sort(v, s_idx, j - 1);
	quick_sort(v, j + 1, e_idx);

	return;
}

void print(vector<int>& v) {
	for (int i : v) cout << i << ' ';

	cout << '\n';

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	select_sort(v); //O(N^2)
	bubble_sort(v); //O(N^2)
	insert_sort(v); //O(N^2)

	quick_sort(v, 0, v.size() - 1); print(v);  //O(NlogN) ~ O(N^2)

	return 0;
}
