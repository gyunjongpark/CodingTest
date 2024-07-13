#include<iostream>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;

    s += "??!";
    cout << s;

    return 0;
}
