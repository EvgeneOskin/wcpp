#include "/Users/eugen/WIP_wcpp/src/def_wc.h"
#include "/Users/eugen/gtest-1.6.0/include/gtest/gtest.h"

TEST(Counter1, test_input)
{
  std::string file_name("test//test_input.txt");
  counter test_count(file_name);
  EXPECT_EQ (4, test_count.line());
  EXPECT_EQ (40, test_count.symbol());
  EXPECT_EQ (10,test_count.word());
}
