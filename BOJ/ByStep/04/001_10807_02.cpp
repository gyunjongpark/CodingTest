#include<iostream>
#include<vector>
#include<algorithm> //sort, upper_bound, lower_bound
using namespace std;

int n, v, temp;
vector<int> ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        ret.push_back(temp);
    }

    cin >> v;

    sort(ret.begin(), ret.end());

    cout << upper_bound(ret.begin(), ret.end(), v) - lower_bound(ret.begin(), ret.end(), v);

    return 0;
}
