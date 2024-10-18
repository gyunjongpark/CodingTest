#include<iostream>
#include<vector>
using namespace std;

int n, s, a[21], ret;

void combi(int start, int m, vector<int>& v) {
    if (v.size() == m) {
        int sum = 0;

        for (int i : v) sum += i;

        if (sum == s) ret++;

        return;
    }

    for (int i = start + 1; i < n; i++) {
        //if (visited[a[i]]) continue;

        v.push_back(a[i]);
        //visited[a[i]] = true;

        combi(i, m, v);

        v.pop_back();
        //visited[a[i]] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> v;
    //vector<bool> visited(n + 1, false);

    //공집합을 제외하기 위해 1부터 시작
    for (int i = 1; i <= n; i++) {
        combi(-1, i, v);
    }

    cout << ret;

    return 0;
}
