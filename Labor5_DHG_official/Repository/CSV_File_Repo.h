#ifndef LABOR5_DHG_OFFICIAL_CSV_FILE_REPO_H
#define LABOR5_DHG_OFFICIAL_CSV_FILE_REPO_H


#include "AbstractRepository.h"

class CSVRepo:public AbstractRepo{
private:
    vector<shared_ptr<Elektroscooter>>scooters;

    ///method to print all the scooters to  the file
    void print_to_file();

public:
    ///Constructor creates a vector of scooters with all the elements red from the file
    CSVRepo();

    /// method to add a new scooter into the vector, if a scooter with the id of the parameter is in the
    ///vector, it's attributes will be changed
    /// \param scooter
    void add(shared_ptr<Elektroscooter>scooter);

    /// method to remove the given scooter from the vector
    /// \param scooter
    void remove(  shared_ptr<Elektroscooter> scooter);

    static shared_ptr<CSVRepo> createInstance();

    /// \return a vector of share_pointers to elektroscooters red from the file
    vector<shared_ptr<Elektroscooter>> getAll() const;

    /// method update the values of a scooter
    /// \param scooter
    void update(shared_ptr<Elektroscooter>scooter);

    ///destructor saves into the file all the scooter in the vector of scooters
    ~CSVRepo();

    vector<shared_ptr<Elektroscooter>> getScooters();

    /// method to compare 2 scooters
    /// \param scooter1
    /// \param scooter2
    /// \return true if the attributes of both scooters are equal, false otherwise
    bool static are_equal(shared_ptr<Elektroscooter>scooter1, shared_ptr<Elektroscooter>scooter2);
};

#endif //LABOR5_DHG_OFFICIAL_CSV_FILE_REPO_H
