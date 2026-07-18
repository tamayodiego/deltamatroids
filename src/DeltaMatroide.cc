#include "DeltaMatroide.h"

struct comparador
{
    bool operator()(const Factible &a, const Factible &b)
    {
        Factible o1(a);
        Factible o2(b);
        if (o1.size() < o2.size())
            return true;
        else if (o1.size() == o2.size())
        {
            std::sort(o1.begin(), o1.end());
            std::sort(o2.begin(), o2.end());
            for (int i = 0; i < o2.size(); i++)
            {
                if (o1[i] != o2[i])
                {
                    if (o1[i] < o2[i])
                        return true;
                    else
                        return false;
                }
            }
        }
        return false;
    }
} comparador;


DeltaMatroide::DeltaMatroide(std::string &nombre_Fam,
                             std::vector<Factible> F,
                             unsigned V)
    : conjunto_V(V), matriz(nullptr), huella(F, V), nombre(nombre_Fam),
      familia_subconjuntos(std::move(F))
{

    CalculaVReal();
    tabla_frecuencias.assign(conjunto_V, 0);

    CalculaTablaFrecuencias();
}


DeltaMatroide::DeltaMatroide(const DeltaMatroide &D)
    : conjunto_V(D.conjunto_V), matriz(D.matriz), huella(D.huella), anchura(D.anchura),
      nombre(D.nombre), conjuntoBase(D.conjuntoBase),
      familia_subconjuntos(D.familia_subconjuntos), tabla_frecuencias(D.tabla_frecuencias)
{
    // matriz se comparte (shared_ptr): es de solo lectura tras construirse.
    // familia_subconjuntos y tabla_frecuencias se copian por valor (son mutables por objeto).
}


DeltaMatroide::DeltaMatroide()
    : conjunto_V(0), matriz(nullptr), anchura(0)
{
}

void DeltaMatroide::init(std::string &nombre_Fam, std::vector<Factible> F, unsigned V)
{

    nombre = nombre_Fam;

    familia_subconjuntos = std::move(F);

    CalculaVReal();

    tabla_frecuencias.assign(conjunto_V, 0);

    CalculaTablaFrecuencias();
    ConstruyeHuella();
}

void DeltaMatroide::elimina()
{
    familia_subconjuntos.clear();
    if (matriz)
        matriz->clear();

    tabla_frecuencias.clear();
}

DeltaMatroide::DeltaMatroide(std::string &nombre_Fam,
                             std::shared_ptr<MatrixR> M,
                             unsigned V,bool ext, unsigned campo)
    : conjunto_V(V), matriz(M), nombre(nombre_Fam)

{

    std::vector<bool> arr(V, false);

    AnalizaSubMatrices(arr, *M, 0, campo);

    for (Factible &F : familia_subconjuntos)
    {
        for (int i = 0; i < F.size(); i++)
            F[i]++;
    }

    CalculaVReal();
    tabla_frecuencias.assign(V, 0);
    CalculaTablaFrecuencias();
    ConstruyeHuella();
    OrdenaFamilia();
}
////////////////////////
int DeltaMatroide::CalculaDeterminante(int a[][7], int n)
{
    ///////////////////
    int det = 0, p, h, k, i, j, temp[7][7];
    if (n == 1)
    {
        return a[0][0];
    }
    else if (n == 2)
    {
        det = (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
        return det;
    }
    else
    {
        for (p = 0; p < n; p++)
        {
            h = 0;
            k = 0;
            for (i = 1; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (j == p)
                    {
                        continue;
                    }
                    temp[h][k] = a[i][j];
                    k++;
                    if (k == n - 1)
                    {
                        h++;
                        k = 0;
                    }
                }
            }
            det = det + a[0][p] * pow(-1, p) * CalculaDeterminante(temp, n - 1);
        }
        return det;
    }
}

//determina si una combinacion de elementos de V es un Factible
bool DeltaMatroide::IsFactible(std::vector<unsigned> &factible, MatrixR &M, unsigned campo)
{
    if(factible.size()==0 ) return true;
   // std::cout << "en fac\n";
    MatrixR matriz(factible.size(),std::vector<Racional>(factible.size()));
    ///////Contruye la subMatriz o matriz prinicpal
    for (unsigned i = 0; i < factible.size(); i++)
        for (unsigned j = 0; j < factible.size(); j++)
            matriz[i][j] = M[factible[i]][factible[j]];

    /*//////////////////////////////////////////////////*
    for(unsigned i = 0; i < matriz.size();++i){
        for(unsigned j=0; j< matriz[i].size();++j) std::cout << matriz[i][j];
        std::cout << "\n";
    }
    */
   /// std::cout << "Tras\n";
    Determinante calcuD;
        int det = calcuD.CalculaD(matriz);

   // std::cout << "trasD\n";
    /// La submatriz principal es no singular sobre GF(campo) si su
    /// determinante no es congruente con 0 modulo campo. En ese caso el
    /// subconjunto es factible.
    if (det % campo != 0)
        return true;
    else
        return false;
}

void DeltaMatroide::AnalizaSubMatrices(std::vector<bool> &arr, MatrixR &M, int ite, unsigned campo)
{
    if (ite == conjunto_V)
    {
        std::vector<unsigned> combinacion;
        for (unsigned i = 0; i < conjunto_V; i++)
        {
            if (arr[i])
                combinacion.push_back(i);
        }
        if (IsFactible(combinacion, M, campo))
            familia_subconjuntos.push_back(combinacion);
    }
    else
    {
        arr[ite] = true;
        AnalizaSubMatrices(arr, M, ite + 1, campo);
        arr[ite] = false;
        AnalizaSubMatrices(arr, M, ite + 1, campo);
    }
}

void DeltaMatroide::Twsting(Factible &x)
{

    std::sort(x.begin(), x.end());

    for (Factible &Fi : familia_subconjuntos)
    {

        std::sort(Fi.begin(), Fi.end());
        /// vector donde quedara el resultado
        Factible c;
        //calculamos diferencia simetrica
        std::set_symmetric_difference(x.begin(), x.end(),
                                      Fi.begin(), Fi.end(), std::back_inserter(c));
        ///////
        ///ordenamos el resultado
        std::sort(c.begin(), c.end());
        //lo asignamos a su lugar
        Fi.assign(c.begin(), c.end());
    }

    CalculaVReal();
    ConstruyeHuella();
    CalculaTablaFrecuencias();
    std::string masName = "{";

    for (unsigned u = 0; u < x.size(); ++u)
    {
        masName = masName + std::to_string(x[u]);
        if (u != x.size() - 1)
            masName = masName + ",";
    }
    masName = masName + "}";

    nombre = nombre + "Δ" + masName;
}

void DeltaMatroide::ConstruyeHuella()
{

    huella.Recontruye(familia_subconjuntos, conjunto_V);
}

void DeltaMatroide::CalculaTablaFrecuencias()
{
     for (int i = 0; i < conjunto_V; i++)
        tabla_frecuencias[i]=0;

    for (auto& tem : familia_subconjuntos)
        for (auto& elements : tem)
            tabla_frecuencias[std::distance(conjuntoBase.begin(), find(conjuntoBase.begin(), conjuntoBase.end(), elements))]++;//Desfase
}

unsigned DeltaMatroide::GetV() const
{
    return conjunto_V;
}
void DeltaMatroide::OrdenaFamilia()
{

    std::sort(familia_subconjuntos.begin(), familia_subconjuntos.end(), comparador);
    for (Factible &F : familia_subconjuntos)
        std::sort(F.begin(), F.end());
}

DeltaMatroide::~DeltaMatroide()
{
    // Sin gestion manual de memoria: shared_ptr (matriz) y los vectores por valor
    // se liberan solos.
}

void DeltaMatroide::ToString()
{
    std::string result = nombre + "={";
    for (int i = 0; i < familia_subconjuntos.size(); i++)
    {
        result += "{";

        Factible Fi(familia_subconjuntos[i]);
        for (int j = 0; j < Fi.size(); j++)
        {
            result += std::to_string(Fi[j]);
            if (j != (Fi.size() - 1))
                result += ",";
        }

        result += "}";
        if (i != (familia_subconjuntos.size() - 1))
            result += ",";
    }
    std::cout << result << "}\n";
}

bool DeltaMatroide::ComparaFamilias(std::vector<Factible> &F1, std::vector<Factible> &F2) const
{
    if (F1.size() != F2.size())
        return false;

    std::sort(F1.begin(), F1.end(), comparador);
    for (Factible &F : F1)
        std::sort(F.begin(), F.end());
    std::sort(F2.begin(), F2.end(), comparador);
    for (Factible &F : F2)
        std::sort(F.begin(), F.end());

    for (unsigned i = 0; i < F1.size(); i++)
    {

        if (F1[i].size() != F2[i].size())
            return false;
        for (unsigned j = 0; j < F1[i].size(); j++)
        {

            if (F1.at(i).at(j) != F2.at(i).at(j))
                return false;
        }
    }

    return true;
}


void DeltaMatroide::CalculaVReal(){
    std::vector<unsigned> conte;

    for(Factible& Fi:familia_subconjuntos){
        for(unsigned i:Fi){
            if(std::find(conte.begin(), conte.end(), i) == conte.end()){
                conte.push_back(i);
            }
        }

    }
    conjunto_V=conte.size();
    std::sort(conte.begin(),conte.end());
    conjuntoBase.assign(conte.begin(),conte.end());
}

bool DeltaMatroide::operator==(DeltaMatroide &D) const
{

    if (!(huella == D.huella))
        return false;
    std::vector<Factible> a(familia_subconjuntos), b(D.familia_subconjuntos);
    return ComparaFamilias(a, b);
}

bool DeltaMatroide::operator<(const DeltaMatroide &D) const{

    if(conjunto_V != D.GetV()) return conjunto_V < D.GetV();
    if(huella != D.huella) return huella < D.huella;

    for(unsigned i=0; i < conjunto_V ; ++i)
        if(conjuntoBase[i] != D.conjuntoBase[i])
            return conjuntoBase[i] <  D.conjuntoBase[i];

    auto F1(familia_subconjuntos);
    auto F2(D.familia_subconjuntos);

    std::sort(F1.begin(),F1.end(),comparador);
    std::sort(F2.begin(),F2.end(),comparador);

    for(unsigned i=0; i< F1.size() ; ++i)
        for(unsigned j=0; j<F1[i].size(); ++j)
            if(F1[i][j]!=F2[i][j])
                return F1[i][j] < F2[i][j];

    return false;
}

bool DeltaMatroide::IsIsomorfo(DeltaMatroide &D) const
{

    //primer filtro sus huellas son iguales?
    if (!(huella == D.huella))
    {

        return false;
    }

    std::vector<std::vector<unsigned>> permutaciones;
    std::vector<unsigned> vAuxiliar(conjunto_V);
    std::vector<bool> no_usados(conjunto_V, true);

    ConstruyeBiyeccion(0, permutaciones, vAuxiliar, D, no_usados);

    //segundo filtro existen permutaciones validas?
    if (permutaciones.empty())
        return false;

    // verificar que alguna permutacion resulte una biyeccion

      return AnalizaPermutaciones(permutaciones, D);


}

bool DeltaMatroide::AnalizaPermutaciones(std::vector<std::vector<unsigned>> &perm, DeltaMatroide &D) const
{
 std::vector<Factible> F2(D.familia_subconjuntos);
    for(std::vector<unsigned>& Pi:perm){
      //  std::cout << "permutacion: ";

       // std::cout << "\n";
        std::vector<Factible> F1(familia_subconjuntos);
        /// aplicando funcion biyectiva

        for(int i=0;i<F1.size();i++)
            for(int j=0;j<F1[i].size();j++){

                F1[i][j]=Pi[std::distance(conjuntoBase.begin(),std::find(
                    conjuntoBase.begin(),conjuntoBase.end(),F1[i][j]
                ))];
            }

        if(ComparaFamilias(F1,F2)) return true;
    }

    return false;
}
void DeltaMatroide::ConstruyeConjuntoPotencia( std::vector<Factible>& CP,unsigned ite,unsigned n,Factible base,bool a[]) const{
    if(ite==n){
        Factible c;
        for(unsigned i=0;i<n;++i) if(a[i]) c.push_back(base[i]);
        CP.push_back(c);
    }else{
        a[ite]=false;
        ConstruyeConjuntoPotencia(CP,ite+1,n,base,a);
         a[ite]=true;
        ConstruyeConjuntoPotencia(CP,ite+1,n,base,a);

    }
}
void DeltaMatroide::GetClaseEquivalencia(std::vector<DeltaMatroide> &salida,Factible& base) const {

     std::vector<Factible> copia;
     std::string nomCopia(nombre);
     std::vector<Factible> CP;
     auto aux = std::make_unique<bool[]>(base.size());
    ConstruyeConjuntoPotencia(CP,0,base.size(),base,aux.get());
    for(Factible& Fi: CP){
        std::string subconjunto=nombre+"Δ{";
        for(int i=0;i<Fi.size();++i) subconjunto+=std::to_string(Fi[i]);
        subconjunto+="}";
        //std::sort(x.begin(), x.end());
        copia=familia_subconjuntos;
        for (Factible &F : copia)
        {

            std::sort(F.begin(), F.end());
            /// vector donde quedara el resultado
            Factible c;
            //calculamos diferencia simetrica
            std::set_symmetric_difference(Fi.begin(), Fi.end(),
                                        F.begin(), F.end(), std::back_inserter(c));
            ///////
            ///ordenamos el resultado
            std::sort(c.begin(), c.end());
            //lo asignamos a su lugar
            F.assign(c.begin(), c.end());
        }

        DeltaMatroide dm(subconjunto,copia,conjunto_V);
        salida.push_back(dm);

    }
    ////* copía de la lista de clase de equivalencia

}


void DeltaMatroide::GetClaseEquivalencia(std::vector<DeltaMatroide> &salida,bool mode) const{

     std::vector<Factible> copia;
     std::string nomCopia(nombre);
     std::vector<Factible> CP;
     if(mode) CP=familia_subconjuntos;
     else {
        auto aux = std::make_unique<bool[]>(conjuntoBase.size());
        ConstruyeConjuntoPotencia(CP,0,conjuntoBase.size(),conjuntoBase,aux.get());

     }
    for(Factible& Fi: CP){

        std::string subconjunto=nombre+"Δ{";
        for(int i=0;i<Fi.size();++i) subconjunto+=std::to_string(Fi[i]);
        subconjunto+="}";
        //std::sort(x.begin(), x.end());
        copia=familia_subconjuntos;
        for (Factible &F : copia)
        {

            std::sort(F.begin(), F.end());
            /// vector donde quedara el resultado
            Factible c;
            //calculamos diferencia simetrica
            std::set_symmetric_difference(Fi.begin(), Fi.end(),
                                        F.begin(), F.end(), std::back_inserter(c));
            ///////
            ///ordenamos el resultado
            std::sort(c.begin(), c.end());
            //lo asignamos a su lugar
            F.assign(c.begin(), c.end());
        }

        DeltaMatroide dm(subconjunto,copia,conjunto_V);
        salida.push_back(dm);

    }
    ////* copía de la lista de clase de equivalencia


}

std::ostream &operator<<(std::ostream &os, const Factible &F)
{
    os << "{";
    for (unsigned u = 0; u < F.size(); ++u)
    {
        os << F[u];
        if (u != F.size() - 1)
            os << ",";
    }
    os << "}";
    return os;
}

std::ostream &operator<<(std::ostream &os, const DeltaMatroide &D)
{

    os << D.nombre << "={";
    for (int i = 0; i < D.familia_subconjuntos.size(); i++)
    {
        os << "{";

        Factible Fi(D.familia_subconjuntos[i]);
        for (int j = 0; j < Fi.size(); j++)
        {
            os << std::to_string(Fi[j]);
            if (j != (Fi.size() - 1))
                os << ",";
        }

        os << "}";
        if (i != (D.familia_subconjuntos.size() - 1))
            os << ",";
    }
    os << "}";
    return os;
}

void DeltaMatroide::ConstruyeBiyeccion(unsigned indx, std::vector<std::vector<unsigned>> &permutaciones,
                                       std::vector<unsigned> &temp, DeltaMatroide &D,
                                       std::vector<bool> &no_usados) const
{
  if(indx==conjunto_V){

        permutaciones.push_back(temp);
    }else{

        for(int i = 0 ; i < conjunto_V; ++i){

            /// si el elemento index en this V  puede ir a el elemento
            /// i en other V osea si tienen la misma frecuencia y no se ha usado
            if(tabla_frecuencias[indx]==D.tabla_frecuencias[i] && no_usados[i]){

                temp[indx]=D.conjuntoBase[i];

                no_usados[i]=false;
                ConstruyeBiyeccion(indx + 1,permutaciones,temp,D,no_usados);

                no_usados[i]=true;
            }
        }
    }
}

void DeltaMatroide::GetMenorBorrado(DeltaMatroide &DMMenor, unsigned x) const
{
    std::vector<Factible> familia;
    for (const Factible &Fi : familia_subconjuntos)
    {
        bool noEsta = true;
        for (const unsigned &i : Fi)
        {
            if (i == x)
            {
                noEsta = false;
                break;
            }
        }
        if (noEsta)
            familia.push_back(Fi);
    }
    std::string Nom = nombre + "\\" + std::to_string(x);
    DMMenor.init(Nom, familia, conjunto_V - 1);
}

void DeltaMatroide::GetMenorContraccion(DeltaMatroide &DMMenor, unsigned x) const
{

    std::vector<Factible> familia;
    for (const Factible &Fi : familia_subconjuntos)
    {
        bool siEsta = false;
        for (const unsigned &i : Fi)
        {
            if (i == x)
            {
                siEsta = true;
                break;
            }
        }
        if (siEsta)
            familia.push_back(Fi);
    }

    for (Factible &Fi : familia)
    {
        for (unsigned i = 0; i < Fi.size(); ++i)
        {
            if (Fi[i] == x)
            {
                for (unsigned j = i; j < Fi.size() - 1; ++j)
                    Fi[j] = Fi[j + 1];
                Fi.pop_back();
                break;
            }
        }
    }

    std::string Nom = nombre + "*" + std::to_string(x);
    DMMenor.init(Nom, familia, conjunto_V - 1);
}

void DeltaMatroide::CalculaAnchura(){
    if(familia_subconjuntos.size()>0)
        anchura=familia_subconjuntos.back().size()-familia_subconjuntos.front().size();
    else anchura=0;
}

void DeltaMatroide::GetClaseMenores(std::vector<DeltaMatroide>& salida) const{

    for(unsigned i=0; i<conjuntoBase.size();++i){

        DeltaMatroide menor;
        GetMenorBorrado(menor,conjuntoBase[i]);
        salida.push_back(menor);
        GetMenorContraccion(menor,conjuntoBase[i]);
        salida.push_back(menor);
    }

 }

bool DeltaMatroide::IsDeltaEquivalente(DeltaMatroide &D) const{

    if(D.familia_subconjuntos.size() != familia_subconjuntos.size())
        return false;
    auto sub = std::make_unique<bool[]>(conjuntoBase.size());
    Factible base(conjuntoBase);
    return twisteaSerie(D,0,conjuntoBase.size(),base,sub.get(),false);

}

bool DeltaMatroide::IsDeltaEquivalente(DeltaMatroide &D,Factible& basedeD) const{

    if(D.familia_subconjuntos.size() != familia_subconjuntos.size())
        return false;
    auto sub = std::make_unique<bool[]>(conjuntoBase.size());
    return twisteaSerie(D,0,basedeD.size(),basedeD,sub.get(),true);
}


bool DeltaMatroide::twisteaSerie(DeltaMatroide& D,unsigned i,unsigned n,Factible& base,bool sub[],bool modo) const{

    if(i==n){
        Factible aux;
        for(unsigned j=0;j<n;++j) if(sub[j]) aux.push_back(base[j]);

        if(modo) {
            DeltaMatroide auxD(D);
            auxD.Twsting(aux);
            if(IsIsomorfo(auxD)) return true;
            else return false;
        }else{
            DeltaMatroide auxD(*this);
            auxD.Twsting(aux);
            if(auxD.IsIsomorfo(D)) return true;
            else return false;
        }
    }
    else{
        sub[i]=false;
        if(twisteaSerie(D,i+1, n, base, sub,modo)) return true;
        sub[i]=true;
        if(twisteaSerie(D,i+1, n, base, sub,modo)) return true;
    }

    return false;
}
