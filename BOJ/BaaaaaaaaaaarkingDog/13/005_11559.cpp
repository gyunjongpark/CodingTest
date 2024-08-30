#include<iostream>
#include<vector>
using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

vector<pair<int, int>> blocks, ret_blocks;
string s;
char a[14][8];
bool visited[14][8];
int ret;


void dfs(int y, int x, char color) {
    visited[y][x] = 1;
    blocks.push_back({ y,x });

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;

        if (a[ny][nx] == color && !visited[ny][nx]) {
            dfs(ny, nx, color);
        }
    }

    return;
}

void chain_reaction() {
    while (true) {
        bool flag = false;

        fill(&visited[0][0], &visited[0][0] + 14 * 8, 0);
        ret_blocks.clear();

        //터질 수 있는 블록들 ret_blocks에 저장하기
        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (a[i][j] != '.' && !visited[i][j]) {
                    dfs(i, j, a[i][j]); //push_back to 'blocks'

                    if (blocks.size() >= 4) {
                        flag = true; //ready to pop!

                        for (int i = 0; i < blocks.size(); i++) {
                            ret_blocks.push_back(blocks[i]);
                        }
                    }

                    blocks.clear(); //init
                }
            }
        }

        //ret_blocks에 저장된 블록들을 '.'으로 바꾸기
        //flag가 true가 아니었다면(4개 이상이 모이지 않았다면) ret_blocks에 저장된 블록이 없으므로 아래 반복문은 실행되지 않는다
        for (int i = 0; i < ret_blocks.size(); i++) {
            int y = ret_blocks[i].first;
            int x = ret_blocks[i].second;

            a[y][x] = '.';
        }

        //맨 아래에 도달하거나, 문자인 블록을 만날 때까지 블록을 한 칸씩 아래로 내리기
        //flag가 true가 아니었다면 아래 반복문에 부합하는 (i, j)가 없어서 아래 반복문 또한 실행되지 않는다
        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (a[i][j] == '.') continue;

                int tmp = i;

                while (true) {
                    if (tmp == 11 || a[tmp + 1][j] != '.') break; 

                    //한 칸씩 아래로 내리기
                    a[tmp + 1][j] = a[tmp][j];
                    a[tmp][j] = '.';
                    tmp++;
                }
            }
        }

        if (flag) ret++;
        else break; //flag가 false였다면 while문 종료
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
