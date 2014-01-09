#include <gtest/gtest.h>

#include "AESEncrypt.h"

TEST(AESTest, ecryptAES128) {
        EXPECT_EQ(-1,ecryptAES128(NULL,NULL,0));
        EXPECT_EQ(-1,ecryptAES128(NULL,NULL,0));
        EXPECT_EQ(0,ecryptAES128("test.jpg","duanwujie",0));
        EXPECT_EQ(0,ecryptAES128("test.jpg","duanwujie",1));

        EXPECT_EQ(0,ecryptAES128("test.zip","duanwujie",0));
        EXPECT_EQ(0,ecryptAES128("test.zip","duanwujie",1));

        
        EXPECT_EQ(0,ecryptAES128("test.rar","duanwujie",0));
        EXPECT_EQ(0,ecryptAES128("test.rar","duanwujie",1));


}
