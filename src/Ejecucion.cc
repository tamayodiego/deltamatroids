#include "Ejecucion.h"

Ejecucion::Ejecucion(std::vector<DeltaMatroide> *L1) : lista_de_ternarios(L1)
{
}

void Ejecucion::ejecuta(bool modoEjecucion, bool minimalidad,DeltaMatroide& D, unsigned hilos)
{
    unsigned h;
    if(modoEjecucion) h=hilos;
    else h=1;

   // std::cout <<"antes de Etapa 1\n";
    /// Etapa 1 Generar Extensiones
    ModuloMGEV generador(D.GetV());
    std::vector<DeltaMatroide*> extensiones;
    generador.GeneraListaBorrado(h,D,extensiones);
    std::cout << "extensiones Generadas: "<<extensiones.size()<<"\n";
   /*  for(DeltaMatroide* D:extensiones){
        std::cout << *D <<"\n";
    }*/
  //  std::cout <<"antes de etapa 2\n";
    /// Etapa 2 Generar Extensiones Ternarias
    ModuloMER generadorTer;
    std::vector<DeltaMatroide> extensionesTernarias;
    generadorTer.GeneraExtensionesTernarias(h,*D.matriz,extensionesTernarias);
    std::cout << "extensiones ternariasGeneradas: "<<extensionesTernarias.size()<<"\n";
    /*for(DeltaMatroide& D:extensionesTernarias){
        std::cout << D <<"\n";
    }*/
   // std::cout <<"tras generacion ternarios\n";
    ModuloDepuracion depurador;
    std::vector<DeltaMatroide*> extensionesTernariasDepuradas;
    depurador.depuraDeltaEquivalente(h,extensionesTernarias,extensionesTernariasDepuradas);
     std::cout << "extensiones ternarias depuradas Generadas: "<<extensionesTernariasDepuradas.size()<<"\n";
    /* for(DeltaMatroide* D:extensionesTernariasDepuradas){
        std::cout << *D <<"\n";
    }*/
   // std::cout <<"antes de etapa 3 isomorfos\n";
    /// Etapa 3 Extensiones - Extensiones ternarias
        // isomorfos
    ModuloOperaciones operaciones;
    std::vector<DeltaMatroide*> extensionesNoTernarias1;
    //std::cout <<"antes de entrar a a-b\n";
    operaciones.listaAmenosB(h,'b',extensiones,extensionesTernariasDepuradas,extensionesNoTernarias1);
   // std::cout <<"antes de etapa 3 deltaEquivalentes\n";
        //DeltaEquivalentes
        
    std::vector<DeltaMatroide*> extensionesNoTernarias2;
    operaciones.listaAmenosB(h,'c',extensionesNoTernarias1,extensionesTernariasDepuradas,extensionesNoTernarias2);
    std::cout << "extensiones no ternarias : "<<extensionesNoTernarias2.size()<<"\n";

    /*for(DeltaMatroide* D:extensionesNoTernarias2){
        std::cout << *D <<"\n";
    }*/

  // Etapa 4 Depuracion de resultados finales
  // std::cout <<"antes de etapa 4\n";
    std::vector<DeltaMatroide*> listaFinal;
    depurador.depuraDeltaEquivalente(h,extensionesNoTernarias2,listaFinal);
   // std::cout <<"antes de resultados\n";
    std::cout << listaFinal.size() <<"\n";






}
