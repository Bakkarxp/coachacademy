//
// Created by hkp28 on 21/09/2020.
//
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
int main()
{
    vector<char> num1={'8','8','2','6'};
    vector<char> num2={'9','6','8','9'};
    char carry{'0'};
    vector<char> sum{'0','0','0','0'};
    for(int i=num1.size()-1; i>=0;i--){
        sum[i]=((carry-'0')+(num1[i]-'0')+(num2[i]-'0'))+'0';
        if(i!=0){
            if(sum[i]>=10){
                carry = '1';
                sum[i]-=10;
            } else{
                carry = '0';
            }
        }
    }
    if(sum[0] > '9')
    {
        sum[0]-= 10;
        sum.insert(sum.begin(),'1');
    }
    for(char c:sum){
        cout<<c;
    }
    return 0;
}