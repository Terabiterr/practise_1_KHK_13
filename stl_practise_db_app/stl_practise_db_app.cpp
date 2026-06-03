#include <iostream>
#include "ServiceUsers.cpp"

int main()
{
    ContextUsers* context = new ContextUsers();
    ServiceUsers* su = new ServiceUsers(context);

    User* new_user = new User();
    new_user->id = 15;
    new_user->name = "Alex";

    su->CreateUser(*new_user);
    
    new_user->name = "Bob";
    su->UpdateUser(15, *new_user);

    cout << "***************GetUserById*************" << endl;
    User& user_found_by_id = su->GetUserById(15);
    cout << user_found_by_id.to_string() << endl;
    cout << "**************GetUserById**************" << endl;

    vector<User> users = su->GetAll();

    for (auto user : users) {
        cout << user.to_string();
    }
    
    return 0;
}