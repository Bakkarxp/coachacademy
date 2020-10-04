#include <iostream>

int main() {


    int t;
    int a,b;
    std::cin>>t;
    if(t<1 || t>1000 ){
        return -1;
    }
    int result[t];

    for (int i=0; i<t ; i++){
        std::cin>>a;
        std::cin>>b;
        if((a<-100000 || a>100000) || (b<-100000 || b>100000) ){
            return -1;
        }
        result[i] = abs(a)+abs(b);

    }
    for(int i=0; i<t ; i++){
        std::cout<< result[i] <<std::endl;
    }

    return 0;
}


