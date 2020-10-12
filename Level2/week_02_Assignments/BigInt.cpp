//
// Created by HKP28 on 05/10/2020.
//

#include "BigInt.h"

// Constructor
BigInt::BigInt(string num, bool sign):m_number(std::move(num)),m_sign(sign) {}
BigInt::BigInt():m_number("0"),m_sign(false){}
BigInt::BigInt(string num) {
    if( isdigit(num[0]) )
    {
        setNumber(num);
        m_sign = false;
    }
    else
    {
        setNumber( num.substr(1) );
        m_sign = (num[0] == '-');
    }
}
BigInt::BigInt(long long num) {
    if(num<0){
        m_sign = true;
        m_number = std::to_string(std::abs(num));
    }else{
        m_sign = false;
        m_number = std::to_string(num);
    }
}


// Arithmetic operators
BigInt BigInt::operator+(const BigInt &num) {
    string temp;
    bool sign = false;
    if(this->m_sign==num.m_sign){
        temp = addBigInt(this->m_number,num.m_number);
        sign = this->m_sign;
    }else{
        if(this->m_number>num.m_number){
            temp = subtractBigInt(this->m_number,num.m_number);
            sign = this->m_sign;
        } else{
            temp = subtractBigInt(num.m_number,this->m_number);
            sign = num.m_sign;
        }
    }
    if(temp=="0") sign = false;

    return BigInt(temp,sign);
}

BigInt BigInt::operator-(BigInt num) {
    num.setSign(!num.getSign()); // invert the sign of right operand and carry the addition operation
    return (*this)+num;
}

BigInt BigInt::operator*(const BigInt &num) {
    string temp;
    bool sign = false;
    temp = multiplyBigInt(this->m_number,num.m_number);
    if(this->m_sign==num.m_sign){
        sign = false;
    } else{
        sign = true;
    }
    if(temp=="0") sign = false;
    return BigInt(temp, sign);
}

BigInt BigInt::operator/(BigInt num) {
    string temp;
    bool sign = false;
    long long divisor = toInt(num.getNumber());
    temp = divideByLl(this->m_number, divisor);
    if(this->m_sign==num.m_sign){
        sign = false;
    } else{
        sign = true;
    }
    if(temp=="0") sign = false;
    return BigInt(temp, sign);
}

BigInt &BigInt::operator+=(const BigInt &num) {
    return (*this) = (*this) + num;
}

BigInt &BigInt::operator-=(const BigInt &num) {
    return (*this) = (*this) - num;
}

BigInt &BigInt::operator*=(const BigInt &num) {
    return (*this) = (*this) * num;
}

BigInt &BigInt::operator/=(const BigInt &num) {
    return (*this) = (*this) / num;
}

BigInt &BigInt::operator++() {
    return (*this) = (*this) + 1;
}

BigInt BigInt::operator++(int) {
    BigInt temp = *this;
    (*this) = (*this) + 1;
    return temp;
}

BigInt &BigInt::operator--() {
    return (*this) = (*this) - 1;
}

BigInt BigInt::operator--(int) {
    BigInt temp = *this;
    (*this) = (*this) - 1;
    return temp;
}


// Relational Operators
bool BigInt::operator<(const BigInt &rhs) const {
    if(!this->m_sign && rhs.m_sign){
        return false;
    } else if(this->m_sign && !rhs.m_sign){
        return true;
    // signs are equal and +ve
    } else if(this->m_sign == rhs.m_sign && !this->m_sign){
        return this->m_number<rhs.m_number;
    // signs are equal and -ve
    } else if(this->m_sign == rhs.m_sign && this->m_sign){
        return this->m_number>rhs.m_number;
    // signs are not equal
    }
}

bool BigInt::operator<=(const BigInt &rhs) const {
    return !this->operator>(rhs);
}

bool BigInt::operator>(const BigInt &rhs) const {
    return !this->operator<(rhs) && !this->operator==(rhs);
}

bool BigInt::operator>=(const BigInt &rhs) const {
    return !this->operator<(rhs);;
}


// Equality operators
bool BigInt::operator==(const BigInt &rhs) const {
    if(this->m_number==rhs.m_number && this->m_sign == rhs.m_sign) return true;
    return false;
}

bool BigInt::operator!=(const BigInt &rhs) const {
    return !this->operator==(rhs);
}


// Stream operators
std::ostream &operator<<(std::ostream &os, const BigInt &anInt) {
//    if(anInt.getSign()) std::cout<<"-";
//    std::cout<<anInt.getNumber();
    std::cout << anInt.toString();
    return os;
}

std::istream &operator>>(std::istream &in, BigInt &anInt) {
    string sNumber;
    in >> sNumber;
    if( isdigit(sNumber[0]) )
    {
        anInt.setNumber(sNumber);
        anInt.setSign(false) ;
    }
    else
    {
        anInt.setNumber( sNumber.substr(1) );
        anInt.setSign(sNumber[0] == '-');
    }
    return in;
}


// utility functions
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

string BigInt::divideByLl(string dividend, long long int divisor) {
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

    if(result.empty())
        result.push_back('0');

    return result;
}

void BigInt::removeLeadingZeros(string &num) {
    while(m_number[0] == '0' && m_number.size() != 1){
        m_number.erase(m_number.begin());
    }
}

 string BigInt::toString() const{
    string sNumber;
    if(m_sign) sNumber = "-";
    sNumber.append(m_number);
    return sNumber;
}

long long BigInt::toInt(const string& num) {
    long long sum = 0;
    for(char i : num)
        sum = (sum*10) + (i - '0');
    return sum;
}


