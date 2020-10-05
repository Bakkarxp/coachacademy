//
// Created by HKP28 on 05/10/2020.
//

#ifndef COACHACADEMY_BIGINT_H
#define COACHACADEMY_BIGINT_H
#include <vector>
using std::vector;
using std::pair;
class BigInt {
private:
    vector<char> m_number;
    bool m_sign;

public:
    // Constructors
    explicit BigInt()=default;
    explicit BigInt(vector<char> num, bool sign);
    explicit BigInt(const BigInt &bigInt);

    // Getter & Setters
    bool getSign()const{return m_sign;}
    void setSign(bool sign){this->m_sign=sign;}
    vector<char> getNumber()const{return m_number;}
    void setNumber(vector<char> number){this->m_number=number;}

    // Operators



private:
    void equalizeSize(vector<char> &num1,vector<char> &num2);
    void removeLeadingZeros(vector<char> &num);
    vector<char> addBigInt(vector<char> num1,vector<char> num2);
    vector<char> subtractBigInt(vector<char> minuend, vector<char> subtrahend);
    vector<char> multiplyBigInt(vector<char> num1, vector<char> num2);
    pair<vector<char>, long long> divideByLl(vector<char> dividend, long long divisor);


};


#endif //COACHACADEMY_BIGINT_H
