#pragma once

#include <string>

namespace PhySim {
	class SymbolInfo final {
	private:
		std::u8string m_String;

	public:
		SymbolInfo() noexcept = default;
		SymbolInfo(const std::u8string& string);
		SymbolInfo(std::u8string&& string) noexcept;
		SymbolInfo(const SymbolInfo&) = delete;
		~SymbolInfo() = default;

	public:
		SymbolInfo& operator=(const SymbolInfo&) = delete;

	public:
		std::u8string GetString() const noexcept;
		void SetString(const std::u8string& string);
		void SetString(std::u8string&& string) noexcept;
	};

	using Symbol = SymbolInfo*;
}