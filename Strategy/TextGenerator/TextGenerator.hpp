#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "../DataBase/DataBase.hpp"
using namespace std;



class TextGenerator {

protected:
	vector<string>		v_DB;
	string				language;
	DataBase			dataBase;

public:

	virtual vector<string>	create(int) = 0;
	virtual void			set_Language(Language*) = 0;
};