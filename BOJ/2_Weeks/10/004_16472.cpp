#include<iostream>
#include<unordered_set>
using namespace std;

int n;
string arr;
unordered_set<char> letters; //중복 방지를 위한 set

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> arr;

    int l = 0, r = 0, dist = 0;

    letters.insert(arr[0]);

    while (l < arr.size() && r < arr.size()) {
        dist = max(dist, r - l + 1);

        if (letters.size() <= n) {
            r++;

            if (r < arr.size() && letters.find(arr[r]) == letters.end()) {
                letters.insert(arr[r]);
            }
        }

        if (letters.size() > n) {
            letters.erase(arr[l]);

            l++;
            r = l; //새로운 시작 문자로 초기화 후 다시 탐색
            letters.clear();
            letters.insert(arr[l]);
        }
    }

    cout << dist;

    return 0;
}
