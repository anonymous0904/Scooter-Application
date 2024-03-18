#include "Controller.h"
#include <algorithm>
#include <sstream>

Controller::Controller(shared_ptr<AbstractRepo> repo1) {
    this->repo=repo1;
}

void Controller::addScooter(shared_ptr<Elektroscooter>scooter) {
    repo->add(scooter);
}

void Controller::deleteScooter(string& id) {
    vector<shared_ptr<Elektroscooter>> scooters = repo->getAll();
    for (auto & scooter : scooters) {
        if (scooter->get_id() == id) {
            repo->remove(scooter);
            return;
        }
    }
}


vector<shared_ptr<Elektroscooter>> Controller::findByLocation(const string& location) const {
    vector<shared_ptr<Elektroscooter>> result;
    for (shared_ptr<Elektroscooter> const &scooter: repo->getAll()) {
        if (scooter->get_last_address() == location) {
            result.push_back(scooter);
        }
    }
    return result;
}


vector<shared_ptr<Elektroscooter>> Controller::findScooters(const string& last_address) const {
    vector<shared_ptr<Elektroscooter>> scooters = findByLocation(last_address);
    return scooters;
}

bool Controller::scooterExists(string& id) const {
    vector<shared_ptr<Elektroscooter>> scooters = repo->getAll();
    for (shared_ptr<Elektroscooter>& scooter : scooters) {
        if (scooter->get_id() == id) {
            return true;
        }
    }
    return false;
}

bool compareByCommision(shared_ptr<Elektroscooter>& s1, shared_ptr<Elektroscooter>& s2) {
    return s1->get_com_date() < s2->get_com_date();
}

vector<shared_ptr<Elektroscooter>> Controller::sortByCommission() const {
    vector<shared_ptr<Elektroscooter>> sortedScooters = repo->getAll();
    sort(sortedScooters.begin(), sortedScooters.end(), compareByCommision);
    return sortedScooters;
}

void Controller::modifyScooter(const string& id, double newKm, const string& newLastAddress, string& newActualState) {
    vector<shared_ptr<Elektroscooter>> scooters = repo->getAll();
    for (shared_ptr<Elektroscooter>& scooter : scooters) {
        if (scooter->get_id() == id) {
            scooter->set_km(newKm);
            scooter->set_last_address(const_cast<string &>(newLastAddress));
            scooter->set_state(newActualState);
            return;
        }
    }
}

void Controller::updateScooter(const shared_ptr<Elektroscooter>& scooter)
{
    repo->update(const_cast<shared_ptr<Elektroscooter> &>(scooter));
}

void Controller::show_all_scooters() {
    vector<shared_ptr<Elektroscooter>> elektroscooters = repo->getAll();
    cout << endl;

    if (elektroscooters.empty()) {
        cout << "No scooters found." << endl;
    } else {
        for (const shared_ptr<Elektroscooter>& scooter : elektroscooters) {
            cout << "ID: " << scooter->get_id() << " -- Model: " << scooter->get_model()
                 << " -- Commission date: " << scooter->get_com_date()
                 << " -- Last Location: " << scooter->get_last_address()
                 << " -- Kilometers: " << scooter->get_km()
                 << " -- State: " << scooter->get_actual_state() << endl;
        }
    }

    cout << endl;
}

vector<shared_ptr<Elektroscooter>> Controller::getAllScooters() const {
    return repo->getAll();
}

bool Controller::valid_kilom(double km) {
    // Convert the double to a string using stringstream
    stringstream ss;
    ss << km;
    string kmString = ss.str();

    // Check if the string contains a decimal point or non-digit characters
    if (kmString.find('.') != string::npos || kmString.find_first_not_of("0123456789") != string::npos) {
        return false;
    }

    // Check if the string starts with a '-' character
    if (kmString.front() == '-') {
        return false;
    }

    return true;
}



bool Controller::valid_comm_date(string const&date) {
    if (date.find_first_not_of("0123456789/") != string::npos) {
        // The date contains non-numeric characters
        return false;
    }
    vector<int>numbers;
    string number;
    stringstream str_date(date);
    while(getline(str_date,number,'/')){
        numbers.push_back(stoi(number));
    }
    if(numbers.at(0)<0 or numbers.at(0)<1850 or numbers.at(0)>2023){
        return false;
    }
    if(numbers.at(1)<1 or numbers.at(1)>12){
        return false;
    }
    if(numbers.at(2)<1 or numbers.at(2)>31){
        return false;
    }
    if(numbers.at(1)==2 and numbers.at(2)>29){
        return false;
    }
    if((numbers.at(1)==2 or numbers.at(1)==4 or numbers.at(1)==6 or numbers.at(1)==9 or numbers.at(1)==11) and numbers.at(2)>30){
        return false;
    }
    return true;
}

bool Controller::valid_state(string const&state) {
    if(state!="parked" and state!="reserved" and state!="being_used" and state!="waiting" and state!="out_of_service"){
        return false;
    }
    return true;
}

void Controller::rentScooter(const string& id) {
    // Check if the scooter with the given ID exists
    bool scooterFound = false;
    vector<shared_ptr<Elektroscooter>> scooters = repo->getAll();
    for (const auto& scooter : scooters) {
        if (scooter->get_id() == id) {
            scooterFound = true;
            break;
        }
    }

    if (!scooterFound) {
        cout << "Invalid scooter ID." << endl;
        return;
    }

    // Retrieve the scooter from the repository
    shared_ptr<Elektroscooter> rentedScooter;
    for (const auto& scooter : scooters) {
        if (scooter->get_id() == id) {
            rentedScooter = scooter;
            break;
        }
    }

    // Update the scooter's state to "Rented"
    rentedScooter->set_state("Rented");

    // Add the rented scooter to the customer's rented scooters
    rentedScooters.push_back(rentedScooter);

    cout << "Scooter rented successfully." << endl;
}

void Controller::printRentedScooters() {
    cout << "Rented scooters: " << endl;

    if (rentedScooters.empty()) {
        cout << "No scooters currently rented." << endl;
    } else {
        for (const auto& scooter : rentedScooters) {
            cout << "ID: " << scooter->get_id() << ", Model: " << scooter->get_model() << endl;
        }
    }
}


shared_ptr<Elektroscooter> Controller::getScooterByID(const string& scooterID) const {
    // Get all scooters from the repository
    vector<shared_ptr<Elektroscooter>> allScooters = repo->getAll();

    // Iterate through each scooter and check if it matches the specified ID
    for (const auto& scooter : allScooters) {
        if (scooter->get_id() == scooterID) {
            return scooter;
        }
    }

    // No scooter found with the specified ID
    return nullptr;
}