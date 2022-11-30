#include <iostream>
using namespace std;

class Hello{
    public:
        int a;
        int b;
        Hello(){}
        int sum(int ,int);
};

int Hello::sum(int a, int b){
    return a + b;
}

int main (){
    Hello A;
    cout << A.sum(4,2);
    cout << A.sum(4,4);
    return 0;
}