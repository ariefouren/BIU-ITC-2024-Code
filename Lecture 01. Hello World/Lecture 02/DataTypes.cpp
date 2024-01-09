#include <iostream>
using namespace std; 

int main()
{
    // operation sizeof(type) returns the size of the type in bytes
    cout<<"short:  "<<sizeof(short)<<endl; 
    cout<<"int:    "<<sizeof(int)<<endl; 
    cout<<"long:   "<<sizeof(int)<<endl; 
    cout<<"float:  "<<sizeof(float)<<endl; 
    cout<<"double: "<<sizeof(double)<<endl; 

    cout<<"char:   "<<sizeof(char)<<endl; 
    cout<<"bool:   "<<sizeof(bool)<<endl; 
 
    system("pause");
    return 0;
}
