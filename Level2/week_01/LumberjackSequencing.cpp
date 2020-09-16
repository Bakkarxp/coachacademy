//
// Created by HKP28 on 16/09/2020.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int compare(int a, int b){
    return a>b;
}

int lumSequencChecker(int group[]){
    int result[9];
    int sum{0};
    for(int i=0;i<9;i++){
        result[i]= compare(group[i],group[i+1]);
    }
    for(int i=0;i<9;i++){
       sum+=result[i];
    }
    if(sum!=9 && sum!=0){
        return 0;
    } else{
        return 1;
    }
}


int main() {
    int t;
    cin >> t;
    if(t>19 || t<1){
        return -1;
    }
    int output[t];
    for (int i = 0; i < t; i++)
    {
       int group[10];
       int element;
        for (int c = 0; c < 10; c++)
        {

           cin>>element;
           if(element<0 || element>100)
           {
               return -1;
           }
            group[c]= element;
        }
        output[i] = lumSequencChecker(group);
    }

    cout<<"Lumberjacks:"<<endl;
    for(int i=0;i<t;i++){
        if(output[i]==0){
            cout<<"Unordered"<<endl;
        } else{
            cout<<"Ordered"<<endl;
        }
    }
    return 0;
}
