#include <string>
#include <vector>
#include <algorithm> //sort
using namespace std;

bool cmp_code(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

bool cmp_date(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

bool cmp_maximum(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

bool cmp_remain(vector<int> a, vector<int> b) {
    return a[3] < b[3];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;

    int idx = 0;

    if (ext == "code") idx = 0;
    else if (ext == "date") idx = 1;
    else if (ext == "maximum") idx = 2;
    else if (ext == "remain") idx = 3;

    for (vector<int> d : data) {
        if (d[idx] < val_ext) answer.push_back(d);
    }

    if (sort_by == "code") {
        sort(answer.begin(), answer.end(), cmp_code);
    }
    else if (sort_by == "date") {
        sort(answer.begin(), answer.end(), cmp_date);
    }
    else if (sort_by == "maximum") {
        sort(answer.begin(), answer.end(), cmp_maximum);
    }
    else if (sort_by == "remain") {
        sort(answer.begin(), answer.end(), cmp_remain);
    }

    return answer;
}
