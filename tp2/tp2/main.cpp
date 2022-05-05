#include <iostream>
#include "queue.hpp"
#include "int.hpp"

using namespace std;

int main()
{

    int queue_size = 0, value = 0, flag = 1, c;
    
    cout << "Task #1 - cyclic queue\nEnter size\n";
    cin >> queue_size;

    
    cout << "Enter values: " << endl;
    cin >> value;
    Queue st(value);
    for (int i = 0; i < queue_size-1; i++)
    {
        cin >> value;
        st.push(value);
    }
    value = 0;

    while (flag == 1)
    {
        cout << "Select a cyclic queue operation:" << endl;
        cout << "1 - Add new element"<< endl;
        cout << "2 - Pop" << endl;
        cout << "3 - Print" << endl;
        cout << "4 - Prefix operator ++ (push)" << endl;
        cout << "5 - Postfix operator ++ (push x2)" << endl;
        cout << "6 - Prefix operator -- (pop)" << endl;
        cout << "7 - Postfix operator -- (pop x2)" << endl;
        //cout << "8 - Delete 1 node" << endl;
        cout << "0 - Second task" << endl;
        cout << "--> ";
        cin >> c;

        switch (c)
        {
        case 1:
            
            cout << "Enter value: " << endl;
            cin >> value;
            st.push(value);
            queue_size++;
            cout << "Value added\n " << endl;
            break;
        case 2:
            if (!st)
            {
                cout << "Queue is Empty\n ";
                break;
            }
            else
            {
                
                value = st.pop();
                cout << "Extracted element: " << value << endl;
            }
            break;
        case 3:
            if (!st)
            {
                cout << "Queue is Empty\n" << endl;
                break;
            }
            else
            {
                
                st.print();
                cout << "\n";
            }
            break;
        case 4:
            if (!st)
            {
                cout << "Queue is Empty\n" << endl;
                break;
            }
            else
            {
                
                queue_size++;
                ++st;
                cout << "The operation was successful! The resulting queue: " << endl;
                st.print();
                cout << "\n";
            }
            break;
        case 5:
            if (!st)
            {
                cout << "Queue is Empty\n" << endl;
                break;
            }
            else
            {
                
                st++;
                queue_size+=2;
                cout << "The operation was successful! The resulting queue: " << endl;
                st.print();
                cout << "\n";
            }
            break;
        case 6:
            if (!st)
            {
                cout << "Queue is Empty\n" << endl;
                break;
            }
            else
            {
                
                --st;
                queue_size--;
                cout << "The operation was successful! The resulting queue: " << endl;
                st.print();
                cout << "\n";
            }
            break;
        case 7:
            if (!st)
            {
                cout << "Queue is Empty\n" << endl;
                break;
            }
            else
            {
                
                if (queue_size == 1)
                {
                    cout << "There is one item in the queue, the operation cannot be performed\n";
                    break;
                }
                
                if (queue_size == 2)
                {
                    st--;
                    queue_size -= 2;
                    cout << "The operation was successful! The resulting queue: " << endl;
                    cout << "Queue is Empty\n" << endl;
                    break;
                }
                
                st--;
                queue_size -= 2;
                cout << "The operation was successful! The resulting queue: " << endl;
                st.print();
                cout << "\n";
            }
            break;
        case 8:
            if (!st)
            {
                cout << "Queue is Empty\n" << endl;
                break;
            }
            else
            {
                
                st.del();
                queue_size--;
                cout << "Success! The resulting queue: " << endl;
                if (!st)
                {
                    cout << "Queue is Empty\n" << endl;
                    break;
                }
                st.print();
                cout << "\n";
            }
            break;

        case 0: 
            cout << "\n";
            flag = 0;
            break;
        default:
            cout << "\n";
            flag = 0;
            break;
        }
    }
    st.~Queue();
    
    
    int a, b;
    Int num1, num2, res(0.0);

    cout << "Task #2 - integer\n" << endl;
    flag = 1;

    while (flag == 1)
    {
        cout << "Choose which operations to perform with the class of real numbers:" << endl;
        cout << "1 - Addition" << endl;
        cout << "2 - Subtraction" << endl;
        cout << "3 - Comparison -less than-" << endl;
        cout << "4 - Comparison -greater than-" << endl;
        cout << "5 - Comparison -unequal-" << endl;
        cout << "6 - Comparison -equals-" << endl;
        cout << "0 - Exit" << endl;
        cout << "--> ";
        cin >> c;

        switch (c)
        {
        case 1:
            
            cout << "Enter the first number: " << endl;
            cin >> a;
            cout << "Enter the second number: " << endl;
            cin >> b;
            num1.set_my_int(a);
            num2.set_my_int(b);
            res = num1 + num2;
            cout << "A = " << a << " B = " << b << " Result: ";
            res.display();
            break;
        case 2:
            
            cout << "Enter the first number: " << endl;
            cin >> a;
            cout << "Enter the second number: " << endl;
            cin >> b;
            num1.set_my_int(a);
            num2.set_my_int(b);
            res = num1 - num2;
            cout << "A = " << a << " B = " << b << " Result: ";
            res.display();
            break;
        case 3:
            
            cout << "Enter the first number: " << endl;
            cin >> a;
            cout << "Enter the second number: " << endl;
            cin >> b;
            num1.set_my_int(a);
            num2.set_my_int(b);
            if (num1 < num2)
                cout << "The first number is smaller than the second" << endl;
            else
                cout << "The first number is not smaller than the second" << endl;
            break;
        case 4:
            
            cout << "Enter the first number: " << endl;
            cin >> a;
            cout << "Enter the second number: " << endl;
            cin >> b;
            num1.set_my_int(a);
            num2.set_my_int(b);
            if (num1 > num2)
                cout << "The first number is greater than the second" << endl;
            else
                cout << "The first number is not greater than the second" << endl;
            break;
        case 5:
            
            cout << "Enter the first number: " << endl;
            cin >> a;
            cout << "Enter the second number: " << endl;
            cin >> b;
            num1.set_my_int(a);
            num2.set_my_int(b);
            if (num1 != num2)
                cout << "The first number is unequal to the second" << endl;
            else
                cout << "The first number is not unequal to the second" << endl;
            break;
        case 6:
            
            cout << "Enter the first number: " << endl;
            cin >> a;
            cout << "Enter the second number: " << endl;
            cin >> b;
            num1.set_my_int(a);
            num2.set_my_int(b);
            if (num1 == num2)
                cout << "The first number is equal to the second" << endl;
            else
                cout << "The first number is not equal to the second" << endl;
            break;
        case 0:
            cout << "\n";
            flag = 0;
            break;
        default:
            cout << "\n";
            flag = 0;
            break;
        }
    }
    
    return 0;
}
