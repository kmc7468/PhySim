#include <PhySim/Expression.hpp>

#include <utility>

namespace PhySim {
	SymbolInfo::SymbolInfo(const std::u8string& string)
		: m_String(string) {}
	SymbolInfo::SymbolInfo(std::u8string&& string) noexcept
		: m_String(std::move(string)) {}

	std::u8string SymbolInfo::GetString() const noexcept {
		return m_String;
	}
	void SymbolInfo::SetString(const std::u8string& string) {
		m_String = string;
	}
	void SymbolInfo::SetString(std::u8string&& string) noexcept {
		m_String = std::move(string);
	}
}