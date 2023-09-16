#include <iostream>
using namespace std;

class Sum
{
    int operand1,operand2,result;
public :
    void getUserValues(void);
    void calculateSum(void);
    void displaySum(void);
};

void Sum ::getUserValues()
{
    cout << "Enter the Value 1 :" <<endl;
    cin >> operand1;
    cout << endl<<"Enter Value 2 :" << endl;
    cin >> operand2;
}

void Sum ::calculateSum()
{
    result = operand1 + operand2;
}

void Sum :: displaySum(){
    cout << "Sum is :" << result;
}

int main()
{
    Sum s;
    s.getUserValues();
    s.calculateSum();
    s.displaySum();
    cout<<endl;
    return 0;
}
