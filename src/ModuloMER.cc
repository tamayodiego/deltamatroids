#include "ModuloMER.h"

void ModuloMER::GeneraExtensionesTernarias(unsigned h, MatrixR& M,std::vector<DeltaMatroide>& LOut){

    std::vector<std::vector<int>> vectores;
    std::vector<int> auxi(M.size()+1);
    GeneraVectores(0,M.size()+1,auxi,vectores);
    //std::cout <<"\ttras generar vectores\n";

    if(h) omp_set_num_threads(h);
    else omp_set_num_threads(1);

    unsigned contador=0;
    #pragma omp parallel for schedule(dynamic) firstprivate(contador)
    for(unsigned k=0;k<vectores.size();++k){

        auto mat = std::make_shared<MatrixR>(M.size() + 1, std::vector<Racional>(M.size() + 1));

        /// aplicando extension
        for (unsigned i = 0; i < M.size(); i++)
            for (unsigned j = 0; j < M[i].size(); j++)
                (*mat)[i][j] = M[i][j];
        
        for (unsigned i = 0; i < mat->size(); i++){
            (*mat)[mat->size() - 1][i] = vectores[k][i];
            (*mat)[i][mat->size() - 1] = vectores[k][i];
        }
      

        std::string nombre = "Ter" + std::to_string(omp_get_thread_num()) +"."+ std::to_string(contador);
        contador++;
       // std::cout <<"\t antes de definicion\n";
        // TODO: confirmar el cuerpo GF(campo) para las extensiones ternarias (2 preserva
        // el comportamiento previo; probablemente deba ser 3 al ser extensiones ternarias).
        DeltaMatroide D(nombre, mat, mat->size(), true, 2);
        #pragma omp critical 
            LOut.push_back(D);
        
       // std::cout <<"\t iteracion\n";

    }


}



ModuloMER::ModuloMER()
{
}

void ModuloMER::GeneraVectores(unsigned i,unsigned V, std::vector<int> &aux ,std::vector<std::vector<int>> &vectorR)
{
    if (i == V)
        vectorR.push_back(aux);
    else
    {
        aux[i]=0;
        GeneraVectores(i + 1,V,aux,vectorR );
        aux[i]=1;
        GeneraVectores(i + 1,V,aux,vectorR );
        aux[i]=-1;
        GeneraVectores(i + 1,V,aux,vectorR );
    }
}