#include "gtest/gtest.h"
#include "../../src/dummy.hpp"

TEST(Empty, Dummy){
    ASSERT_EQ(func(), 10);
}
