#include<iostream>

class Stack {
private:
    int* data; // Pointer to dynamically allocated array
    int TOP;   // Index of the top element in the stack
    int size;  // Maximum size of the stack
public:

    // Parameterized constructor with default size
    Stack(int SI = 100) {
        data = new int[SI]; // Allocate memory for the stack
        TOP = -1;           // Initialize top index to -1 (empty stack)
        size = SI;          // Set maximum size of the stack
    }

    // Destructor to deallocate memory
    ~Stack() {
        delete[] data;
    }

    // Function to get the current size of the stack
    int Size() {
        return TOP + 1; // Return the number of elements in the stack
    }

    // Function to check if the stack is full
    bool full() const {
        return TOP == size - 1; // Check if top index is at maximum size
    }

    // Function to check if the stack is empty
    bool empty() const {
        return TOP == -1; // Check if top index is at -1 (empty stack)
    }

    // Function to push an element onto the stack
    void push(const int& val) {
        if (full()) {
            throw("Stack overflow"); // Throw an exception if stack is full
        }
        else {
            TOP++;          // Increment top index
            data[TOP] = val; // Store the value at the top index
        }
    }

    // Function to get the top element of the stack
    int top() const {
        if (empty()) {
            throw("Stack underflow"); // Throw an exception if stack is empty
        }
        else {
            return data[TOP]; // Return the top element of the stack
        }
    }

    // Function to pop an element from the stack
    void pop() {
        if (empty()) {
            throw("Stack underflow"); // Throw an exception if stack is empty
        }
        else {
            TOP--; // Decrement top index
        }
    }

    // Operator overloading for assignment
    void operator =(const Stack& rhs) {
        for (int i = 0; i <= rhs.TOP; i++) {
            this->push(rhs.data[i]); // Push elements from rhs stack to this stack
        }
    }

    // Function to display the elements of the stack
    void display() {
        for (int i = 0; i <= TOP; i++) {
            std::cout << data[i] << " "; // Output each element separated by space
        }
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    std::cout << "\n\nTOP " << s.top() << " size " << s.Size() << std::endl;
    s.display(); // Display elements of stack


    s.pop(); // Pop an element from the stack
    std::cout << "\nTOP " << s.top() << " size " << s.Size() << std::endl;
    s.display(); // Display elements of stack

    Stack op;
    op.operator=(s); // Assign s to op using operator overloading
    op.display(); // Display elements of op stack

    return 0;
}
