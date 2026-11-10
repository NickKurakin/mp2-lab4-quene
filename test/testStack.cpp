#include "header.h"

#include <gtest/gtest.h>

TEST(Stack, can_create_stack)
{
	ASSERT_NO_THROW(Stack<int> s);
}

TEST(Stack, can_copy_stack)
{
	Stack<int> s1;
	ASSERT_NO_THROW(Stack<int> s2(s1));
}

TEST(Stack, can_equate_stack)
{
	Stack<int> s1;
	Stack<int> s2;
	ASSERT_NO_THROW(s2 = s1);
}

TEST(Stack, equate_stacks_has_his_own_memory)
{
	Stack<int> s1;
	Stack<int> s2;
	s2 = s1;
	s1.push(1);
	ASSERT_NE(s2.getSize(), s1.getSize());
}

TEST(Stack, can_add_object_stack)
{
	Stack<int> s1;
	EXPECT_NO_THROW(s1.push(1));
}

TEST(Stack, can_del_object_list)
{
	Stack<int> s1;
	s1.push(1);
	EXPECT_NO_THROW(s1.del());
}

TEST(Stack, cant_del_object_from_empty_list)
{
	Stack<int> s1;
	ASSERT_ANY_THROW(s1.del());
}