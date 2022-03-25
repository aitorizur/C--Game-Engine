//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <string>

namespace engine
{
    /// <summary>
    /// Clase mensaje que puede ser recibida por cualquier clase derivada de MessageObserver
    /// </summary>
    class Message
    {
    public:

        std::string target;
        std::string action;

        Message(const std::string & givenTarget, const std::string & givenAction)
        {
            target = givenTarget;
            action = givenAction;
        }
    };
}