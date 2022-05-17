/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Daniel
 */

#include "doctest.h"

#include "OrgChart.hpp"

#include <exception>

using namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
using namespace std;

TEST_CASE("Tree creation"){
    OrgChart mafia;
    CHECK_THROWS(mafia.add_sub("Non exists","Failed"));
    CHECK_NOTHROW(mafia.add_root("Boss"));
    CHECK_NOTHROW(mafia.add_sub("Boss","Underboss"));
    CHECK_THROWS(mafia.add_sub("Caporegime","Vito Scalleta"));

    CHECK_NOTHROW(mafia.add_root("Vito Scalleta"));
}

TEST_CASE("level Oreder"){
    OrgChart mafia;
    mafia.add_root("Boss");
    mafia.add_sub("Boss","Underboss");
    mafia.add_sub("Underboss","Capo I");
    mafia.add_sub("Underboss","Capo II");
    mafia.add_sub("Underboss","Capo III");
    mafia.add_sub("Capo I","Soldier I");
    mafia.add_sub("Capo II","Soldier II");
    mafia.add_sub("Capo III","Soldier III");
    
    std::vector<std::string> testStrings = {"Boss","Underboss",
                                            "Capo I","Capo II","Capo III",
                                            "Soldier I","Soldier II","Soldier III"};

    for (auto it = mafia.begin_level_order(); it != mafia.end_level_order(); ++it){
        CHECK_EQ(*it,testStrings.front());
        testStrings.erase(testStrings.begin());
    }
}  

TEST_CASE("reverse Oreder"){
    OrgChart mafia;
    mafia.add_root("Boss");
    mafia.add_sub("Boss","Underboss");
    mafia.add_sub("Underboss","Capo I");
    mafia.add_sub("Underboss","Capo II");
    mafia.add_sub("Underboss","Capo III");
    mafia.add_sub("Capo I","Soldier I");
    mafia.add_sub("Capo II","Soldier II");
    mafia.add_sub("Capo III","Soldier III");
    
    std::vector<std::string> testStrings = {"Soldier I","Soldier II","Soldier III",
                                            "Capo I","Capo II","Capo III",
                                            "Underboss","Boss"
                                            };

    std::for_each(mafia.begin_reverse_order(),mafia.reverse_order(),[&](std::string role){
        CHECK_EQ(role,testStrings.front());
        testStrings.erase(testStrings.begin());
    });
}  

TEST_CASE("Preorder Oreder"){
    OrgChart mafia;
    mafia.add_root("Boss");
    mafia.add_sub("Boss","Underboss");
    mafia.add_sub("Underboss","Capo I");
    mafia.add_sub("Underboss","Capo II");
    mafia.add_sub("Underboss","Capo III");
    mafia.add_sub("Capo I","Soldier I");
    mafia.add_sub("Capo II","Soldier II");
    mafia.add_sub("Capo III","Soldier III");
    
    std::vector<std::string> testStrings = {"Boss","Underboss",
                                            "Capo I","Soldier I",
                                            "Capo II","Soldier II",
                                            "Capo III","Soldier III"};

    std::for_each(mafia.begin_preorder(),mafia.end_preorder(),[&](std::string role){
        
        CHECK_EQ(role,testStrings.front());
        testStrings.erase(testStrings.begin());
    });
}  

