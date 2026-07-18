#include "ModuloDepuracion.h"

void ModuloDepuracion::depuracionIsomorfismo(unsigned hilos,std::vector<DeltaMatroide>& L1,std::vector<DeltaMatroide*>& L2){
     
     
    if(hilos) omp_set_num_threads(hilos);
    else omp_set_num_threads(1);
    std::vector<int> indices(L1.size());//={-1};

    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0; i < L1.size() ; ++i){
        indices[i]=-1;
        for(unsigned j=i+1; j < L1.size() ; ++j){

            if(L1[i].IsIsomorfo(L1[j])){
                indices[i]=j;
                break;
            } 
            
        }
        
    }

    std::vector<bool> usados(L1.size(),true);

    for(unsigned i=0;i<L1.size();++i){

        if(indices[i]!=-1) usados[indices[i]]=false;
        if(usados[i]) L2.push_back(&L1[i]);
        
    }

}

void ModuloDepuracion::depuracionIsomorfismo(unsigned hilos,std::vector<DeltaMatroide>& L1,std::vector<DeltaMatroide>& L2){

    if(hilos) omp_set_num_threads(hilos);
    else omp_set_num_threads(1);
    std::vector<int> indices(L1.size());//={-1};

    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0; i < L1.size() ; ++i){
        indices[i]=-1;
        for(unsigned j=i+1; j < L1.size() ; ++j){

            if(L1[i].IsIsomorfo(L1[j])){
                indices[i]=j;
                break;
            } 
            
        }
        
    }

    std::vector<bool> usados(L1.size(),true);

    for(unsigned i=0;i<L1.size();++i){

        if(indices[i]!=-1) usados[indices[i]]=false;
        if(usados[i]) L2.push_back(L1[i]);
        
    }


}


void ModuloDepuracion::depuracionIsomorfismo(unsigned hilos,std::vector<DeltaMatroide*>& L1,std::vector<DeltaMatroide*>& L2){

    if(hilos) omp_set_num_threads(hilos);
    else omp_set_num_threads(1);
    std::vector<int> indices(L1.size());//={-1};

    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0; i < L1.size() ; ++i){
        indices[i]=-1;
        for(unsigned j=i+1; j < L1.size() ; ++j){

            if(L1[i]->IsIsomorfo(*L1[j])){
                indices[i]=j;
                break;
            } 
            
        }
        
    }

    std::vector<bool> usados(L1.size(),true);

    for(unsigned i=0;i<L1.size();++i){

        if(indices[i]!=-1) usados[indices[i]]=false;
        if(usados[i]) L2.push_back(L1[i]);
        
    }

}

void ModuloDepuracion::depuracionIsomorfismo(unsigned hilos,std::vector<DeltaMatroide*>& L1,std::vector<DeltaMatroide>& L2){  
    
    if(hilos) omp_set_num_threads(hilos);
    else omp_set_num_threads(1);
    std::vector<int> indices(L1.size());//={-1};

    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0; i < L1.size() ; ++i){
        indices[i]=-1;
        for(unsigned j=i+1; j < L1.size() ; ++j){

            if(L1[i]->IsIsomorfo(*L1[j])){
                indices[i]=j;
                break;
            } 
            
        }
        
    }

    std::vector<bool> usados(L1.size(),true);

    for(unsigned i=0;i<L1.size();++i){

        if(indices[i]!=-1) usados[indices[i]]=false;
        if(usados[i]) L2.push_back(*L1[i]);
        
    }
}



void ModuloDepuracion::depuraDeltaEquivalente(unsigned h,Factible& base,std::vector<DeltaMatroide>& inL,std::vector<DeltaMatroide>& outL){
   
    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    std::vector<int> indices(inL.size());//={-1};

    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0; i < inL.size() ; ++i){
        indices[i]=-1;
        for(unsigned j=i+1; j < inL.size() ; ++j){

            if(inL[i].IsDeltaEquivalente(inL[j],base)){
                indices[i]=j;
                break;
            } 
            
        }
        
    }

    std::vector<bool> usados(inL.size(),true);

    for(unsigned i=0;i<inL.size();++i){

        if(indices[i]!=-1) usados[indices[i]]=false;
        if(usados[i]) outL.push_back(inL[i]);
        
    }

}

void ModuloDepuracion::depuraDeltaEquivalente(unsigned h,Factible& base,std::vector<DeltaMatroide*>& inL,std::vector<DeltaMatroide>& outL){

    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    std::vector<int> indices(inL.size());//={-1};

    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0; i < inL.size() ; ++i){
        indices[i]=-1;
        for(unsigned j=i+1; j < inL.size() ; ++j){

            if(inL[i]->IsDeltaEquivalente(*inL[j],base)){
                indices[i]=j;
                break;
            } 
            
        }
        
    }

    std::vector<bool> usados(inL.size(),true);

    for(unsigned i=0;i<inL.size();++i){

        if(indices[i]!=-1) usados[indices[i]]=false;
        if(usados[i]) outL.push_back(*inL[i]);
        
    }
}

void ModuloDepuracion::depuraDeltaEquivalente(unsigned h,Factible& base,std::vector<DeltaMatroide>& inL,std::vector<DeltaMatroide*>& outL){

    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    std::vector<int> indices(inL.size());//={-1};

    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0; i < inL.size() ; ++i){
        indices[i]=-1;
        for(unsigned j=i+1; j < inL.size() ; ++j){

            if(inL[i].IsDeltaEquivalente(inL[j],base)){
                indices[i]=j;
                break;
            } 
            
        }
        
    }

    std::vector<bool> usados(inL.size(),true);

    for(unsigned i=0;i<inL.size();++i){

        if(indices[i]!=-1) usados[indices[i]]=false;
        if(usados[i]) outL.push_back(&inL[i]);
        
    }

}

void ModuloDepuracion::depuraDeltaEquivalente(unsigned h,Factible& base,std::vector<DeltaMatroide*>& inL,std::vector<DeltaMatroide*>& outL){

    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    std::vector<int> indices(inL.size());//={-1};

    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0; i < inL.size() ; ++i){
        indices[i]=-1;
        for(unsigned j=i+1; j < inL.size() ; ++j){

            if(inL[i]->IsDeltaEquivalente(*inL[j],base)){
                indices[i]=j;
                break;
            } 
            
        }
        
    }

    std::vector<bool> usados(inL.size(),true);

    for(unsigned i=0;i<inL.size();++i){

        if(indices[i]!=-1) usados[indices[i]]=false;
        if(usados[i]) outL.push_back(inL[i]);
        
    }
}


void ModuloDepuracion::depuraDeltaEquivalente(unsigned h,std::vector<DeltaMatroide>& inL,std::vector<DeltaMatroide>& outL){
   
    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    std::vector<int> indices(inL.size());//={-1};

    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0; i < inL.size() ; ++i){
        indices[i]=-1;
        for(unsigned j=i+1; j < inL.size() ; ++j){

            if(inL[i].IsDeltaEquivalente(inL[j])){
                indices[i]=j;
                break;
            } 
            
        }
        
    }

    std::vector<bool> usados(inL.size(),true);

    for(unsigned i=0;i<inL.size();++i){

        if(indices[i]!=-1) usados[indices[i]]=false;
        if(usados[i]) outL.push_back(inL[i]);
        
    }

}

void ModuloDepuracion::depuraDeltaEquivalente(unsigned h,std::vector<DeltaMatroide*>& inL,std::vector<DeltaMatroide>& outL){

    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    std::vector<int> indices(inL.size());//={-1};

    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0; i < inL.size() ; ++i){
        indices[i]=-1;
        for(unsigned j=i+1; j < inL.size() ; ++j){

            if(inL[i]->IsDeltaEquivalente(*inL[j])){
                indices[i]=j;
                break;
            } 
            
        }
        
    }

    std::vector<bool> usados(inL.size(),true);

    for(unsigned i=0;i<inL.size();++i){

        if(indices[i]!=-1) usados[indices[i]]=false;
        if(usados[i]) outL.push_back(*inL[i]);
        
    }
}

void ModuloDepuracion::depuraDeltaEquivalente(unsigned h,std::vector<DeltaMatroide>& inL,std::vector<DeltaMatroide*>& outL){

    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    std::vector<int> indices(inL.size());//={-1};

    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0; i < inL.size() ; ++i){
        indices[i]=-1;
        for(unsigned j=i+1; j < inL.size() ; ++j){

            if(inL[i].IsDeltaEquivalente(inL[j])){
                indices[i]=j;
                break;
            } 
            
        }
        
    }

    std::vector<bool> usados(inL.size(),true);

    for(unsigned i=0;i<inL.size();++i){

        if(indices[i]!=-1) usados[indices[i]]=false;
        if(usados[i]) outL.push_back(&inL[i]);
        
    }

}

void ModuloDepuracion::depuraDeltaEquivalente(unsigned h,std::vector<DeltaMatroide*>& inL,std::vector<DeltaMatroide*>& outL){

    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    std::vector<int> indices(inL.size());//={-1};

    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0; i < inL.size() ; ++i){
        indices[i]=-1;
        for(unsigned j=i+1; j < inL.size() ; ++j){

            if(inL[i]->IsDeltaEquivalente(*inL[j])){
                indices[i]=j;
                break;
            } 
            
        }
        
    }

    std::vector<bool> usados(inL.size(),true);

    for(unsigned i=0;i<inL.size();++i){

        if(indices[i]!=-1) usados[indices[i]]=false;
        if(usados[i]) outL.push_back(inL[i]);
        
    }
}

ModuloDepuracion::ModuloDepuracion(){

 }

