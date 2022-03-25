//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <unordered_map>
#include <Message.hpp>
#include <MessageObserver.hpp>
#include <memory>

namespace engine
{
    /// <summary>
    /// Encargado de hacer llegar los mensajes a los observadores de los mensajes
    /// </summary>
    class MessageDispatcher
    {
        static std::unordered_map<std::string, std::list<MessageObserver*>>observers;
    public:

        MessageDispatcher() = default;

        /// <summary>
        /// Envia un mensaje a toas las clases que lo esten escuchando
        /// </summary>
        /// <param name="message">Mensaje a eniar</param>
        static void Send(const Message& message)
        {
            auto targets = observers.find(message.target);
            if (targets != observers.end())
            {
                for (auto target : targets->second)
                {
                    target->handle(message);
                }
            }
        }

        /// <summary>
        /// Anade un observador de mensajes
        /// </summary>
        /// <param name="targetName">El observador</param>
        /// <param name="observer">Nombre bajo el que recibe mensajes el observador</param>
        static void AddObserver(const std::string & targetName, MessageObserver * observer)
        {
            auto currentObserver = observers.find(targetName);
            if (currentObserver != observers.end())
            {
                currentObserver->second.push_back(observer);
            }
            else
            {
                observers.emplace(std::make_pair(targetName, std::list<MessageObserver*>{observer}));
            }
        }
    };
}