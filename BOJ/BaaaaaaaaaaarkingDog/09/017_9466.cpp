#include<iostream>
using namespace std;

int a[100001], state[100001], t, n;

const int NOT_VISITED = 0;
const int VISITED = 1;
const int CYCLE_IN = 2;
const int NOT_CYCLE_IN = 3;

void run(int here) {
    int cur = here;

    while (true) {
        state[cur] = VISITED;
        cur = a[cur];

        if (state[cur] == CYCLE_IN || state[cur] == NOT_CYCLE_IN) {
            cur = here;

            while (state[cur] == VISITED) {
                state[cur] = NOT_CYCLE_IN;
                cur = a[cur];
            }

            return;
        }

        if (state[cur] == VISITED && cur != here) {
            while (state[cur] != CYCLE_IN) {
                state[cur] = CYCLE_IN;
                cur = a[cur];
            }
            cur = here;
            while (state[cur] != CYCLE_IN) {
                state[cur] = NOT_CYCLE_IN;
                cur = a[cur];
            }
            return;
        }

        if (state[cur] == VISITED && cur == here) {
            while (state[cur] != CYCLE_IN) {
                state[cur] = CYCLE_IN;
                cur = a[cur];
            }
            return;
        }        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;

        fill(&state[0], &state[0] + 100001, 0);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        for (int i = 1; i <= n; i++) {
            if (state[i] == NOT_VISITED) { //방문하지 않았다면
                run(i);
            }
        }

        int ret = 0;

        for (int i = 1; i <= n; i++) {
            if (state[i] == NOT_CYCLE_IN) ret++;
        }

        cout << ret << '\n';
    }

    return 0;
}
