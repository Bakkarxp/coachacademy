//
// Created by HKP28 on 05/10/2020.
//

#include "BigInt.h"

void BigInt::equalizeSize(string &num1, string &num2) {
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

string BigInt::addBigInt(string num1, string num2) {
    equalizeSize(num1,num2);
    char carry{'0'};
    string sum(num1.length(),'0');
    for(int i = (int) num1.length()-1; i>=0;i--){
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

string BigInt::subtractBigInt(string minuend, string subtrahend) {
    // minuend should be greater than subtrahend
    equalizeSize(minuend, subtrahend);
    string difference(minuend.length(), '0');
    // subtract
    for(int i = (int) minuend.length() - 1; i >= 0; i--){
        if(minuend[i] < subtrahend[i]){
            minuend[i]+=10;
            minuend[i - 1]--;
        }
        difference[i]= (minuend[i] - '0') - (subtrahend[i] - '0') + '0';
    }
    // Remove Left zeros
    while(difference[0] == '0' && difference.length() != 1){
        difference.erase(difference.begin());
    }

    return difference;
}

string BigInt::multiplyBigInt(string num1, string num2) {
    //
    if(num1.length()>num2.length()){
        num1.swap(num2);
    }
    string result{'0'};

    // num1 is the smaller
    for(int i = (int) num1.length()-1; i>=0;i--){

        string temp(num2);
        int carry = 0;

        // num2 is the bigger
        for(int j = (int) num2.length()-1; j>=0;j--){
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
        temp.insert(temp.end(),num1.length()-i-1,'0');
        result = addBigInt(result,temp);
    }

    // Remove Left zeros
    while(result[0] == '0' && result.length() != 1){
        result.erase(result.begin());
    }
    return result;
}

pair<string, long long> BigInt::divideByLl(string dividend, long long int divisor) {
    long long rem = 0;
    string result; result.resize(10000);

    for(int indx=0, len = dividend.size(); indx<len; ++indx)
    {
        rem = (rem * 10) + (dividend[indx] - '0');
        result[indx] = rem / divisor + '0';
        rem %= divisor;
    }
    result.resize( dividend.size() );

    // Remove Left zeros
    while(result[0] == '0' && result.size() != 1){
        result.erase(result.begin());
    }

    if(result.size() == 0)
        result.push_back('0');

    return make_pair(result, rem);
}

void BigInt::removeLeadingZeros(string &num) {
    while(m_number[0] == '0' && m_number.size() != 1){
        m_number.erase(m_number.begin());
    }
}

BigInt::BigInt(string num, bool sign) {

}