#include <iostream>
using namespace std;

// Using "switch" for a menu

int main()
{
    double a, b;
    char c;
    
    cout<<"Enter number1 op number2 : ";
    cin>> a >> c >> b;
    
    switch (c)
    {
        
    case '+':
        cout<<"The answer is "<<a+b<<endl;
        break;
        
    case '-':
        cout<<"The answer is "<<a-b<<endl;
        break;
        
    case '*':
        cout<<"The answer is "<<a*b<<endl;
        break;
        
    case '/':
        cout<<"The answer is "<< a/b<<endl;
        break;

    default:
        cout<<"Wrong operation"<<endl;
        
    }

    system("pause");
    return 0;
}

