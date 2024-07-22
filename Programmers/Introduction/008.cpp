#include <string>
#include <vector>
using namespace std;

vector<int> v;

vector<int> solution(vector<int> numbers) {
    for(int i : numbers) v.push_back(2*i);
  
    return v;
}
