#pragma once

#include <compare>
#include <cstdint>

namespace PhySim {
	class Rational final {
	private:
		std::int64_t m_Numerator = 0;
		std::int64_t m_Denominator = 1;

	public:
		Rational() noexcept = default;
		Rational(std::int64_t numerator) noexcept;
		Rational(std::int64_t numerator, std::int64_t denominator) noexcept;
		Rational(const Rational& rational) noexcept;
		~Rational() = default;

	public:
		Rational& operator=(const Rational& rational) noexcept;
		std::strong_ordering operator<=>(const Rational& rational) const noexcept;
		Rational operator+(const Rational& rational) const noexcept;
		Rational operator-(const Rational& rational) const noexcept;
		Rational operator*(const Rational& rational) const noexcept;
		Rational operator/(const Rational& rational) const noexcept;
		Rational& operator+=(const Rational& rational) noexcept;
		Rational& operator-=(const Rational& rational) noexcept;
		Rational& operator*=(const Rational& rational) noexcept;
		Rational& operator/=(const Rational& rational) noexcept;
		Rational operator+() const noexcept;
		Rational operator-() const noexcept;
		explicit operator double() const noexcept;

	public:
		std::int64_t GetNumerator() const noexcept;
		std::int64_t GetDenominator() const noexcept;

	private:
		void Normalize() noexcept;
	};
}