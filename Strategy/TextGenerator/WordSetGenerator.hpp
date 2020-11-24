#pragma once
#include "TextGenerator.hpp"
using namespace std;



class QuateGenerator : public TextGenerator {

public:

	void set_Language(Language* L) {
		language = L->get_language();
	}

	// .create()
	// -------------------------------------------
	// get Data from database and return the value
	// -------------------------------------------
	// 	 [#1] it open the DataBase[TextFileVersion] & turn it into DataBase[C++Version: Vectortype]
	// 	 [#2] it take the index from user, and get the corsponding data from database
	// 	 [#3] parse that data into the words and save the words into a new vector, return the vector
	// -------------------------------------------
	vector<string> create(int word_count) {

		v_DB = dataBase.get_dataBase("TextGenerator_WordSet_" + language + ".txt");
		string				output;

		// [#2]
		for (int i=0; i<word_count;i++)
		{
			output = v_DB[i];
			v_DB.push_back(output);
		}
		v_DB.clear();

		return v_DB;
	}
};

