#include <iostream>
#include "doctest.h"
#include "OrgChart.hpp"
using namespace ariel;

 //* AUTHORS: <Tavor Levine>

#include <string>
#include <algorithm>
using namespace std;

TEST_CASE("Build a OrgChart tree"){
    OrgChart orgChart;
    CHECK_NOTHROW(orgChart.add_root("Boaz BenMoshe"));
    SUBCASE("level order"){
        CHECK_EQ(*(orgChart.begin_level_order()),"Boaz BenMoshe");
        CHECK_EQ(*(orgChart.end_level_order()),"Boaz BenMoshe");
        CHECK_NOTHROW(orgChart.add_sub("Boaz BenMoshe","Noam Hazon"));
        CHECK_NOTHROW(orgChart.add_sub("Boaz BenMoshe","Elad Horev"));
        CHECK_EQ(*(orgChart.end_level_order()),"Elad Horev");
        CHECK_NOTHROW(orgChart.add_sub("Boaz BenMoshe","Dan Hefetz"));
        CHECK_NOTHROW(orgChart.add_sub("Boaz BenMoshe","Gavriel Nibash"));
        CHECK_EQ(*(orgChart.end_level_order()),"Gavriel Nibash");
        CHECK_NOTHROW(orgChart.add_sub("Gavriel Nibash","Edoot Cohen"));
        CHECK_NOTHROW(orgChart.add_sub("Elad Horev", "Doron Mor"));
        CHECK_NOTHROW(orgChart.add_sub("Noam Hazon", "Chaya Levinger"));
        CHECK_NOTHROW(orgChart.add_sub("Dan Hefetz", "Shani Shoob"));
        CHECK_EQ(*(orgChart.end_level_order()),"Edoot Cohen");
        CHECK_EQ(*(orgChart.begin_level_order()),"Boaz BenMoshe"); // the root stay in the begin
    }
    SUBCASE("reverse order"){
        CHECK_EQ(*(orgChart.begin_reverse_order()),"Boaz BenMoshe");
        CHECK_NOTHROW(orgChart.add_sub("Boaz BenMoshe","Noam Hazon"));
        CHECK_NOTHROW(orgChart.add_sub("Boaz BenMoshe","Elad Horev"));
        CHECK_EQ(*(orgChart.begin_reverse_order()),"Noam Hazon");
        CHECK_NOTHROW(orgChart.add_sub("Boaz BenMoshe","Dan Hefetz"));
        CHECK_NOTHROW(orgChart.add_sub("Boaz BenMoshe","Gavriel Nibash"));
        CHECK_EQ(*(orgChart.begin_reverse_order()),"Noam Hazon");
        CHECK_NOTHROW(orgChart.add_sub("Gavriel Nibash","Edoot Cohen"));
        CHECK_NOTHROW(orgChart.add_sub("Elad Horev", "Doron Mor"));
        CHECK_NOTHROW(orgChart.add_sub("Noam Hazon", "Chaya Levinger"));
        CHECK_NOTHROW(orgChart.add_sub("Dan Hefetz", "Shani Shoob"));
        CHECK_EQ(*(orgChart.begin_reverse_order()),"Chaya Levinger");
        CHECK_EQ(*(orgChart.reverse_order()),"Boaz BenMoshe");
    }
    SUBCASE("pre order"){
        CHECK_EQ(*(orgChart.begin_preorder()),"Boaz BenMoshe");
        CHECK_NOTHROW(orgChart.add_sub("Boaz BenMoshe","Noam Hazon"));
        CHECK_NOTHROW(orgChart.add_sub("Boaz BenMoshe","Elad Horev"));
        CHECK_EQ(*(orgChart.end_preorder()),"Elad Horev");
        CHECK_NOTHROW(orgChart.add_sub("Boaz BenMoshe","Dan Hefetz"));
        CHECK_NOTHROW(orgChart.add_sub("Boaz BenMoshe","Gavriel Nibash"));
        CHECK_EQ(*(orgChart.end_preorder()),"Gavriel Nibash");
        CHECK_NOTHROW(orgChart.add_sub("Gavriel Nibash","Edoot Cohen"));
        CHECK_NOTHROW(orgChart.add_sub("Elad Horev", "Doron Mor"));
        CHECK_NOTHROW(orgChart.add_sub("Noam Hazon", "Chaya Levinger"));
        CHECK_NOTHROW(orgChart.add_sub("Dan Hefetz", "Shani Shoob"));
        CHECK_EQ(*(orgChart.end_preorder()),"Edoot Cohen");
        CHECK_EQ(*(orgChart.begin_preorder()),"Boaz BenMoshe");        
    }
    SUBCASE("bad input"){
        CHECK_THROWS(orgChart.add_sub("Elad Horev","Michael Trushkin"));
        CHECK_NOTHROW(orgChart.add_root("Tavor Levine"));
        CHECK_EQ(*(orgChart.begin_level_order()),"Tavor Levine");
        CHECK_THROWS(orgChart.add_sub("Boaz BenMoshe", "Elad Horev"));
        CHECK_THROWS(orgChart.add_sub("Boaz BenMoshe", "Natzig Shnatun"));
        CHECK_THROWS(orgChart.add_sub("Tavor", "Natzig Shnatun"));
    }


}