#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void trim(std::string s){
    std::string  unWantedChars=" ";
    for(char c: unWantedChars ){
        s.erase(std::remove(s.begin(), s.end(), c), s.end());
    }
}

std::string clean(std::string s){
    std::string  unWantedChars=".,?! ";
    // Transform to lower
    std::transform(s.begin(),s.end(),s.begin(),::tolower);
    // Execlude unwanted chars
    for(char c: unWantedChars ){
        s.erase(std::remove(s.begin(), s.end(), c), s.end());
    }
    return s;
}

bool ispalindrome(std::string s){

    if(s.size()%2==0){

    }else{

    }

    return true;
}

int main() {
    std::vector<std::string> statements;
    std::vector<std::string> results;
    std::string statment;
    while(statment!="DONE"){
        std::getline(std::cin,statment);
        trim(statment);
        if(statment=="DONE"){
            break;
        }
        cout<<clean(statment)<<endl;
    }


    //char *statement;
    //cin.getline(statement);
    //std::cout << statement << std::endl;
    return 0;
}
