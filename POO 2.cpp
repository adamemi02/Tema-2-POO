#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
using namespace std;

class Adresa{
private:
    string oras;
    string strada;
    int nr_strada;
    int cod_postal;

public:
    Adresa(string oras_="", string strada_="", int nr_strada_=0, int cod_postal_=0){
        oras=oras_;
        strada=strada_;
        nr_strada=nr_strada_;
        cod_postal=cod_postal_;
    }
    Adresa(const Adresa &A){
        oras=A.oras;
        strada=A.strada;
        nr_strada=A.nr_strada;
        cod_postal=A.cod_postal;
    }
    ~Adresa(){
    }
    void set_adresa(string oras_, string strada_, int nr_strada_, int cod_postal_) {
        oras=oras_;
        strada=strada_;
        nr_strada=nr_strada_;
        cod_postal=cod_postal_;
    }

    void set_oras(string oras_) {
        oras = oras_;
    }

    void set_strada(const string strada_) {
        strada=strada_;
    }

    void set_nr_strada(int nr_strada_) {
        nr_strada = nr_strada_;
    }
    void set_cod_postal(int cod_postal_) {
        cod_postal = cod_postal_;
    }

    string get_oras() const {
        return oras;
    }
    string get_strada() const {
        return strada;
    }
    int get_nr_strada() const {
        return nr_strada;
    }
    int get_cod_postal() const {
        return cod_postal;
    }

    Adresa &operator=(const Adresa &A) {
        oras=A.oras;
        strada=A.strada;
        nr_strada=A.nr_strada;
        cod_postal=A.cod_postal;
        return *this;
    }

    bool operator!=(const Adresa &A) {
        bool ok = 1;
        if (oras != A.oras)
            ok = 0;
        if (nr_strada != A.nr_strada)
            ok = 0;
        if (strada != A.strada)
            ok = 0;
        if (cod_postal != A.cod_postal)
            ok = 0;
        return !ok;
    }

    friend std::ostream &operator<<(std::ostream &os, const Adresa &A) {
        os<<A.oras<<", "<<A.strada<<", nr. "<<A.nr_strada<<", cod postal "<<A.cod_postal;
        return os;
    }

    friend std::istream& operator>>(std::istream &is, Adresa &A) {
        cout<<"Oras: ";
        is>>A.oras;
        cout<<"Strada: ";
        is>>A.strada;
        cout<<"nr: ";
        is>>A.nr_strada;
        cout<<"Cod postal: ";
        is>>A.cod_postal;
        return is;
    }

};

class Imobil{
protected:
    static float val_euro ;
    Adresa adresa_imobil;
    int m_patrati;
    float pret_chirie_euro; //per metru patrat

public:
    Imobil(Adresa adresa_imobil_, int m_patrati_, float pret_chirie_euro_){
        adresa_imobil=adresa_imobil_;
        m_patrati=m_patrati_;
        pret_chirie_euro=pret_chirie_euro_;
    }
    Imobil(const Imobil &I){
        adresa_imobil=I.adresa_imobil;
        m_patrati=I.m_patrati;
        pret_chirie_euro=I.pret_chirie_euro;
    }
    virtual ~Imobil(){
    }
    void set_Imobil(Adresa adresa_imobil_, int m_patrati_, float pret_chirie_euro_ ) {
        adresa_imobil=adresa_imobil_;
        m_patrati=m_patrati_;
        pret_chirie_euro=pret_chirie_euro_;
    }

    void set_adresa_imobil(Adresa adresa_imobil_) {
        adresa_imobil = adresa_imobil_;
    }

    void set_m_patrati(int m_patrati_) {
        m_patrati = m_patrati_;
    }
    void set_pret_chirie_euro(float pret_chirie_euro_) {
        pret_chirie_euro = pret_chirie_euro_;
    }

    Adresa get_adresa_imobil() const {
        return adresa_imobil;
    }
    int get_m_patrati() const {
        return m_patrati;
    }
    float get_pret_chirie_euro() const {
        return pret_chirie_euro;
    }

    Imobil &operator=(const Imobil &I) {
        adresa_imobil=I.adresa_imobil;
        m_patrati=I.m_patrati;
        pret_chirie_euro=I.pret_chirie_euro;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os,const Imobil &I) {
        os<<"Adresa: "<<I.adresa_imobil<<", metrii patrati "<<I.m_patrati<<", pret chirie in euro per metru patrat: "<<I.pret_chirie_euro;
        return os;
    }
    friend std::istream& operator>>(std::istream &is, Imobil &I) {
        cout<<"Adresa: ";
        is>>I.adresa_imobil;
        cout<<"Metri patrati: ";
        is>>I.m_patrati;
        cout<<"Pret chirie in euro: ";
        is>>I.pret_chirie_euro;
        return is;
    }
    float pret_chirie_in_lei(){
        float cost_total_chirie_in_euro=cost_chirie();
        return val_euro*cost_total_chirie_in_euro;
    }
    virtual float cost_chirie(){};

    static void schimba_val_euro(float val_actuala){
        val_euro=val_actuala;
    }
};

float Imobil:: val_euro=4.948;


class Casa: public Imobil {
protected:
    int nr_etaje;

public:
    Casa(int nr_etaje_, Adresa adresa_imobil_, int m_patrati_, float pret_chirie_euro_): Imobil(adresa_imobil_, m_patrati_, pret_chirie_euro_) {
        nr_etaje=nr_etaje_;
    }

    Casa(const Casa &C)
            : Imobil(C) {
        nr_etaje=C.nr_etaje;
    }

    void operator=(const Casa &C) {
        (Imobil &) (*this) = C;
        nr_etaje=C.nr_etaje;
    }
    ~Casa(){};
    friend std::ostream &operator<<(std::ostream &os, Casa &C) {
        os<<(Imobil &)(C)<<"Numar de etaje casa: "<<C.nr_etaje<<", ";
        return os;
    }
    friend std::istream& operator>>(std::istream &is, Casa &C) {
        is>>(Imobil &)(C);
        cout<<"Numar de etaje casa: ";
        is>>C.nr_etaje;
        return is;
    }
    void set_nr_etaje(int nr_etaje_) {
        nr_etaje = nr_etaje_;
    }

    int get_nr_etaje() const{
        return nr_etaje;
    }
    float cost_chirie(){
        float cost_chirie_= pret_chirie_euro*m_patrati+10*nr_etaje;
        return cost_chirie_;
    }
};

class Apartament: public Imobil {
protected:
    int etaj;
    int nr_apartament;

public:
    Apartament(int etaj_,int nr_apartament_, Adresa adresa_imobil_, int m_patrati_, float pret_chirie_euro_): Imobil(adresa_imobil_, m_patrati_, pret_chirie_euro_) {
        etaj=etaj_;
        nr_apartament=nr_apartament_;
    }

    Apartament(const Apartament &A): Imobil(A) {
        etaj=A.etaj;
        nr_apartament=A.nr_apartament;
    }

    void operator=(const Apartament &A) {
        (Imobil &) (*this) = A;
        etaj=A.etaj;
        nr_apartament=A.nr_apartament;
    }
    ~Apartament(){};
    friend std::ostream &operator<<(std::ostream &os, Apartament &A) {
        os<<(Imobil &)(A)<<", etajul apartamentului "<<A.etaj<<", nr apartamentului: "<<A.nr_apartament;
        return os;
    }
    friend std::istream& operator>>(std::istream &is, Apartament &C) {
        is>>(Imobil &)(C);
        cout<<"Etajul apartamentului: ";
        is>>C.etaj;
        cout<<"Numarul apartamentului: ";
        is>>C.nr_apartament;
        return is;
    }
    void set_etaj(int etaj_) {
        etaj = etaj_;
    }
    int get_etaj() const{
        return etaj;
    }
    void set_nr_apartament(int nr_apartament_) {
        nr_apartament = nr_apartament_;
    }
    int get_nr_apartament() const{
        return nr_apartament;
    }
    float cost_chirie(){
        float cost_chirie_= pret_chirie_euro*m_patrati;
        return cost_chirie_;
    }
};


class Exception : public std::exception {
public:
    Exception() = default;
    const char* ex() const noexcept {
        return "Nu exista atatea elemente";
    }
};

void vector_n_elemente(){
    int n,x;
    cout<<"Introduceti n:";
    cin>>n;
    Imobil **v;
    v = static_cast<Imobil **>(malloc(sizeof(Imobil *) * n));
    Adresa ad("Bucuresti", "Splaiul Independentei", 203,60234);
    for (int i=0;i<n/2;i++)
    {
        v[i] = new Casa((i+1)%3,ad,40,12.5);
        Casa *p = dynamic_cast<Casa*>(v[i]);
        cout<<*p<<'\n';
    }
    for(int i=n/2;i<n;i++)
    {
        v[i] = new Apartament((i+2)%10,i/4,ad,40,12.5);
        Apartament *p = dynamic_cast<Apartament*>(v[i]);
        cout<<*p<<'\n';
    }
    cout<<"Afisati chiria pt un element: ";
    cin>>x;
    try{
        if(x>=n) throw Exception();;
         cout<<v[x]->pret_chirie_in_lei();;
    }
    catch (const Exception &e) {
        cout << e.ex() << '\n';
    }

}
void vector_pointeri(){
    Adresa adresa1("Bucuresti", "Splaiul Independentei", 203,60234);
    Adresa adresa2("Bucuresti", "Splaiul Independentei", 204,60435);
    Adresa adresa3("Bucuresti", "Splai", 43,60434);
    Imobil *v[3];
    v[0]= new Casa(2,adresa1,40,12.5);
    v[1]= new Apartament(1,5,adresa2,40,7.4 );
    v[2]= new Casa(3,adresa3,60,15.7);
    for(int i=0;i<3;i++)
        cout<<"Chirie in lei: "<<v[i]->pret_chirie_in_lei()<<'\n';
}

void vector_stl()
{
    Adresa adresa1("Bucuresti", "Splaiul Independentei", 203,60234);
    Adresa adresa2("Bucuresti", "Splaiul Independentei", 204,60435);
    Adresa adresa3("Bucuresti", "Splai", 43,60434);
    vector< std::shared_ptr<Imobil> > v;
    std::shared_ptr<Casa> pc( new Casa(2,adresa1,40,12.5));
    std::shared_ptr<Apartament> pa( new Apartament(1,5,adresa2,40,7.4 ));
    std::shared_ptr<Casa> p( new Casa(3,adresa3,60,15.7));
    v.push_back(pc);
    v.push_back(pa);
    v.push_back(p);
    for(int i=0;i<3;i++)
        cout<<"Chirie in lei: "<<v[i]->pret_chirie_in_lei()<<'\n';
}
void testare_Adresa(){
    Adresa ad;
    cin>>ad;
    cout<<ad;
}

int main() {
    int n;
    cout<<"Numarul comenzii: "<<'\n';
    cout<<"1-Testati tipul Adresa"<<'\n';
    cout<<"2-Testati vector de pointeri"<<'\n';
    cout<<"3-Testati vector stl cu smart pointers"<<'\n';
    cout<<"4-Testati vector cu n elemente"<<'\n';
    cin>>n;
    if(n==1) testare_Adresa();
    else
    if(n==2) vector_pointeri();
    else
    if(n==3) vector_stl();
    else
    if(n==4) vector_n_elemente();
    return 0;
}
