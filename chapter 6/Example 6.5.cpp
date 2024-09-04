#include <bits/stdc++.h>
using namespace std;

class str {
    char *name;  // pointer to char array
    int l;
public:
    str()  
    {
        l = 0;
        name = new char[l + 1];
        name[0] = '\0';  // initialize with an empty string
    }
    
    str(const char *s)  // dynamic constructor
    {
        l = strlen(s);
        name = new char[l + 1];
        strcpy(name, s);
    }

    ~str()  // destructor to release allocated memory
    {
        delete[] name;
    }

    void display() const
    {
        cout << name << endl;
    }

    void join(const str &a, const str &b);
};

void str::join(const str &a, const str &b)
{
    l = a.l + b.l;
    delete[] name;

    name = new char[l + 1];

    strcpy(name, a.name);
    strcat(name, b.name);
}

int main()
{
    const char *first = "joe";
    str n1(first), n2("max"), n3("chloe"), s1, s2;

    s1.join(n1, n2);
    s2.join(s1, n3);

    n1.display();
    n2.display();
    n3.display();
    s1.display();
    s2.display();

    return 0;
}
