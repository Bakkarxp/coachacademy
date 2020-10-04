#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;

char findMaxRepChar(char str[]);

int main()
{
    int t;
    cin>>t;
    if(t<1 || t>100){
        return -1;
    }
    char resultchars[t];
    for(int i = 1; i<=t; i++){
        int strlen;
        cin>>strlen;

        if(strlen<1 || strlen>100){
            return -1;
        }

        char str[strlen+1];
        cin>>str;
        resultchars[i] = findMaxRepChar(str);
    }
    for(int i = 1; i<=t; i++){
        cout<<resultchars[i]<<endl;
    }
    return 0;
}

char findMaxRepChar(char str[]){
    std::map<char, int> repeatedChars;
    int loopCounter{0};

    // counting repeated chars in std::map
    while(str[loopCounter] != '\0'){
        char character = str[loopCounter];
        auto iter = repeatedChars.find(character);
        if(iter != repeatedChars.end())
        {
            iter->second++;
        }else
        {
            auto pair = std::make_pair(character,1);
            repeatedChars.insert(pair);
        }
        loopCounter++;
    }

    // copy std::map elements into std::vector
    std::vector<std::pair<char, int>> repeatedCharsVec {};
    for(auto pair : repeatedChars){
        repeatedCharsVec.push_back(pair);
    }


    // sorting the vector
    std::sort(repeatedCharsVec.begin(),repeatedCharsVec.end(),[=](std::pair<char, int>& a,std::pair<char, int>& b){
        return b.second < a.second;
    });

    return repeatedCharsVec[0].first;

}