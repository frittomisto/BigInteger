#include "BigInteger.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <complex>

BigInteger::BigInteger()
{
	m_vector.clear();
	m_sign = POSITIVE;
}

BigInteger::BigInteger(UInt i_number)
{
	m_vector.clear();
	m_sign = POSITIVE;
	if (i_number)
	{
		UInt result;
		do
		{
			result = i_number / BASE;
			m_vector.push_back(i_number % BASE);
			i_number = result;
		} while (result > 0);
	}
}

BigInteger::BigInteger(const int i_number)
{
	m_vector.clear();
	m_sign = POSITIVE;

	UInt abs_num = i_number;
	if (i_number == 0) 
		return;
	if (i_number < 0)
	{
		m_sign = NEGATIVE;
		abs_num *= -1;
	}

	UInt result;
	
	do
	{
		result = abs_num / BASE;
		m_vector.push_back(abs_num % BASE);
		abs_num = result;
	} while (result > 0);

}

BigInteger& BigInteger::operator=(const UInt i_number)
{
	m_vector.clear();
	m_sign = POSITIVE;
	if (i_number)
	{
		UInt result;
		do
		{
			result = i_number / BASE;
			m_vector.push_back(i_number % BASE);
		} while (result > 0);
	}
	return *this;
}

BigInteger& BigInteger::operator=(int i_number)
{
	m_vector.clear();
	m_sign = POSITIVE;
	if (i_number)
	{
		i_number > 0 ? m_sign = POSITIVE : m_sign = NEGATIVE;
		UInt result;
		do
		{
			result = i_number / BASE;
			m_vector.push_back(i_number % BASE);
		} while (result > 0);
	}
	return *this;
}

bool operator!=(const BigInteger& v, const UInt i_num)
{
	return !(v == i_num);
}

bool operator!=(const BigInteger& v, int i_num)
{
	return !(v == i_num);
}

bool operator!=(UInt i_num, const BigInteger& v)
{
	return !(v == i_num);
}

bool operator!=(int i_num, const BigInteger& v)
{
	return !(v == i_num);
}

bool operator!=(const BigInteger& v, const BigInteger& i_big)
{
	return !(v == i_big);
}

bool operator>=(const BigInteger& v, const BigInteger& i_big)
{
	return !(v < i_big);
}

bool operator<=(const BigInteger& v, const BigInteger& i_big)
{
	return !(v > i_big);
}

BigInteger& BigInteger::operator++()
{
	const BigInteger unit(1);
	(*this) += unit;
	return *this;
}

BigInteger& BigInteger::operator--()
{
	const BigInteger unit(1);
	(*this) -= unit;
	return (*this);
}

BigInteger BigInteger::operator++(int)
{
	auto clone(*this);
	const BigInteger unit(1);
	(*this) += unit;
	return clone;
}

BigInteger BigInteger::operator--(int)
{
	auto clone(*this);
	const BigInteger unit(1);
	(*this) -= unit;
	return clone;
}

BigInteger BigInteger::pow(int i_power)
{
	if (i_power >= 0)
	{
		return this->pow(static_cast<UInt>(i_power));
	}

	return (1 / this->pow(static_cast<UInt>(i_power)));
}

BigInteger operator+(const BigInteger& i_first, const BigInteger& i_second)
{
	auto temp(i_first);
	temp += i_second;
	return temp;
}

BigInteger operator>>(const BigInteger& i_big, const UInt i_shift)
{
	auto temp(i_big);
	temp >>= i_shift;
	return temp;
}

BigInteger operator<<(const BigInteger& i_big, int i_shift)
{
	auto temp(i_big);
	temp <<= i_shift;
	return temp;
}

BigInteger operator>>(const BigInteger& i_big, int i_shift)
{
	auto temp(i_big);
	temp <<= i_shift;
	return temp;
}

BigInteger operator<<(const BigInteger& i_big, const UInt i_shift)
{
	auto temp(i_big);
	temp <<= i_shift;
	return temp;
}

BigInteger operator-(const BigInteger& i_first, const BigInteger& i_second)
{
	auto temp(i_first);
	temp -= i_second;
	return temp;
}

BigInteger operator*(const BigInteger& i_first, const  BigInteger& i_second)
{
	auto temp(i_first);
	temp *= i_second;
	return temp;
}

BigInteger operator*(const UInt c, const BigInteger& i_big)
{
	auto temp(i_big);
	temp *= c;
	return temp;
}

BigInteger operator*(int c, const BigInteger& i_big)
{
	auto temp(i_big);
	temp *= c;
	return temp;
}

BigInteger operator*(const BigInteger& i_big, const UInt c)
{
	auto temp(i_big);
	temp *= c;
	return temp;
}

BigInteger operator*(const BigInteger& i_big, int c)
{
	auto temp(i_big);
	temp *= c;
	return temp;
}

BigInteger operator/(const UInt c, const BigInteger& i_big)
{
	auto temp(i_big);
	temp /= c;
	return temp;
}

BigInteger operator/(const BigInteger& i_big, const UInt c)
{
	auto temp(i_big);
	temp /= c;
	return temp;
}

BigInteger operator/(const BigInteger& i_big, int c)
{
	auto temp(i_big);
	temp /= c;
	return temp;
}

BigInteger operator/(int c, const BigInteger& i_big)
{
	auto temp(i_big);
	temp /= c;
	return temp;
}

BigInteger operator/(const BigInteger& i_first, const BigInteger& i_second)
{
	auto temp(i_first);
	temp /= i_second;
	return temp;
}

void BigInteger::set_sign(Sign i_sign)
{
	m_sign = i_sign;
}

Sign BigInteger::get_sign() const
{
	return m_sign;
}

const UIntVec& BigInteger::get_vector() const
{
	return m_vector;
}


bool unsigned_equal(const BigInteger& v, const BigInteger& i_big)
{
	if (&v == &i_big)
		return true;

	if (v.get_vector().size() != i_big.get_vector().size())
		return false;

	auto m_it = v.get_vector().rbegin();
	auto b_it = i_big.get_vector().rbegin();

	for (; m_it != v.get_vector().rend(); ++m_it, ++b_it)
	{
		if (*m_it != *b_it)
			return false;
	}
	return true;
}

bool operator== (const BigInteger& v, const BigInteger& i_big)
{
	if (v.get_sign() != i_big.get_sign())
		return false;

	return unsigned_equal(v, i_big);
}

bool operator== (const BigInteger& v, const UInt i_num)
{
	//if (i_num == 0 && v.get_vector().empty())
	//	return true;
	//if (v.get_sign() == NEGATIVE)
	//	return false;
	//if (v.get_vector().size() > 1 || v.get_vector().empty()) // -> i_num !=0
	//	return false;
	//return v.get_vector()[0] == i_num;

	const BigInteger big_tmp(i_num);
	return v == big_tmp;
}

bool operator==(const BigInteger& v, int i_num)
{
	const BigInteger big_tmp(i_num);
	return v == big_tmp;
}

bool operator==(UInt i_num, const BigInteger& v)
{
	const BigInteger big_tmp(i_num);
	return v == big_tmp;
}

bool operator==(int i_num, const BigInteger& v)
{
	const BigInteger big_tmp(i_num);
	return v == big_tmp;
}

bool operator<(const BigInteger& v, const BigInteger& i_big)
{
	if (&v == &i_big)
		return false;

	if (v.get_vector().size() < i_big.get_vector().size())
		return true;

	if (v.get_vector().size() > i_big.get_vector().size())
		return false;

	auto m_it = v.get_vector().rbegin();
	auto b_it = i_big.get_vector().rbegin();

	for (; m_it != v.get_vector().rend(); ++m_it, ++b_it)
	{
		if (*m_it < *b_it)
			return true;

		if (*m_it > *b_it)
			return false;
	}
	return false;
}

bool operator<(const BigInteger& v, UInt i_num)
{
	if ((i_num >= 0 && v.get_sign() == 1) )
		return true;
	if (v.get_vector().size() == 1)
		return v.get_vector()[0] < i_num;

	return false;
}

bool operator<(const BigInteger& v, int i_num)
{
	if ((i_num >= 0 && v.get_sign() == NEGATIVE) || (i_num < 0 && v.get_sign() == POSITIVE))
		return true;

	const UInt unsigned_num = i_num;

	if (v.get_vector().size() == 1)
		return v.get_vector()[0] < unsigned_num;

	return false;
}

bool operator<(UInt i_num, const BigInteger& v)
{
	return v < i_num;
}

bool operator<(int i_num, const BigInteger& v)
{
	return v < i_num;
}

bool operator>(const BigInteger& v, const BigInteger& i_big)
{
	if (&v == &i_big)
		return false;

	if (v.get_vector().size() > i_big.get_vector().size())
		return true;

	if (v.get_vector().size() < i_big.get_vector().size())
		return false;

	auto m_it = v.get_vector().rbegin();
	auto b_it = i_big.get_vector().rbegin();

	for (; m_it != v.get_vector().rend(); ++m_it, ++b_it)
	{
		if (*m_it > *b_it)
			return true;
		
		if (*m_it < *b_it)
			return false;
	}
	return false;
}

bool operator>(const BigInteger& v, UInt i_num)
{
	if (i_num >= 0 && v.get_sign() == NEGATIVE)
		return false;
	if (v.get_vector().size() == 1)
		return v.get_vector()[0] > i_num;

	return true;
}

bool operator>(const BigInteger& v, int i_num)
{
	if ((i_num >= 0 && v.get_sign() == NEGATIVE) || (i_num < 0 && v.get_sign() == POSITIVE))
		return false;

	const UInt unsigned_num = i_num;

	if (v.get_vector().size() == 1)
		return v.get_vector()[0] > unsigned_num;

	return true;
}

bool operator>(UInt i_num, const BigInteger& v)
{
	return v > i_num;
}

bool operator>(int i_num, const BigInteger& v)
{
	return v > i_num;
}

BigInteger radix(const BigInteger& i_big, const UInt i_radix, const UInt i_estimation)
{
	//tangent (or Newton) method: we solve
	//xi = x0 - f(x)/f'(x)
	//where f(x) : x^radix - (*this) = 0
	//NB: result could be a (big) approx of correct result 'caused by integer arithmetic

	if (i_radix == 0 || i_radix == 1)
		return i_big;

	BigInteger x0(0), x1(i_estimation);

	while (x1 - x0 != 0)
	{
		x0 = x1;
		auto dfa = x0;
		//f'
		dfa.pow(i_radix - 1);	//x^i_radix-1
		auto df = dfa;
		df *= i_radix;

		//f
		auto fa = dfa;
		fa *= x0;			//x^i_radix
		auto f = fa - i_big;
		// f = f/f'
		f /= df;
		x1 = x0 - f;
	}
	return x1;
}

std::ostream& operator<<(std::ostream& os, const BigInteger& b)
{
	if (b.m_vector.empty() || b == 0)
	{
		os << "0";
		return os;
	}

	if (b.m_sign == NEGATIVE)
	{
		os << "-";
	}

	for (auto it = b.m_vector.rbegin(); it != b.m_vector.rend(); ++it)
	{
		std::ostringstream ostream;
		ostream << (*it);
		auto str = ostream.str();
		if (it != b.m_vector.rbegin())
		{
			while (str.length() != 9)  //every token has 9 digits: if a token is smaller, fullfil with 0
			{
				str = "0" + str;
			}
		}
		os << str;
	}
	return os;

}

BigInteger::BigInteger(const std::string& i_string_number)
{
	const auto str_len = i_string_number.length();
	m_sign = POSITIVE;

	if (str_len > 0)
	{
		if (i_string_number[0] == '-')
		{
			m_sign = NEGATIVE;
		}

		m_vector.clear();
		UIntVec v;
		for (UInt i = 0; i < str_len; i++)  //divide string in vector of tokens
		{
			auto s = i_string_number.substr(i*TOKEN_LENGHT, TOKEN_LENGHT);
			v.push_back(atoi(s.c_str()));
		}

		for (UInt i = 0; i < str_len; i++)
		{
			auto it = v.begin();
			const auto v_end = v.end();
			UInt64 rest = 0;
			for (; it != v_end; ++it)
			{
				auto number = rest * 10;
				number += (*it);
				(*it) = static_cast<UInt>(number / BASE);
				rest = number % BASE;
			}
			m_vector.push_back(static_cast<UInt>(rest));
		}

		while ((*m_vector.rbegin()) == 0)
		{
			m_vector.pop_back();
		}
	}
}

BigInteger& BigInteger::unsigned_sum(const BigInteger& i_big)
{
	if (!i_big.m_vector.empty())
	{
		auto i_it = i_big.m_vector.begin();
		auto m_it = m_vector.begin();
		const auto i_end = i_big.m_vector.end();
		const auto m_end = m_vector.end();

		UInt64 p_result = 0;

		while (m_it != m_end)
		{
			p_result += (*m_it);
			if (i_it != i_end)
			{
				p_result += (*i_it++);
			}
			if (p_result > MAXVALUE)
			{
				(*m_it++) = static_cast<UInt>(p_result - BASE);
				p_result = 1;
			}
			else
			{
				(*m_it++) = static_cast<UInt>(p_result);
				p_result = 0;
			}
		}

		while (i_it != i_end)
		{
			m_vector.push_back(static_cast<UInt>((*i_it++) + p_result));
			p_result = 0;
		}

		if (p_result)
		{
			m_vector.push_back(static_cast<UInt>(p_result));
		}
	}
	return *this;
}

BigInteger& BigInteger::unsigned_subtract(const BigInteger& i_big)
{

	UInt	rest = 0;
	UIntVec p_array;
	auto second_it = i_big.m_vector.begin();
	auto second_end = i_big.m_vector.end();
	UIntVecConstIterator	first_it = m_vector.begin();
	UIntVecConstIterator	first_end = m_vector.end();

	if ((*this) < i_big)
	{
		//swap operands:always major - minor
		second_it = m_vector.begin();
		second_end = m_vector.end();

		first_it = i_big.get_vector().begin();
		first_end = i_big.get_vector().end();
	}

	if (!i_big.m_vector.empty())
	{
		while (first_it != first_end || second_it != second_end || rest != 0)
		{
			UInt64 p_result;
			UInt64 first = 0;
			UInt64 second = 0;

			if (first_it != first_end)
			{
				first = (*first_it++);
				first -= rest;
			}

			if (second_it != second_end)
			{
				second = (*second_it++);
			}

			if (first < second)
			{
				p_result = first + BASE - second;
				rest = 1;
			}
			else
			{
				p_result = first - second;
				rest = 0;
			}

			p_array.push_back(static_cast<UInt>(p_result));
		}

		m_vector = p_array;

		if (*this == 0)
			m_sign = POSITIVE;
	}

	return *this;

}

void BigInteger::CheckZeroVal()
{
	if (m_vector.empty() || (m_vector.size() == 1 && m_vector[0] == 0))
	{
		m_vector.clear();
		m_sign = POSITIVE;
	}
}

BigInteger& BigInteger::operator+=(const BigInteger& i_big)
{
	if (!i_big.m_vector.empty())
	{
		if (m_vector.empty())
		{
			m_vector = i_big.m_vector;
			m_sign = i_big.m_sign;
		}
		else if (m_sign != i_big.m_sign)
		{
			if (i_big > (*this)) m_sign = i_big.m_sign;
			unsigned_subtract(i_big);
		
		}
		else 
		{
			unsigned_sum(i_big);
		}
	}

	CheckZeroVal();

	return *this;
}

BigInteger& BigInteger::operator-=(const BigInteger& i_big)
{
	if (!i_big.m_vector.empty())
	{
		if (m_vector.empty())
		{
			m_vector = i_big.m_vector;
			m_sign = (i_big.m_sign == POSITIVE) ? NEGATIVE : POSITIVE;
			return *this;
		}

		//i_big.m_sign = !i_big.m_sign;

		if (m_sign == i_big.m_sign)
		{
			if (i_big > (*this))
			{
				i_big.m_sign == POSITIVE ? m_sign = NEGATIVE : m_sign = POSITIVE;
			}
			unsigned_subtract(i_big);
			return *this;
		}

		unsigned_sum(i_big);
	}

	CheckZeroVal();

	return *this;

}

BigInteger& BigInteger::operator+=(UInt number)
{
	this->operator+=(BigInteger(number));
	return *this;
}

BigInteger& BigInteger::operator-=(UInt number)
{
	this->operator-=(BigInteger(number));
	return *this;
}

BigInteger& BigInteger::operator+=(int number)
{
	this->operator+=(BigInteger(number));
	return *this;
}

BigInteger& BigInteger::operator-=(int number)
{
	this->operator-=(BigInteger(number));
	return *this;
}

BigInteger BigInteger::pow(const UInt i_power)
{
	if (i_power == 0)
	{
		m_vector.clear();
		m_vector.push_back(1);
		m_sign = POSITIVE;
		return *this;
	}

	BigInteger part_result(1);
	if (i_power != 1)
	{
		UInt pow = i_power;
		m_vector.reserve(m_vector.size()*pow);
		part_result.m_vector.reserve(m_vector.size()*pow);
		while (pow)
		{
			if (pow & 1)
			{
				part_result *= (*this);
				pow--;
			}
			else
			{
				auto this_copy(*this);
				this_copy *= (*this);
				*this = this_copy;
				pow >>= 1;
			}
		}
		(*this) = part_result;
	}
	return *this;
}

BigInteger BigInteger::pow(const BigInteger& i_power)
{
	if (i_power == 0)
	{
		m_vector.clear();
		m_vector.push_back(1);
		m_sign = POSITIVE;
		return *this;
	}

	if (i_power.m_sign == NEGATIVE)
	{
		std::cout << "Sorry but negative power is not supported" << std::endl;
		return *this;
	}

	BigInteger pow(i_power);
	BigInteger part_result(1);
	if (i_power != 1)
	{
		while (pow != 0)
		{
			if ((*pow.m_vector.begin()) & 1)
			{
				part_result *= (*this);
				--pow;
			}
			else
			{
				(*this) *= (*this);
				pow >>= 1;
			}
		}
		(*this) = part_result;
	}
	return *this;
}

BigInteger& BigInteger::operator*= (const UInt i_mul)
{
	auto it = m_vector.begin();
	const auto end = m_vector.end();
	UInt64 carry = 0, res = 0;
	for (; it != end; ++it)
	{
		while ((*it) == 0 && res == 0)
		{
			++it;
		}

		res = (*it);
		res *= i_mul;
		res += carry;
		if (res < BASE)
		{
			(*it) = static_cast<UInt>(res);
			carry = 0;
		}
		else
		{
			(*it) = static_cast<UInt>(res % BASE);
			carry = res / BASE;
		}
	}
	if (carry)
	{
		m_vector.push_back(static_cast<UInt>(carry));
	}
	
	CheckZeroVal();

	return *this;
}

BigInteger& BigInteger::operator<<=(int number)
{
	return (number >= 0) ? this->operator<<=(static_cast<UInt>(number)) : this->operator>>=(static_cast<UInt>(number * -1));
}

BigInteger& BigInteger::operator>>=(int number)
{
	return (number >= 0) ? this->operator>>=(static_cast<UInt>(number)) : this->operator<<=(static_cast<UInt>(number * -1));
}

BigInteger& BigInteger::operator/=(int i_div)
{
	if (i_div >= 0)
	{
		return this->operator/=(static_cast<UInt>(i_div));
	}
	(this->operator/=(static_cast<UInt>(-1 * i_div)));
	*this *= -1;
	return *this;
}

BigInteger& BigInteger::operator*=(int i_mul)
{
	if (i_mul >= 0)
	{
		return this->operator*=(static_cast<UInt>(i_mul));
	}
	(this->operator*=(static_cast<UInt>(-1 * i_mul)));
	*this *= -1;
	return *this;
}

BigInteger& BigInteger::operator*=(const BigInteger& i_mul)
{
	//column mul:
	//-> 22 * 123 = 22*100*1 + 22*10*2 + 22*3*1
	//create n bigint(clone of this) with the right number of 0 in front and multiply it by the "digit"
	//result = sum of all bigints
	if (i_mul == 0)
	{
		m_vector.resize(0);
		m_sign = POSITIVE;
		return *this;
	}

	if (i_mul == 1)
	{
		return *this;
	}

	if ((*this) == 1)
	{
		(*this) = i_mul;
		return *this;
	}

	(i_mul.m_sign == m_sign) ? m_sign = POSITIVE : m_sign = NEGATIVE;

	auto clone_vec = m_vector; //clone of (*this) vector
	auto i_mul_it = i_mul.m_vector.begin();
	const auto i_mul_end = i_mul.m_vector.end();

	BigInteger big_int;	//result
	big_int.m_sign = m_sign;
	m_vector.resize(0);

	for (UInt i = 0; i_mul_it != i_mul_end; ++i_mul_it, ++i)
	{
		if (*i_mul_it)
		{
			big_int.m_vector.clear();
			big_int.m_vector.resize(i, 0);
			big_int.m_vector.insert(big_int.m_vector.end(), clone_vec.begin(), clone_vec.end());
			if ((*i_mul_it) != 1)
			{
				big_int *= (*i_mul_it);
			}
			(*this) += big_int;
		}
	}
	CheckZeroVal();
	return *this;
}

BigInteger& BigInteger::operator/=(const BigInteger& i_div)
{
	if (i_div == 0)
	{
		std::cout << "Illegal operation" << std::endl;
		return *this;
	}

	(i_div.m_sign == m_sign) ? m_sign = POSITIVE : m_sign = NEGATIVE;

	if (unsigned_equal(i_div, *this))
	{
		//sign previous set
		m_vector.clear();
		m_vector.push_back(1);
		return *this;
	}

	if (i_div.m_vector.size() == 1)
	{
		//i_div is simply an integer-> call specific func
		(*this) /= (*i_div.m_vector.begin());
		return *this;
	}

	BigInteger result;				//final result
	BigInteger clone_div;			//empty bigint with right result size

	UInt exp_counter = 0, exp_diff = m_vector.size() - i_div.m_vector.size();  //diff polynomial exp

	//create empty bigint with correct size: es  X^5 / X^3 = X^2 
	if (exp_diff == 0)
	{
		++exp_diff;
	}

	result.m_vector.resize(exp_diff + 1, 0);
	clone_div.m_vector.resize(exp_diff + 1, 0);

	auto res_it = result.m_vector.rbegin();
	const auto div_it = i_div.m_vector.rbegin();
	while ((*this) >= i_div)
	{
		exp_counter = 0;
		auto partial_res = i_div;
		const auto m_it = m_vector.rbegin();
		const auto clone_it = clone_div.m_vector.rbegin();

		//maybe res <<<< 1
		//solution: res * 10^n until res has integer part > 1
		//-> needs to divide partial_res(and final result too) for the same quantity
		double res = (*m_it);
		res /= (*div_it);							//divide max grade terms of polys

		//res and m_it must have at least same number of int digits
		if (res < (*m_it))							//if havent (at least)same number of int digit
		{
			double delta = (*m_it) - res;			//check approx error: continue if delta < 1
			while (delta > 1)
			{
				res *= 10;
				exp_counter++;
				delta = (*m_it) - res;
			}
		}

		(*clone_it) = static_cast<UInt>(res);
		//prepare partial_res for test
		partial_res *= clone_div;					//p_res = quotient * partial_result

		for (UInt i = 0; i != exp_counter; ++i)			//recover correct value of partial_res
		{
			partial_res /= 10;
		}

		//res is a result overrating -> 
		//so if partial_res > this we need to decrease res until this >= partial_res (to remove the maxgrade term)

		if (partial_res > (*this))
		{
			do										//recalc partial_res until this >= partial_res
			{
				res--;
				(*clone_it) = static_cast<UInt>(res);
				partial_res = i_div;
				partial_res *= clone_div;
				for (UInt i = 0; i != exp_counter; i++)
				{
					partial_res /= 10;
				}
			} while (partial_res > (*this));
		}

		(*this) -= partial_res;						//this - p_res = rest : at least the max grade term must be 0

		(*res_it) = static_cast<UInt>((*res_it) /**10*/ + res);

		while ((*m_vector.rbegin()) == 0 && m_vector.size() > 1)
		{
			//remove 0 from m_vector
			//and go to analyze next element
			m_vector.pop_back();
			if (res_it != result.m_vector.rend())
			{
				++res_it;
			}
			if (clone_div.m_vector.size() > 1)
			{
				clone_div.m_vector.pop_back();		//remove first elem from clone -> max_grade_clone = max_grade_clone - 1
			}
		}
	}
	//final exp_counter fix if needed
	for (UInt i = 0; i != exp_counter; ++i)
	{
		result /= 10;
	}

	m_vector = result.m_vector;
	CheckZeroVal();

	return *this;
}

BigInteger& BigInteger::operator/=(const UInt i_div)
{
	int_division(i_div);
	return *this;
}

UInt BigInteger::int_division(const UInt i_div)
{
	UInt64 rest = 0;
	if (i_div > 1)
	{
	
		auto it = m_vector.rbegin();
		const auto end = m_vector.rend();
		for (; it != end; ++it)
		{
			const UInt64 num = (*it);
			const auto p_result = (num + rest * BASE) / i_div;
			(*it) = static_cast<UInt>(p_result);
			rest = (num + rest * BASE) % i_div;
		}

		while ((*m_vector.rbegin()) == 0 && m_vector.size() > 1)
		{
			m_vector.pop_back();
		}
	}
	CheckZeroVal();
	return static_cast<UInt>(rest);
}

BigInteger& BigInteger::operator<<=(const UInt number)
{
	UInt old_carry = 0, new_carry = 0;
	for (UInt i = 0; i != number; i++)
	{
		auto it = m_vector.begin();
		const auto v_end = m_vector.end();
		for (; it != v_end; ++it)
		{
			UInt value = (*it);
			new_carry = 0;
			if (value > CARRY_THRESHOLD)
			{
				new_carry = 1;
			}

			value <<= 1;
			(*it) = value | old_carry;
			old_carry = new_carry;
		}

		if (new_carry == 1)
			m_vector.push_back(new_carry);
	}
	return *this;
}

BigInteger& BigInteger::operator>>=(const UInt number)
{
	UInt old_carry = 0, new_carry = 0;
	for (UInt i = 0; i != number; i++)
	{
		auto it = m_vector.rbegin();
		const auto v_end = m_vector.rend();
		for (; it != v_end; ++it)
		{
			UInt value = (*it);
			new_carry = 0;
			if (value & 1)
			{
				new_carry = 0x10000000;
			}

			value >>= 1;
			(*it) = value | old_carry;
			old_carry = new_carry;
		}

		if (new_carry == 1)
			m_vector.push_back(new_carry);
	}
	return *this;
}


