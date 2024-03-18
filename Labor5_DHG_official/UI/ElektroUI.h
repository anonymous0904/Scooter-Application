#ifndef LABOR5_DHG_OFFICIAL_ELEKTROUI_H
#define LABOR5_DHG_OFFICIAL_ELEKTROUI_H

#include "../Controller/Controller.h"
#include "../Repository/ElektroRepo.h"


class UI {
private:
    void choose_identity();

    void manager_identity(int &validationStatus);

    void is_manager();

    void is_customer();

    int manager_Anda();

    int manager_Andrada();

    int manager_Stef();

    int manager_Tudor();

    void custumor_menu();

    void manager_menu(int option_manager);

    void customer_menu(int option_customer);

    void search_by_location();

    void sort_by_date();

    void sort_by_km();

    void filter_by_date();

    void filter_by_km();

    void rent_a_scooter();

    void add_a_scooter();

    void delete_scooter();

    void modify_scooter();

    void method_memory(int &choice);

    void continue_or_not();

    shared_ptr<AbstractRepo> obj;
public:
    Controller controller;

    explicit UI(Controller& controller);

    void menu();
    void mainUI();

    void manager_menu();
    void customer_menu();
    void static manager_interface();
    void static customer_interface();

    //void search_by_location();
    void sort_by_date_kilom();
    void filter_by_date_kilom();
    //void rent_a_scooter();
    //void add_a_scooter();
    //void delete_scooter();
    //void modify_scooter();


    ~UI();
};
//public:
//    Controller controller;
//    explicit UI(Controller& controller);
//    void mainUI();
//
//    void manager_menu();
//    void customer_menu();
//    void static manager_interface();
//    void static customer_interface();
//
//    void search_by_location();
//    void sort_by_date_kilom();
//    void filter_by_date_kilom();
//    void rent_a_scooter();
//    void add_a_scooter();
//    void delete_scooter();
//    void modify_scooter();
//
//    ~UI();



#endif //LABOR5_DHG_OFFICIAL_ELEKTROUI_H
