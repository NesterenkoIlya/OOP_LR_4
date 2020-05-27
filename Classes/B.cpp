#include "B.h"

B::B() {
    counter = 0;
    type = "";
    purpose = "";
}

B::B(float c, string t, string p): counter(c), type(t), purpose(p) { }

B::B(B& obj) {
    counter = obj.counter;
    type = obj.type;
    purpose = obj.purpose;
}

void B::counter_increment() { counter++; }

void B::counter_decrement() { counter--; }

void B::counter_annul() { counter = 0; }

void B::set_counter(float c) { counter = c; }

float B::get_counter() { return counter; }

void B::set_type(string t) { type = t; }

string B::get_type() { return type; }

void B::set_purpose(string p) { purpose = p; }

string B::get_purpise() { return purpose; }

B::~B() { cout << "Destructor Counter\n"; }

ostream &operator<<(ostream &out, B &obj) {
    out << "Counter\n"
        << "type: " << obj.type
        << "\npurpose: " << obj.purpose
        << "\ncounter: " << obj.counter
        << endl;
    return out;
}

istream &operator>>(istream &in, B &obj) {
    cout << "type: "; cin >> obj.type;
    cout << "purpose: "; cin >> obj.purpose;
    cout << "counter: "; cin >> obj.counter;
    return in;
}
