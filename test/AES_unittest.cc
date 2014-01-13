



#include "gtest/gtest.h"


TEST(AES, ecryptAES128) {
        EXPECT_EQ(0,ecryptAES128,"test.jpg","1234567890",0);
        EXPECT_EQ(1,ecryptAES128,"test.jpg","1234567890",1);
}


