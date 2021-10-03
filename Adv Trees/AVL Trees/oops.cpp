#include <bits/stdc++.h>
using namespace std;

class A {
    public:
    virtual void f(){
        cout << "A";
    }
};

class B : A {
    public:
    void f(){
        cout << "B";
    }
};

int main(){
   
    A* abc = new B();
    

}