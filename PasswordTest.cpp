/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_leading_a)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("aab"));
}

TEST(PasswordTest, two_leading_caps)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("AAb"));
}

TEST(PasswordTest, one_leading_caps)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Ab"));
}

TEST(PasswordTest, ending_repeats)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("abaaaaaa"));
}

TEST(PasswordTest, three_leading_z)
{
	Password my_password;
	ASSERT_EQ(3, my_password.count_leading_characters("zzzx"));
}

TEST(PasswordTest, cap_diff_check)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("AAaa"));
}

TEST(PasswordTest, cap_diff_check2)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("aaAA"));
}

TEST(PasswordTest, multi_cap_check)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("AaAa"));
}

TEST(PasswordTest, empty_string)
{
	Password my_password;
	ASSERT_EQ(0, my_password.count_leading_characters(""));
}

TEST(PasswordTest, check_num)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("AAb2"));
}

TEST(PasswordTest, three_leading_num)
{
	Password my_password;
	ASSERT_EQ(3, my_password.count_leading_characters("111ab"));
}

TEST(PasswordTest, ending_two_a)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("abaa"));
}

TEST(PasswordTest, two_leading_special)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("@@ba"));
}

//MIXED CASE TESTING:
TEST(PasswordTest, leading_cap)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("Password"));
}
TEST(PasswordTest, no_cap)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("password"));
}
TEST(PasswordTest, ending_cap)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("passworD"));
}
TEST(PasswordTest, all_cap)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("PASSWORD"));
}
