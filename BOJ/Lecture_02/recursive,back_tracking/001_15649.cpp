#include <iostream>
#include <vector>
using namespace std;

int n, m; //n개 중에서 m개를 뽑는다

void permutation(vector<int>& v, vector<bool>& visited) {
    if (v.size() == m) {
        for (int i : v) cout << i << ' ';
        cout << '\n';

        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue; //중복 제거

        visited[i] = true;
        v.push_back(i);

        permutation(v, visited);

        visited[i] = false; //원상복구
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    vector<int> arr; //순열, 실제 값을 나열한 배열 arr
    vector<bool> visited(n + 1, false); //중복 방지를 위한 visited
    permutation(arr, visited); 

    return 0;
}
