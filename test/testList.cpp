#include "header.h"

#include <gtest/gtest.h>

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> l);
}

TEST(List, can_copy_list)
{
	List<int> l1;
	ASSERT_NO_THROW(List<int> l2(l1));
}

TEST(List, can_equate_lists)
{
	List<int> l1;
	List<int> l2;
	ASSERT_NO_THROW(l2 = l1);
}

TEST(List, equate_lists_has_his_own_memory)
{
	List<int> l1;
	List<int> l2;
	l2 = l1;
	l1.pushBack(1);
	ASSERT_NE(l2.getSize(), l1.getSize());
}

TEST(List, can_add_object_list)
{
	List<int> l1;
	EXPECT_NO_THROW(l1.pushFirst(1));
	EXPECT_NO_THROW(l1.pushBack(1));
	EXPECT_NO_THROW(l1.push(1,1));
}

TEST(List, cant_add_object_with_too_big_index_list)
{
	List<int> l1;
	ASSERT_ANY_THROW(l1.push(1, 10));
}

TEST(List, cant_add_object_with_negative_index_list)
{
	List<int> l1;
	ASSERT_ANY_THROW(l1.push(1, -1));
}

TEST(List, can_del_object_list)
{
	List<int> l1;
	l1.pushBack(1);
	l1.pushBack(1);
	l1.pushBack(1);
	EXPECT_NO_THROW(l1.del(1));
	EXPECT_NO_THROW(l1.delFirst());
	EXPECT_NO_THROW(l1.delBack());
}

TEST(List, cant_del_object_from_empty_list)
{
	List<int> l1;
	ASSERT_ANY_THROW(l1.delFirst());
}