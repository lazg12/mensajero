#ifndef ISOCKET_H
#define ISOCKET_H

#include <string>

/**
 * @file ISocket.h
 * @brief Interfaz abstracta para la gestión de sockets.
 * @details Esta clase define el contrato para que el Mensajero funcione
 * tanto en Windows como en Linux sin cambiar el código principal.
 */
class ISocket {
public:
    virtual ~ISocket() {}

    /// @brief Inicializa los componentes de red del sistema.
    /// @return true si el sistema está listo para comunicar.
    virtual bool iniciar() = 0;

    /// @brief Envía un mensaje de texto a través del socket.
    /// @param datos Cadena de texto a enviar.
    virtual bool enviar(const std::string& datos) = 0;
    
    /// @brief Cierra la conexión de forma segura.
    virtual void detener() = 0;
};

#endif