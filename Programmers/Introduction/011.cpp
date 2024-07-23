#include <string>
#include <vector>
#include <algorithm> //max_element, min_element
using namespace std;

int maxVal,minVal,maxArr,ret,answer,answerIdx,cnt[1001];

int solution(vector<int> array) {
    maxVal=*(max_element(array.begin(),array.end()));
    minVal=*(min_element(array.begin(),array.end()));
    
    for(int i : array) {
        cnt[i]++; //횟수 저장
    }
    
    for(int i=minVal;i<=maxVal;i++) {
        maxArr = max(maxArr,cnt[i]); //최대 빈도수 maxArr에 저장
    }
    
    for(int i=minVal;i<=maxVal;i++) {
        if(cnt[i]==maxArr){ //횟수가 최대 빈도수라면
            ret++;
            answerIdx=i; //최대 빈도수에 해당하는 값 자체를 answerIdx에 저장
        }
    }
    
    if(ret>1) answer = -1; //최대 빈도수에 해당하는 값이 여러개라면 -1
    else answer = answerIdx; //최대 빈도수에 해당하는 값 answerIdx 출력
    
    return answer;
}
