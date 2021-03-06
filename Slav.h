#pragma once
#include <string>
#include <vector>
#include <cstdlib>
#include <iterator>

using namespace std;

enum GENDER
{
	MAN,
	WOMAN
};

class Slav
{
private:
	static void init();

	static std::vector <string> names;
	static int _counter;

	string _name;
	int _id;
	GENDER gender;

public:
	Slav();

	static int counter() { return _counter; }
	
	string name() { return _name; }
	int id() { return _id; }

	string description();

	GENDER getGender()const{return gender;}
};
