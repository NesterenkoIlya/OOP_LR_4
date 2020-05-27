#pragma once

#include "D2.h"

class D3 : public D2 {
    string seal;
    float error;
    int diapasone_size;
    void discharge();
public:
    D3();
    D3(float, string, string, int, int, string, string, float);
    D3(D3&);

    void unseal();
    void calculate_diapasone_size();

    void print() override;

    void set_seal(string);
    string get_seal();
    void set_error(float);
    float get_error();
    int get_diapasone();

    friend ostream& operator<<(ostream&, D3&);
    friend istream& operator>>(istream&, D3&);

    virtual ~D3();
};
