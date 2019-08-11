#include "stack.hpp"
#include <iostream>

using namespace std;

int main() {

    stack s;

    s.push(4);
    s.push(5);
    s.push(6);

    stack s2;
    s2 = s;

    cout << "Empty: " << (s2.empty() ? "Yes" : "No") << endl;

    cout << "Top: " << s2.top() << endl;

    cout << "Size: " << s2.size() << endl;
    cout << "Capacity: " << s2.capacity() << endl;

    cout << "Stack dump:" << endl;
    s2.dump(cout);

    return 0;
}