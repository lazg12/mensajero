#ifndef VERSIONADOR_H
#define VERSIONADOR_H

#include <string>

/**
 * @file Versionador.h
 * @brief Clase encargada de la gestión de actualizaciones.
 * @details Compara la versión local del ejecutable con un archivo remoto en GitHub.
 */
class Versionador
{
private:
    // Versión actual del programa (la cambiaremos manualmente en cada release)
    const std::string VERSION_LOCAL = "1.0.0";

    // URL del archivo de texto en tu repo que contiene solo el número de versión (ej: 1.0.1)
    const std::string URL_VERSION_REMOTA = "https://raw.githubusercontent.com/lazg12/mensajero/main/version.txt";

public:
    Versionador() = default;

    /// @brief Obtiene la versión configurada en el código local.
    std::string getVersionLocal() const { return VERSION_LOCAL; }

    /// @brief Verifica si existe una versión más reciente en el servidor.
    /// @return true si la versión remota es diferente a la local.
    bool hayActualizacionDisponible();

    /// @brief Descarga el contenido del archivo de versión desde GitHub.
    /// @return Una cadena con el número de versión (ej: "1.0.1").
    std::string descargarVersionRemota();
};

#endif