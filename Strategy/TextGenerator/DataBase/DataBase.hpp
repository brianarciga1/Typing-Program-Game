#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "../Language/Language.hpp"
using namespace std;



class DataBase
{

private:

	ifstream			DB;
	vector<string>		v_DB;

public:

	// .get_dataBase()
	// -------------------------------------------
	// get Data from DATABASE[TextType] and return a VECTOR of values
	// -------------------------------------------
	// 	 [#1] it open the DataBase[TextFileVersion] & turn it into DataBase[C++Version: Vectortype]
	//	 [#2] return the DATABASE[VectorVersion]
	// -------------------------------------------
	vector<string>  get_dataBase(string address) {

		string				output;

		// [#1]
		DB.open(address);

		while (!DB.eof())
		{
			getline(DB, output);
			v_DB.push_back(output);
		}

		DB.close();

		// [#2]
		return v_DB;
	}
};

