//
// Created by HKP28 on 16/09/2020.
//


#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int numbers[],int n){
    int i, j;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(numbers[j] > numbers[j+1])
                swap(&numbers[j],&numbers[j+1]);
        }
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

int median(int numbers[], int n){
    int medianIndex;
    if(isOdd(n)){
        medianIndex =(n-1)/2;
        return numbers[medianIndex];
    }else{
        medianIndex = n/2;
        return std::ceil((numbers[medianIndex]+numbers[medianIndex-1])/2);
    }

}

int numbers[10000];
int medians[10000];
int main() {



    // Get median
    int x{0};
    // Get Input
    while (cin>>numbers[x]){
        // Sort array
        bubbleSort(numbers,x+1);
        cout<< median(numbers,x+1)<<endl;
        x++;
    }


    return 0;
}