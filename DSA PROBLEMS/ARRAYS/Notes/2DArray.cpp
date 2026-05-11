//2D arrays
/*
storing data in matrix form in memory-
in the backend , it is stored in a linear array . 
it is then mapped to a tabular format , 
index to position , 
//questions
//creating 2 d array 
/*
#include <iostream>
using namespace std;
//row wise input
int main(){
    int arr[3][4] ;  //declaration
    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 4 ; j ++){
            cin >> arr[i][j] ; 

        }
    }
    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 4 ; j ++){
            
            cout << arr[i][j] << "  " ;
        }
    }
    return 0;
   
}
//column wise input
int main(){
    int arr[3][4] ;
    for (int i = 0 ; i < 4 ; i++){
        for (int j = 0 ; j <3 ; j ++){
            cin >> arr[j][i] ; 

        }
    }
    for (int i = 0 ; i < 4 ; i++){
        for (int j = 0 ; j < 3 ; j ++){
             
            cout << arr[j][i] << "  " ;
        }
    }
    return 0;
}

//initialization
int arr[3][4] = {1 , 2 , 3 , 4, 5, 6, 7, 8, 9, 10, 11, 12};
int arr [3][4] = {{1 , 1 , 1 , 1} , {2, 2,2 ,2 }, {3, 3, 3 }};



//linear search  in 2d arrays

#include <iostream>
using namespace std;
//isPrestent
bool isPresent (int arr[][4] , int target ,, int i , int j){
    for (int i = 0 ;i < 3 ; i++){
        for (int j = 0 ; j < 4 ; j ++){
            if (arr[i][j] == target){
                return 1 ;
            }
            else {
                return 0  ;
            }
        }
    }
}
//row wise input
int main(){
    int arr[3][4] ;  //declaration
    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 4 ; j ++){
            cin >> arr[i][j] ; 
        }
    int target;
    cout <<  "enter the element to be searched " ;
    cin >> target ;
    if (isPresent (arr , target , 3 , 4)){
        cout << "element found"; 
    }
    else {
        cout << "element not found" << endl ; 
    }
    return 0 ;

    }


// sum of elements in a row  (rowwise sum)
#include <iostream>
using namespace std;
int main(){
    // input array
    int arr[3][4] ;  //declaration
    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 4 ; j ++){
            cin >> arr[i][j] ; 

        }
    }
    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 4 ; j ++){
            
            cout << arr[i][j] << "  " ;
        }
    }
    for (int i = 0 ; i < 3 ; i++){
        int sum = 0;
        for (int j = 0 ; j < 4 ; j ++){
             sum += arr[i][j];
        }
        cout << "sum of " << i << "th row is" << sum << endl; 

    return 0;
}



//largest row sum
#include <iostream>
using namespace std; 
#include <climits>

int largestRowSum(int arr [][3] , int i , int j){
    int maxi = INT_MIN;
    int rowIndex = -1 ;
    for (int i = 0 ; i < 3 ; i++){
        int sum = 0;
        for (int j = 0 ; j < 3 ; j ++){
             sum += arr[i][j];
        }
        cout << "sum of " << i << "th row is" << sum << endl  ; 
    if (sum > maxi){
        maxi = sum ;
        rowIndex = i ;
    }

}
cout << "the largest row sum is " << maxi << endl;
cout << "the row index is "  << rowIndex << endl ;
return 0 ;
}


int main(){
    int arr[3][3] = {{1, 2 , 3} , {4 , 5 , 6} , {7, 8 ,9}};
    largestRowSum (arr , 3 , 3 );
}
   



//from code studio
/*
wave print
take a 2D array and print one column from top to bottom and the next
column from bottom to top and so on
*/
#include <iostream>
using namespace std ;
int waveprint (int arr [][4], int i , int j){
    for (int col = 0 ; col < 4 ; col  ++){
        if(col%2 == 0){
            for  (int row = 0 ; row < 3 ; row ++){
                cout << arr [row][col] << " " ;
            }
        }
        else {
            for (int row = 2 ; row >= 0 ; row --){
                cout << arr [row ][col] << " " ; 
            }
        }
    }
    return 0 ; 
}
int main (){
    int arr[3][4] = {{1 , 2 ,3,4} , {5, 6 , 7 , 8 } , {9, 10 , 11 , 12}};
    waveprint( arr , 3 , 4) ; 
    return 0 ;
}




//spiral print 
/*
approach:
print first row -> last col -> last row -> first col
move similarilly for inner matrix
shift the boundaries at each step

#include <iostream>
using namespace std ;
int spiralprint(int arr [][4] , int i , int j ){
    int startingrow = 0 ;
    int endingrow = i - 1 ;
    int startingcol = 0 ;
    int endingcol = j-1 ;
    int count = 0 ;
    int total = i*j ;
    while ( count < total) {
        // print starting row 
        for ( int index = startingcol ; count < total && index <= endingcol ; index ++){
            cout << arr[startingrow][index] << " " ;
            count ++ ; 
        }
        startingrow ++ ; 
        // print ending col 
        for (int index = startingrow ; count < total && index <= endingrow ; index ++){
            cout << arr[index][endingcol] << " ";
            count ++ ; 
        }
        endingcol -- ; 
        //print ending row 
        for (int index = endingcol ; count < total && index >= startingcol ; index --){
            cout << arr[endingrow][index] << " " ; 
            count ++ ; 
        }
        endingrow -- ;
        // printing starting col
        for (int index = endingrow ; count < total && index >= startingrow ; index --){
             cout << arr[index][startingcol] << " " ; 
        }
        startingcol ++ ;

    }
}
// rotate a matrix by 90 degree 
// sorting a 2d array row wise and column wise 




#include <iostream>
using namespace std ;
int i , j ;
int arr[3][3]; //declaration
cin >> arr[i][j]; //input
cout << arr[i][j]; //output
*/


// matrix multiplication 
#include <iostream>
using namespace std ;
int main (){
    int col1 , row1 , col2 , row2 ;

    int a[3][3] ;
    int b[3][3];
    //input for both matrices
    for (int i = 0 ; i < 3 ; i ++ ){
        for (int j = 0 ; j <3 ; j++){
            cin >> a[i][j];
            cin >> b[i][j];
        }
    }
    //printing both matrices
    for (int i = 0 ; i < 3 ; i ++ ){
        for (int j = 0 ; j <3 ; j++){
            cout << a[i][j] << "  ";
            cout << b[i][j] << "  " ; 
        }
    }
    //mul
    int res[3][3] ;
    if (col1 != row2){
        cout << "multiplication not possible" << endl ;
    }
    else {
        for (int i = 0 ; i < row1 ; i++){
            for (int j = 0 ; j < col2 ; j ++){
                res[i][j] = 0 ;
                for (int k = 0 ; k < col1  ; k ++){
                    res[i][j] += a[i][j] * b[i][j] ;
                }
            }
        }
    }
    

}