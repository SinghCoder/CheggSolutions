#include <iostream>
#include <vector>
using namespace std;

int numLocalMax(vector<double> x){
    double xmin, xmax;
    cout<<"Enter values of xmin and xmax";
    cin>>xmin>>xmax;
    int i, n = x.size(), count = 0;
    for(i = 0; i < n; i++){
        if(x[i] >= xmin && x[i] <= xmax)
            count++;
    }
    return count;
}