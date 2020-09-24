//
// Created by Aboubakr on 9/15/2020.
//

#include <iostream>

int main() {

    int t;
    std::cin>>t;
    if(t>=15)
        return -1;
    char result[t];
    int a,b;
    for (int i = 0; i<t; i++){
        std::cin>>a;
        std::cin>>b;
        if(a>b)
        {
            result[i]='>';
        }
        else if(a<b)
        {
            result[i]='<';
        }
        else
        {
            result[i]='=';
        }
    }
    for (int i = 0; i<t; i++){
        std::cout<<result[i]<<std::endl;
    }

    return 0;
}