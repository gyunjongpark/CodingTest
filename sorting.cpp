#include<iostream>
#include<vector>
using namespace std;

//O(N^2)
void selectSort(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		int minVal = 1e6; int idx = -1;
		
		for (int j = i; j < v.size(); j++) {
			if (v[j] < minVal) {
				minVal = v[j];
				idx = j;
			}
		}

		int temp = v[i];
		v[i] = v[idx];
		v[idx] = temp;
	}

	return;
}

//O(N^2)
void bubbleSort(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size() - 1 - i; j++) {
			if (v[j] > v[j + 1]) {
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}

	return;
}

//O(N^2)
void insertSort(vector<int>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		int j = i;
		while (j >= 0 && v[j] > v[j + 1]) {
			int temp = v[j];
			v[j] = v[j + 1];
			v[j + 1] = temp;
			j--;
		}
	}

	return;
}
