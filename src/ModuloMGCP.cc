
#include "ModuloMGCP.h"


void ModuloMGCP::construye(std::vector<bool>& arr, unsigned ite,unsigned n ){
    if(ite==n){
        Factible aux;
        for(int i=0;i< arr.size();i++) if(arr[i]) aux.push_back((i+1));
        Pv.push_back(aux);
    }else{
        arr[ite]=true;
        construye(std::ref(arr),ite+1,n);
        arr[ite]=false;
        construye(std::ref(arr),ite+1,n);
    }
}
void ModuloMGCP::ClasificaConjuntoPotencia(){
    for (Factible subconjunto : Pv ) {
        bool esta=false;
        for (int j = 0; j < subconjunto.size(); j++) {
            if(subconjunto[j]==this_V){
                esta=true;
                break;
            }            
        }
        if(esta) Pv_con_Vmas.push_back(subconjunto); /// preguntar que esto funcione
        else Pv_sin_Vmas.push_back(subconjunto); //// preguntar que esto funcione
    }
}


ModuloMGCP::ModuloMGCP(unsigned V): Pv(),this_V(V+1){
    std::vector<bool> arr(this_V,false);

    construye(arr,0,this_V);
    ClasificaConjuntoPotencia();
}

ModuloMGCP::~ModuloMGCP(){
   // delete Pv;
}