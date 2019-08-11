#include "stack.hpp"

// Init
stack::stack(int numItems):
        _capacity(numItems) {

    _arr = new TYPE(_capacity);
    _tos = -1;
    
}

// Copy
stack::stack(const stack& copyStack) {

    // We can't use non-const member functions, so we use the private variables
    delete[] _arr;
    _arr = new TYPE(copyStack._capacity);

    _capacity = copyStack._capacity;

    _tos = -1;

    // Now copy them in
    for (int i = 0; i <= copyStack._tos; i++) {
        _tos = i;
        _arr[i] = copyStack._arr[i];
    }

}

// Cleanup
stack::~stack() {
    delete[] _arr;
}

stack& stack::operator=(const stack& equalsStack) {
    // This is the same as the copy constructor

    // We can't use non-const member functions, so we use the private variables
    delete[] _arr;
    _arr = new TYPE(equalsStack._capacity);

    _capacity = equalsStack._capacity;
    _tos = -1;

    // Now copy them in
    for (int i = 0; i <= equalsStack._tos; i++) {
        _tos = i;
        _arr[i] = equalsStack._arr[i];
    }

    return *this;
}

int stack::size() {
    return _tos + 1;
}

int stack::capacity() {
    return _capacity;
}

bool stack::empty() {
    return _tos == -1;
}

void stack::dump(std::ostream& os) {

    for (int i = _tos; i >= 0; i--) {
        os << _arr[i] << std::endl;
    }

}

// push an element, expanding if necessary;
void stack::push(const TYPE x) {

    _tos++;

    // Resize
    if (_capacity <= _tos) {
        //_capacity++;
        TYPE* newArr = new TYPE[_capacity + 1];
        for (int i = 0; i < _capacity; i++) {
            newArr[i] = _arr[i];
        }
        _tos = _capacity;
    }

    _arr[_tos] = x;

}

// remove and element; throw EmptyStackException when stack is empty
void stack::pop() {
    if (_tos == -1)
        throw new EmptyStackException;

    _arr[_tos] = *(new TYPE());

    _tos--;

}

// return a reference to the top element without popping; throw EmptyStackException when stack is empty
TYPE& stack::top() {
    if (_tos == -1)
        throw new EmptyStackException;

    return _arr[_tos];
}
