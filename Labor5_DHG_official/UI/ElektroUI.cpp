#include <string>
#include <algorithm>
#include <limits>
#include "ElektroUI.h"

using namespace std;

UI::UI(Controller& controller): controller(controller) {
}

void UI::search_by_location() {
    string location;
    cout << "Enter the location to search: ";
    cin >> std::ws; // Skip leading whitespace characters
    getline(cin, location);
    vector<shared_ptr<Elektroscooter>> foundScooters = controller.findScooters(location);
    if(foundScooters.empty()){
        cout<<"No scooter at that location."<<endl;
    }
    else {
        // Display the found scooters
        cout << "Found scooters:" << endl;
        for (const shared_ptr<Elektroscooter> &scooter: foundScooters) {
            cout << "ID: " << scooter->get_id() << endl;
            cout << "Model: " << scooter->get_model() << endl;
            cout << "Commission Date: " << scooter->get_com_date() << endl;
            cout << "Kilometers: " << scooter->get_km() << endl;
            cout << "Last Address: " << scooter->get_last_address() << endl;
            cout << "State: " << scooter->get_actual_state() << endl;
            cout << endl;
        }
    }
}

void UI::sort_by_date_kilom() {
    int new_option;
    cout << "Sort by: " << endl;
    cout << "1. Commission date" << endl;
    cout << "2. Kilometers" << endl;
    cin >> new_option;
    if (new_option == 1) {
        vector<shared_ptr<Elektroscooter>> sortedScooters = controller.sortByCommission();

        // Display the sorted scooters
        cout << "Sorted scooters by commission date:" << endl;
        for (const shared_ptr<Elektroscooter>& scooter: sortedScooters) {
            cout << "ID: " << scooter->get_id() << endl;
            cout << "Model: " << scooter->get_model() << endl;
            cout << "Commission Date: " << scooter->get_com_date() << endl;
            cout << "Kilometers: " << scooter->get_km() << endl;
            cout << "Last Address: " << scooter->get_last_address() << endl;
            cout << "State: " << scooter->get_actual_state() << endl;
            cout << endl;
        }
    } else if (new_option == 2) {
        vector<shared_ptr<Elektroscooter>> sortedScooters = controller.getAllScooters();
        sort(sortedScooters.begin(), sortedScooters.end(),
             [](const shared_ptr<Elektroscooter> &s1, const shared_ptr<Elektroscooter> &s2) {
                 return s1->get_km() < s2->get_km();
             });

        // Display the sorted scooters
        cout << "Sorted scooters by kilometers:" << endl;
        for (const shared_ptr<Elektroscooter>& scooter: sortedScooters) {
            cout << "ID: " << scooter->get_id() << endl;
            cout << "Model: " << scooter->get_model() << endl;
            cout << "Commission Date: " << scooter->get_com_date() << endl;
            cout << "Kilometers: " << scooter->get_km() << endl;
            cout << "Last Address: " << scooter->get_last_address() << endl;
            cout << "State: " << scooter->get_actual_state() << endl;
            cout << endl;
        }
    } else {
        cout << "Invalid option" << endl;
    }
}

void UI::filter_by_date_kilom() {
    int filter_option;
    cout << "Filter by:" << endl;
    cout << "1. Commission date" << endl;
    cout << "2. Kilometers" << endl;
    cin >> filter_option;

    if (filter_option == 1) {
        string filter_commission_date;
        cout << "Enter the commission date to filter by: ";
//                        cin.ignore();
//                        getline(cin, filter_commission_date);
        cin >> filter_commission_date;
        while (not Controller::valid_comm_date(filter_commission_date)) {
            cout << endl << "Please enter valid data: ";
            cin >> filter_commission_date;
        }
        vector<shared_ptr<Elektroscooter>> filteredScooters;
        for (const shared_ptr<Elektroscooter> &scooter: controller.getAllScooters()) {
            if (scooter->get_com_date() == filter_commission_date) {
                filteredScooters.push_back(scooter);
            }
        }
        if (filteredScooters.empty()) {
            cout << endl << "No scooter with that commission date." << endl;
        } else {
            // Display the filtered scooters
            cout << "Filtered scooters by commission date:" << endl;
            for (const shared_ptr<Elektroscooter> &scooter: filteredScooters) {
                cout << "ID: " << scooter->get_id() << endl;
                cout << "Model: " << scooter->get_model() << endl;
                cout << "Commission Date: " << scooter->get_com_date() << endl;
                cout << "Kilometers: " << scooter->get_km() << endl;
                cout << "Last Address: " << scooter->get_last_address() << endl;
                cout << "State: " << scooter->get_actual_state() << endl;
                cout << endl;
            }
        }
    } else if (filter_option == 2) {
        double filter_kilometers;
        cout << "Enter the kilometers to filter by: ";
        cin >> filter_kilometers;
        while (not Controller::valid_kilom(filter_kilometers)) {
            cout << endl << "Please enter valid data: ";
            cin >> filter_kilometers;
        }
        vector<shared_ptr<Elektroscooter>> filteredScooters;
        for (const shared_ptr<Elektroscooter> &scooter: controller.getAllScooters()) {
            if (scooter->get_km() == filter_kilometers) {
                filteredScooters.push_back(scooter);
            }
        }
        if (filteredScooters.empty()) {
            cout << "No scooter with that number of kilometers." << endl;
        } else {
            // Display the filtered scooters
            cout << "Filtered scooters by kilometers:" << endl;
            for (const shared_ptr<Elektroscooter> &scooter: filteredScooters) {
                cout << "ID: " << scooter->get_id() << endl;
                cout << "Model: " << scooter->get_model() << endl;
                cout << "Commission Date: " << scooter->get_com_date() << endl;
                cout << "Kilometers: " << scooter->get_km() << endl;
                cout << "Last Address: " << scooter->get_last_address() << endl;
                cout << "State: " << scooter->get_actual_state() << endl;
                cout << endl;
            }
        }
    } else {
        cout << "Invalid option" << endl;
        return; // Exit the function if the option is invalid
    }
}

void UI::rent_a_scooter() {

    cout << "Enter the ID of the scooter you want to rent: ";
    string id;
    cin >> id;

    if (controller.scooterExists(id)) {
        shared_ptr<Elektroscooter> scooter = controller.getScooterByID(id);
        if (scooter->get_actual_state() == "reserved") {
            cout << "The scooter is already rented." << endl;
        } else {
            controller.rentScooter(id);
            //cout << "Scooter rented successfully." << endl;
        }
    } else {
        cout << "Invalid scooter ID." << endl;
    }
}

void UI::add_a_scooter() {
    string id, model, commission_date1, last_address, state1;
    double km1;

    cout << "Enter the scooter details:" << endl;
    cout << "ID: ";
    cin >> id;
    while(controller.scooterExists(id)){
        cout<<endl<<"Please enter id of non-existing scooter: ";
        cin>>id;
    }
    cout << "Model: ";
    cin >> model;
    cout << "Commission Date(yyyy/mm/dd): ";
    cin >> commission_date1;
    while(not Controller::valid_comm_date(commission_date1)){
        cout<<endl<<"Please enter valid data: ";
        cin>>commission_date1;
    }
    cout << "Kilometers: ";
    while (!(cin >> km1) || !Controller::valid_kilom(km1)) {
        cout << endl << "Please enter valid data: ";
        cin.clear(); // Clear the fail state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the entire line including invalid input
    }

    cout << "Last Address: ";
    cin >> std::ws; // Skip leading whitespace characters
    getline(cin, last_address);
    cout << "State (parked, reserved, being_used, waiting, out_of_service): ";
    cin >> state1;
    while(not Controller::valid_state(state1)){
        cout<<endl<<"Please enter valid data: ";
        cin>>state1;
    }
    shared_ptr<Elektroscooter> scooter = make_shared<Elektroscooter>(id, model, commission_date1, km1, last_address, state1);
    controller.addScooter(scooter);
    std::cout << endl << "Scooter added successfully." << std::endl;

}

void UI::delete_scooter() {
    string id;

    cout << "Enter the ID of the scooter to delete: ";
    cin >> id;
    if (controller.scooterExists(id))
    {
        controller.deleteScooter(id);
        cout << "Scooter deleted successfully." << endl;
    }

    else
    {
        cout << "This scooter doesn't exist" << endl;
    }
}

void UI::modify_scooter() {
    string id;
    double newKm;
    string newLastAddress;
    string newActualState;

    cout << "Enter the ID of the scooter to modify: ";
    cin >> id;

    if (controller.scooterExists(id)) {
        cout << "Enter the new kilometers: ";
        cin >> newKm;
        while(not Controller::valid_kilom(newKm)){
            cout<<endl<<"Please enter valid data: ";
            cin>>newKm;
        }
        cout << "Enter the new last address: ";
        // Ignore the newline character in the input buffer
        cin >> std::ws; // Skip leading whitespace characters
        getline(cin, newLastAddress);

        cout << "Enter the new state (parked, reserved, being_used, waiting, out_of_service): ";
        string newStateString;
        cin >> newStateString;
        while(not Controller::valid_state(newStateString)){
            cout<<endl<<"Please enter valid data: ";
            cin>>newStateString;
        }

        try {
            newActualState = newStateString;
            controller.modifyScooter(id, newKm, newLastAddress, newActualState);
            cout << "Scooter modified successfully." << endl;
        } catch (const std::runtime_error &e) {
            cout << "Invalid input. Scooter modification failed." << endl;
        }
    } else {
        cout << "Scooter with the specified ID does not exist." << endl;
    }
}

void UI::customer_menu() {
    int option_customer;
    //double km;
    string location, commission_date;
    string scooter_state;
    do {
        customer_interface();
        cin >> option_customer;
        cout << endl;

        if (option_customer == 1) {
            search_by_location();

        } else if (option_customer == 2) {
            sort_by_date_kilom();

        } else if (option_customer == 3) {
            filter_by_date_kilom();

        } else if (option_customer == 4) {
            rent_a_scooter();
        }

        else if (option_customer == 5) {
            controller.printRentedScooters();
        }

        if(option_customer==6){
            controller.show_all_scooters();
        }
    } while (option_customer >0 and option_customer<7);

}

void UI::manager_menu() {
    int option_manager;

    string password_sistem = "DHG";
    string password_manager;
    cout << "Enter the password for the Manager account: ";
    cin >> password_manager;
    if (password_manager != password_sistem) {
        cout << "You're not a manager, bro. Nice try\n";
        option_manager = 8;
    } else {

        //double km;
        string location, commission_date;
        string scooter_state;
        do {
            manager_interface();
            cin >> option_manager;
            cout << endl;

            if (option_manager == 1) {
                add_a_scooter();

            } else if (option_manager == 2) {
                delete_scooter();

            }
            if (option_manager == 3) {
                search_by_location();

            } else if (option_manager == 4) {
                sort_by_date_kilom();

            } else if (option_manager == 5) {
                filter_by_date_kilom();

            } else if (option_manager == 6) {
                modify_scooter();

            } else if (option_manager == 7) {
                controller.show_all_scooters();
            }

        } while (option_manager > 0 and option_manager < 8);
    }
}
void UI::customer_interface() {
    cout << "CUSTOMER MENU" << endl;
    cout << "Select an action:" << endl;
    cout << "1. Search scooter by location" << endl;
    cout << "2. Sort by commission date/ by kilometers" << endl;
    cout << "3. Filter by commission date/ by kilometers" << endl;
    cout << "4. Rent scooters" << endl;
    cout << "5. Show rented scooters" << endl;
    cout << "6. Show all scooters"<< endl;
    cout << "7. Exit" << endl;
    cout << "Your option: ";
}

void UI::manager_interface() {
    cout << "MANAGER MENU" << endl;
    cout << "Select an action:" << endl;
    cout << "1. Add a scooter" << endl;
    cout << "2. Delete a scooter" << endl;
    cout << "3. Search scooter by location" << endl;
    cout << "4. Sort by commission date/ by kilometers" << endl;
    cout << "5. Filter by commission date/ by kilometers" << endl;
    cout << "6. Modify a scooter" << endl;
    cout << "7. Show all scooters" << endl;
    cout << "8. Exit" << endl;
    cout << "Your option: ";
}

void UI::mainUI() {
    int option;
    while(true) {
        cout << "MAIN MENU" << endl;
        cout << "Select identity:" << endl;
        cout << "1. Customer" << endl;
        cout << "2. Manager" << endl;

        cin >> option;
        cout << endl;
        if (option == 1) {
            customer_menu();

        } else if (option == 2) {
            manager_menu();

        }
        string your_answer;
        cout<<endl<<"Do you want to continue? yes/no: ";
        cin>>your_answer;
        cout<<endl;
        while(your_answer!="yes" and your_answer!="no"){
            cout<<endl<<"Type a valid answer: ";
            cin>>your_answer;
        }
        if(your_answer=="no"){
            break;
        }
    }
}

UI::~UI() =default;
