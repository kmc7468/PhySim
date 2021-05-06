#include <PhySim/Numeric.hpp>

#include <cassert>
#include <numeric>

namespace PhySim {
	Rational::Rational(std::int64_t numerator) noexcept
		: m_Numerator(numerator) {}
	Rational::Rational(std::int64_t numerator, std::int64_t denominator) noexcept
		: m_Numerator(numerator), m_Denominator(denominator) {
		assert(denominator != 0);

		Normalize();
	}
	Rational::Rational(const Rational& rational) noexcept
		: m_Numerator(rational.m_Numerator), m_Denominator(rational.m_Denominator) {}

	Rational& Rational::operator=(const Rational& rational) noexcept {
		m_Numerator = rational.m_Numerator;
		m_Denominator = rational.m_Denominator;
		return *this;
	}
	std::strong_ordering Rational::operator<=>(const Rational& rational) const noexcept {
		const std::int64_t lcm = std::lcm(m_Denominator, rational.m_Denominator);
		return m_Numerator * (lcm / m_Denominator) <=> rational.m_Numerator * (lcm / rational.m_Denominator);
	}
	Rational Rational::operator+(const Rational& rational) const noexcept {
		const std::int64_t lcm = std::lcm(m_Denominator, rational.m_Denominator);
		return { m_Numerator * (lcm / m_Denominator) + rational.m_Numerator * (lcm / rational.m_Denominator), lcm };
	}
	Rational Rational::operator-(const Rational& rational) const noexcept {
		const std::int64_t lcm = std::lcm(m_Denominator, rational.m_Denominator);
		return { m_Numerator * (lcm / m_Denominator) - rational.m_Numerator * (lcm / rational.m_Denominator), lcm };
	}
	Rational Rational::operator*(const Rational& rational) const noexcept {
		return +*this *= rational;
	}
	Rational Rational::operator/(const Rational& rational) const noexcept {
		return +*this /= rational;
	}
	Rational& Rational::operator+=(const Rational& rational) noexcept {
		return *this = *this + rational;
	}
	Rational& Rational::operator-=(const Rational& rational) noexcept {
		return *this = *this - rational;
	}
	Rational& Rational::operator*=(const Rational& rational) noexcept {
		m_Numerator *= rational.m_Numerator;
		m_Denominator *= rational.m_Denominator;

		Normalize();
		return *this;
	}
	Rational& Rational::operator/=(const Rational& rational) noexcept {
		m_Numerator *= rational.m_Denominator;
		m_Denominator *= rational.m_Numerator;

		Normalize();
		return *this;
	}
	Rational Rational::operator+() const noexcept {
		return *this;
	}
	Rational Rational::operator-() const noexcept {
		return { -m_Numerator, m_Denominator };
	}
	Rational::operator double() const noexcept {
		return static_cast<double>(m_Numerator) / m_Denominator;
	}

	std::int64_t Rational::GetNumerator() const noexcept {
		return m_Numerator;
	}
	std::int64_t Rational::GetDenominator() const noexcept {
		return m_Denominator;
	}

	void Rational::Normalize() noexcept {
		const std::int64_t gcd = std::gcd(m_Numerator, m_Denominator);
		m_Numerator /= gcd;
		m_Denominator /= gcd;

		if (m_Denominator < 0) {
			m_Numerator = -m_Numerator;
			m_Denominator = -m_Denominator;
		}
	}
}