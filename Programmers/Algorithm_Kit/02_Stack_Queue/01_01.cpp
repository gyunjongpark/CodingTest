#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    reverse(arr.begin(),arr.end()); //10^6 * log(10^6)
    
    vector<int> answer;
    stack<int> stk;
    
    for(int i : arr) { //10^6
        if(stk.empty()){
            stk.push(i);
        }
        else {
            if(stk.top()==i) continue;
            
            stk.push(i);
        }
    }
    
    while(!stk.empty()){
        answer.push_back(stk.top());
        stk.pop();
    }

    return answer;
}
