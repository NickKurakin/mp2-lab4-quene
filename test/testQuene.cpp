#include "header.h"

#include <gtest/gtest.h>

TEST(Quene, can_create_Quene)
{
	ASSERT_NO_THROW(Quene<int> s);
}

TEST(Quene, can_copy_Quene)
{
	Quene<int> q1;
	ASSERT_NO_THROW(Quene<int> q2(q1));
}

TEST(Quene, can_equate_Quene)
{
	Quene<int> q1;
	Quene<int> q2;
	ASSERT_NO_THROW(q2 = q1);
}

TEST(Quene, equate_Quenes_has_his_own_memory)
{
	Quene<int> q1;
	Quene<int> q2;
	q2 = q1;
	q1.push(1);
	ASSERT_NE(q2.getSize(), q1.getSize());
}

TEST(Quene, can_add_object_Quene)
{
	Quene<int> q1;
	EXPECT_NO_THROW(q1.push(1));
}

TEST(Quene, can_del_object_list)
{
	Quene<int> q1;
	q1.push(1);
	EXPECT_NO_THROW(q1.del());
}

TEST(Quene, cant_del_object_from_empty_list)
{
	Quene<int> q1;
	ASSERT_ANY_THROW(q1.del());
}