//Codigo propiedad de Aitor Izurrategui

#pragma once

#include <Message.hpp>

namespace engine
{
    /// <summary>
    /// Clase de la que se debe derivar e implementar para poder escuchar mensajes
    /// </summary>
    class MessageObserver
    {
    public:
        /// <summary>
        /// Implementar para hacer algo con un mensaje cuando se recibe
        /// </summary>
        /// <param name="">Mensaje a manejar</param>
        virtual void handle(const Message &) {}
    };
}