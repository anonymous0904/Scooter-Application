#ifndef LABOR5_DHG_OFFICIAL_ELEKTROSCOOTER_H
#define LABOR5_DHG_OFFICIAL_ELEKTROSCOOTER_H

#include <string>
#include <iostream>
using namespace std;

class Elektroscooter{
private:
    string id;
    string model;
    string commission_date;
    double km;
    string last_address;
    string actual_state;

public:
    /// Constructor
    /// \param id
    /// \param model
    /// \param commission_date
    /// \param km
    /// \param last_address
    /// \param actual_state
    Elektroscooter(string id, string model, string &commission_date, double km, string &last_address, string &actual_state);

    /// Copy constructor
    /// \param original
    Elektroscooter(const Elektroscooter&original);

    /// assignment operator
    /// \param original
    /// \return
    Elektroscooter &operator=(const Elektroscooter&original){//assignment operator
        this->id=original.id;
        this->model=original.model;
        this->commission_date=original.commission_date;
        this->km=original.km;
        this->last_address=original.last_address;
        this->actual_state=original.actual_state;
        return *this;
    }

    // getters/setters
    string get_id();

    string get_com_date();

    string get_model();

    double get_km()const;

    void set_km(double &kilom);

    string get_last_address();

    void set_last_address(string &address);

    string get_actual_state();

    void set_state(string actualState);

    bool compare(const Elektroscooter& other) const;

    ///destructor
    ~Elektroscooter();
};

#endif //LABOR5_DHG_OFFICIAL_ELEKTROSCOOTER_H
