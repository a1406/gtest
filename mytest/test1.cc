#include <stdio.h>
#include <stdlib.h>

int Foo(int a, int b)
{
	if (a == 0 || b == 0)
	{
		throw "don't do that";
	}
	int c = a % b;
	if (c == 0)
		return b;
	return Foo(b, c);
}

#include <gtest/gtest.h>

TEST(FooTest, HandleNoneZeroInput)
{
	EXPECT_EQ(2, Foo(4, 10));
	EXPECT_EQ(1, Foo(30, 18));
	EXPECT_EQ(2, Foo(30, 18));
	EXPECT_EQ(3, Foo(30, 18));
	EXPECT_EQ(6, Foo(30, 18));	
}

TEST(FooTest, HandleNoneZeroInput1)
{
	EXPECT_EQ(2, Foo(4, 10));
	EXPECT_EQ(6, Foo(30, 18));
	EXPECT_EQ(6, Foo(30, 18));
	EXPECT_EQ(6, Foo(30, 18));
	EXPECT_EQ(6, Foo(30, 18));	
}

TEST(FooTest22, HandleNoneZeroInput1)
{
	EXPECT_EQ(2, Foo(4, 10));
	EXPECT_EQ(3, Foo(30, 18));
	EXPECT_EQ(4, Foo(30, 18));
	EXPECT_EQ(5, Foo(30, 18));
	EXPECT_EQ(6, Foo(30, 18));	
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

