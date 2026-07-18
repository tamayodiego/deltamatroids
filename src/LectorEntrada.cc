#include "LectorEntrada.h"

void LectorEntrada::ConvierteAFactible(Factible &F, std::string cad)
{
    if (cad.size() == 0)
        return;
    int i = 0, j = 0;
    while (j < cad.size())
    {
        if (cad[j] == ',')
        {
            std::string subInt(cad.substr(i, j - i));
            unsigned a = (unsigned)std::atoi(subInt.c_str());
            F.push_back(a);
            i = j + 1;
        }
        ++j;
    }
    std::string subInt2(cad.substr(i, j - i));
    unsigned b = (unsigned)std::atoi(subInt2.c_str());
    F.push_back(b);
}

bool LectorEntrada::ConstruyeFamilia(std::vector<Factible> &fam, std::string &cadena)
{

    std::size_t pos = cadena.find("=");
    std::string subCadena(cadena.substr(pos + 2));
    subCadena = subCadena.substr(0, subCadena.size() - 1);
    bool flag = false;
    int i = 0;
    int j = 0;
    while (i < subCadena.size())
    {
        if (subCadena[i] == '{')
        {
            if (flag)
            {
                return true;
            }
            else
            {
                flag = true;
                j = i;
            }
        }
        if (subCadena[i] == '}')
        {
            if (flag)
            {
                std::string subFactible(subCadena.substr(j + 1, i - 1 - j));

                Factible F;
                ConvierteAFactible(F, subFactible);
                fam.push_back(F);
                flag = false;
            }
            else
            {
                return true;
            }
        }
        i++;
    }
    if (flag)
    {
        return true;
    }
    return false;
}
void LectorEntrada::ConstruyeNombre(std::string &cadDestino, std::string &cadOrigen)
{
    std::size_t pos = cadOrigen.find("=");
    cadDestino = cadOrigen.substr(0, pos);
}
bool LectorEntrada::LeerArchivoDeTexto(const char nombre_archivo[])
{

    std::ifstream leer(nombre_archivo);
    std::string cadena;
    leer >> cadena;
    int n = std::atoi(cadena.c_str());
    for (int i = 0; i < n; ++i)
    {

        leer >> cadena;
        unsigned V = (unsigned)std::atoi(cadena.c_str());
        leer >> cadena;
        std::vector<Factible> fam;

        if (ConstruyeFamilia(fam, cadena))
        {
            leer.close();
            return false;
        }
        std::string nombre;
        ConstruyeNombre(nombre, cadena);
        auto M = std::make_shared<MatrixR>(V, std::vector<Racional>(V));
        for (int j = 0; j < V; ++j)
            for (int k = 0; k < V; ++k)
            {
                leer >> cadena;
                (*M)[j][k] = std::atoi(cadena.c_str());
            }
        DeltaMatroide D(nombre, fam, V);
        D.matriz = M;

        lista.push_back(D);
    }

    leer.close();
    return true;
}
