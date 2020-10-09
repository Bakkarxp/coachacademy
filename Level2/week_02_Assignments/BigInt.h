//
// Created by HKP28 on 05/10/2020.
//

#ifndef COACHACADEMY_BIGINT_H
#define COACHACADEMY_BIGINT_H
#include <iostream>
#include <string>

using std::pair;
using std::string;
class BigInt {
private:
    string m_number;
    bool m_sign;

public:
    // Constructors
    explicit BigInt()=default;
    explicit BigInt(string num, bool sign);
    //BigInt(const BigInt &bigInt);

    // Getters & Setters
    bool getSign()const{return m_sign;}
    void setSign(bool sign){this->m_sign=sign;}
    string getNumber()const{return m_number;}
    void setNumber(string number){this->m_number=number;}

    // Operators
    // Arithmetic operators
    BigInt operator+(BigInt num);
    BigInt operator-(BigInt num);
    BigInt operator*(BigInt num);
    BigInt operator/(BigInt num);
    BigInt& operator+=(BigInt num);
    BigInt& operator-=(BigInt num);
    BigInt& operator*=(BigInt num);
    BigInt& operator/=(BigInt num);
    BigInt& operator++();
    BigInt operator++(int);
    BigInt& operator--();
    BigInt operator--(int );

    // Relational Operators
    bool operator<(const BigInt &rhs) const;
    bool operator<=(const BigInt &rhs) const;
    bool operator>(const BigInt &rhs) const;
    bool operator>=(const BigInt &rhs) const;

    // Equality operators
    friend bool operator==(const BigInt &lhs, const BigInt &rhs);
    friend bool operator!=(const BigInt &lhs, const BigInt &rhs);

    // Stream operators
    friend std::ostream &operator<<(std::ostream &os, const BigInt &anInt);
    friend std::istream &operator>>(std::istream &in, BigInt &anInt);




private:
    void equalizeSize(string &num1,string &num2);
    void removeLeadingZeros(string &num);
    string addBigInt(string num1,string num2);
    string subtractBigInt(string minuend, string subtrahend);
    string multiplyBigInt(string num1, string num2);
    pair<string, long long> divideByLl(string dividend, long long divisor);

};


#endif //COACHACADEMY_BIGINT_H
