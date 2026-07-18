#include "ExportadorSalida.h"

bool ExportadorSalida::EscribirArchivoDeTexto(std::vector<DeltaMatroide> lista, const char nombre_archivo[])
{
    std::ofstream escritor(nombre_archivo);
    if (!escritor)
        return false;
    escritor << lista.size() << "\n";
    for (DeltaMatroide &D : lista)
    {
        escritor << D.matriz->size() << " " << D << "\n";
        for (unsigned i = 0; i < D.matriz->size(); ++i)
        {
            for (unsigned j = 0; j < D.matriz->size(); ++j)
                escritor << (*D.matriz)[i][j] << " ";
            escritor << "\n";
        }
    }
    escritor.close();
    return true;
}