#include "lib.h"
#include "gtest/gtest.h"

TEST(test_version_valid_1, test_version_valid)
{
	ASSERT_GT(version(), 0);
}


