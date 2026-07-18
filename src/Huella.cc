#include "Huella.h"

Huella::Huella(std::vector<Factible>& dm,unsigned  V)
: huella()
{
   
    unsigned masGrande=0;
    for(Factible& F: dm){
        if(F.size()>masGrande) masGrande=F.size();
    }

    for(unsigned i=0;i<= masGrande;i++) huella.push_back(0);
   
    for(Factible& F: dm) huella[F.size()]++; /// cada factible esta relacionado su tamaño
                                                // en un indice del arrelo huella
}

Huella::Huella()
: huella()
{

}
void Huella::Recontruye(std::vector<Factible>& dm,unsigned  V){
    unsigned masGrande=0;
    for(Factible& F: dm){
        if(F.size()>masGrande) masGrande=F.size();
    }
    huella.erase(huella.begin(),huella.end());
    for(unsigned i=0;i<= masGrande;i++) huella.push_back(0);
  
    for(Factible& F: dm) huella[F.size()]++; /// 
}
Huella::~Huella() 
{
  
}
bool Huella::operator==(const Huella& h) const{
     if(h.huella.size()!=huella.size()) return false;
  
    for (int i = 0; i < huella.size(); ++i)
       
        if(h.huella[i] != huella[i])
            return false;
    return true;

}
 bool Huella::operator!=(const Huella& h) const{

      if(h.huella.size()!=huella.size()) return true;
  
    for (int i = 0; i < huella.size(); ++i)
       
        if(h.huella[i] != huella[i])
            return true;
    return false;


 }
 bool Huella::operator<(const Huella& h) const{

    for(unsigned i=0; i < huella.size() && i < h.huella.size() ; ++i)
        if(huella[i] >= h.huella[i] ) return false;
    if(huella.size() != h.huella.size()) return huella.size() < h.huella.size();
    return false;
 }
bool Huella::operator>(const Huella& h) const{

    for(unsigned i=0; i < huella.size() && i < h.huella.size() ; ++i)
        if(huella[i] <= h.huella[i] ) return false;
    if(huella.size() != h.huella.size()) return huella.size() > h.huella.size();
    return false;

}
bool Huella::operator<=(const Huella& h) const{

    for(unsigned i=0; i < huella.size() && i < h.huella.size() ; ++i)
        if(huella[i] > h.huella[i] ) return false;
    if(huella.size() != h.huella.size()) return huella.size() <= h.huella.size();
    return false;

}
bool Huella::operator>=(const Huella& h) const{

    for(unsigned i=0; i < huella.size() && i < h.huella.size() ; ++i)
        if(huella[i] < h.huella[i] ) return false;
    if(huella.size() != h.huella.size()) return huella.size() >= h.huella.size();
    return false;

}
std::ostream& operator << (std::ostream& os,const Huella& h){
      os<<"(";
 
    for(unsigned i=0; i < h.huella.size(); ++i) { 
        os << h.huella[i];
        if(i != h.huella.size()-1) os <<",";
    }
    os << ")";

    return os;
}


