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
    std::string firstHalf;
    std::string secondHalf;
    std::string secondHalfInv;
    if(s.size()%2==0){
        firstHalf = s.substr(0,s.size()/2);
        secondHalf = s.substr(s.size()/2,s.size());
        std::reverse(secondHalf.begin(),secondHalf.end());
//        cout<<s<<endl;
//        cout<<firstHalf<<endl;
//        cout <<secondHalf<<endl;
        if(firstHalf==secondHalf){
            //cout<<"true";
            return true;
        } else{
            return false;
        }
    }else{
        int half = (s.size()-1)/2;
        firstHalf = s.substr(0,half);
        secondHalf = s.substr(half+1,s.size());
        std::reverse(secondHalf.begin(),secondHalf.end());
//        cout<<s<<endl;
//        cout<<firstHalf<<endl;
//        cout <<secondHalf<<endl;
        if(firstHalf==secondHalf){
            //cout<<"true";
            return true;
        } else{
            return false;
        }
    }

   //return true;
}

int main() {
    std::vector<bool> results;
    std::string statement;
    while(statement != "DONE"){
        std::getline(std::cin, statement);
        trim(statement);
        if(statement == "DONE"){
            break;
        }
        //cout << clean(statement) << endl;
        std::string cleanedString;
        cleanedString= clean(statement);
        results.push_back(ispalindrome(cleanedString));

    }
    for(bool b : results){
        if(b == true){
            cout<<"You won't be eaten!"<<endl;
        }else{
            cout<<"Uh oh.."<<endl;
        }
    }

    //char *statement;
    //cin.getline(statement);
    //std::cout << statement << std::endl;
    return 0;
}
