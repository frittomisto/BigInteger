#ifdef _GTEST
#include "../BigInteger/BigInteger.h"
#include "gtest/gtest.h"

TEST(bigIntegerTest, ctor_from_int)
{
	BigInteger one(1);
	EXPECT_EQ(one, 1U);
}

TEST(bigIntegerTest, ctor_from_String)
{
	BigInteger one("1");
	EXPECT_EQ(one, 1U);
}

TEST(bigIntegerTest, ctor_from_String_)
{
	BigInteger minus_one("-1");
	EXPECT_EQ(minus_one, -1);
}

TEST(bigIntegerTest, ctor_from_large_int)
{
	BigInteger intmax(INT_MAX);
	EXPECT_EQ(intmax, INT_MAX);
}

TEST(bigIntegerTest, postincrement)
{
	BigInteger zero(0);
	auto zero_expected = zero++;
	EXPECT_EQ(zero, 1U);
	EXPECT_EQ(zero_expected, 0U);

	BigInteger intmax(INT_MAX);
	auto res = intmax++;
	const UInt expected_res = INT_MAX + 1;
	EXPECT_EQ(intmax, expected_res);
	EXPECT_EQ(res, INT_MAX);
}

TEST(bigIntegerTest, preincrement)
{
	BigInteger zero(0);
	EXPECT_EQ(++zero, 1U);
}

TEST(bigIntegerTest, postdecrement)
{
	BigInteger zero(0);
	auto zero_expected = zero--;
	EXPECT_EQ(zero, -1);
	EXPECT_EQ(zero_expected, 0);
}

TEST(bigIntegerTest, predecrement)
{
	BigInteger zero(0);
	--zero;
	EXPECT_EQ(zero, -1);
}

TEST(bigIntegerTest, sum)
{
	BigInteger one(1);
	BigInteger ten(10);
	EXPECT_EQ(one + ten, 11U);
}

TEST(bigIntegerTest, large_sum)
{
	BigInteger a("13407807929942597099574024998205846127479365820592393377723561443721764000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	BigInteger b("30073546976801874298166903427690031858186486050853753882811946569946433649006084096");
	BigInteger c("13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096");
	EXPECT_EQ(a + b, c);
}

TEST(bigIntegerTest, diff)
{
	BigInteger one(1);
	BigInteger ten(10);
	EXPECT_EQ(ten - one, 9U);
}

TEST(bigIntegerTest, large_diff)
{
	BigInteger a("13407807929942597099574024998205846127479365820592393377723561443721764000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	BigInteger b("30073546976801874298166903427690031858186486050853753882811946569946433649006084096");
	BigInteger c("13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096");
	EXPECT_EQ(c - b, a);
}

TEST(bigIntegerTest, mul)
{
	BigInteger one(1);
	BigInteger two(2);
	BigInteger ten(10);
	EXPECT_EQ(one*ten, 10U);
	EXPECT_EQ(two*ten, 20U);
}

TEST(bigIntegerTest, large_mul)
{
	BigInteger aie("20000000000");
	BigInteger bie("10");
	BigInteger res("10");

	for (int i = 0; i!=5000; ++i)
		aie *= bie;
}

TEST(bigIntegerTest, mul_2)
{
	BigInteger one(1);
	BigInteger two(2);
	BigInteger large("10000000000");
	BigInteger large_expected("20000000000");
	EXPECT_EQ(one*large, large);
	EXPECT_EQ(two*large, large_expected);
}

TEST(bigIntegerTest, div)
{
	BigInteger one(1);
	BigInteger two(2);
	BigInteger ten(10);
	EXPECT_EQ(ten / one, 10U);
	EXPECT_EQ(ten / two, 5U);
}

TEST(bigIntegerTest, large_div)
{
	BigInteger div1("2287342482348930009991239876012345566");
	BigInteger div2("10000000900001010203000");
	BigInteger expected("228734227648789");
	EXPECT_EQ(div1 / div2, expected);
	EXPECT_TRUE(div2 * expected <= div1);
}

TEST(bigIntegerTest, mixed_op)
{
	BigInteger neg(-10);
	BigInteger pos(10);
	EXPECT_EQ(neg / pos, -1);
	EXPECT_EQ(neg * pos, -100);
	EXPECT_EQ(neg * neg, 100);
	EXPECT_EQ(neg + pos, 0);
	EXPECT_EQ(neg - pos, -20);
}
	
TEST(bigIntegerTest, mixed_op_2)
{
	BigInteger neg("-50");
	BigInteger pos("100");
	EXPECT_EQ(neg / pos, 0);
	EXPECT_EQ(neg * pos, -5000);
	EXPECT_EQ(neg * neg, 2500);
	EXPECT_EQ(neg + pos, 50);
	EXPECT_EQ(neg - pos, -150);
}
	
TEST(bigIntegerTest, test_pow)
{
	BigInteger testpow2("2");
	testpow2.pow(150);
	std::stringstream out;
	out << testpow2;
	EXPECT_EQ(out.str() , "1427247692705959881058285969449495136382746624");
}
	
TEST(bigIntegerTest, large_test_pow)
{
	BigInteger testpow2("2");
	testpow2.pow(512);
	std::stringstream out;
	out << testpow2;
	EXPECT_EQ(out.str(), "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096");
}

#endif
