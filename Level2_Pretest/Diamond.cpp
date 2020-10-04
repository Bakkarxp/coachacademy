#include <iostream>
using std::cout;
using std::endl;
using std::cin;
void printDiamond(int);
bool isOdd(int);
int main(){
    int t;
    cin>>t;
    if(t<1 || t>100){
        return -1;
    }
    int dimArray[t];
    for(int i=1;i<=t;i++){
        int d;
        cin>>d;
        if(d<1 || d>99 || isOdd(d) == false){
            return -1;
        }
        dimArray[i] = d;

    }
    for(int i=1;i<=t;i++){
        printDiamond(dimArray[i]);
    }


    return 0;
}


void printDiamond(int d){
    int c = (d-1)/2;

    for (int x=1;x<=c;x++){
        for (int y=1;y<=x;y++){
            cout<<"*";
        }

        for (int y=d-x*2;y>=1;y--){
            cout<<" ";
        }

        for (int y=1;y<=x;y++){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i = 1;i<=d;i++){
        cout<<"*";
    }

    cout<<endl;

    for (int x=c;x>=1;x--){
        for (int y=x;y>=1;y--){
            cout<<"*";
        }

        for (int y=1;y<=d-x*2;y++){
            cout<<" ";
        }

        for (int y=x;y>=1;y--){
            cout<<"*";
        }
        cout<<endl;
    }

}


bool isOdd(int n){
    int reminder;
    reminder = n%2;
    if(reminder == 0)
    {
        return false;
    } else{
        return true;
    }

}