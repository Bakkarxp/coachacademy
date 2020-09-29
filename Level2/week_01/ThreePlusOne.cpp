//
// Created by hkp28 on 19/09/2020.
//

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int threePlusOneRec(int n){
//    static int cycle=1;
//    cout<<n<<endl;
//    if(n==1)
//        return cycle ;
//    if(n%2==0){
//        //n = n/2;
//        threePlusOneRec(n / 2);
//    }else{
//        //n=3*n+1;
//        threePlusOneRec(3 * n + 1);
//    }
//    cycle++;
return 0;
}

int threePlusOne(int n){
    int cycle{0};
    while(n>1){
        if(n%2==0){
            n = n/2;
        }else{
            n=3*n+1;
        }
        cycle++;
    }
    if (n==1){
        cycle++;
    }
    return cycle;
}

int maximumCycle(int a, int b){
    int maxCycle{0};

    if(a>b){
        std::swap(a,b);
    }
    for(int i = a;i<=b;i++){
        int cycleLength = threePlusOne(i);
        if(cycleLength>maxCycle){
            maxCycle = cycleLength;
        }
    }
    return maxCycle;
}

int main(){
    int num{0};
    std::vector<int> numbers;
    std::vector<int> result;
    while(cin>>num){

        numbers.push_back(num);
    }
    for(int i = 0;i<numbers.size(); i+=2){
        cout<<numbers[i] <<" "<<numbers[i+1]<<" "<<maximumCycle(numbers[i],numbers[i+1])<<endl;
    }

    return 0;
}