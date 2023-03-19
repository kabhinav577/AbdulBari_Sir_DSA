#include <iostream>
using namespace std;

int main(){
    void fun(int);
    fun(3);
    return 0;
}

void fun(int n){
    if(n>0){
        cout<<n<<endl;
        fun(n-1);
        fun(n-1);
    }
}