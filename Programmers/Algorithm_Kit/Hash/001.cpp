#include <vector>
#include<iostream>
#include<set>
using namespace std;

set<int> st;

int solution(vector<int> nums)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = nums.size() / 2;

    for (int num : nums) st.insert(num);

    answer = min(answer, (int)st.size()); //모든 자료구조의 size 연산은 unsigned long을 반환합니다
    return answer;
}
