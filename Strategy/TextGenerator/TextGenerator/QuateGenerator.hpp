#pragma once
#include "TextGenerator.hpp"
using namespace std;


class QuateGenerator : public TextGenerator {

public:

// ----- [ QuateGenerator constructor ]
// -------------------------------------------------------------------------
// ----- [ convert DataBase ( text version ) to DataBase( vector Version ) ]
// ----- [ we use Data Base Vector Version from now ]
	QuateGenerator(Language* L) {
		_dataBase_Vector = _dataBase_Text.get_dataBase( "Strategy/TextGenerator/DataBase/TextGenerator_Quate_" +  L->get_language() + ".txt" );
	}

// ----- [ generate() ]
// -------------------------------------------------------------------------
// ----- [ only use dataBase Vector version ]
// ----- [ 1st, take the index from user. 2nd, take that index from dataBase ]
// ----- [ 3rd, parse that index into the word, 4th return all the word as a vector ]
	vector<string> generate(int index) {

		vector<string> sub_vector;

		string data = _dataBase_Vector[index];
		stringstream dataBase_stream(data);
 
		while (getline(dataBase_stream, data, ' ')) 
		{
			sub_vector.push_back(data);
		}

		return sub_vector;
	}
};

