#pragma once

#include <sid.h>


class StringHash
{
public:
	std::size_t operator()(const std::string& key) const
	{
		return SID_VAL(key.c_str());
	}
};

class StringEqual
{
public:
	bool operator()(const std::string& lhs, const std::string& rhs) const
	{
		return SID_VAL(lhs.c_str()) == SID_VAL(rhs.c_str());
	}
};

template<typename key, typename value>
class KeyPairHash
{
public:
	std::size_t operator()(const std::pair<key, value>& Key) const {
		key t = Key.first;
		return t;
	}
};

template<typename key, typename value>
class KeyPairEqual
{
public:
	bool operator()(const std::pair<key, value>& lhs, const std::pair<key, value>& rhs) const {
		return lhs.first == rhs.first;
	}
};