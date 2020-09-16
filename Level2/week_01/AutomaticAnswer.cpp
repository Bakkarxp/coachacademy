//
// Created by HKP28 on 16/09/2020.
//
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int tensColumnDigit(int n){
    int result;
    result = (n*567/9+7492)*235/47-498;
    return (abs(result)/10)%10;
}

int main() {
    int t;
    cin >> t;
    if(t>100 || t<1){
        return -1;
    }
    int output[t];
    int n;
    for (int i = 0; i < t; i++)
    {
        cin>>n;
        if(n<-1000 || n>1000){
            return -1;
        }
        output[i] = tensColumnDigit(n);
    }
    for (int i = 0; i < t; i++)
    {
        cout<<output[i] <<endl;
    }

    return 0;
}

