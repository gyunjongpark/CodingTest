#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for(int i : numbers) answer.push_back(2*i);
  
    return answer;
}
