#include "header.h"

#include <gtest/gtest.h>

TEST(Calc, can_create_calc)
{
	ASSERT_NO_THROW(Calc exp);
}

TEST(Calc, can_input_calc)
{
	Calc exp;
	ASSERT_NO_THROW(exp.input("a+b"));
}

TEST(Calc, can_to_post_calc)
{
	Calc exp("a+b");
	ASSERT_NO_THROW(exp.toPost());
}

TEST(Calc, can_calculate_calc)
{
	Calc exp("a+b");
	map<char, double> values;
	values['a'] = 1;
	values['b'] = 2;

	ASSERT_NO_THROW(exp.calculate(values));
}

TEST(Calc, calc_correct_to_post)
{
	Calc exp("a+b");
	EXPECT_EQ("ab+", exp.toPost());
	exp.input("a/b");
	EXPECT_EQ("ab/", exp.toPost());
	exp.input("a+b*c");
	EXPECT_EQ("abc*+", exp.toPost());
	exp.input("a+b-c+d");
	EXPECT_EQ("ab+c-d+", exp.toPost());
	exp.input("(a+b)*(c-d)");
	EXPECT_EQ("ab+cd-*", exp.toPost());
	exp.input("a-(b+c)*d");
	EXPECT_EQ("abc+d*-", exp.toPost());
}

TEST(Calc, calc_correct_colculate)
{
	map<char, double> values;
	values['a'] = 1;
	values['b'] = 2;
	values['c'] = 3;
	values['d'] = 4;

	Calc exp("a+b");
	EXPECT_EQ(3, exp.calculate(values));
	exp.input("a/b");
	EXPECT_EQ(0.5, exp.calculate(values));
	exp.input("a+b*c");
	EXPECT_EQ(7, exp.calculate(values));
	exp.input("a+b-c+d");
	EXPECT_EQ(4, exp.calculate(values));
	exp.input("(a+b)*(c-d)");
	EXPECT_EQ(-3, exp.calculate(values));
	exp.input("a-(b+c)*d");
	EXPECT_EQ(-19, exp.calculate(values));
}