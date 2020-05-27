#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class B {
protected:
    float counter;
    string type;
    string purpose;
public:
    B();
    B(float, string, string);
    B(B&);

    void counter_increment();
    void counter_decrement();
    void counter_annul();

    virtual void print() = 0;

    void set_counter(float);
    float get_counter();
    void set_type(string);
    string get_type();
    void set_purpose(string);
    string get_purpise();

    friend ostream& operator<<(ostream&, B&);
    friend istream& operator>>(istream&, B&);

    virtual ~B();
};
