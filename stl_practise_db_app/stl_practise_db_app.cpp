#include <iostream>
#include "ServiceUsers.cpp"

int main()
{
    ContextUsers* context = new ContextUsers();
    ServiceUsers* su = new ServiceUsers(context);

    vector<User> users = su->GetAll();

    for (auto user : users) {
        cout << user.to_string();
    }
    
    return 0;
}