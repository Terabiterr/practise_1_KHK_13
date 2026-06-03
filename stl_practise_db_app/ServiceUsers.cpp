#include "User.cpp"
#include "ContextUsers.cpp"
#include <functional>
#include <algorithm>
using namespace std;

class IServiceUsers { //interface
public:
	//CRUD
	virtual User& CreateUser(User& user) = 0;
	virtual vector<User>& GetAll() = 0;
	virtual User& UpdateUser(int id, User& user) = 0;
	virtual User& DeleteUser(int id) = 0;
	virtual User& GetUserById(int id) = 0;
	virtual void SortByName() = 0;
	virtual void SortById() = 0;
	virtual vector<User>& BinarySearchByName(string name) = 0;
	virtual User& BinarySearchById(int id) = 0;
	virtual void ReverseAll() = 0;
	virtual void AddRange(vector<User>& users) = 0;
	virtual void ClearAll() = 0;
	virtual vector<User>& GetRange(int start, int count) = 0;
	virtual int GetCount() = 0;
	virtual int GetIndexOf(User& user) = 0;
	virtual int GetLastIndexOf(User& user) = 0;
	virtual bool Contains(User& user) = 0;
	virtual void ForEach(function<void(User&)> action) = 0;
	virtual vector<User>& FindAll(function<bool(User&)> predicate) = 0;
};

class ServiceUsers : public IServiceUsers {
private:
	ContextUsers* context;
public:
	ServiceUsers(ContextUsers* context) : context{context} {}
	User& CreateUser(User& user) override {
		if (&user != nullptr) {
			context->users.push_back(user);
			return user;
		}
		throw new exception("The user is nullptr ...");
	}
	vector<User>& GetAll() override {
		return context->users;
	}
	User& UpdateUser(int id, User& user) override {
		auto &user_found = GetUserById(id);
		if (&user_found != nullptr) {
			user_found.id = user.id;
			user_found.name = user.name;
			return user_found;
		}
		throw new exception("The user not found ...");
	}
	User& DeleteUser(int id) override {
		auto user_found = GetUserById(id);
		if (&user_found != nullptr) {
			for (auto it = context->users.begin(); it != context->users.end(); it++) {
				if (it->id == id) {
					context->users.erase(it);
					return user_found;
				}
			}
		}
		throw new exception("The user not found ...");
	}
	User& GetUserById(int id) override {
		for (auto& user : context->users) {
			if (user.id == id) {
				return user;
			}
		}
		throw new exception("The user not found ...");
	}
};