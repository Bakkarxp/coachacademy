//
// Created by hkp28 on 23/09/2020.
//

/*
Tommy lanterns
 No. = n
 Brightness = a1,a2,an,.....

 Banban lanterns
 No. = m
 Brightness = b1,b2,bm,.....

Tommy hides the largest brightness lantern
 Banban the second largest of Tommy's lanterns and the largest of his own to form the pair

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(){
    int n,m;
    cin >> n;
    if(n<2||n>50){
        return -1;
    }
    cin >> m;
    if(m<2||m>50){
        return -1;
    }
    vector<long long> a,b;
    // Get the inputs
    for(int i=1; i <= n; i++){
        long long brightness;
        cin>>brightness;
        if(brightness<-1000'000'000||brightness>1000'000'000){
            return -1;
        }
        a.push_back(abs(brightness));
    }
    for(int i=1; i <= m; i++){
        long long brightness;
        cin>>brightness;
        if(brightness<-1000'000'000||brightness>1000'000'000){
            return -1;
        }
        b.push_back(abs(brightness));
    }
    // sorting
    std::sort(a.begin(), a.end(), std::greater<long long>());
    std::sort(b.begin(), b.end(), std::greater<long long>());

    // pop_up biggest value
    cout << a[1] * b[0];

    return 0;
}