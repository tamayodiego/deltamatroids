#include "ModuloMEI.h"

ModuloMEI::ModuloMEI()
{
}

void ModuloMEI::EjecutaDepuracion(std::vector<DeltaMatroide *> &lista_obstrucciones, std::vector<DeltaMatroide *> &lista_e)
{

    /// depuracion isomorfos
    std::vector<DeltaMatroide *> result(lista_e);
    while (result.size())
    {
        DeltaMatroide *D = result.back();
        result.pop_back();
        if (!buscaDMEnLista(*D, result))
            lista_obstrucciones.push_back(D);
    }

    /// depuracion delta-Equivalentes
    result.assign(lista_obstrucciones.begin(), lista_obstrucciones.end());
    lista_obstrucciones.erase(lista_obstrucciones.begin(), lista_obstrucciones.end());

    for (int i = 0; i < result.size(); ++i)
    {
        if (result[i] != nullptr)
        {
            DeltaMatroide *D = result[i];

            result[i] = nullptr;
            for (int j = 0; j < D->familia_subconjuntos.size(); ++j)
            {
                DeltaMatroide aux(*D);
                aux.Twsting(D->familia_subconjuntos[j]);

                for (int k = 0; k < result.size(); ++k)
                {
                    if (result[k] != nullptr)
                    {

                        if (aux.IsIsomorfo(*(result[k])))
                        {
                            result[k] = nullptr;
                        }
                    }
                }
            }
            result[i] = D;
        }
    }
    for (unsigned i = 0; i < result.size(); ++i)
        if (result[i] != nullptr)
            lista_obstrucciones.push_back(result[i]);
    for (DeltaMatroide *D : lista_obstrucciones)
        D->OrdenaFamilia();
}
bool ModuloMEI::BuscaDeltaEquivalentes(DeltaMatroide &F, unsigned i, std::vector<DeltaMatroide *> &lista)
{

    DeltaMatroide D(F);

    D.Twsting(F.familia_subconjuntos[i]);
    return buscaDMEnLista(D, lista);
}
void ModuloMEI::OrdenaDeltaMatroides(std::vector<DeltaMatroide> &lista)
{
    for (DeltaMatroide &D : lista)
        D.OrdenaFamilia();
}

bool ModuloMEI::buscaDMEnLista(DeltaMatroide &D, std::vector<DeltaMatroide *> &lista_entrada)
{
    for (DeltaMatroide *D_en_lista : lista_entrada)
    {

        bool res = D.IsIsomorfo(*D_en_lista);

        if (res)
            return true;
    }
    return false;
}

void ModuloMEI::ImprimeListaObstrucciones(std::vector<DeltaMatroide> &lista)
{
    OrdenaDeltaMatroides(lista);
    ImprimeLista(lista);
}