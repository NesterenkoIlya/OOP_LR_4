#pragma once
#include "D1.h"
#include "D3.h"

class D4 : protected D1, protected D3 {
    int precision;
    int serial_number;
    int current;
    void set_diapasone();
public:
    D4();
    D4(float, string, string, string, string, int, int, int, string, string, float, int, int, int);
    D4(D4&) = default;

    void print () override final;

    void set_precision(int);
    int get_precision();
    void set_serial_number(int);
    int get_serial_number();
    void set_current(int);
    int get_current();

    friend ostream& operator<<(ostream&, D4&);
    friend istream& operator>>(istream&, D4&);

    virtual ~D4();
};
