#include <bits/stdc++.h>  
using namespace std;

class User{
    string name;
    public:
    
    User( string name ){
        this->name = name;
        cout << "Sucess\n";
    }
    void show(){
        cout << name;
    }
};

int main() {
 
   { User t("user1");
    t.show();}
    User t("User2");
    t.show();

   return 0;
}