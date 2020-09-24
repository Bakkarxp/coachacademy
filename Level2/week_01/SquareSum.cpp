
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
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

int getSquaresCount(int dimention){
    int squareNum ;
    if(isOdd(dimention)){
        squareNum= (dimention+1)/2;
    }else{
        squareNum= dimention/2;
    }
    return squareNum;
}

int main() {
    int dimention{1} ;
    vector<vector<int>> caseResults;

    do{
        // Getting Input
        cin>>dimention;
        if(dimention==0)
            break;
        int numbers[dimention][dimention];
        for (int r = 0; r < dimention; r++) {
            for (int c = 0; c < dimention; c++) {
                cin>>numbers[r][c];
            }
        }

        // Calculate Squares sum
        int squares = getSquaresCount(dimention) ;
        std::vector<int> results;
        int row{0};
        int col{0};
        for(int i =1;i<=squares;i++){
            int squareSum{0};
            for(int r=row;r<dimention;r++){
                for(int c=col;c<dimention;c++){
                    squareSum +=numbers[r][c];
                }
            }
            results.push_back(squareSum);
            row++;
            col++;
            dimention--;
        }
            std::vector<int> finalResult;
            for(int i=0;i<results.size();i++) {
                if(i==results.size()-1) {
                    finalResult.push_back(results[i]);
                }else {
                    finalResult.push_back(results[i]-results[i+1]);
                }
            }

        caseResults.push_back(finalResult);
        if(dimention==0){
            dimention=1;
        }
    }while (dimention!=0);

    // Print output
    int x= 1;
    for (auto vec : caseResults){
        cout<<"Case "<<x<<":";
        for (auto n : vec){
            cout<<" "<< n ;
        }
        cout<<endl;
        x++;
    }

    return 0;
}

