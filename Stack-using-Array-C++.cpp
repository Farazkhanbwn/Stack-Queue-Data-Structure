#include <stdio.h>
#include <iostream>
using namespace std;

class ArrayStack
{
    public:
        int top;
        int capacity;
        int array[4];
    ArrayStack(int cap){
        top = -1;
        capacity = cap;
        // array[] = sizeof(4 * capacity);
    }

    int isFull()
    {
        if (capacity-1 == top)
            return (1);
        else
            return (0);
    }
    
    int isEmpty(){
    if(top == -1)
        return (1);
    else
        return (0);
    }
    
    int push (int item){
    if(!isFull()){
        top++;
        array[top] = item;
        return (1);
    }
    else
    {
        return (0);
    }
}
    
    int pop(){
    int item;
    if (!isEmpty()){
        item = array[top];
        top--;
        return item;
    }
    return (-1);
}
};

int main() {
    int choice , item ;
    ArrayStack rect(4);

    while(1){
        system("clear");
        cout << "\n" << "1 Push";
        cout << "\n" << "2 Pop";
        cout << "\n" << "3 Exit";
        cout<< "\n" << "Enter Your Choice";
        cin >> choice;
        
        switch(choice){
            case 1:
                cout << "\n" << "Enter a number: ";
                cin >> item;
                // checkValue=rect.push(item);
                if(rect.push(item)){
                    cout << "\n" << "Pushed Value in stack is : "<<item;
                }
                else{
                    cout << "\n" << "Stack is Full Your have Failed to Push "<<item;
                }
                break;
            case 2:
                item = rect.pop();
                if(item == -1)
                {
                    cout << "\n" << "Stack is Empty";
                }
                else
                {
                   cout << "\n" << "Poped Value is: " << item;
                }
                break;
                
            case 3:
                    return false;
        }
    }
    return 0;
}