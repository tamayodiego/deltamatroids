#ifndef GENERACIONDM_DELTAMATROIDE_H_
#define GENERACIONDM_DELTAMATROIDE_H_
//https://stackoverflow.com/questions/1403150/how-do-you-dynamically-allocate-a-MatrixR
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#include <string>
#include <memory>
#include "Huella.h"
#include "Definiciones.h"
#include "Determinante.h"

class DeltaMatroide
{
  private:
    unsigned conjunto_V;

    void CalculaTablaFrecuencias();
    void CalculaVReal();
    void AnalizaSubMatrices(std::vector<bool> &arr, MatrixR &M, int ite, unsigned campo);
    bool IsFactible(Factible &factible, MatrixR &M, unsigned campo);
    int CalculaDeterminante(int a[][7], int n);
    bool ComparaFamilias(std::vector<Factible> &F1, std::vector<Factible> &F2) const;
    bool CompSort(const Factible &a, const Factible &b);
    bool AnalizaPermutaciones(std::vector<std::vector<unsigned>> &perm, DeltaMatroide &D) const;
    void ConstruyeBiyeccion(unsigned indx, std::vector<std::vector<unsigned>> &permutaciones,
                            std::vector<unsigned> &temp, DeltaMatroide& D,
                            std::vector<bool> &no_usados) const;
    void DiferenciaSimetrica(Factible &A, Factible &B, Factible &resultado);
    bool twisteaSerie(DeltaMatroide&,unsigned,unsigned,Factible&,bool[],bool) const;
    void ConstruyeConjuntoPotencia( std::vector<Factible>& CP,unsigned ite,unsigned n,Factible base,bool a[]) const;


  public:
    std::shared_ptr<MatrixR> matriz;
    Huella huella;
    unsigned anchura;
    std::string nombre;
    Factible conjuntoBase;
    std::vector<Factible> familia_subconjuntos;
    std::vector<unsigned> tabla_frecuencias;
    void ConstruyeHuella();
    void init(std::string &nombre_Fam, std::vector<Factible> F, unsigned V);
    void elimina();
    DeltaMatroide();
    DeltaMatroide(const DeltaMatroide &D);
    DeltaMatroide(std::string &nombre_Fam, std::vector<Factible> F, unsigned V);
    DeltaMatroide(std::string &nombre_Fam, std::shared_ptr<MatrixR> M, unsigned V,bool ext, unsigned campo);
    bool operator==(DeltaMatroide &D) const;
    bool operator<(const DeltaMatroide &D) const;
    friend std::ostream &operator<<(std::ostream &os, const DeltaMatroide &D);
    ~DeltaMatroide();
    void OrdenaFamilia();
    void SetF(std::vector<Factible> &F);
    void Twsting(Factible &x);
    std::string &GetNombre();
    void ToString();
    unsigned GetV() const;
    void CalculaAnchura();
    bool IsIsomorfo(DeltaMatroide &D) const;
    bool IsDeltaEquivalente(DeltaMatroide &D) const;
    bool IsDeltaEquivalente(DeltaMatroide &D,Factible& basdeD) const;
    void GetClaseEquivalencia(std::vector<DeltaMatroide> &salida,Factible& base) const;
    void GetClaseEquivalencia(std::vector<DeltaMatroide> &salida,bool modo) const;
    void GetClaseMenores(std::vector<DeltaMatroide>& salida) const;
    void GetMenorBorrado(DeltaMatroide &DMMenor, unsigned x) const;
    void GetMenorContraccion(DeltaMatroide &DMMenor, unsigned x) const;
};

#endif // GENERACIONDM_DELTAMATROIDE_H_
