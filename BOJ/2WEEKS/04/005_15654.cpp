#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 10004
using namespace std;

int n, m; // n개 중에서 m개를 뽑는다
int a[10];

void combi(int start, vector<int>& v, vector<bool>& visited) {
    if (v.size() == m) {
        for (int i : v) cout << i << ' ';
        cout << '\n';

        return;
    }

    for (int i = start + 1; i < n; i++) {
        if (visited[a[i]]) continue;

        v.push_back(a[i]);
        visited[a[i]] = true;

        combi(start, v, visited);

        v.pop_back();
        visited[a[i]] = false;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    vector<int> v;
    vector<bool> visited(MAX, false);

    combi(-1, v, visited);

    return 0;
}
