#include "Determinante.h"


void Determinante::Intercambio(unsigned i,unsigned j,MatrixR& M){
    std::vector<Racional> aux(M[i]);
    M[i]=M[j];
    M[j]=aux;
    pila.push(-1);
}

Determinante::Determinante(){
    
}

Determinante::Determinante(const Determinante& D){

 }

void Determinante::ConstantePorRenglon(Racional C,unsigned i,MatrixR& M){
    for(unsigned j=0;j<M[i].size();++j) {
        //std::cout << M[i][j] << "  "<< C<< " \n";
        M[i][j] *= C;
        //std::cout << M[i][j] << "  "<< C<< " \n";
    }
        
    pila.push(C^-1);

}


void Determinante::SumaDeRenglones(Racional C,unsigned i,unsigned j,MatrixR& M){
    std::vector<Racional> Ri(M[i]);
    C*=-1;
    for(unsigned k=0; k < Ri.size(); ++k)
       Ri[k]*=C;
    for(unsigned k=0; k < Ri.size(); ++k)
        M[j][k] = M[j][k] + Ri[k];
}

void Determinante::Diagonaliza(MatrixR& M){

    for(unsigned i=0; i < M.size() - 1;++i){
      /// creacion de pivote
        if(M[i][i] != 1 ){
        /// hacer el pivote 
            //ver si no es 0
           
            if(M[i][i] == 0){
               
                bool columnaDeCeros=true;
                // si es 0 buscar en la column uno que no
                for(unsigned j=i+1;j<M.size();++j){
                    if(M[j][i]!=0) {
                        Intercambio(i,j,M);
                        columnaDeCeros=false;
                        break;
                    }
                }
                // Si no exite entoncs continuar con el siguiente
                if(columnaDeCeros)              
                    continue;   
            }
            // hacer 1 al valor M[i][i] para que sea pivte
            if(M[i][i] != 1 ) 
                ConstantePorRenglon(M[i][i]^-1,i,M);
                
            
        }
        // hacer ceros
        for(unsigned j=i+1;j<M.size();++j){
            if(M[j][i] != 0)
                SumaDeRenglones(M[j][i],i,j,M);
                        
        
        }
              
    }
   
 }


 int Determinante::CalculaD(MatrixR M){

    Diagonaliza(M);
    Racional determinante=1;
    for(int i=0; i<M.size();++i) determinante*=M[i][i];
    while(pila.size()){
        determinante*=pila.top();
        pila.pop();
    }


    return determinante.numerador/determinante.denominador;
 }


