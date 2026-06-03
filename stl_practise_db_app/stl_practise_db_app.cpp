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

    vector<User> users = su->GetAll();

    for (auto user : users) {
        cout << user.to_string();
    }
    
    return 0;
}