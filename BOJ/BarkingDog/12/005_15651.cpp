#include<iostream>
#include<vector>
using namespace std;

int n, m;

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

    for (int i = start + 1; i <= n; i++) {
        //if (visited[i]) continue;

        v.push_back(i);
        //visited[i] = true;

        combi(start, v, visited);

        v.pop_back();
        //visited[i] = false;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    vector<int> v;
    vector<bool> visited(n + 1, false); //중복 방지를 위한 visited

    combi(0, v, visited); //1 ~ n까지의 수이므로 start = 0

    return 0;
}