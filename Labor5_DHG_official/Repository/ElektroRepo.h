#ifndef LABOR5_DHG_OFFICIAL_ELEKTROREPO_H
#define LABOR5_DHG_OFFICIAL_ELEKTROREPO_H


#include <vector>
#include <utility>
#include "../Domain/Elektroscooter.h"
#include <memory>
#include "AbstractRepository.h"

class Repo :public AbstractRepo{
private:
    vector <shared_ptr<Elektroscooter>> scooters;

public:
    //Constructor
    Repo();
    static shared_ptr<Repo> createInstance();

    /// method to add a scooter to the vector
    /// \param scooter
    void add(const shared_ptr<Elektroscooter> scooter);

    /// method to remove the scooter from the vector
    /// \param scooter
    void remove(const shared_ptr<Elektroscooter> scooter);

    /// \return method to return a vector of all scooters
    vector <shared_ptr<Elektroscooter>> getAll() const;

    vector <shared_ptr<Elektroscooter>> getScooters();



    /// method to update the values from a scooter
    /// \param scooter
    void update(shared_ptr<Elektroscooter> scooter);

    //Destructor
    ~Repo();
};

#endif //LABOR5_DHG_OFFICIAL_ELEKTROREPO_H
