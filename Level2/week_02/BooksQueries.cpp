//
// Created by hkp28 on 25/09/2020.
//
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::deque;
using std::vector;

int booksToPopup(deque<int> shelf, int id){
    int pos{0};
    int books{0};
    for(int i=0 ;i<shelf.size();i++){
        if(shelf[i]==id){
            pos = i+1;
            break;
        }
    }
    if(pos<=shelf.size()/2){
        books = pos-1;
    }else{
        books = shelf.size()-pos;
    }

    return books;
}


int main(){
    int queries;
    cin>>queries;
    deque<int> shelf;
    vector<int> queryresults;

    for(int i=1 ;i<=queries;i++){
        char queryType;
        int id;
        cin>>queryType;
        cin >> id;
        if(queryType=='L'){
            // Insert left
            shelf.push_front(id);
        } else if (queryType=='R'){
            // Insert right
            shelf.push_back(id);
        } else if (queryType=='?'){
            // Search id
            int books = booksToPopup(shelf,id);
            // insert query result
            queryresults.push_back(books);
        }
    }


    for (int r:queryresults){
        cout<<r<<endl;
    }
//    for(int i=0 ;i<shelf.size();i++){
//        cout<<shelf[i]<<endl;
//    }
//    cout<<"Popped books: "<< booksToPopup(shelf,115);
    return 0;
}

