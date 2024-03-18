#include "ElektroRepo.h"
using namespace std;

Repo::Repo() {

    // Initialize the repository with a vector of 10 scooters
    string id="0001";
    string model="bolt";
    string commission_date="2023/02/12";
    double km=22.2;
    string last_address="street tomato";
    string actual_state="parked";
    shared_ptr<Elektroscooter>a= make_shared<Elektroscooter>(id,model,commission_date,km,last_address,actual_state);

    scooters.push_back(a);

    string id1="0002";
    string model1="lime";
    string commission_date1="2022/10/12";
    double km1=2.31;
    string last_address1="street potato";
    string actual_state1="out_of_order";
    shared_ptr<Elektroscooter>b= make_shared<Elektroscooter>(id1,model1,commission_date1,km1,last_address1,actual_state1);

    scooters.push_back(b);

    string id2="0003";
    string model2="spark";
    string commission_date2="2020/12/12";
    double km2=74.3;
    string last_address2="street cucumber";
    string actual_state2="reserved";
    shared_ptr<Elektroscooter>c= make_shared<Elektroscooter>(id2,model2,commission_date2,km2,last_address2,actual_state2);

    scooters.push_back(c);

    string id3="0004";
    string model3="bolt";
    string commission_date3="2023/04/22";
    double km3=11;
    string last_address3="street salad";
    string actual_state3="being_used";
    shared_ptr<Elektroscooter>d= make_shared<Elektroscooter>(id3,model3,commission_date3,km3,last_address3,actual_state3);

    scooters.push_back(d);

    string id4="0005";
    string model4="bolt";
    string commission_date4="2023/02/12";
    double km4=22.2;
    string last_address4="street spinach";
    string actual_state4="waiting";
    shared_ptr<Elektroscooter>e= make_shared<Elektroscooter>(id4,model4,commission_date4,km4,last_address4,actual_state4);

    scooters.push_back(e);

    string id5="0006";
    string model5="lime";
    string commission_date5="2021/05/29";
    double km5=73.11;
    string last_address5="street tomato";
    string actual_state5="parked";
    shared_ptr<Elektroscooter>f= make_shared<Elektroscooter>(id5,model5,commission_date5,km5,last_address5,actual_state5);

    scooters.push_back(f);

    string id6="0007";
    string model6="bmw";
    string commission_date6="2019/02/12";
    double km6=82.98;
    string last_address6="street avocado";
    string actual_state6="waiting";
    shared_ptr<Elektroscooter>g= make_shared<Elektroscooter>(id6,model6,commission_date6,km6,last_address6,actual_state6);

    scooters.push_back(g);

    string id7="0008";
    string model7="bolt";
    string commission_date7="2023/04/21";
    double km7=35.2;
    string last_address7="street peanuts";
    string actual_state7="being_used";
    shared_ptr<Elektroscooter>h= make_shared<Elektroscooter>(id7,model7,commission_date7,km7,last_address7,actual_state7);

    scooters.push_back(h);

    string id8="0009";
    string model8="bolt";
    string commission_date8="2022/03/14";
    double km8=22.2;
    string last_address8="street sandwich";
    string actual_state8="parked";
    shared_ptr<Elektroscooter>i= make_shared<Elektroscooter>(id8,model8,commission_date8,km8,last_address8,actual_state8);

    scooters.push_back(i);

    string id9="0010";
    string model9="logan";
    string commission_date9="2022/10/12";
    double km9=100.2;
    string last_address9="street onions";
    string actual_state9="out_of_order";
    shared_ptr<Elektroscooter>j= make_shared<Elektroscooter>(id9,model9,commission_date9,km9,last_address9,actual_state9);

    scooters.push_back(j);
}

shared_ptr<Repo>Repo::createInstance() {
    return make_shared<Repo>();
}

void Repo::add(const shared_ptr<Elektroscooter> scooter) {
    scooters.push_back(scooter);
}


void Repo::remove(const shared_ptr<Elektroscooter> scooter) {
    for (auto i = scooters.begin(); i != scooters.end(); ++i) {
        if (scooter->compare(**i)) {
            scooters.erase(i);
            return;
        }
    }
}

vector<shared_ptr<Elektroscooter>> Repo::getAll() const {
    return scooters;
}

vector<shared_ptr<Elektroscooter>> Repo::getScooters() {
    return scooters;
}

void Repo::update(shared_ptr<Elektroscooter> scooter)
{
    for (auto& s : scooters)
    {
        if (s->get_id() == scooter->get_id())
        {
            s->set_state("reserved");
            return;
        }
    }

}


Repo::~Repo() = default;
