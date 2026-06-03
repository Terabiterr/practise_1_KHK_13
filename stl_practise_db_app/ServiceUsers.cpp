#include "User.cpp"
#include "ContextUsers.cpp"
using namespace std;

class IServiceUsers { //interface
public:
	//CRUD
	virtual User& CreateUser(User& user) = 0;
	virtual vector<User>& GetAll() = 0;
	virtual User& UpdateUser(int id, User& user) = 0;
	virtual User& DeleteUser(int id) = 0;
	virtual User& GetUserById(int id) = 0;
};

class ServiceUsers : public IServiceUsers {
private:
	ContextUsers* context;
public:
	ServiceUsers(ContextUsers* context) : context{context} {}
	User& CreateUser(User& user) override {
		
	}
	vector<User>& GetAll() override {
		return context->users;
	}
	User& UpdateUser(int id, User& user) override {

	}
	User& DeleteUser(int id) override {

	}
	User& GetUserById(int id) override {

	}
};