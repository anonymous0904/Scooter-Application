#include "CSV_File_Repo.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <streambuf>

CSVRepo::CSVRepo() {
    scooters=getScooters();
}

vector<shared_ptr<Elektroscooter>> CSVRepo::getScooters(){
    fstream file;
    file.open("C:\\Users\\andaf\\CLionProjects\\Labor5_DHG_official\\Repository\\CSVRepoScooters",ios::in);
    vector<string> row;
    string line,word;
    vector<shared_ptr<Elektroscooter>>vectorScooters;
    while(getline(file,line)){
        row.clear();
        stringstream str(line);
        while(getline(str,word,',')){
            row.push_back(word);
        }

        string id=row.at(0);
        string model=row.at(1);
        string commission_date=row.at(2);
        double km=stod(row.at(3));
        string last_address=row.at(4);
        string actual_state=row.at(5);
        shared_ptr<Elektroscooter>elektroscooter= make_shared<Elektroscooter>(id,model,commission_date,km,last_address,actual_state);

        vectorScooters.push_back(elektroscooter);
    }
    file.close();
    return vectorScooters;
}

bool CSVRepo::are_equal(shared_ptr<Elektroscooter> scooter1, shared_ptr<Elektroscooter> scooter2) {
    if(scooter1->get_id()!=scooter2->get_id()){
        return false;
    }
    if(scooter1->get_model()!=scooter2->get_model()){
        return false;
    }
    if(scooter1->get_com_date()!=scooter2->get_com_date()){
        return false;
    }
    if(scooter1->get_actual_state()!=scooter2->get_actual_state()){
        return false;
    }
    if(scooter1->get_last_address()!=scooter2->get_last_address()){
        return false;
    }
    if(scooter1->get_km()!=scooter2->get_km()){
        return false;
    }
    return true;
}

void CSVRepo::print_to_file() {
    fstream file;
    file.open("C:\\Users\\andaf\\CLionProjects\\Labor5_DHG_official\\Repository\\CSVRepoScooters",ios::out);

    for(auto scooter:scooters){
        file<<scooter->get_id()<<','<<scooter->get_model()<<','<<scooter->get_com_date()<<','<<scooter->get_km()<<','<<scooter->get_last_address()<<','<<scooter->get_actual_state()<<endl;
    }

    file.close();
}

void CSVRepo::add(shared_ptr<Elektroscooter> scooter) {
    bool is=false;
    for(int i=0;i<scooters.size()and not is;i++){
        if(scooter->get_id()==scooters[i]->get_id()){
            scooters[i]=scooter;
            is=true;
        }
    }
    if(not is){
        scooters.push_back(scooter);
    }
}

vector<shared_ptr<Elektroscooter>> CSVRepo::getAll() const {
    return scooters;
}

void CSVRepo::remove(shared_ptr<Elektroscooter> scooter) {
    for(auto scoot:scooters){
        if(are_equal(scoot,scooter)){
            scooters.erase(std::remove(scooters.begin(), scooters.end(), scoot), scooters.end());
            break;
        }
    }
}

void CSVRepo::update(shared_ptr<Elektroscooter> scooter) {
    for(int i=0;i<scooters.size();i++){
        if(scooters.at(i)->get_id()==scooter->get_id()){
            scooters.at(i)=scooter;
        }
    }
}

CSVRepo::~CSVRepo() {
    print_to_file();
}

shared_ptr<CSVRepo> CSVRepo::createInstance(){
    return make_shared<CSVRepo>();
}