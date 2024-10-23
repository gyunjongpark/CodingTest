#include<iostream>
#include<vector>
using namespace std;

int n, a[51];
int m = 6;

void print(vector<int>& v) {
    for (int i : v) {
        cout << i << ' ';
    }

    cout << '\n';

    return;
}

void combi(int start, vector<int>& v, vector<bool>& visited) {
    if (v.size() == m) {
        print(v);
        return;
    }

    for (int i = start + 1; i < n; i++) {
        if (visited[a[i]]) continue;

        v.push_back(a[i]);
        visited[a[i]] = true;

        combi(i - 1, v, visited);

        v.pop_back();
        visited[a[i]] = false;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        cin >> n;

        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> v;
        vector<bool> visited(10001, false); //중복 방지를 위한 visited

        combi(-1, v, visited); //idx를 다루어야 하므로 start = -1

        cout << '\n';
    }

    return 0;
}
