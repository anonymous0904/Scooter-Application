#include "../Controller/Controller.h"
#include <cassert>
#include <iostream>


using namespace std;

//Controller tests

void testAddScooter() {
    // Create a repository
    shared_ptr<AbstractRepo> repo= make_shared<Repo>();

    // Create a controller
    Controller controller(repo);

    // Define the scooter data
    string id = "S001";
    string model = "Model X";
    string commission_date = "2023/05/15";
    double km = 100.0;
    string last_address = "Street A";
    string actual_state = "parked";

    // Call the addScooter method
    shared_ptr<Elektroscooter>scoot1= make_shared<Elektroscooter>(id, model, commission_date, km, last_address, actual_state);
    controller.addScooter(scoot1);

    // Check if the scooter was added successfully
    vector<shared_ptr<Elektroscooter>> scooters = controller.getAllScooters();
    assert(scooters.at(10)->get_id() == id); // Check if the added scooter has the correct ID

    cout << "AddScooter test passed!" << endl;
}

void testDeleteScooter() {

    shared_ptr<AbstractRepo> repo= make_shared<Repo>();
    Controller controller(repo);

    string id = "S001";
    string model = "Model X";
    string commission_date = "2023/05/15";
    double km = 100.0;
    string last_address = "Street A";
    string actual_state = "parked";
    shared_ptr<Elektroscooter>scoot1= make_shared<Elektroscooter>(id, model, commission_date, km, last_address, actual_state);
    controller.addScooter(scoot1);
    controller.deleteScooter(id);

    vector<shared_ptr<Elektroscooter>> scooters = repo->getAll();
    assert(not scooters.empty());
    assert(scooters.size()==10);
    cout << "DeleteScooter test passed!" << endl;
}

void testFindScooters() {

    shared_ptr<AbstractRepo> repo= make_shared<Repo>();

    Controller controller(repo);

    string id1 = "S001";
    string model1 = "Model X";
    string commission_date1 = "2023/05/15";
    double km1 = 100.0;
    string last_address1 = "Street A";
    string actual_state1 = "parked";
    shared_ptr<Elektroscooter>scoot1= make_shared<Elektroscooter>(id1, model1, commission_date1, km1, last_address1, actual_state1);
    controller.addScooter(scoot1);

    string id2 = "S002";
    string model2 = "Model Y";
    string commission_date2 = "2023/05/16";
    double km2 = 200.0;
    string last_address2 = "Street B";
    string actual_state2 = "reserved";
    shared_ptr<Elektroscooter>scoot2= make_shared<Elektroscooter>(id2, model2, commission_date2, km2, last_address2, actual_state2);
    controller.addScooter(scoot2);

    string id3 = "S003";
    string model3 = "Model Z";
    string commission_date3 = "2023/05/17";
    double km3 = 300.0;
    string last_address3 = "Street A";
    string actual_state3 = "parked";

    shared_ptr<Elektroscooter>scoot3= make_shared<Elektroscooter>(id3, model3, commission_date3, km3, last_address3, actual_state3);
    controller.addScooter(scoot3);


    string location = "Street A";
    vector<shared_ptr<Elektroscooter>> foundScooters = controller.findScooters(location);



    assert(foundScooters[0]->get_id() == id1);
    assert(foundScooters[0]->get_model() == model1);
    assert(foundScooters[0]->get_com_date() == commission_date1);
    assert(foundScooters[0]->get_last_address() == last_address1);
    assert(foundScooters[0]->get_km() == km1);
    assert(foundScooters[0]->get_actual_state() == actual_state1);

    assert(foundScooters[1]->get_id() == id3);
    assert(foundScooters[1]->get_model() == model3);
    assert(foundScooters[1]->get_com_date() == commission_date3);
    assert(foundScooters[1]->get_last_address() == last_address3);
    assert(foundScooters[1]->get_km() == km3);
    assert(foundScooters[1]->get_actual_state() == actual_state3);

    cout << "FindScooters test passed!" << endl;
}

void testScooterExists() {
    shared_ptr<AbstractRepo> repo= make_shared<Repo>();

    Controller controller(repo);

    string id = "S001";
    string model = "Model X";
    string commission_date = "2023/01/01";
    double km = 100.0;
    string last_address = "Location A";
    string actual_state = "parked";
    shared_ptr<Elektroscooter>scoot=make_shared<Elektroscooter>(id, model, commission_date, km, last_address, actual_state);
    controller.addScooter(scoot);

    bool exists = controller.scooterExists(id);
    assert(exists == true);

    string nonExistingId = "S002";
    bool nonExistingExists = controller.scooterExists(nonExistingId);
    assert(nonExistingExists == false);

    cout << "Scooter existence test passed!" << endl;
}

void testModifyScooter() {
    // Create a repository
    shared_ptr<AbstractRepo> repo= make_shared<Repo>();

    // Create a controller
    Controller controller(repo);

    // Add a scooter to the repository
    string id = "S001";
    string model = "Model X";
    string commission_date = "2023/05/15";
    double km = 100.0;
    string last_address = "Street A";
    string actual_state = "parked";
    shared_ptr<Elektroscooter>scoot=make_shared<Elektroscooter>(id, model, commission_date, km, last_address, actual_state);
    controller.addScooter(scoot);

    // Modify the scooter
    double newKm = 150.0;
    string newLastAddress = "Street B";
    string newActualState = "reserved";
    controller.modifyScooter(id, newKm, newLastAddress, newActualState);

    // Retrieve the modified scooter
    vector<shared_ptr<Elektroscooter>> scooters = controller.getAllScooters();
    assert(scooters.size() == 11); // Check if there is only one scooter in the repository

    shared_ptr<Elektroscooter> modifiedScooter = scooters[10];
    assert(modifiedScooter->get_id() == id); // Check if the modified scooter has the correct ID
    assert(modifiedScooter->get_km() == newKm); // Check if the kilometer value was updated
    assert(modifiedScooter->get_last_address() == newLastAddress); // Check if the last address was updated
    assert(modifiedScooter->get_actual_state() == newActualState); // Check if the actual state was updated

    cout << "ModifyScooter test passed!" << endl;
}

void testSortByCommission(){
    shared_ptr<AbstractRepo>repo= make_shared<Repo>();
    Controller controller(repo);
    string id1 = "S001";
    string model1 = "Model X";
    string commission_date1 = "2023/05/17";
    double km1 = 100.0;
    string last_address1 = "Street A";
    string actual_state1 = "parked";
    shared_ptr<Elektroscooter>scoot1=make_shared<Elektroscooter>(id1, model1, commission_date1, km1, last_address1, actual_state1);
    controller.addScooter(scoot1);

    string id2 = "S002";
    string model2 = "Model Y";
    string commission_date2 = "2023/05/16";
    double km2 = 200.0;
    string last_address2 = "Street B";
    string actual_state2 = "reserved";
    shared_ptr<Elektroscooter>scoot2=make_shared<Elektroscooter>(id2, model2, commission_date2, km2, last_address2, actual_state2);
    controller.addScooter(scoot2);

    string id3 = "S003";
    string model3 = "Model Z";
    string commission_date3 = "2023/05/15";
    double km3 = 300.0;
    string last_address3 = "Street A";
    string actual_state3 = "Available";
    shared_ptr<Elektroscooter>scoot3=make_shared<Elektroscooter>(id3, model3, commission_date3, km3, last_address3, actual_state3);
    controller.addScooter(scoot3);

    vector<shared_ptr<Elektroscooter>>sorted=controller.sortByCommission();
    assert(sorted[0]->get_id()=="0007");
    assert(sorted[1]->get_id()=="0003");
    assert(sorted[2]->get_id()=="0006");
}

void testRepo_AddScooter(){
    shared_ptr<AbstractRepo>repo= make_shared<Repo>();
    string id = "S001";
    string model = "Model X";
    string commission_date = "2023/05/15";
    double km = 100.0;
    string last_address = "Street A";
    string actual_state = "parked";
    shared_ptr<Elektroscooter> elektroscooter1=make_shared<Elektroscooter>(id,model,commission_date,km,last_address,actual_state);

    assert(repo->getAll().empty()== false);
    assert(repo->getAll().size()==10);

    repo->add(elektroscooter1);
    shared_ptr<Elektroscooter> scooter=repo->getAll().at(10);
    assert(scooter->get_id()==id);
    assert(scooter->get_actual_state()==actual_state);
    assert(scooter->get_km()==km);
    assert(scooter->get_last_address()==last_address);
    assert(scooter->get_com_date()==commission_date);
    assert(scooter->get_model()==model);
}

void testRepo_FindByLocation(){
    shared_ptr<AbstractRepo>repo= make_shared<Repo>();
    string id = "S001";
    string model = "Model X";
    string commission_date = "2023/05/15";
    double km = 100.0;
    string last_address = "Street A";
    string actual_state = "parked";
    shared_ptr<Elektroscooter> elektroscooter1=make_shared<Elektroscooter>(id,model,commission_date,km,last_address,actual_state);
    repo->add(elektroscooter1);

    string id2 = "S002";
    string model2 = "Model Y";
    string commission_date2 = "2023/05/16";
    double km2 = 200.0;
    string last_address2 = "Street B";
    string actual_state2 = "reserved";
    shared_ptr<Elektroscooter>elektroscooter2=make_shared<Elektroscooter>(id2,model2,commission_date2,km2,last_address2,actual_state2);
    repo->add(elektroscooter2);

    string id3 = "S003";
    string model3 = "Model Z";
    string commission_date3 = "2023/05/17";
    double km3 = 300.0;
    string last_address3 = "Street A";
    string actual_state3 = "parked";
    shared_ptr<Elektroscooter>elektroscooter3=make_shared<Elektroscooter>(id3,model3,commission_date3,km3,last_address3,actual_state3);
    repo->add(elektroscooter3);
    Controller controller(repo);
    vector<shared_ptr<Elektroscooter>>found=controller.findByLocation("Street A");

    assert(found.size()==2);
    assert(found[0]->get_id()==id);
    assert(found[0]->get_last_address()==last_address);
    assert(found[0]->get_km()==km);
    assert(found[0]->get_actual_state()==actual_state);

    assert(found[1]->get_id()==id3);
    assert(found[1]->get_actual_state()==actual_state3);
    assert(found[1]->get_km()==km3);
    assert(found[1]->get_last_address()==last_address3);

}

void TestAllController()
{
    testAddScooter();
    testDeleteScooter();
    testScooterExists();
    testFindScooters();
    testModifyScooter();
    testSortByCommission();

    cout<<"Controller tests all good!\n";
}

void testRepo_RemoveScooter(){
    shared_ptr<AbstractRepo>repo= make_shared<Repo>();
    string id = "S001";
    string model = "Model X";
    string commission_date = "2023/05/15";
    double km = 100.0;
    string last_address = "Street A";
    string actual_state = "parked";
    shared_ptr<Elektroscooter> elektroscooter1=make_shared<Elektroscooter>(id,model,commission_date,km,last_address,actual_state);
    repo->add(elektroscooter1);

    string id2 = "S002";
    string model2 = "Model Y";
    string commission_date2 = "2023/05/16";
    double km2 = 200.0;
    string last_address2 = "Street B";
    string actual_state2 = "reserved";
    shared_ptr<Elektroscooter>elektroscooter2=make_shared<Elektroscooter>(id2,model2,commission_date2,km2,last_address2,actual_state2);
    repo->add(elektroscooter2);

    string id3 = "S003";
    string model3 = "Model Z";
    string commission_date3 = "2023/05/17";
    double km3 = 300.0;
    string last_address3 = "Street A";
    string actual_state3 = "parked";
    shared_ptr<Elektroscooter>elektroscooter3=make_shared<Elektroscooter>(id3,model3,commission_date3,km3,last_address3,actual_state3);
    repo->add(elektroscooter3);

    assert(repo->getAll().size()==13);
    repo->remove(elektroscooter1);
    assert(repo->getAll().size()==12);
    assert(repo->getAll()[10]->get_id()==id2);
    assert(repo->getAll()[11]->get_id()==id3);

}

void testCSVRepo_AddScooter(){
    shared_ptr<AbstractRepo>repo= make_shared<CSVRepo>();
    Controller ctrl(repo);

    unsigned long long init_size=repo->getAll().size();

    string id3 = "S003";
    string model3 = "Model Z";
    string commission_date3 = "2023/05/17";
    double km3 = 300.0;
    string last_address3 = "Street A";
    string actual_state3 = "parked";
    shared_ptr<Elektroscooter>elektroscooter3=make_shared<Elektroscooter>(id3,model3,commission_date3,km3,last_address3,actual_state3);
    repo->add(elektroscooter3);

    assert(repo->getAll().size()==init_size+1);
    assert(repo->getAll()[init_size]->get_id()==id3);
    assert(repo->getAll()[init_size]->get_model()==model3);
    assert(repo->getAll()[init_size]->get_actual_state()==actual_state3);
    repo->remove(elektroscooter3);
    cout<<"test add scooter"<<endl;
}

void testCSVRepo_RemoveScooter(){
    shared_ptr<AbstractRepo>repo= make_shared<CSVRepo>();
    unsigned long long size=repo->getAll().size();
    string id = "S001";
    string model = "Model X";
    string commission_date = "2023/05/15";
    double km = 100.0;
    string last_address = "Street A";
    string actual_state = "parked";
    shared_ptr<Elektroscooter> elektroscooter1=make_shared<Elektroscooter>(id,model,commission_date,km,last_address,actual_state);
    repo->add(elektroscooter1);

    string id2 = "S002";
    string model2 = "Model Y";
    string commission_date2 = "2023/05/16";
    double km2 = 200.0;
    string last_address2 = "Street B";
    string actual_state2 = "reserved";
    shared_ptr<Elektroscooter>elektroscooter2=make_shared<Elektroscooter>(id2,model2,commission_date2,km2,last_address2,actual_state2);
    repo->add(elektroscooter2);

    string id3 = "S003";
    string model3 = "Model Z";
    string commission_date3 = "2023/05/17";
    double km3 = 300.0;
    string last_address3 = "Street A";
    string actual_state3 = "parked";
    shared_ptr<Elektroscooter>elektroscooter3=make_shared<Elektroscooter>(id3,model3,commission_date3,km3,last_address3,actual_state3);

    repo->add(elektroscooter3);
    assert(repo->getAll().size()==size+3);
    repo->remove(elektroscooter3);
    assert(repo->getAll().at(size+1)->get_id()=="S002");
    assert(repo->getAll().at(size+1)->get_model()=="Model Y");
    repo->remove(elektroscooter2);
    repo->remove(elektroscooter1);
    //assert(repo->getAll().size()==size);
    cout<<"test remove scooter"<<endl;

}

void testSCVRepo_update(){
    shared_ptr<AbstractRepo>repo= make_shared<CSVRepo>();
    unsigned long long size=repo->getAll().size();
    string id = "S001";
    string model = "Model X";
    string commission_date = "2023/05/15";
    double km = 100.0;
    string last_address = "Street A";
    string actual_state = "parked";
    shared_ptr<Elektroscooter> elektroscooter1=make_shared<Elektroscooter>(id,model,commission_date,km,last_address,actual_state);
    repo->add(elektroscooter1);

    string id2 = "S002";
    string model2 = "Model Y";
    string commission_date2 = "2023/05/16";
    double km2 = 200.0;
    string last_address2 = "Street B";
    string actual_state2 = "reserved";
    shared_ptr<Elektroscooter>elektroscooter2=make_shared<Elektroscooter>(id2,model2,commission_date2,km2,last_address2,actual_state2);
    repo->add(elektroscooter2);

    string id3 = "S003";
    string model3 = "Model Z";
    string commission_date3 = "2023/05/17";
    double km3 = 300.0;
    string last_address3 = "Street C";
    string actual_state3 = "parked";
    shared_ptr<Elektroscooter>elektroscooter3=make_shared<Elektroscooter>(id3,model3,commission_date3,km3,last_address3,actual_state3);
    repo->add(elektroscooter3);

    string id4 = "S003";
    string model4 = "Model Z";
    string commission_date4 = "2023/05/17";
    double km4 = 300.0;
    string last_address4 = "Street D";
    string actual_state4 = "parked";
    shared_ptr<Elektroscooter>elektroscooter4=make_shared<Elektroscooter>(id4,model4,commission_date4,km4,last_address4,actual_state4);
    repo->update(elektroscooter4);
    assert(repo->getAll().size()==size+3);
    assert(repo->getAll()[size+2]->get_id()==id3);
    assert(repo->getAll()[size+2]->get_id()==id4);
    assert(repo->getAll()[size+2]->get_model()==model4);
    repo->remove(elektroscooter4);
    repo->remove(elektroscooter1);
    repo->remove(elektroscooter2);
    cout<<"test update scooter"<<endl;
}

void TestAllCSV(){

    testCSVRepo_AddScooter();
    testCSVRepo_RemoveScooter();
    testSCVRepo_update();
    cout<<"CSV tests all good!"<<endl;
}

void TestAllRepo()
{
    testRepo_AddScooter();
    testRepo_FindByLocation();
    testRepo_RemoveScooter();
    cout<<"Repo tests all good!"<<endl;
}

