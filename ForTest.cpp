//
// Created by hkp28 on 21/09/2020.
//
#include <iostream>
#include <vector>

using std::vector;
using std::pair;
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
}

vector<char> addBigInt(vector<char> num1,vector<char> num2){
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

vector<char> subtractBigInt(vector<char> minuend, vector<char> subtrahend){
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

vector<char> multiplyBigInt(vector<char> num1, vector<char> num2){
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

vector<char> divideBigInt(vector<char> dividend, vector<char> divisor){
    vector<char> reminder;

    return vector<char>();
}

pair<vector<char>, long long> divideByLl(vector<char> dividend, long long divisor){
    long long rem = 0;
    vector<char> result; result.resize(10000);

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

int main()
{

    vector<char> num1={'6','2','0','6','2','0','9'};
    vector<char> num2={'9','5'};
//    vector<char>sum = addBigInt(num1,num2);
//    vector<char>sum = multiplyBigInt(num1,num2);
    auto result = divideByLl(num1,3);
    cout<<result.second<<endl;
    for(auto c:result.first){
        cout<<c;
    }
    return 0;
}