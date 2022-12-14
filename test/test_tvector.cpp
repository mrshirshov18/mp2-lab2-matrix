#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
    TDynamicVector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = 1;
    TDynamicVector<int> v1(v);
    EXPECT_EQ(v1, v);
    //ADD_FAILURE();
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
    TDynamicVector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = i;
    TDynamicVector<int> v1(v);
    v[0] = 5;
    int a = v[0];
    int b = v1[0];
    //expected v[0]=5, v1[0]=0;
    EXPECT_NE(a, b);
    //ADD_FAILURE();
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
    TDynamicVector<int> v(5);
    ASSERT_ANY_THROW(v.at(-2));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
    TDynamicVector<int> v(5);
    ASSERT_ANY_THROW(v.at(8));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
    TDynamicVector<int> v(5);
    ASSERT_NO_THROW(TDynamicVector<int> v(v));
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(5);
    ASSERT_NO_THROW(TDynamicVector<int> v1(v2));
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
    TDynamicVector<int> v1(5);
    TDynamicVector<int> v2(6);
    v1 = v2;
    EXPECT_EQ(v1.size(), 6);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
    TDynamicVector<int> v1(6);
    TDynamicVector<int> v2(5);
    ASSERT_NO_THROW(TDynamicVector<int> v1(v2));
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
    TDynamicVector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = i;
    TDynamicVector<int> v1(v);
    EXPECT_EQ(v1 == v, 1);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
    TDynamicVector<int> v(10);
    for (int i = 0; i < 10; i++)
        v[i] = i;
    EXPECT_EQ(v == v, 1);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
    TDynamicVector<int> v1(6);
    TDynamicVector<int> v2(5);
    EXPECT_NE(v1 == v2, 1);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
    TDynamicVector<int> v(10);
    for (int i = 0; i < 10; i++) {
        v[i] = i;
    }
    ASSERT_NO_THROW(v = v + 2);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
    TDynamicVector<int> v(10);
    for (int i = 0; i < 10; i++) {
        v[i] = i;
    }
    ASSERT_NO_THROW(v = v - 2);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
    TDynamicVector<int> v(10);
    for (int i = 0; i < 10; i++) {
        v[i] = i;
    }
    ASSERT_NO_THROW(v = v * 2);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> v2(10);
    for (int i = 0; i < 10; i++) {
        v[i] = i;
        v2[i] = 5;
    }
    ASSERT_NO_THROW(v = v + v2);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> v2(11);
    for (int i = 0; i < 10; i++) {
        v[i] = i;
        v2[i] = 5;
    }
    v2[10] = 5;
    ASSERT_ANY_THROW(v = v + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> v2(10);
    for (int i = 0; i < 10; i++) {
        v[i] = i;
        v2[i] = 5;
    }
    ASSERT_NO_THROW(v = v - v2);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> v2(11);
    for (int i = 0; i < 10; i++) {
        v[i] = i;
        v2[i] = 5;
    }
    v2[10] = 5;
    ASSERT_ANY_THROW(v = v - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> v2(10);
    for (int i = 0; i < 10; i++) {
        v[i] = i;
        v2[i] = 5;
    }
    ASSERT_NO_THROW(v = v * v2);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
    TDynamicVector<int> v(10);
    TDynamicVector<int> v2(11);
    for (int i = 0; i < 10; i++) {
        v[i] = i;
        v2[i] = 5;
    }
    v2[10] = 5;
    ASSERT_ANY_THROW(v = v * v2);
}

