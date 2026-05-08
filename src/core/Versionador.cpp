#include "core/Versionador.h"
#include <windows.h>
#include <urlmon.h>
#include <iostream>
#include <fstream>

// Esta línea le dice al compilador de Windows que use la librería de internet
#pragma comment(lib, "urlmon.lib")

std::string Versionador::descargarVersionRemota()
{
    char rutaTemporal[MAX_PATH];

    // 1. Descargamos el archivo de GitHub a una carpeta temporal de Windows
    // Usamos la URL que definimos en el .h
    HRESULT hr = URLDownloadToCacheFileA(NULL, URL_VERSION_REMOTA.c_str(), rutaTemporal, MAX_PATH, 0, NULL);

    if (hr == S_OK)
    {
        // 2. Si la descarga fue exitosa, leemos el archivo temporal
        std::ifstream archivo(rutaTemporal);
        std::string versionRemota;
        if (archivo >> versionRemota)
        {
            return versionRemota;
        }
    }

    // Si algo falla, devolvemos la local para que no salga el aviso de actualizar
    return VERSION_LOCAL;
}

bool Versionador::hayActualizacionDisponible()
{
    std::string remota = descargarVersionRemota();

    // Comparamos las cadenas de texto
    // Si en GitHub dice "1.0.1" y aquí tenemos "1.0.0", devolverá true
    return (remota != VERSION_LOCAL);
}