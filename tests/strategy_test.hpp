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
    EXPECT_STREQ(L->get_language(), "English");
}

TEST(STG_Test_Language, Spanish) {
    
    Language* L = new Language_English();
    EXPECT_STREQ(L->get_language(), "Spanish");
}


// ----------------------------------
// ----- [ Test - class DataBase ] --
// ----------------------------------

        // ----- [ get_dataBase() ]

TEST(STG_Test_DataBase, getDataBaseSuccess) {
    
    DataBase        DB;
    vector<string>  V;
    V = DB.get_dataBase("Strategy/TextGenerator/DataBase/TextGenerator_Quate_English.txt");

    EXPECT_STREQ(V[0], "Get busy living or get busy dying. Stephen King");
    EXPECT_STREQ(V[39], "Only the paranoid survive. Andy Grove, former CEO of Intel");
    EXPECT_STREQ(V[40], "ss");
    EXPECT_STREQ(V[-1], "ss");
}      

TEST(STG_Test_DataBase, getDataBaseFaild) {
    
    DataBase        DB;

    EXPECT_EXIT(DB.get_dataBase("wrong address"), ::testing::ExitedWithCode(1), " ");
}
