#include <iostream>


int recSum(int elements[], int n) {
    if (n == 0) {
        return 0;
    }
    return elements[0] + recSum(elements + 1, n - 1);
}


int main() {
    int t;
    std::cin >> t;
    if(t>100){
        return -1;
    }

    int arraySize;
    int output[t];

    for (int i = 0; i < t; i++) {
        std::cin >> arraySize;
        if(arraySize<1 || arraySize>100){
            return -1;
        }

        int array[arraySize];
        for (int x = 0; x < arraySize; x++) {
            int element;

            std::cin >> element;
            if(element<-1000 || element>1000){
                return -1;
            }
            array[x]= element;
        }
        output[i] = recSum(array, arraySize);
    }
    for (int i = 0; i < t; i++) {
        std::cout << "Case " << i + 1 << ": " << output[i] << std::endl;
    }
    return 0;
}


