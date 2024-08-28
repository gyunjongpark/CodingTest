#include<iostream>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

vector<pair<int, int>> blocks, ret_blocks; //dfs를 진행하면서 저장하는 blocks, 갯수가 4개 이상이라면 저장하는 ret_blocks
int ret;
char a[14][8];
bool visited[14][8];
string s;

int dfs(int y, int x, char color) {
    visited[y][x] = 1;
    blocks.push_back({ y,x });

    int ret = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;

        if (a[ny][nx] == color && !visited[ny][nx]) {
            ret += dfs(ny, nx, color);

            blocks.push_back({ ny,nx });
        }
    }

    return ret;
}

void chain_reaction() {
    while (true) {
        bool flag = false;

        fill(&visited[0][0], &visited[0][0] + 14 * 8, 0);
        ret_blocks.clear();

        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (a[i][j] != '.' && !visited[i][j]) {
                    int block_cnt = dfs(i, j, a[i][j]);

                    if (block_cnt >= 4) {
                        flag = true; //터뜨릴 blocks가 생겼으므로 true
                        
                        for (int i = 0; i < blocks.size(); i++) {
                            ret_blocks.push_back(blocks[i]);
                        }
                    }

                    blocks.clear();
                }
            }
        }

        for (int i = 0; i < ret_blocks.size(); i++) {
            int y = ret_blocks[i].first;
            int x = ret_blocks[i].second;

            a[y][x] = '.';
        }

        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (a[i][j] == '.') continue;
                
                int tmp = i;

                while (true) {
                    if (tmp == 11 || a[tmp + 1][j] != '.') break;

                    a[tmp + 1][j] = a[tmp][j];
                    a[tmp][j] = '.';
                    tmp++;
                }
            }
        }

        if (flag) ret++;
        else break;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 12; i++) {
        cin >> s;

        for (int j = 0; j < 6; j++) {
            a[i][j] = s[j];
        }
    }

    chain_reaction();

    cout << ret;

    return 0;
}
