#pragma once
#include <vector>
#include <string>

typedef unsigned int					UInt;
typedef unsigned __int64				UInt64;
typedef std::vector<UInt>				UIntVec;

typedef UIntVec::iterator				UIntVecIterator;
typedef UIntVec::const_iterator			UIntVecConstIterator;
typedef UIntVec::reverse_iterator		UIntVecReverseIterator;
typedef UIntVec::const_reverse_iterator	UIntVecReverseConstIterator;

//static const __int64 MAXVALUE			= UINT_MAX;
static const UInt64 MAXVALUE = 999999999;
static const UInt64 CARRY_THRESHOLD = MAXVALUE / 2;
static const UInt64 BASE = MAXVALUE + 1;

static const int	TOKEN_LENGHT = 1;

enum Sign
{
	POSITIVE = 0,
	NEGATIVE = 1,
};


class BigInteger
{
public:
	//ctors
	BigInteger();
	explicit BigInteger(UInt i_number);
	explicit BigInteger(int i_number);
	explicit BigInteger(const std::string& i_string_number);

	BigInteger& operator=	(UInt i_number);
	BigInteger& operator=	(int i_number);

	BigInteger& operator+=	(const BigInteger& i_big);
	BigInteger& operator+=	(UInt number);
	BigInteger& operator+=	(int number);

	BigInteger& operator-=	(const BigInteger& i_big);
	BigInteger& operator-=	(UInt number);
	BigInteger& operator-=	(int number);
	
	BigInteger& operator/=	(const BigInteger& i_div);
	BigInteger& operator/=	(UInt i_div);
	BigInteger& operator/=	(int i_div);
	
	BigInteger& operator<<=	(UInt number);
	BigInteger& operator<<=	(int number);

	BigInteger& operator>>=	(UInt number);
	BigInteger& operator>>=	(int number);
	
	BigInteger& operator*=	(const BigInteger& i_mul);
	BigInteger& operator*=	(UInt i_mul);
	BigInteger& operator*=	(int i_mul);


	BigInteger& operator++();				//preincrement 
	BigInteger operator++(int);				//postincrement
	
	BigInteger& operator--();				//predecrement 
	BigInteger operator--(int);				//postdecrement 

	BigInteger pow(int i_power);
	BigInteger pow(UInt i_power);
	BigInteger pow(const BigInteger& i_power);

	
	void set_sign(Sign i_sign);
	Sign get_sign() const;
	const UIntVec& get_vector() const;

	friend std::ostream& operator<<(std::ostream& os, const BigInteger& b);
private:

	UInt int_division(UInt i_div);				//int div return reminder
	BigInteger& unsigned_sum(const BigInteger& i_big);
	BigInteger& unsigned_subtract(const BigInteger& i_big);
	void CheckZeroVal();

	//***data members***
	UIntVec	m_vector;
	Sign 	m_sign;									//0 = positive ; 1 = negative
};

BigInteger operator*(const BigInteger& i_big, UInt c);
BigInteger operator*(const BigInteger& i_big, int c);
BigInteger operator*(UInt c, const BigInteger& i_big);
BigInteger operator*(int c,  const BigInteger& i_big);
BigInteger operator*(const BigInteger& i_first, const BigInteger& i_second);

BigInteger operator+(const BigInteger& i_first, const BigInteger& i_second);
BigInteger operator-(const BigInteger& i_first, const BigInteger& i_second);

BigInteger operator/(const BigInteger& i_first, const BigInteger& i_second);
BigInteger operator/(const BigInteger& i_big, UInt c);
BigInteger operator/(const BigInteger& i_big, int c);
BigInteger operator/(int c, const BigInteger& i_big);
BigInteger operator/(UInt c, const BigInteger& i_big);

BigInteger operator<<(const BigInteger& i_big, UInt i_shift);
BigInteger operator>>(const BigInteger& i_big, UInt i_shift);

BigInteger operator<<(const BigInteger& i_big, int i_shift);
BigInteger operator>>(const BigInteger& i_big, int i_shift);

BigInteger radix(const BigInteger&  i_big, UInt i_radix, UInt i_estimation);

bool unsigned_equal(const BigInteger& v, const BigInteger& i_big);
bool operator==(const BigInteger& v, const BigInteger& i_big);
bool operator==(const BigInteger& v, UInt i_num);
bool operator==(const BigInteger& v, int i_num);
bool operator==(UInt i_num, const BigInteger& v);
bool operator==(int i_num, const BigInteger& v);

bool operator!=(const BigInteger& v, const BigInteger& i_big);
bool operator!=(const BigInteger& v, UInt i_num);
bool operator!=(const BigInteger& v, int i_num);
bool operator!=(UInt i_num, const BigInteger& v);
bool operator!=(int i_num, const BigInteger& v);

bool operator>(const BigInteger& v, const BigInteger& i_big);
bool operator>(const BigInteger& v, UInt i_num);
bool operator>(const BigInteger& v, int i_num);
bool operator>(UInt i_num, const BigInteger& v);
bool operator>(int i_num, const BigInteger& v);

bool operator<(const BigInteger& v, const BigInteger& i_big);
bool operator<(const BigInteger& v, UInt i_num);
bool operator<(const BigInteger& v, int i_num);
bool operator<(UInt i_num, const BigInteger& v);
bool operator<(int i_num, const BigInteger& v);

bool operator>=(const BigInteger& v, const BigInteger& i_big);
bool operator<=(const BigInteger& v, const BigInteger& i_big);
