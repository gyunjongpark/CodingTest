#include<iostream>
#include<vector>
using namespace std;

int n, a[101];
vector<int> v;

void print(vector<int>& v) {
	if (v.empty()) {
		cout << "[]";
    
		return;
	}

	cout << "[";
	
	for (int i = 0; i < v.size() - 1; i++) {
		cout << v[i] << ", ";
	}
	cout << v[v.size() - 1] << "]";
  
	return;
}

void combi(int start, vector<int>& v, int k) {
	if (v.size() == k) {
		print(v);

		return;
	}

	for (int i = start + 1; i < n; i++) {
		v.push_back(a[i]);
		combi(i, v, k);
		v.pop_back();
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}

	for (int k = 0; k <= n; k++) {
		combi(-1, v, k);
		cout << '\n';
	}

	return 0;
}



/* chatGPT가 작성한 답변. C++로 문자열은 역시 힘들다...

#include<iostream>
#include<vector>
using namespace std;

vector<int> nums;
vector<int> v;
vector<vector<int>> all_subsets;

void generate_subsets(int start, vector<int>& v) {
    all_subsets.push_back(v);

    for (int i = start + 1; i < nums.size(); i++) {
        v.push_back(nums[i]);
        generate_subsets(i, v);
        v.pop_back();
    }

    return;
}

void print_all_subsets(const vector<vector<int>>& subsets) {
    cout << "[";
    for (size_t i = 0; i < subsets.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < subsets[i].size(); j++) {
            cout << subsets[i][j];
            if (j < subsets[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < subsets.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    nums = { 1, 2, 3 };

    generate_subsets(-1, v);
    print_all_subsets(all_subsets);

    return 0;
}
*/
