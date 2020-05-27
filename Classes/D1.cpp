#include "D1.h"

void D1::value_check() {
    if (counter > pow(10, bit_number) - 1)
        counter = pow(10, bit_number) - 1;
    else if (counter < 0)
        counter = 0;
}

D1::D1() {
    bit_number = 1;
    counter = 0;
    connection_type = "";
    name = "";
}

D1::D1(float c, string t, string p, string ct, string n, int bn): B(c, t, p) {
    connection_type = ct;
    name = n;
    bit_number = bn;
    if (bit_number < 1) {
        cout << "bit_number must be over than 1\n"
             << "bit_number set to 4\n";
        bit_number = 4;
    }
    value_check();
}

D1::D1(D1 &obj) {
    counter = obj.counter;
    type = obj.type;
    purpose = obj.purpose;
    connection_type = obj.connection_type;
    name = obj.name;
    bit_number = obj.bit_number;
}

void D1::counter_info() {
    cout << "counter name: " << name
         << "\ncounter type: " << type
         << "\ncounter purpose: " << purpose
         << "\nconnection type: " << connection_type;
}

void D1::set_connection_type(string ct) { connection_type = ct; }

string D1::get_connection_type() { return connection_type; }

void D1::set_bit_number(int bn) { bit_number = bn; }

int D1::get_bit_number() { return bit_number; }

void D1::set_name(string n) { name = n; }

string D1::get_name() { return name; }

D1::~D1() { cout << "Destructor ElectricityCounter\n"; }

ostream &operator<<(ostream &out, D1 &obj) {
    out << "Class ElectricityCounter\n";
    B* bobj = new D1(obj);
    cout << *bobj;
    out << "connection_type: " << obj.connection_type
        << "\nbit_number: " << obj.bit_number
        << "\nname: " << obj.name << endl;
    return out;
}

istream &operator>>(istream &in, D1 &obj) {
    cout << "type: "; cin >> obj.type;
    cout << "purpose: "; cin >> obj.purpose;
    cout << "counter: "; cin >> obj.counter;
    cout << "connection_type: "; cin >> obj.connection_type;
    cout << "bit_number: "; cin >> obj.bit_number;
    cout << "name: "; cin >> obj.name;
    obj.value_check();
    return in;
}

void D1::print() {
    cout << "counter: " << counter;
}
