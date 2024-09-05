/*6.2: Define a class String that could work as a user-defined string type. Include
constructors that will enable us to create an uninitialized string:
String s1; // string with length 0
And also initialize an object with a string constant at the time of creation like
String s2(“Well done!”);
Include a function that adds two strings to make a third string. Note that the statement
S2 = s1;
will be perfectly reasonable expression to copy one string to another.
Write a complete program to test your class to see that it does the following tasks:
(a) Creates uninitialized string objects.
(b) Creates objects with string constants.
(c) Concatenates two strings properly.
(d) Displays a desired string object. */


#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;      // Pointer to the string
    int length;     // Length of the string

public:
    // Default constructor (uninitialized string)
    String() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    // Constructor to initialize with a string constant
    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Copy constructor
    String(const String& s) {
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Overload assignment operator to handle deep copy
    String& operator=(const String& s) {
        if (this == &s) return *this;  // Handle self-assignment
        delete[] str;  // Free existing memory
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
        return *this;
    }

    // Function to concatenate two strings
    String operator+(const String& s) {
        String newStr;
        newStr.length = length + s.length;
        newStr.str = new char[newStr.length + 1];
        strcpy(newStr.str, str);
        strcat(newStr.str, s.str);
        return newStr;
    }

    // Function to display the string
    void display() const {
        cout << str;
    }

    // Function to return the length of the string
    int getLength() const {
        return length;
    }
};

int main() {
    // (a) Creates uninitialized string objects
    String s1;
    cout << "Uninitialized string (s1): ";
    s1.display();
    cout << " (length: " << s1.getLength() << ")\n";

    // (b) Creates objects with string constants
    String s2("Well done!");
    cout << "Initialized string (s2): ";
    s2.display();
    cout << " (length: " << s2.getLength() << ")\n";

    // (c) Concatenates two strings properly
    String s3 = s2 + String(" Keep it up!");
    cout << "Concatenated string (s3): ";
    s3.display();
    cout << " (length: " << s3.getLength() << ")\n";

    // (d) Displays a desired string object
    cout << "Display s2 again: ";
    s2.display();
    cout << " (length: " << s2.getLength() << ")\n";

    // Test assignment operator
    s1 = s2;
    cout << "After assignment (s1 = s2): ";
    s1.display();
    cout << " (length: " << s1.getLength() << ")\n";

    return 0;
}
