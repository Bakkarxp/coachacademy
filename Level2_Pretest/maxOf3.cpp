#include <iostream>
#include <algorithm>

// compiler should support c++17 for std::max_element to work


int main() {


    int t;
    std::cin>>t;
    if(t<1 || t>100 ){
        return -1;
    }
    int result[t];

    for (int i=0; i<t ; i++){
        int numbers[3];
        for (int x=0; x<3 ;x++){
            int number;
            std::cin>>number;
            if(number<1 || number>5 ){
                return -1;
            }
            numbers[x]= number;
        }
        result[i] = *std::max_element(numbers,numbers+3);

    }
    for(int i=0; i<t ; i++){
        std::cout<< result[i] <<std::endl;
    }



    return 0;
}


