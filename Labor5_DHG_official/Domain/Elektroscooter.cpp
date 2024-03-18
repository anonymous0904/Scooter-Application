#include "Elektroscooter.h"

Elektroscooter::Elektroscooter(string id, string model, string& commission_date, double km, string& last_address,
                               string &actual_state) {
    this->id=id;
    this->model=model;
    this->commission_date=commission_date;
    this->km=km;
    this->last_address=last_address;
    this->actual_state=actual_state;
}

Elektroscooter::Elektroscooter(const Elektroscooter &original) {
    this->id=original.id;
    this->model=original.model;
    this->commission_date=original.commission_date;
    this->km=original.km;
    this->last_address=original.last_address;
    this->actual_state=original.actual_state;
}

string Elektroscooter::get_id() {
    return id;
}

string Elektroscooter::get_com_date() {
    return commission_date;
}

string Elektroscooter::get_model() {
    return model;
}

double Elektroscooter::get_km() const {
    return km;
}

void Elektroscooter::set_km(double &kilom) {
    this->km = kilom;
}

string Elektroscooter::get_last_address() {
    return last_address;
}

void Elektroscooter::set_last_address(string& address) {
    this->last_address = address;
}

string Elektroscooter::get_actual_state() {
    return actual_state;
}

void Elektroscooter::set_state(string actualState) {
    this->actual_state=actualState;
}

//checks if name, origin, and price of two objects are equal
bool Elektroscooter::compare(const Elektroscooter& other) const {
    return (actual_state == other.actual_state && km == other.km);
}

Elektroscooter::~Elektroscooter() = default;
