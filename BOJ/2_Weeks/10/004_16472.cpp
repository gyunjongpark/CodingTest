#include<iostream>
#include<unordered_set>
using namespace std;

int n, s, e, dist;
string arr;
unordered_set<char> letters;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> arr;

    letters.insert(arr[0]);

    while (s < arr.size() && e < arr.size()) {
        dist = max(dist, e - s + 1);

        if (letters.size() <= n) {
            e++;

            if (e < arr.size() && letters.find(arr[e]) == letters.end()) {
                letters.insert(arr[e]);
            }
        }

        if (letters.size() > n) {
            letters.erase(arr[s]);
            s++;
            e = s;
            letters.clear();
            letters.insert(arr[s]);
        }
    }

    cout << dist;

    return 0;
}
