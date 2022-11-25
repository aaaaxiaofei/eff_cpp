#include <iostream>
#include <assert.h>

using namespace std;

/*
 *   Class Definition
 */
class StaticConstMember {
public:
    static const double value;
};
const double StaticConstMember::value = 0.3;

class EnumClass {
public:
    enum {Color = 5};
};

/*
 *   Test 1
 */
void constChar() {
    const char* x = "str_x";
    const char* ptr = "Ptr0";
    cout << ptr << ", " << x << "," << *x << ", " << &x << endl;
    // *ptr = &x; //error

    const char* constPtr = "Ptr1";
    cout << "Initialized with " << constPtr << endl;
    constPtr = "Ptr2";
    cout << "Re-point to " << constPtr << endl;
    // *constPtr = &x;


    const char* const constPtr3 = "Ptr3";
    cout << "Initialized with " << constPtr3 << endl;
    // constPtr3 = "Ptr2"; // error
}

/*
 *   Test 2
 */
void TestConstClass(){
    StaticConstMember A, B;
    assert(&A.value == &B.value);
    EnumClass e;
    cout << e.Color << endl;
}

int main() {
    constChar();
    TestConstClass();
    return 0;
}