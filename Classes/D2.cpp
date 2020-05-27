#include "D2.h"

void D2::diapasone_check() {
    if (counter > max_value)
        counter = max_value;
    else if (counter < min_value)
        counter = min_value;
}

D2::D2() {
    counter = 0;
    type = "";
    purpose = "";
    min_value = 0;
    max_value = 1;
    display_type = "";
}

D2::D2(float c, string t, string p, int min, int max, string dt): B(c, t, p) {
    if (min > max) swap(min, max);
    min_value = min;
    max_value = max;
    display_type = dt;
    diapasone_check();
}

D2::D2(D2 &obj) {
    counter = obj.counter;
    type = obj.type;
    purpose = obj.purpose;
    min_value = obj.min_value;
    max_value = obj.max_value;
    display_type = obj.display_type;
}

void D2::select_range(int min, int max) {
    set_min_value(min);
    set_max_value(max);
    if (min > max) swap(min, max);
    diapasone_check();
}

void D2::set_min_value(int min) { min_value = min; }

int D2::get_min_value() { return min_value; }

void D2::set_max_value(int max) { max_value = max; }

int D2::get_max_value() { return max_value; }

void D2::set_display_type(string dt) { display_type = dt; }

string D2::get_display_type() { return display_type; }

D2::~D2() { cout << "Destructor DigitalCounter\n"; }

ostream &operator<<(ostream &out, D2 &obj) {
    out << "Class DigitalCounter\n";
    B* bobj = new D2(obj);
    out << *bobj
        << "min_value: " << obj.min_value
        << "\nmax_value: " << obj.max_value
        << "\ndisplay_type: " << obj.display_type << endl;
    return out;
}

istream &operator>>(istream &in, D2 &obj) {
    cout << "type: "; cin >> obj.type;
    cout << "purpose: "; cin >> obj.purpose;
    cout << "counter: "; cin >> obj.counter;
    cout << "min_value: "; cin >> obj.min_value;
    cout << "max_value: "; cin >> obj.max_value;
    cout << "display_type: "; cin >> obj.display_type;
    if (obj.min_value > obj.max_value) swap(obj.min_value, obj.max_value);
    return in;
}
