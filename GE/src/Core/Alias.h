#pragma once

#include <cstdint>
#include <functional>

namespace Geek
{
	using u16 = uint16_t;
	using u32 = uint32_t;
	using u64 = uint64_t;

	using i16 = int16_t;
	using i32 = int32_t;
	using i64 = int64_t;

	template <typename... args>
	using Callback = std::function<void(args...)>;

}