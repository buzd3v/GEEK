#pragma once
#include <unordered_map>
#include "Alias.h"
namespace Geek
{
	using u64 = uint64_t;

	template <typename... args>
	class Delegate
	{
		std::unordered_map<u64, Callback<args...>> m_callbackList;
		static u64 m_key = 0;

	public:
		Delegate() = default;
		Delegate(const Delegate&) = delete;
		Delegate(Delegate&&) = default;
		Delegate& operator=(const Delegate&) = delete;
		Delegate& operator=(Delegate&&) = default;
		~Delegate() = default;

		u64 Subscribe(Callback<args ...> callback);
		void Unsubscribe(u64 key);
		void Invoke();

		void Clear();
	};
	template<typename ...args>
	inline u64 Delegate<args...>::Subscribe(Callback<args...> callback)
	{
		m_callbackList.insert({ m_key, callback });
		return m_key++;
	}
	template<typename ...args>
	inline void Delegate<args...>::Unsubscribe(u64 key)
	{
		if (auto iter = m_callbackList.find(key) != m_callbackList.end())
		{
			m_callbackList.erase(iter);
		}
	}
	template<typename ...args>
	inline void Delegate<args...>::Invoke()
	{
		for (auto& callback : m_callbackList)
		{
			callback.second(args...);
		}
	}
	template<typename ...args>
	inline void Delegate<args...>::Clear()
	{
		m_callbackList.clear();
	}
}