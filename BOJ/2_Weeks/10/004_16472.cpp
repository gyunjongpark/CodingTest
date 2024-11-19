#include<iostream>
#include<set>
using namespace std;

int n;
string s;
set<char> st; //중복 방지를 위한 set

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;

    int dist = 0;

    //init
    int l = 0, r = 0; //two pointer
    st.clear(); //set
    st.insert(s[0]);

    while (l < s.size() && r < s.size()) {
        dist = max(dist, r - l + 1);

        if (st.size() <= n) {
            r++;

            //오른쪽 포인터가 문자열 범위 내 + 집합에 해당 포인터의 문자가 없다면
            if (r < s.size() && st.find(s[r]) == st.end()) {
                st.insert(s[r]); //해당 포인터의 문자 추가
            }
        }

        if (st.size() > n) {
            st.erase(s[l]); //가장 처음의 문자 제거

            l++; //왼쪽 포인터 옮기기

            //init
            r = l; //two pointer
            st.clear(); //set
            st.insert(s[l]);
        }
    }

    cout << dist;

    return 0;
}
