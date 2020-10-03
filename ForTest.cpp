//
// Created by hkp28 on 21/09/2020.
//
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void equalizeSize(vector<char> &num1,vector<char> &num2){

   unsigned int sizeDiff;
    if(num1.size()>num2.size()){
        sizeDiff = num1.size()-num2.size();
    } else{
        sizeDiff = num2.size()-num1.size();
    }

    // equalize vector sizes
    if(num1.size()>num2.size()){
        num2.insert(num2.begin(),sizeDiff,'0');
    } else{
        num1.insert(num1.begin(),sizeDiff,'0');
    }

    for(char c:num1){
        cout<<c;
    }
    cout<<endl;
    for(char c:num2){
        cout<<c;
    }
    cout<<endl;
}

vector<char> addBigInt(vector<char> num1,vector<char> num2){



    
    return vector<char>();
}

int main()
{

    vector<char> num1={'6','2','0','6','2','0','9'};
    vector<char> num2={'9','5','8','9'};

    equalizeSize(num1,num2);

    char carry{'0'};
    vector<char> sum(num1.size(),'0');
    for(char c:sum){
        cout<<c;
    }
    cout<<endl;
    for(int i = (int) num1.size()-1; i>=0;i--){
        sum[i]=((carry -'0')+(num1[i] -'0')+(num2[i] -'0'))+'0';
        if(i!=0){
            if(sum[i]>'9'){
                carry = '1';
                sum[i]-=10;
            } else{
                carry = '0';
            }
        }
    }

    //Check the last digit in the left
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