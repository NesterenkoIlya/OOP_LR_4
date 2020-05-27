#pragma once

#include "B.h"

class D1 : virtual public B {
    string connection_type;
    string name;
    int bit_number;
    void value_check();
public:
    D1();
    D1(float, string, string, string, string, int);
    D1(D1&);

    void counter_info();

    void print() override;

    void set_connection_type(string);
    string get_connection_type();
    void set_bit_number(int);
    int get_bit_number();
    void set_name(string);
    string get_name();

    friend ostream& operator<<(ostream&, D1&);
    friend istream& operator>>(istream&, D1&);

    virtual ~D1();
};
