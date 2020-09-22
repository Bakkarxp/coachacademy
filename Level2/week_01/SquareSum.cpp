//
// Created by HKP28 on 18/09/2020.
//
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


int main() {
    int dimention{1} ;
    vector<vector<int>> caseResults;
    vector<int> dimentions;


    do{
        // Getting Input
        cin>>dimention;
        if(dimention==0)
            break;
        dimentions.push_back(dimention/2);
        int square[dimention][dimention];
        for (int r = 0; r < dimention; r++) {
            for (int c = 0; c < dimention; c++) {
                cin>>square[r][c];
            }
        }

        // Calculate Squares sum
        int squareNum ;
        if(isOdd(dimention)){
            squareNum= (dimention+1)/2;
        }else{
            squareNum= dimention/2;
        }

        vector<int>result;
        if(dimention==1){
            result.push_back(square[dimention-1][dimention-1]);
        } else{
            int squares[squareNum];
            int row{0};
            int col{0};
            for(int i=0;i<squareNum;i++) {
                int sum{0};

                for (int r = row; r < dimention; r++) {
                    for (int c = col; c < dimention; c++) {
                        sum += square[r][c];
                    }
                }

                row++;
                col++;
                dimention--;
                squares[i]=sum;
                if(dimention<1){
                    dimention=1;
                }
            }

            for(int i=0;i<squareNum;i++) {
                result.push_back(squares[i]-squares[i+1]);
                //std::cout << "Sum of array:"<<squares[i]-squares[i+1]<< std::endl;
            }
        }

        caseResults.push_back(result);





    }while (dimention!=0);






    // Print output
    int x= 1;
    for (auto vec : caseResults){
        cout<<"Case "<<x<<": ";
        for (auto n : vec){
            cout<<n;
            for (int i=0;i<dimentions[x-1];i++){
                cout<<" ";
            }
        }
        cout<<endl;
        x++;
    }



    return 0;
}

