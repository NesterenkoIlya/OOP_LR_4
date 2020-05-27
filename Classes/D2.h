#pragma once

#include "B.h"

class D2 : virtual protected B {
    int min_value;
    int max_value;
    string display_type;
    void diapasone_check();
public:
    D2();
    D2(float, string, string, int, int, string);
    D2(D2&);

    void select_range(int, int);

    void print() override { cout << "Xedg" << endl; }

    void set_min_value(int);
    int get_min_value();
    void set_max_value(int);
    int get_max_value();
    void set_display_type(string);
    string get_display_type();

    friend ostream& operator<<(ostream&, D2&);
    friend istream& operator>>(istream&, D2&);

    virtual ~D2();
};
