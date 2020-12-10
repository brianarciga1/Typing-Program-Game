#pragma once
#include "gtest/gtest.h"
#include "../Strategy/TextGenerator/TextGenerator.hpp"
#include <iostream>
using namespace std;

// ----------------------------------
// ----- [ Test - Class Language ] --
// ----------------------------------

    // ----- [ get_Language() ]

TEST(STG_Test_Language, English) {
    
    Language* L = new Language_English();  
    EXPECT_TRUE(L->get_language() == "English");
}

TEST(STG_Test_Language, Spanish) {
    
    Language* L = new Language_Spanish();
    EXPECT_TRUE(L->get_language() == "Spanish");
}

// ----------------------------------
// ----- [ Test - class DataBase ] --
// ----------------------------------

        // ----- [ get_dataBase() ]

TEST(STG_Test_DataBase, getDataBaseSuccess) {
    
    DataBase        DB;
    vector<string>  V;
    V = DB.get_dataBase("Strategy/TextGenerator/DataBase/TextGenerator_Quate_English.txt");

    EXPECT_TRUE(V[0] == "Get busy living or get busy dying. Stephen King");
    EXPECT_TRUE(V[39] == "Only the paranoid survive. Andy Grove, former CEO of Intel");
}      

TEST(STG_Test_DataBase, getDataBaseFaild) {
    
    DataBase        DB;

    EXPECT_EXIT(DB.get_dataBase("wrong address"), ::testing::ExitedWithCode(2),"");
}

// ----------------------------------------
// ----- [ Test - ParagraphGenerator() ] --
// ----------------------------------------

	// ----- [ generate() ]

TEST(STG_Test_ParagraphGenerator, normalIndex) {

    vector<string> V;
    string text;
    TextGenerator* P = new ParagraphGenerator( new Language_English() );

    V = P->generate(0);

    for(int i =0; i < V.size(); i++)
    {
        text += V[i];
        text += " ";
    }

    EXPECT_TRUE(text == "Sunset is the time of day when our sky meets the outer space solar winds. There are blue, pink, and purple swirls, spinning and twisting, like clouds of balloons caught in a whirlwind. The sun moves slowly to hide behind the line of horizon, while the moon races to take its place in prominence atop the night sky. People slow to a crawl, entranced, fully forgetting the deeds that must still be done. There is a coolness, a calmness, when the sun does set. ");
}

TEST(STG_Test_ParagraphGenerator, outIndex0) {

    TextGenerator* P = new ParagraphGenerator( new Language_English() );
    
    EXPECT_EXIT(P->generate(-1);, ::testing::ExitedWithCode(1),"");
}

TEST(STG_Test_ParagraphGenerator, outIndex1) {

    TextGenerator* P = new ParagraphGenerator( new Language_English() );

    EXPECT_EXIT(P->generate(18);, ::testing::ExitedWithCode(1),"");
}

TEST(STG_Test_ParagraphGenerator, outIndex2) {

    TextGenerator* P = new ParagraphGenerator( new Language_English() );

    EXPECT_EXIT(P->generate(10000);, ::testing::ExitedWithCode(1),"");
}

	// ----- [ size() ]

TEST(STG_Test_ParagraphGenerator, size1) {

    TextGenerator* P = new ParagraphGenerator( new Language_English() );
    EXPECT_FLOAT_EQ(P->size(), 18);
}

TEST(STG_Test_ParagraphGenerator, size2) {

    vector<string> V;
    TextGenerator* P = new ParagraphGenerator( new Language_English() );
    
    V = P->generate(0);

    EXPECT_FLOAT_EQ(P->size(), 18);
    EXPECT_FLOAT_EQ(V.size(), 84);
}

// ------------------------------------
// ----- [ Test - QuateGenerator() ] --
// ------------------------------------

         // ----- [ generate() ]

TEST(STG_Test_QuateGenerator, normalIndex0) {

    vector<string> V;
    string text;
    TextGenerator* Q = new QuateGenerator( new Language_English() );

    V = Q->generate(0);

    for(int i =0; i < V.size(); i++)
    {
        text += V[i];
        text += " ";
    }

    EXPECT_TRUE(text == "Get busy living or get busy dying. Stephen King ");
}

TEST(STG_Test_QuateGenerator, normalIndex1) {

    vector<string> V;
    string text;
    TextGenerator* Q = new QuateGenerator( new Language_English() );

    V = Q->generate(10);

    for(int i =0; i < V.size(); i++)
    {
        text += V[i];
        text += " ";
    }

    EXPECT_TRUE(text == "When you reach the end of your rope, tie a knot in it and hang on. Franklin D. Roosevelt ");
}

TEST(STG_Test_QuateGenerator, normalIndex2) {

    vector<string> V;
    string text;
    TextGenerator* Q = new QuateGenerator( new Language_English() );

    V = Q->generate(39);

    for(int i =0; i < V.size(); i++)
    {
        text += V[i];
        text += " ";
    }

    EXPECT_TRUE(text == "Only the paranoid survive. Andy Grove, former CEO of Intel ");
}

TEST(STG_Test_QuateGenerator, outIndex0) {

    TextGenerator* Q = new QuateGenerator( new Language_English() );

    EXPECT_EXIT(Q->generate(-1);, ::testing::ExitedWithCode(1),"");
}

TEST(STG_Test_QuateGenerator, outIndex1) {

    TextGenerator* Q = new QuateGenerator( new Language_English() );

    EXPECT_EXIT(Q->generate(40);, ::testing::ExitedWithCode(1),"");
}

TEST(STG_Test_QuateGenerator, outIndex2) {

    TextGenerator* Q = new QuateGenerator( new Language_English() );

    EXPECT_EXIT(Q->generate(10000);, ::testing::ExitedWithCode(1),"");
}

        // ----- [ size() ]

TEST(STG_Test_QuateGenerator, size1) {

    TextGenerator* Q = new QuateGenerator( new Language_English() );
    EXPECT_FLOAT_EQ(Q->size(), 40);
}

TEST(STG_Test_QuateGenerator, size2) {

    vector<string> V;
    TextGenerator* Q = new QuateGenerator( new Language_English() );

    V = Q->generate(0);

    EXPECT_FLOAT_EQ(Q->size(), 40);
    EXPECT_FLOAT_EQ(V.size(), 9);
}

// --------------------------------------
// ----- [ Test - WordSetGenerator() ] --
// --------------------------------------

	// ----- [ generate() ]	

        
TEST(STG_Test_WordSetGenerator, outIndex0) {

    TextGenerator* W = new WordSetGenerator( new Language_English() );

    EXPECT_EXIT(W->generate(0);, ::testing::ExitedWithCode(1),"");
}

TEST(STG_Test_WordSetGenerator, outIndex1) {

    TextGenerator* W = new WordSetGenerator( new Language_English() );

    EXPECT_EXIT(W->generate(-10);, ::testing::ExitedWithCode(1),"");
}

TEST(STG_Test_WordSetGenerator, outIndex2) {

    vector<string> text;
    TextGenerator* W = new WordSetGenerator( new Language_English() );

    text = W->generate(140);

    for(int i=0; i< text.size(); i++)
    {
        cout << text[i] << ", "; 
    }

    cout << endl << endl;

    EXPECT_TRUE(text.size() == 140);
}
