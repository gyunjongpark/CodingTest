#include<iostream>
#include<vector>
using namespace std;

// 선택정렬: O(N^2)
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

// 버블정렬: O(N^2)
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

// 삽입정렬: O(N^2)
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

// 퀵정렬: 평균 O(N log N), 최악 O(N^2)
void quickSort(vector<int>& v, int left, int right) {
    if (left >= right) return;

    int pivot = v[(left + right) / 2]; // 피벗은 중간값으로 선택
    int l = left, r = right;

    while (l <= r) {
        while (v[l] < pivot) l++;
        while (v[r] > pivot) r--;
	    
        if (l <= r) {
            swap(v[l], v[r]);
            l++; r--;
        }
    }

    quickSort(v, left, r);
    quickSort(v, l, right);
}

// 병합정렬: O(N log N)
void merge(vector<int>& v, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) temp[k++] = v[i++];
        else temp[k++] = v[j++];
    }

    while (i <= mid) temp[k++] = v[i++];
    while (j <= right) temp[k++] = v[j++];

    for (int p = 0; p < temp.size(); p++) {
        v[left + p] = temp[p];
    }
}

void mergeSort(vector<int>& v, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
	
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);
    merge(v, left, mid, right);
}

// 힙정렬: O(N log N)
void heapify(vector<int>& v, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && v[left] > v[largest])
        largest = left;

    if (right < n && v[right] > v[largest])
        largest = right;

    if (largest != i) {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void heapSort(vector<int>& v) {
    int n = v.size();

    // 힙 생성
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);

    // 요소 추출
    for (int i = n - 1; i >= 0; i--) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

// 계수정렬: O(N + K)
void countingSort(vector<int>& v) {
    int maxVal = *max_element(v.begin(), v.end());
    int minVal = *min_element(v.begin(), v.end());
    int range = maxVal - minVal + 1;
    
    vector<int> count(range), output(v.size());
    
    for (int i = 0; i < v.size(); i++)
        count[v[i] - minVal]++;
    
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
    
    for (int i = v.size() - 1; i >= 0; i--) {
        output[count[v[i] - minVal] - 1] = v[i];
        count[v[i] - minVal]--;
    }
    
    for (int i = 0; i < v.size(); i++)
        v[i] = output[i];
}
