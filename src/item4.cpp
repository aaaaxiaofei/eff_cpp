#include <iostream>
using namespace std;

/*
* Make sure initialized before use
*/

class A {
public:
    A(int n) {
        num = n; // Assignement
    }
private:
    int num;
};

class B {
public:
    B(int n): num(n) {} // Initialization, more efficient
private:
    int num;
};
// If many constructors share initialization of primative type,
// we can move them to a private function and call it as pseudo-initialization

// Initialization order is same as declaration order, not the constructor initialization list order

class FileSystem {
public:
    int numDisk() {
        return 3;
    }
};
FileSystem& tfs() {
    static FileSystem fs;
    return fs;
}

int main() {
    // FileSystem fs;
    cout << tfs().numDisk() << endl;
    return 0;
}