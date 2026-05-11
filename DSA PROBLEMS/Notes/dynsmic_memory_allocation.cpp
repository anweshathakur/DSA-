// dynamic memory allocation
// used when the number of  objects are unknown
// allocate , assign , deallocate
/*
#include <iostream>
using namespace std;
int main(){
double *p = new double; // allocate
*p = 3.14; //assign
cout << *p << endl;
delete p; // deallocate
}

*/

//example:
#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "enter tootal number of students:";
    cin >> n;
    // alloate memory for n students
    float *p = new float[n];
    //assing 
    cout << "enter cgpa of students:" << endl;
    for (int i =0 ; i < n ; i++){
        cin >> *(p +i );
        cout << "cgpa of studnet" << i+1  << "is" << *(p +1) << endl;
    }
    // deallocate 
    delete[]p;
}


