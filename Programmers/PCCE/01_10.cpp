#include <string>
#include <vector>
using namespace std;

bool postable(int mat_size, vector<vector<string>> park) {
    bool flag = true;
    int r, c;

    r = park.size();
    c = park[0].size();

    for (int y = 0; y <= r - mat_size; y++) {
        for (int x = 0; x <= c - mat_size; x++) {
            flag = true;

            for (int i = 0; i < mat_size; i++) {
                for (int j = 0; j < mat_size; j++) {
                    if (park[i + y][j + x] != "-1") {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }

            if (flag) return true;
        }
    }

    return false;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;

    for (int i : mats) {
        if (postable(i, park)) {
            if (i > answer) answer = i;
        }
    }

    if (answer == 0) return -1;

    return answer;
}
