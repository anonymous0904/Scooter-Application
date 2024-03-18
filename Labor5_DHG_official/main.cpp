#include "UI/ElektroUI.h"
#include "Tests/Test.h"
using namespace std;

int main() {

    TestAllController();
    TestAllRepo();
    TestAllCSV();

    int choice;
    cout<<endl<<"How do you want to save the products?"<<endl;
    cout<<"1. Volatile"<<endl;
    cout<<"2. Persistent"<<endl;
    cout<<"Your choice: ";
    cin>>choice;
    while(choice!=1 and choice!=2){
        cout<<endl<<"Please enter valid data!"<<endl<<"Your choice:";
        cin>>choice;
    }
    cout<<endl;
    shared_ptr<AbstractRepo> obj;
    if(choice==1) {
        obj = Repo::createInstance();
    }
    else{
        obj = CSVRepo::createInstance();
    }
    auto ctrl = Controller(obj);
    auto ui = UI(ctrl);
    ui.mainUI();

    return 0;
}
