#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, a[21][21];
int ret = INT_MAX;
bool visited[21];
vector<int> v;

int go(vector<int>& start, vector<int>& link) {
    pair<int, int> ret; //init

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            if (i == j) continue;

            ret.first += a[start[i]][start[j]];
            ret.second += a[link[i]][link[j]];
        }
    }

    return abs(ret.first - ret.second);
}

void combi(int start, vector<int>& v) {
    if (v.size() == n / 2) {
        vector<int> start, link; //사이즈가 될 때마다 init

        for (int i = 0; i < n; i++) {
            if (visited[i]) start.push_back(i); //visited에 따라서 아침, 저녁으로 나누기
            else link.push_back(i);
        }

        ret = min(ret, go(start, link));

        return;
    }

    for (int i = start + 1; i < n; i++) {
        visited[i] = 1;
        v.push_back(i);

        combi(i, v);

        visited[i] = 0;
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    combi(-1, v); //팀 나누기

    cout << ret;

    return 0;
}
