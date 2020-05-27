#include "D4.h"

void D4::set_diapasone() {
    set_min_value(0);
    set_max_value(pow(10, get_bit_number())-1);
}

D4::D4() {
    type = "";
    purpose = "";
    counter = 0;
    set_min_value(0);
    set_max_value(1);
    set_display_type("");
    set_seal("");
    set_error(0);
    calculate_diapasone_size();
    precision = 0;
    serial_number = 0;
    current = 0;
}

D4::D4(float c, string t, string p, string ct, string n, int bn, int min, int max, string dt, string s, float err, int prec, int sn, int curr)
: D1(c, t, p, ct, n, bn), D3(c, t, p, min, max, dt, s, err) {
    precision = prec;
    serial_number = sn;
    current = curr;
}

void D4::set_precision(int p) { precision = p; }

int D4::get_precision() { return precision; }

void D4::set_serial_number(int sn) { serial_number = sn; }

int D4::get_serial_number() { return serial_number; }

void D4::set_current(int curr) { current = curr; }

int D4::get_current() { return current; }

D4::~D4() { cout << "Destructor DigitalElectricityCounter\n"; }

ostream &operator<<(ostream &out, D4 &obj) {
    out << "Class DigitaElectricitylCounter\n";
    D1 bobj1(obj);
    D3 bobj2(obj);
    out << bobj1 << bobj2;
    out << "precision: " << obj.precision
        << "\nserial_number: " << obj.serial_number
        << "\ncurrent: " << obj.current << endl;
    return out;
}

istream &operator>>(istream &in, D4 &obj) {
    int min, max, err, bn;
    string dt, s, ct, n;
    cout << "type: "; in >> obj.type;
    cout << "purpose: "; in >> obj.purpose;
    cout << "counter: "; in >> obj.counter;
    cout << "min_value: "; in >> min;
    cout << "max_value: "; in >> max;
    cout << "display_type: "; in >> dt; obj.set_display_type(dt);
    cout << "seal: "; in >> s; obj.set_seal(s);
    cout << "error: +-"; in >> err; obj.set_error(err);
    cout << "type: "; cin >> obj.type;
    cout << "purpose: "; cin >> obj.purpose;
    cout << "counter: "; cin >> obj.counter;
    cout << "connection_type: "; cin >> ct; obj.set_connection_type(ct);
    cout << "bit_number: "; cin >> bn;
    cout << "name: "; cin >> n; obj.set_name(n);
    if (bn < 1) bn = 4;
    obj.set_bit_number(bn);
    if (min > max) swap(min, max);
    obj.set_min_value(min);
    obj.set_max_value(max);
    return in;
}

void D4::print() {
    cout.fixed;
    cout << setprecision(precision)
         << "counter: " << counter << endl
         << setprecision(6);
    cout.unsetf(ios::fixed);
}
