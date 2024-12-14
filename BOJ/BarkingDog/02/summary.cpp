#include<iostream>
#include<vector>
using namespace std;

//STL, 구조체, 단순 자료형 변수를 인자로 대입하면 값이 바뀌지 않는다. call by value
//포인터, 참조자를 인자로 대입하면 값이 바뀐다. call by reference

//call by value. 두 값이 바뀌지 않는다
void swap1(int a, int b) { //단순 변수
    int temp = a;
    a = b;
    b = temp;

    return;
}

//call by reference. 두 값이 바뀐다
void swap2(int* a, int* b) { //포인터(주소)
    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}

//call by reference. 두 값이 바뀐다
void swap3(int& a, int& b) { //참조자
    int temp = a;
    a = b;
    b = temp;

    return;
}

//call by value. 배열의 값이 변하지 않는다
void change_vector_val1(vector<int> v) { //단순 벡터 STL
    v[10] = 7;
    return;
}

//call by reference. 배열의 값이 변한다
void change_vector_val2(vector<int>& v) { //참조자
    v[10] = 7;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a = 10, b = 20;

    //swap1(a, b); //값이 바뀌지 않는다
    //swap2(&a, &b); //값이 바뀐다
    swap3(a, b); //값이 바뀐다

    cout << a << ' ' << b << '\n';

    vector<int> v(100);

    //change_vector_val1(v); //값이 변하지 않는다
    change_vector_val2(v); //값이 변한다

    cout << v[10];

    return 0;
}
