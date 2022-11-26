#include <iostream>
#include <assert.h>

using namespace std;

/*********************************************
 *        const to avoid operator assignment
**********************************************/
class Rational {
public:
    Rational(int v) {
        value = v;
    }

    int getValue() const {
        return value;
    }

private:
    int value;
};

Rational operator+(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.getValue() + rhs.getValue());
}

const Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.getValue() * rhs.getValue());
}

void testOperatorAssignement() {
    Rational a(3), b(5);
    cout << a.getValue() << ", " << b.getValue() << endl;
    Rational c = a * b;

    cout << c.getValue() << endl;
    // (a * b) = c;
}

/*********************************************
 *        Mutable
**********************************************/

class ConstClass {
public:
    ConstClass() {
        length = 3;
        functionCalled = false;
    }

    int getLength() const {
        functionCalled = true;
        return length;
    }
private:
    int length;
    mutable bool functionCalled;
};

void testMutable() {
    const ConstClass cc;
    cout << "Lenght is " << cc.getLength() << endl;
}


int main() {
    testOperatorAssignement();
    testMutable();
    return 0;
}