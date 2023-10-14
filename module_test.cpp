#include <gtest/gtest.h>
#include "module.h"
#include<iostream>

class StackTest : public ::testing::Test
{
public:
    Stack s;
    void SetUp() override
    {std::cout << "Google Test version:  " << __VERSION__ << std::endl;

        s.size=5;
    }
    void TearDown() override
    {
    }
};

//0
TEST_F(StackTest, zero_condition_is_created)
{
    ASSERT_EQ(5,s.size);
}


//1
TEST_F(StackTest, is_empty_after_creation_zero_condition)
{
    ASSERT_TRUE(s.is_empty());
    
}
//2
TEST_F(StackTest, is_not_full_after_creation_zero_condition)
{
    ASSERT_FALSE(s.is_full());
}
//3
TEST_F(StackTest, is_not_empty_after_put_one)
{
    s.push(0);

    ASSERT_FALSE(s.is_empty());
}

//4
TEST_F(StackTest, is_empty_after_put_then_get_one)
{
    // s.push(0); Is Pushed in the previous Test.
    int element;
    s.pop(element);
    ASSERT_TRUE(s.is_empty());
    // std::cout<<element<<std::endl;
    // std::cout<<s.temp<<std::endl;
    
}

//5
TEST_F(StackTest, get_equals_put_for_one_item)
{
    int pushed_element=9,poped_element;
    s.push(pushed_element);
    s.pop(poped_element);

    ASSERT_EQ(pushed_element,poped_element);
}
  
//6
TEST_F(StackTest, put_multiple_get_multiple_LIFO)
{
    int i,j,k,poped_elements[5]={0},pushed_elements[5];
    // std::cout<<"Top= .."<<s.top<<std::endl;

    // std::cout<<"The insrted elements are..."<<std::endl;


    for(i=0;i<s.size;i++){
        s.push(i);
        pushed_elements[i]=i;
    // std::cout<<s.Buffer[i]<<" ";
    }

    // std::cout<<std::endl;
    // std::cout<<"Top= .."<<s.top<<std::endl;

    for(j =s.size-1;j>=0;j--){
        s.pop(poped_elements[j]);                                                 //why this?
        // std::cout<<poped_elements[j]<<" ";
    }
    // std::cout<<std::endl;   
    // std::cout<<"Top= .."<<s.top<<std::endl;
    for(k=0;k<s.size;k++){
        ASSERT_EQ(poped_elements[k],pushed_elements[k]);
    // std::cout<<pushed_elements[i]<<" ";
    }
}

//7
TEST_F(StackTest, full_capacity)
{
int i,dump;

    for(i=0;i<s.size;i++){
        s.push(i);
    }

   ASSERT_TRUE(s.is_full());
    for(i=0;i<s.size;i++){
            s.pop(dump);
        }
}
//8
TEST_F(StackTest, is_not_full_after_get_from_full_buffer)
{
int i,dump;

    for(i=0;i<s.size;i++){
        s.push(i);
    }
    for(i=0;i<s.size;i++){
            s.pop(dump);
        }
    ASSERT_FALSE(s.is_full());

}

//9
TEST_F(StackTest, put_to_full_fails)
{
int i,dump;

    for(i=0;i<s.size;i++){
        s.push(i);
    }
    ASSERT_EQ(-1,s.push(5));
    for(i=0;i<s.size;i++){
            s.pop(dump);
        }
                // std::cout<<s.temp;

}

//10
TEST_F(StackTest, pop_from_empty_fails)
{
    int dump;
    ASSERT_EQ(-1,s.pop(dump));
}

