#ifndef LABOR5_DHG_OFFICIAL_CONTROLLER_H
#define LABOR5_DHG_OFFICIAL_CONTROLLER_H

#include "../Repository/ElektroRepo.h"
#include "../Repository/CSV_File_Repo.h"
#include <vector>
#include <string>



class Controller {
private:
    shared_ptr<AbstractRepo> repo;
    vector<shared_ptr<Elektroscooter>> rentedScooters;

public:

    /// Constructor of controller that uses an object of type repo
    /// \param repo1
    explicit Controller(shared_ptr<AbstractRepo> repo1);

    /// method to delete the scooter with the given id from the vector
    /// \param id
    void deleteScooter(string& id);

    /// \param last_address
    /// \return the values of the scooters with the given address stored into a vector
    vector< shared_ptr<Elektroscooter>>findScooters(const string& last_address) const;

    /// \param id
    /// \return true if the scooter with the given id exists, false otherwise
    bool scooterExists(string& id) const;

    /// \param location
    /// \return method to return a vector of all scooters at the given location
    vector <shared_ptr<Elektroscooter>> findByLocation(const string &location) const;

    /// \return vector of all the existing scooters sorted from the oldest to the newest by commission date
    vector<shared_ptr<Elektroscooter>>sortByCommission() const;

    /// method to change the attributes of a scooter
    /// \param id
    /// \param newKm
    /// \param newLastAddress
    /// \param newActualState
    void modifyScooter(const string& id, double newKm, const string& newLastAddress, string& newActualState);

    void updateScooter(const shared_ptr<Elektroscooter> &scooter);

    ///method to print all the scooters with their attributes
    void show_all_scooters();

    /// \return vector of all the existing scooters
    vector<shared_ptr<Elektroscooter>> getAllScooters() const;

    /// method to add a new scooter with the given attributes to the vector
    /// \param id
    /// \param model
    /// \param commission_date
    /// \param km
    /// \param last_address
    /// \param actual_state
    void addScooter(shared_ptr<Elektroscooter>scooter);

    ///static methods to validate the data given by the user
    bool static valid_kilom(double km);
    bool static valid_comm_date(string const&date);
    bool static valid_state(string const&state);

    /// function for renting mulitple scooters
    void rentScooter(const string& id);

    ///function for printing the rented scooters
    void printRentedScooters();

    shared_ptr<Elektroscooter> getScooterByID(const string &scooterID) const;
};

#endif //LABOR5_DHG_OFFICIAL_CONTROLLER_H
