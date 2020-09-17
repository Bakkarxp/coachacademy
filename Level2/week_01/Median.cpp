//
// Created by HKP28 on 16/09/2020.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

bool isOdd(int n){
    int reminder;
    reminder = n%2;
    if(reminder == 0)
    {
        return false;
    } else{
        return true;
    }

}

int median(std::vector<int> numbers, int n){
    int medianIndex;
    if(isOdd(n)){
        medianIndex =(n-1)/2;
        return numbers[medianIndex];
    }else{
        medianIndex = n/2;
        return std::ceil((numbers[medianIndex]+numbers[medianIndex-1])/2);
    }

}

int main() {
    int num{0}, x{0};
    std::vector<int> numbers;
    while(cin>>num){
        numbers.push_back(num);
        std::sort(numbers.begin(), numbers.end());
        cout<< median(numbers,numbers.size())<<endl;
        x++;
    }
    return 0;
}