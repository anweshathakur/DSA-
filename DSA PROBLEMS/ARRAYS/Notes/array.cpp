/*
//questionson arrays 
//q1 maximum and minimum in  a linear array
#include <iostream>
#include <climits>
using namespace std  ;

int getmax(int arr[] , int n){
    int maxi =  INT_MIN ;
    for (int i = 0 ; i < n ; i++){

        //predefined funnctions 
        maxi = max(maxi , arr[i]);
//same  as 
        if (arr[i] > maxi ){
            maxi = arr[i];
        }
        return maxi ; 
    }
}
int getmin(int arr[] , int n){
    int min =  INT_MAX ;
    for (int i = 0 ; i < n ; i++){
        if (arr[i] < min ){
            min = arr[i];
        }
        return min ; 
    }
}


int main(){
    int size ; 
    cin >> size ;
    int arr[100] ; 

    //taking input
    for (int i = 0  ; i < size ; i ++){
        cin >> arr[i];

        return 0 ;
    }

}
*/
//scopes in arrays
#include <iostream>
using namespace std ;

void update(int arr [] , int n ){

    printf("inside fumction \n");

}

int main(){
    int arr[3] = {1 , 2 , 3 };

    arr[0] = 120;

    //update[arr , 3];

    for ( int i = 0  ; i < 3  ; i ++){
        cout << arr[i] << endl; 

    }

}
// print sum of all elementss in an array 

 // linear search
 #include <iostream>
 using namespace std ; 
 bool  search (int arr [] , int n ){
    int n ; 
    cout << "enter the number to search " << endl ;
    cin>> n ;
    for (int i = 0 ; i < n ; i++){
        if (arr[i] == n ){
            return 1 ;
        }
        else {
            return 0 ;
        }
    }

 }
 int main(){
    int arr [5] = {1 , 2, 3 ,4 , 5 };

    return 0 ;

 }

 // reverse an array

 #include <iostream>
 using namespace std ;
 void reverse (int arr[] , int start = 0 , int end = 4){
    while (start < end){
        swap (arr[start] , arr[end ]);
        start ++;
        end -- ;
        
    }

 }
 int main (){
    int arr[5] = {1 , 2 , 3 , 4 , 5 } ; 

    return 0;
 }
// find unique element in an array
// pair sum
// triplet sum
// swap alternate
//find duplicates in an array
//find intersection of two arrays
// find union of two arrays 




//linkedlist 
// stacks  
// queues
// strings
// trees