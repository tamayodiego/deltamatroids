#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include "DeltaMatroide.h"
#include "ModuloMGEV.h"
#include "ModuloMER.h"
#include "ModuloDepuracion.h"
#include "LectorEntrada.h"
#include "ExportadorSalida.h"
#include "Ejecucion.h"
#include "Estructuras.h"
#include "LectorParametros.h"
#include "Definiciones.h"


void construyeDms(MatrixR& M,std::vector<unsigned>& V,unsigned indx,unsigned n,std::vector<MatrixR>& DMs){
    if(indx==n){
      //  std::cout << "Se entro\n";
        MatrixR mat(M);
        unsigned cont=0;
        for(unsigned i=1;i<3;++i){
            for(unsigned j=3;j<7;++j){
                mat[i][j]=V[cont];
                mat[j][i]=V[cont];
                cont++;
            }
        }
        DMs.push_back(mat);     
      
    }
    else{
        V[indx]=0;
        construyeDms(M,V,indx+1,n,DMs);
        V[indx]=1;
        construyeDms(M,V,indx+1,n,DMs);
    }
}
int main(int argc, char *argv[])
{
    std::cout << "Comenzando Programa...\n";
    MatrixR matrizBase={
        {0,1,1,    1,0,0,1},

        {1,0,1,    0,0,0,0},
        {1,1,0,    0,0,0,0},

        {1,  0,0,  0,1,0,0},
        {0,  0,0,  1,0,1,0},
        {0,  0,0,  0,1,0,1},
        {1,  0,0,  0,0,1,0}
    };

    std::vector<unsigned> vectorR(8,0);

    std::vector<MatrixR> matr;

    construyeDms(matrizBase,vectorR,0,vectorR.size(),matr);

    std::cout << "numero de delta-matroides generados: "<< matr.size() <<"\n";
    std::vector<DeltaMatroide> lista;
    unsigned cont=1;
    // Cuerpo GF(campo) sobre el que se decide la factibilidad de los subconjuntos:
    // 2 = binario (GF2), 3 = ternario (GF3).
    unsigned campo=2;
    for(MatrixR M:matr) {
       // std::cout << "iteracion\n";
        std::string n="D"+std::to_string(cont);
        cont++;
        DeltaMatroide D(n,std::make_shared<MatrixR>(M),6,false,campo);
        //std::cout << "Despues de asignacion\n";
        std::cout << D << "\n";
        for(unsigned i=0;i<D.matriz->size();++i){
            for(unsigned j=0;j<D.matriz->size();++j){
                std::cout << (*D.matriz)[i][j] << " ";
            }
            std::cout << "\n";
        }
        lista.push_back(D);
        //std::cout << "Despues de copia\n";
    }
    ModuloDepuracion dep;
    std::vector<DeltaMatroide*> listafinal;
    std::cout << "Depurando...\n";
    dep.depuraDeltaEquivalente(1,lista,listafinal);

    std::cout << "\n\nDepurando delta-matroides deltaequivalentes e isomorfos......\n";
    for(DeltaMatroide* D: listafinal){
        std::cout << D->familia_subconjuntos.size()<<" "<< D->huella << " " << *D << "\n";

    } 
    return 0;
    std::cout << "tamaño de la lista: "<< listafinal.size()<<"\nQuitando DMs con anchura menor que 3\n";
   
    std::vector<DeltaMatroide*> listafinal2;
    for(DeltaMatroide* D: listafinal){
       std::vector<DeltaMatroide> claseEquivalencia;
       D->GetClaseEquivalencia(claseEquivalencia,false);
       //std::cout << D->conjuntoBase.size() << "\n";
       bool anchuraCumple=true;
      
        for(DeltaMatroide& Dm:claseEquivalencia){
            Dm.OrdenaFamilia();
            Dm.CalculaAnchura();
            std::cout <<"\t"<< Dm.anchura << " " << Dm <<"\n";
            if(Dm.anchura < 3 ){
                anchuraCumple=false;
                std::cout << Dm.nombre << " no cumple condicion de anchura... terminando subrutina\n";
                break;
            }
        }
        if(anchuraCumple) listafinal2.push_back(D);
        std::cout << "\n";
    } 


    std::cout << "resultados finales: \n";

      for(DeltaMatroide* D: listafinal2){
        std::cout << *D << "\n";
        for(unsigned i=0;i<D->matriz->size();++i){
            for(unsigned j=0;j<D->matriz->size();++j){
                std::cout << (*D->matriz)[i][j] << " ";
            } 
            std::cout << "\n";
        }
        std::cout << "\n";

    } 

    std::cout << "Total: "<< listafinal2.size() <<"\n";



    return 0;

   
}
