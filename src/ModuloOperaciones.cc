#include "ModuloOperaciones.h"

void ModuloOperaciones::listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide>& LB, std::vector<DeltaMatroide>& LR ){

    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    //para cada elemento en LA
    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0;i<LA.size();++i){
        bool NoexisteEnB=true;
        bool romper=true;
        //comparar en cada elemento en LB
        for(unsigned j=0;j<LB.size() && romper;++j){
            bool comparacion=false;
            //comparacion segun parametro
            switch(p){
                case 'a':
                    comparacion= LA[i] == LB[j];
                break;
                case 'b':
                    comparacion= LA[i].IsIsomorfo(LB[j]);
                break;
                case 'c':
                    comparacion = LA[i].IsDeltaEquivalente(LB[j]);
                break;
            }
            if(comparacion){
                NoexisteEnB=false;
                romper=false;
            }

        }

        if(NoexisteEnB){
            #pragma omp critical 
            LR.push_back(LA[i]);
        }
    }


}

void ModuloOperaciones::listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide>& LB, std::vector<DeltaMatroide*>& LR ){

    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);
   
    //para cada elemento en LA
    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0;i<LA.size();++i){
        bool NoexisteEnB=true;
        bool romper=true;
        //comparar en cada elemento en LB
        for(unsigned j=0;j<LB.size() && romper;++j){
            bool comparacion=false;
            //comparacion segun parametro
            switch(p){
                case 'a':
                    comparacion= LA[i] == LB[j];
                break;
                case 'b':
                    comparacion= LA[i].IsIsomorfo(LB[j]);
                break;
                case 'c':
                    comparacion = LA[i].IsDeltaEquivalente(LB[j]);
                break;
            }
            if(comparacion){
                NoexisteEnB=false;
                romper=false;
            }

        }

        if(NoexisteEnB){
            #pragma omp critical
            LR.push_back(&LA[i]);
        }
    }

}
void ModuloOperaciones::listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide*>& LB, std::vector<DeltaMatroide>& LR ){

        if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    //para cada elemento en LA
    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0;i<LA.size();++i){
        bool NoexisteEnB=true;
        bool romper=true;
        //comparar en cada elemento en LB
        for(unsigned j=0;j<LB.size() && romper;++j){
            bool comparacion=false;
            //comparacion segun parametro
            switch(p){
                case 'a':
                    comparacion= LA[i] == *LB[j];
                break;
                case 'b':
                    comparacion= LA[i].IsIsomorfo(*LB[j]);
                break;
                case 'c':
                    comparacion = LA[i].IsDeltaEquivalente(*LB[j]);
                break;
            }
            if(comparacion){
                NoexisteEnB=false;
                romper=false;
            }

        }

        if(NoexisteEnB){
            #pragma omp critical 
            LR.push_back(LA[i]);
        }
    }


}
void ModuloOperaciones::listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide*>& LB, std::vector<DeltaMatroide*>& LR ){

    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    //para cada elemento en LA
    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0;i<LA.size();++i){
        bool NoexisteEnB=true;
        bool romper=true;
        //comparar en cada elemento en LB
        for(unsigned j=0;j<LB.size() && romper;++j){
            bool comparacion=false;
            //comparacion segun parametro
            switch(p){
                case 'a':
                    comparacion= LA[i] == *LB[j];
                break;
                case 'b':
                    comparacion= LA[i].IsIsomorfo(*LB[j]);
                break;
                case 'c':
                    comparacion = LA[i].IsDeltaEquivalente(*LB[j]);
                break;
            }
            if(comparacion){
                NoexisteEnB=false;
                romper=false;
            }

        }

        if(NoexisteEnB){
            #pragma omp critical 
            LR.push_back(&LA[i]);
        }
    }

}
void ModuloOperaciones::listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide>& LB, std::vector<DeltaMatroide>& LR ){

    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    //para cada elemento en LA
    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0;i<LA.size();++i){
        bool NoexisteEnB=true;
        bool romper=true;
        //comparar en cada elemento en LB
        for(unsigned j=0;j<LB.size() && romper;++j){
            bool comparacion=false;
            //comparacion segun parametro
            switch(p){
                case 'a':
                    comparacion= *LA[i] == LB[j];
                break;
                case 'b':
                    comparacion= LA[i]->IsIsomorfo(LB[j]);
                break;
                case 'c':
                    comparacion = LA[i]->IsDeltaEquivalente(LB[j]);
                break;
            }
            if(comparacion){
                NoexisteEnB=false;
                romper=false;
            }

        }

        if(NoexisteEnB){
            #pragma omp critical 
            LR.push_back(*LA[i]);
        }
    }

}
void ModuloOperaciones::listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide>& LB, std::vector<DeltaMatroide*>& LR ){

    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    //para cada elemento en LA
    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0;i<LA.size();++i){
        bool NoexisteEnB=true;
        bool romper=true;
        //comparar en cada elemento en LB
        for(unsigned j=0;j<LB.size() && romper;++j){
            bool comparacion=false;
            //comparacion segun parametro
            switch(p){
                case 'a':
                    comparacion= *LA[i] == LB[j];
                break;
                case 'b':
                    comparacion= LA[i]->IsIsomorfo(LB[j]);
                break;
                case 'c':
                    comparacion = LA[i]->IsDeltaEquivalente(LB[j]);
                break;
            }
            if(comparacion){
                NoexisteEnB=false;
                romper=false;
            }

        }

        if(NoexisteEnB){
            #pragma omp critical 
            LR.push_back(LA[i]);
        }
    }

}
void ModuloOperaciones::listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide*>& LB, std::vector<DeltaMatroide>& LR ){
    
    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    //para cada elemento en LA
    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0;i<LA.size();++i){
        bool NoexisteEnB=true;
        bool romper=true;
        //comparar en cada elemento en LB
        for(unsigned j=0;j<LB.size() && romper;++j){
            bool comparacion=false;
            //comparacion segun parametro
            switch(p){
                case 'a':
                    comparacion= *LA[i] == *LB[j];
                break;
                case 'b':
                    comparacion= LA[i]->IsIsomorfo(*LB[j]);
                break;
                case 'c':
                    comparacion = LA[i]->IsDeltaEquivalente(*LB[j]);
                break;
            }
            if(comparacion){
                NoexisteEnB=false;
                romper=false;
            }

        }

        if(NoexisteEnB){
            #pragma omp critical 
            LR.push_back(*LA[i]);
        }
    }

}
void ModuloOperaciones::listaAmenosB(unsigned h,char p,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide*>& LB, std::vector<DeltaMatroide*>& LR ){

    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);
    // std::cout << "\ten listaa-b\n";
    //para cada elemento en LA
    #pragma omp parallel for schedule(dynamic)
    for(unsigned i=0;i<LA.size();++i){
      //  std::cout << "\titeracion "<<i<<" de "<<LA.size()<<"\n";
        bool NoexisteEnB=true;
        bool romper=true;
        //comparar en cada elemento en LB
        for(unsigned j=0;j<LB.size() && romper;++j){
          //  std::cout << "\t\titeracion "<<j<<" de "<<LB.size()<< "\n";
            bool comparacion=false;
            //comparacion segun parametro
            switch(p){
                case 'a':
                    comparacion= *LA[i] == *LB[j];
                break;
                case 'b':
                    comparacion= LA[i]->IsIsomorfo(*LB[j]);
                break;
                case 'c':
                    comparacion = LA[i]->IsDeltaEquivalente(*LB[j]);
                break;
            }
            if(comparacion){
                NoexisteEnB=false;
                romper=false;
            }

        }

        if(NoexisteEnB){
            #pragma omp critical 
            LR.push_back(LA[i]);
        }

      //  std::cout << "\tfin for\n";

    }
}


void ModuloOperaciones::deleteMinorsAofB(unsigned h,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide>& LB){

    //obtener V minima
    unsigned min=LB[0].GetV();
    for(unsigned i=1;i<LB.size();++i)
        if(LB[i].GetV() < min) 
            min=LB[i].GetV();
    //calculando menores de Lista A
    std::vector<std::map<unsigned,std::vector<DeltaMatroide>>> listaMenores(LA.size());
    for(unsigned i=0;i< LA.size();++i){
        unsigned n=LA[i].GetV()-1;
        ///calcular primer nivel de menores 
        LA[i].GetClaseMenores(listaMenores[i][n]);
        /// siguientes niveles de menores
        for(unsigned j=n; j>min;--j)
            for(unsigned k=0; k< listaMenores[i][j].size();++k)
                listaMenores[i][j][k].GetClaseMenores(listaMenores[i][j-1]);
    }

    //Calculamos Delta-Equivalentes de Lista B
    


    for(unsigned i=0; i<LA.size();++i){
        bool noHayMenorIsomorfo;
        for(unsigned j=0;j<LB.size();++j){
            for(DeltaMatroide& D:listaMenores[i][LB[j].GetV()]){
                //if()
            }
        }


    }


    





}

  //  void ModuloOperaciones::deleteMinorsAofB(unsigned h,std::vector<DeltaMatroide>& LA,std::vector<DeltaMatroide*>& LB);
   // void ModuloOperaciones::deleteMinorsAofB(unsigned h,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide>& LB);
    //void ModuloOperaciones::deleteMinorsAofB(unsigned h,std::vector<DeltaMatroide*>& LA,std::vector<DeltaMatroide*>& LB);


