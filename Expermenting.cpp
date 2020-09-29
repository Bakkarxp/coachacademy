//
// Created by Aboubakr on 9/25/2020.
//
#include <iostream>
using namespace std;
int invertNumber(int n){
    int reverse=0,rem;
    while(n!=0)
    {
        rem=n%10;
        reverse=reverse*10+rem;
        n/=10;
    }
    return reverse;
}
int main()
{
    int n, reverse=0, rem;
    cout<<"Enter a number: ";
    cin>>n;
//    while(n!=0)
//    {
//        rem=n%10;
//        reverse=reverse*10+rem;
//        n/=10;
//    }


    cout<<"Reversed Number: "<<invertNumber(n)<<endl;
    return 0;
}
