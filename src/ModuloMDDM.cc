#include "ModuloMDDM.h"

bool ModuloMDDM::BuscaFactibleEn(Factible& difEnF,std::vector<Factible>& D){
    
    for (std::vector<unsigned> Fi : D) {
        /// solo en factibles del mismo tamaño
        if(Fi.size()==difEnF.size()){
          //ordenamos los factibles
          bool seEncontro=true;
          if(Fi.size()==0) return true;
          std::sort(Fi.begin(),Fi.end());
          std::sort(difEnF.begin(),difEnF.end());
          //buscamos en cada indice debe de corresponder 
            for (int i = 0; i < Fi.size(); i++) {
                if(Fi[i]!=difEnF[i]) {
                    seEncontro=false;
                    break;
                }
            }
            /// si ninguno rompio el ciclo significa que los
            // factibles son iguales
            if(seEncontro)return true;    
        }
    }
    // si recorrimos todos los factibles 
    //y ningunos activo entonces el factible no esta en F
    return false;
}

bool ModuloMDDM::AxiomaSimetrico(Factible& F1,  Factible& F2,
                                 std::vector<Factible>&  D){
   Factible dif;
   std::set_symmetric_difference(F1.begin(), F1.end(), 
   F2.begin(), F2.end(), std::back_inserter(dif));
    for (unsigned x : dif) {
        bool seCumpleX=false;
        for (unsigned y : dif) {
            Factible aux;
            aux.push_back(x);
            if(x!=y) aux.push_back(y);
            std::sort(aux.begin(),aux.end());
            Factible difEnF;
            std::set_symmetric_difference(F1.begin(), F1.end(), 
            aux.begin(), aux.end(), std::back_inserter(difEnF));
            if(BuscaFactibleEn(difEnF,D)){
                seCumpleX=true;
                break;
                
            }
        }
        if(!seCumpleX) return false;
    }
    return true;
}

bool ModuloMDDM::IsMatroide(std::vector<Factible>&  D){
    for (int i = 0; i < D.size(); i++) {
        Factible F1 = D[i];
        for (int j = 0; j < D.size(); j++) {
            if(i!=j){
                Factible F2 = D[j];
                if(!AxiomaSimetrico(F1,F2,D)) {  
                
                    return false;
                }
            }
        }
    }   
   return true;
}

ModuloMDDM::ModuloMDDM(){

}
ModuloMDDM::~ModuloMDDM(){
    
}