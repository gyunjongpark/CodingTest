#include <string>
#include <vector>
using namespace std;

int getGCD(int a,int b){
    if(a==0) return b;
    
    return getGCD(b%a,a);
}

int getLCM(int a,int b){
    return a*b/getGCD(a,b);
}

int solution(int n) {
    int answer = n*6/getGCD(n,6)/6;
    
    return answer;
}
