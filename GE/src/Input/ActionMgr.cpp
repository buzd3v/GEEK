#include "ActionMgr.h"


template<typename T, typename... args>
inline void Geek::ActionMgr::Connect(std::string actionName, Callback<T(args...)> callback)
{

}

void Geek::ActionMgr::Disconnect(std::string actionName)
{
}
