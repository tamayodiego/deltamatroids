#include "LectorParametros.h"

LectorParametros::LectorParametros(): params(std::vector<std::string>(5)){

    params[0]="-P";
    params[1]="-S";
    params[2]="-I";
    params[3]="-O";
    params[4]="-D";
}

void LectorParametros::AnalizaParametros(int argc, char *argv[],Parametros *p){
    p->hilos=1;
    p->modo=false;
    p->depuracionM=false;
    p->in="entrada";
    p->out="Ternarios";

    for(unsigned i=1; i < argc ; ++i){
        std::string cad;
        switch(DecodificaParametro(argv[i])){

            case 0 :
                p->modo=true;
                cad= argv[i+1];
                if(EsUnNumero(cad)) p->hilos=(unsigned)std::atoi(argv[i+1]);
                else std::cout << "Error de parametros, no has introducido un nuemro valido de hilos\n";
                ++i;
            break;

            case 1 :
                p->modo=false;
            break;

            case 2 :
                if(i+1 <argc){
                    p->in=argv[i+1];
                    i++;
                }else std::cout <<"Error en parametros, sin nombre de archivo de entrada\n";
            break;

            case 3 :
                if(i+1 <argc){
                    p->out=argv[i+1];
                    i++;
                } else std::cout <<"Error en parametros, sin nombre de archivo de salida\n";
            break;
            case 4 :
                p->depuracionM=true;
            break;

            default :
                std::cout <<"Error en parametros, parametro "<< argv[i] << " es desconocido\n";
            break;
            

        }

    }

}

bool LectorParametros::EsUnNumero(std::string& cadena){
  for(char& c : cadena){
    // En cuanto un caracter no sea numérico
    if( !std::isdigit(c) )
      return false;
  }

  return true;
}

int LectorParametros::DecodificaParametro(char param[]){
    std::string cad(param);
    std::vector<std::string>::iterator it=find (params.begin(), params.end(), cad);
    if(it == params.end()) return -1;
    else return std::distance(params.begin(),it);
    

}