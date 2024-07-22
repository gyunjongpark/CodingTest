#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int numer = (denom1 * numer2) + (denom2 * numer1);
    int denom = denom1 * denom2;

    for(int i = min(denom, numer); i >= 2 ; i--) {
        if(denom % i == 0 && numer % i == 0) {
            denom /= i;
            numer /= i;
            
            break;
        }
    }
    
    answer.push_back(numer);
    answer.push_back(denom);
    
    return answer;
}
