#include<iostream>
#include<vector>
using namespace std;

int n, m, q, a, b;
vector<int> p(1000001, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;
    
    //v의 랭크가 더 큰 경우
    if (p[v] < p[u]) swap(u, v);

    //랭크가 같은 경우
    if (p[u] == p[v]) p[u]--;
        
    p[v] = u;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    while (m--) {
        cin >> q >> a >> b;

        if (q == 0) {
            uni(a, b);
        }            
        else {
            if (find(a) == find(b)) {
                cout << "YES\n";
            }               
            else {
                cout << "NO\n";
            }                
        }
    }

    return 0;
}
