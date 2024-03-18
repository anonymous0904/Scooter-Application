
#ifndef LABOR5_DHG_OFFICIAL_ABSTRACTREPOSITORY_H
#define LABOR5_DHG_OFFICIAL_ABSTRACTREPOSITORY_H

#include "../Domain/Elektroscooter.h"
#include <vector>
using namespace std;
#include <memory>

class AbstractRepo{
public:

    virtual ~AbstractRepo()=default;
    virtual void add(shared_ptr<Elektroscooter>scooter) = 0;
    virtual void remove(  shared_ptr<Elektroscooter> scooter) = 0;
    virtual vector<shared_ptr<Elektroscooter>> getAll() const = 0;
    virtual void update(shared_ptr<Elektroscooter>scooter)=0;
};


#endif //LABOR5_DHG_OFFICIAL_ABSTRACTREPOSITORY_H
