#pragma once
#include <string>
#include <sstream>
using namespace std;
struct User {
	int id;
	string name;

	string to_string() {
		stringstream ss;
		ss
			<< "id: " << id
			<< ", name: " << name
			<< endl;
	}

};