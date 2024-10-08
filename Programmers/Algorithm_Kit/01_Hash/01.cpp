#include<vector>
#include<iostream>
#include<set>
#include<climits> //INT_MAX
using namespace std;

set<int> st;

int solution(vector<int> nums)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = nums.size() / 2;

    for (int num : nums) st.insert(num);

    //size() 연산은 size_t 타입을 반환하므로 비교 시 주의할 것!
    answer = min(answer, (st.size() <= INT_MAX) ? (int)st.size() : INT_MAX);

    return answer;
}
