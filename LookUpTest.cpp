
#include <iostream>
//include the google test dependencies
#include <gtest/gtest.h>
using namespace std;
class LookUp {
private:
    float output;
    float key1;
    float key2;
public:
    LookUp(float val1, float val2){
        output = 0;
        key1 = val1;
        key2 = val2;
    }
    ~LookUp(){};
    
    int findkey();
};

//test case: exact key match
TEST(IntegerInputsSuite, LookUp1)
{
  //first, set up any inputs to your
    LookUp a(2281,75);
  //then, make an assertion to test
    EXPECT_EQ(a.findkey(), 849) << "The output is  correct";
}

//test case: rpm key match
TEST(IntegerInputsSuite, LookUp2)
{
  //first, set up any inputs to your
    LookUp a(969,60);
  //then, make an assertion to test
    EXPECT_EQ(a.findkey(), 1075) << "The output is  correct";
}

//test case: throttle key match
TEST(IntegerInputsSuite, LookUp3)
{
  //first, set up any inputs to your
    LookUp a(968,25);
  //then, make an assertion to test
    EXPECT_EQ(a.findkey(), 705 ) << "The output is  correct";
}

//test case: no exact match
TEST(IntegerInputsSuite, LookUp4)
{
  //first, set up any inputs to your
    LookUp a(1405,49);

  //then, make an assertion to test
    EXPECT_EQ(a.findkey(), 93) << "The output is  correct";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
