#include "D3.h"

void D3::discharge() {
    if (counter == get_max_value())
        counter = get_min_value();
    else if (counter > get_max_value()){
        while (counter > get_max_value()){
            counter -= diapasone_size + 1;
        }
    }
}

D3::D3() {
    counter = 0;
    type = "";
    purpose = "";
    set_min_value(0);
    set_max_value(1);
    set_display_type("");
    seal = "";
    error = 0;
    calculate_diapasone_size();
}

D3::D3(float c, string t, string p, int min, int max, string dt, string s, float err): D2(c, t, p, min, max, dt) {
    seal = s;
    error = err;
    calculate_diapasone_size();
}

D3::D3(D3 &obj) {
    counter = obj.counter;
    type = obj.type;
    purpose = obj.purpose;
    set_min_value(obj.get_min_value());
    set_max_value(obj.get_max_value());
    set_display_type(obj.get_display_type());
    diapasone_size = obj.diapasone_size;
}

void D3::unseal() { seal = ""; }

void D3::calculate_diapasone_size() { diapasone_size = get_max_value() - get_min_value() + 1; }

void D3::set_seal(string s) { seal = s; }

string D3::get_seal() { return seal; }

void D3::set_error(float err) { error = err; }

float D3::get_error() { return error; }

int D3::get_diapasone() { return diapasone_size; }

D3::~D3() { cout << "Destructor AutoDigitalCounter\n"; }

ostream &operator<<(ostream &out, D3 &obj) {
    out << "Class AutoDigitalCounter\n";
    D2 bobj(obj);
    cout << bobj;
    cout << "seal: " << obj.seal
         << "\nerror: " << obj.error
         << "\ndiapasone_size: " << obj.diapasone_size
         << endl;
    return out;
}

istream &operator>>(istream &in, D3 &obj) {
    cout << "type: "; cin >> obj.type;
    cout << "purpose: "; cin >> obj.purpose;
    cout << "counter: "; cin >> obj.counter;
    int min, max;
    string dt;
    cout << "min_value: "; cin >> min;
    cout << "max_value: "; cin >> max;
    cout << "display_type: "; cin >> dt;
    if (min > max) swap(min, max);
    obj.set_min_value(min);
    obj.set_max_value(max);
    obj.set_display_type(dt);
    cout << "seal: "; cin >> obj.seal;
    cout << "error: +-"; cin >> obj.error;
    return in;
}

void D3::print() {
    cout << counter << endl;
}
