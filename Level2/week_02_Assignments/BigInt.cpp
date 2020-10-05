//
// Created by HKP28 on 05/10/2020.
//

#include "BigInt.h"

void BigInt::equalizeSize(vector<char> &num1, vector<char> &num2) {
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
}

vector<char> BigInt::addBigInt(vector<char> num1, vector<char> num2) {
    equalizeSize(num1,num2);
    char carry{'0'};
    vector<char> sum(num1.size(),'0');
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
    return sum;
}

vector<char> BigInt::subtractBigInt(vector<char> minuend, vector<char> subtrahend) {
    // minuend should be greater than subtrahend
    equalizeSize(minuend, subtrahend);
    vector<char> difference(minuend.size(), '0');
    // subtract
    for(int i = (int) minuend.size() - 1; i >= 0; i--){
        if(minuend[i] < subtrahend[i]){
            minuend[i]+=10;
            minuend[i - 1]--;
        }
        difference[i]= (minuend[i] - '0') - (subtrahend[i] - '0') + '0';
    }
    // Remove Left zeros
    while(difference[0] == '0' && difference.size() != 1){
        difference.erase(difference.begin());
    }

    return difference;
}

vector<char> BigInt::multiplyBigInt(vector<char> num1, vector<char> num2) {
    //
    if(num1.size()>num2.size()){
        num1.swap(num2);
    }
    vector<char> result{'0'};

    // num1 is the smaller
    for(int i = (int) num1.size()-1; i>=0;i--){

        vector<char> temp(num2.size());
        int carry = 0;

        // num2 is the bigger
        for(int j = (int) num2.size()-1; j>=0;j--){
            temp[j] = (num2[j]-'0')*(num1[i]-'0')+carry;
            if(temp[j]>9){
                carry = temp[j]/10;
                temp[j]-= carry*10;
            }else{
                carry = 0;
            }
            temp[j]+='0';
        }
        if(carry>0){
            temp.insert(temp.begin(),(carry+'0'));
        }
        temp.insert(temp.end(),num1.size()-i-1,'0');
        result = addBigInt(result,temp);
    }

    // Remove Left zeros
    while(result[0] == '0' && result.size() != 1){
        result.erase(result.begin());
    }
    return result;
}

pair<vector<char>, long long> BigInt::divideByLl(vector<char> dividend, long long int divisor) {
    long long rem = 0;
    vector<char> result; result.resize(10000);

    for(int i=0, len = dividend.size(); i < len; ++i)
    {
        rem = (rem * 10) + (dividend[i] - '0');
        result[i] = rem / divisor + '0';
        rem %= divisor;
    }
    result.resize( dividend.size() );

    // Remove Left zeros
    while(result[0] == '0' && result.size() != 1){
        result.erase(result.begin());
    }

    if(result.empty())
        result.push_back('0');

    return make_pair(result, rem);
}

void BigInt::removeLeadingZeros(vector<char> &num) {
    while(m_number[0] == '0' && m_number.size() != 1){
        m_number.erase(m_number.begin());
    }
}
