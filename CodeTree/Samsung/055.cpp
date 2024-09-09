#include<iostream>
#include<vector>
#include<climits> //INT_MAX
using namespace std;

int n, a[21][21];
int ret = INT_MAX;
bool visited[21];
vector<int> v;

int go(vector<int> morning, vector<int> evening) {
    pair<int, int> ret;

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            if (i == j) continue;

            ret.first += a[morning[i]][morning[j]];
            ret.second += a[evening[i]][evening[j]];
        }
    }

    return abs(ret.first - ret.second);
}

void combi(int start, vector<int>& v) {
    if (v.size() == n / 2) {
        vector<int> morning, evening; //사이즈가 될 때마다 init

        for (int i = 0; i < n; i++) {
            if (visited[i]) morning.push_back(i); //visited = true인 일은 아침, 아니라면 저녁으로 정의
            else evening.push_back(i);
        }
        
        ret = min(ret, go(morning, evening));

        return;
    }

    for (int i = start + 1; i < n; i++) {
        visited[i] = 1; //아침, 저녁으로 나누기 위해 visited로 구분
        v.push_back(i);

        combi(i, v);

        visited[i] = 0; //원상 복구
        v.pop_back(); //원상 복구
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

    combi(-1, v);

    cout << ret;

    return 0;
}
