#include <bits/stdc++.h>  
using namespace std;


class User{
    public:
    
    string name;
    User(string s =""){
        name = s;
    }

    void show(){
        cout << name;
    }

    map< string, vector< pair< bool , string > > > book;

    void booking(string date, int stime, int duration, string user_name){
    //  map - > string(date) , vector < time , metting with the person ) 1440 hona chaiye
      

        vector< pair < bool , string> > t (1440);
        if(book.find(date) == book.end()) // nahi hai aise date toh event banao
        {

        }
        else{
            
            auto x = book[date];
            
            for(int i =stime ; i < stime + duration; i++){
                if(x[i].first == true){ // booked
                    cout << "failure\n";
                    break;
                }
            }





        }
       
    }
    

};



int main() {
  
    int n;
    cin>>n;
    map<string,User> NameMap;
    int j = 0;
    
    for(int i =0; i < n; i++){
        string s;
        cin>> s; // command

        if(s == "add-user"){
            string userName;
            cin >> userName;

            // object creation aur add krna hai vector mai 
            // string = 0 vansh ruhela 
            
            User temp(userName);
            
            if(NameMap.find(userName) == NameMap.end()){
               
                NameMap[userName] = temp;
                cout <<"Sucess\n";
            }
            else{
                cout <<"failure\n";
            }
            
        }

        else if(s == "create-event"){
            string date;
            cin>>date;
            string time;
            cin>>time;
            string duration;
            cin>> duration;
            string num_user;
            cin>> num_user;

            for(int i=0; i< stoi(num_user); i++){
                
            }

        }

    }


    for(auto n : NameMap){
         (n.second).show();
    }


   return 0;
}