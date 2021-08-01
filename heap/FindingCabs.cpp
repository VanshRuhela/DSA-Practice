/*=============================================================================
#  PROBLEM:          Given N caretsian Points in a 2D plane each represents the location of the cab.
                    You are standing at origin you want to know the names of nearest "k" cars.
=============================================================================*/
#include <bits/stdc++.h>
using namespace std;

class Car {
   public:
    string id;
    int x, y;
    Car(string id, int x, int y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int dist() const{
        return x*x + y*y;
    }
};

class CarCompare{
    public:
    bool operator()(const Car a, const Car b){
        return a.dist() > b.dist();  // greater than max heap sign
    }
};

void NearestCars(vector<Car> cars, int k) {
     // creat a max heap of size K
     
     priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k); // oth car + kth 

    for(int i=k; i<cars.size(); i++){
        auto car = cars[i];

        if(car.dist() < max_heap.top().dist()){
            max_heap.pop();
            max_heap.push(car);
        }
    }

    while(!max_heap.empty()){
        cout<< max_heap.top().id <<endl;
        max_heap.pop();
    }


}

int main() {
    int N, K;
    cin>> N>>K;

    string id;
    int x, y;

    vector<Car> cars;
    for (int i = 0; i < N; i++) {
        cin >> id >> x >> y;
        Car car(id,x,y);
        cars.push_back(car);
    }

    NearestCars(cars, K);

    return 0;
}