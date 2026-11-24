#include "header.h"

#include <gtest/gtest.h>

TEST(TForwardList, can_create_TForwardList)
{
	ASSERT_NO_THROW(TForwardList<int> l);
}

TEST(TForwardList, can_copy_TForwardList)
{
	TForwardList<int> l1;
	ASSERT_NO_THROW(TForwardList<int> l2(l1));
}

TEST(TForwardList, can_equate_TForwardLists)
{
	TForwardList<int> l1;
	TForwardList<int> l2;
	ASSERT_NO_THROW(l2 = l1);
}

TEST(TForwardList, equate_TForwardLists_has_his_own_memory)
{
	TForwardList<int> l1;
	TForwardList<int> l2;
	l2 = l1;
	l1.pushBack(1);
	ASSERT_NE(l2.getSize(), l1.getSize());
}

TEST(TForwardList, can_add_object_TForwardList)
{
	TForwardList<int> l1;
	EXPECT_NO_THROW(l1.pushFront(1));
	EXPECT_NO_THROW(l1.pushBack(1));
	EXPECT_NO_THROW(l1.push(1,1));
}

TEST(TForwardList, cant_add_object_with_too_big_index_TForwardList)
{
	TForwardList<int> l1;
	ASSERT_ANY_THROW(l1.push(1, 10));
}

TEST(TForwardList, cant_add_object_with_negative_index_TForwardList)
{
	TForwardList<int> l1;
	ASSERT_ANY_THROW(l1.push(1, -1));
}

TEST(TForwardList, can_Erase_object_TForwardList)
{
	TForwardList<int> l1;
	l1.pushBack(1);
	l1.pushBack(1);
	l1.pushBack(1);
	EXPECT_NO_THROW(l1.Erase(1));
	EXPECT_NO_THROW(l1.EraseFront());
	EXPECT_NO_THROW(l1.EraseBack());
}

TEST(TForwardList, cant_Erase_object_from_empty_TForwardList)
{
	TForwardList<int> l1;
	ASSERT_ANY_THROW(l1.EraseFront());
}