#include<vector>
#include<iostream>
#include<set>
using namespace std;

set<int> st;

int solution(vector<int> nums)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int answer = nums.size() / 2;

    for (int num : nums) {
			st.insert(num);
		}

	return st.size() > answer ? answer : st.size();
}
