#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
        
    vector<int> answer;
    
    answer.push_back(arr[0]);
    
    for(int i=1;i<arr.size();i++){
        if(answer[answer.size() - 1]!=arr[i]){
            answer.push_back(arr[i]);
        }
    }
    

    return answer;
}