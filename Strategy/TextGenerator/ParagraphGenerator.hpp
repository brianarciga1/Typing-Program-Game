#pragma once
#include "TextGenerator.hpp"
using namespace std;



class ParagraphGenerator : public TextGenerator {

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
	vector<string> create(int index) {

		v_DB = dataBase.get_dataBase("TextGenerator_Paragraph_" + language + ".txt");
		string				output;

		// [#2]
		output = v_DB[index];
		v_DB.clear();

		// [#3]
		stringstream s_DB(output);
		string word;
 
		while (getline(s_DB, word, ' ')) 
			v_DB.push_back(word);

		return v_DB;
	}
    
};

