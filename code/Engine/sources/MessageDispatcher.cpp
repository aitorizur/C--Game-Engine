#include <MessageDispatcher.hpp>

namespace engine
{
    std::unordered_map<std::string, std::list<MessageObserver*>> MessageDispatcher::observers;
}