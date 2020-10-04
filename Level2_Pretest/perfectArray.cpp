#include <iostream>
#include <math.h>
using std::cout;
using std::endl;
using std::cin;
bool isPerfect(int);
int main(){
    int t, arrayDim;
    cin>>t;
    if(t<1 || t>100 ){
        return -1;
    }
    int output[t];
    for(int i=1;i<=t; i++){
        cin>>arrayDim;
        if(arrayDim<1 || arrayDim>100 ){
            return -1;
        }
        int array[arrayDim][arrayDim];

        for(int r=0;r<arrayDim;r++){
            for(int c=0;c<arrayDim;c++){
                int element;
                std::cin >> element;
                if(element<1 || element>100){
                    return -1;
                }
                array[r][c] = element;
            }
        }


        int sum{0};
        for(int r=0;r<arrayDim;r++){
            for(int c=0;c<arrayDim;c++){
                if(isPerfect(array[r][c])){
                    sum += array[r][c];
                }

            }
        }
        output[i]=sum;
    }
    for(int i=1;i<=t; i++){
        cout<<output[i]<<endl;
    }


    return 0;
}

bool isPerfect(int x){
    return (std::sqrt(x) - std::ceil(std::sqrt(x)))==0;
}