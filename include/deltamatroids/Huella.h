#ifndef GENERACIONDM_HUELLA_H_
#define GENERACIONDM_HUELLA_H_

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include "Definiciones.h"

class Huella {
  
    public:
        std::vector<unsigned> huella;
        Huella();
        Huella(std::vector<Factible>& dm,unsigned  V);
        void Recontruye(std::vector<Factible>& dm,unsigned V);
        ~Huella();
        bool operator==(const Huella& h) const;
        bool operator!=(const Huella& h) const;
        bool operator<(const Huella& h) const;
        bool operator>(const Huella& h) const;
        bool operator<=(const Huella& h) const;
        bool operator>=(const Huella& h) const;

        friend std::ostream& operator << (std::ostream& os,const Huella& h);
      
};

#endif // GENERACIONDM_HUELLA_H_