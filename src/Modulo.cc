#include "Modulo.h"

Modulo::Modulo()
{
}


bool Modulo::BuscaIsomorfos(std::vector<DeltaMatroide>& lista,DeltaMatroide& D){
        for(DeltaMatroide& F:lista){

            bool des=D.IsIsomorfo(F);
         
            if(des) return true;
        }
        return false;
}

bool Modulo::BuscaIsomorfos(std::vector<DeltaMatroide*>& lista,DeltaMatroide& D){
        for(DeltaMatroide* F:lista){

            bool des=D.IsIsomorfo(*F);
            if(des) return true;
        }
        return false;
}


bool Modulo::BuscaDeltaEquivalentes(std::vector<DeltaMatroide>& lista,DeltaMatroide& D){
        for(DeltaMatroide& F:lista){

            bool des=D.IsDeltaEquivalente(F);
         
            if(des) return true;
        }
        return false;
}

bool Modulo::BuscaDeltaEquivalentes(std::vector<DeltaMatroide*>& lista,DeltaMatroide& D){
        for(DeltaMatroide* F:lista){
            bool des=D.IsDeltaEquivalente(*F);
            if(des) return true;
        }
        return false;
}


bool Modulo::HuellaEnLista(Huella &h, std::vector<Huella> lista)
{
    for (Huella &enL : lista)
        if (h == enL)
            return true;
    return false;
}

void Modulo::obtenBloquesHuellas(std::vector<Huella> &lista,
                                 std::vector<DeltaMatroide> &lista_borrado)
{
    lista_borrado[0].ConstruyeHuella();
    lista.push_back(lista_borrado[0].huella);
    for (DeltaMatroide &D : lista_borrado)
    {
        D.ConstruyeHuella();
        if (!HuellaEnLista(D.huella, lista))
            lista.push_back(D.huella);
    }
}
void Modulo::obtenBloquesHuellas(std::vector<Huella> &lista,
                                 std::vector<DeltaMatroide *> &lista_borrado)
{
    lista_borrado[0]->ConstruyeHuella();
    lista.push_back(lista_borrado[0]->huella);
    for (DeltaMatroide *D : lista_borrado)
    {
        D->ConstruyeHuella();
        if (!HuellaEnLista(D->huella, lista))
            lista.push_back(D->huella);
    }
}
void Modulo::ImprimeLista(std::vector<DeltaMatroide> &lista)
{
    std::vector<Huella> lista_huellas;
    obtenBloquesHuellas(lista_huellas, lista);

    for (unsigned i = 0; i < lista_huellas.size(); i++)
    {
        std::cout << "Bloque " << (i + 1) << ": " << lista_huellas[i] << "\n";
        for (DeltaMatroide &D : lista)
        {
            if (lista_huellas[i] == D.huella)
            {
                D.ToString();
            }
        }
    }
}
void Modulo::ImprimeLista(std::vector<DeltaMatroide *> &lista)
{
    for(DeltaMatroide *D:lista){
        std::cout << *D <<"\n";
        /*
        if(D->matriz != nullptr){
            std::cout << "[" ;
            for(unsigned k=0;k < D->matriz->size();++k){
                std::cout << D->matriz->at(D->matriz->size()-1)[k]<<",";
            }
            std::cout << "]\n" ;
            for(unsigned i=0;i< D->matriz->size();++i){
                for(unsigned j=0;j< D->matriz->at(i).size();++j) 
                    std::cout << D->matriz->at(i)[j] << " ";
                std::cout << "\n";
            }
        }
        */


    }
        

    
}
