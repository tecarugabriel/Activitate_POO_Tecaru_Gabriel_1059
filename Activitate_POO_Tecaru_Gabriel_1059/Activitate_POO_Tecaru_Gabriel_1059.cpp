#include <iostream>
#include <string.h>

using namespace std;


class Proiect {
    const int id;
    string denumire;
    int nrMembri;
    int nrEtape;
    float* durataEtape;
    float bugetLuna;
    float estimareCheltuieli;

    //  - - ------ 
public:


    // constructor cu parametrul id
    Proiect(const int id) :id(0) {
        this->denumire = "Anonim";
        this->nrMembri = 0;
        this->nrEtape = 0;
        this->durataEtape = nullptr;
        this->bugetLuna = 0.0;
        this->estimareCheltuieli = 0.0;

    }
    // constructor cu parametrii
    Proiect(int _id, string _denumire, int _nrMembri, int _nrEtape, float* _durataEtape, float _bugetLuna, float _estimareCheltuieli) :id(_id) {
        this->denumire = _denumire;
        if (_nrMembri >= 1)
        {
            this->nrMembri = _nrMembri;
        }
        else {
            this->nrMembri = 1;
            cout << "nu exista membri";
        }
        
        if (_nrEtape > 0 && _durataEtape != nullptr) {
            this->nrEtape = _nrEtape;
            this->durataEtape = new float[nrEtape];
            for (int i = 0; i < nrEtape; i++)
            {

                this->durataEtape[i] = _durataEtape[i];
            }
        }

        else {
            cout << "nu exista etape";
            this->nrEtape = 0;
            this->durataEtape = nullptr;
        }
        this->bugetLuna = _bugetLuna;
        this->estimareCheltuieli = _estimareCheltuieli;
    }

    //getter-setteri 
    int getnrEtape() {
        return this->nrEtape;
    }

    void setnrEtape(int _nrEtape) {
        this->nrEtape = _nrEtape;
    }

    // constructor de copiere 
    Proiect(const Proiect& p) :id(p.id) {
        this->denumire = p.denumire;
        this->bugetLuna = p.bugetLuna;
        this->estimareCheltuieli = p.estimareCheltuieli;
        if (p.nrMembri >= 1)
        {
            this->nrMembri = p.nrMembri;

        }
        else this->nrMembri = 1;

        if (p.nrEtape > 0 && p.durataEtape != nullptr) {
            this->nrEtape = p.nrEtape;
            this->durataEtape = new float[nrEtape];
            for (int i = 0; i < nrEtape; i++)
            {
                this->durataEtape[i] = p.durataEtape[i];
            }
        }

        else {
            this->nrEtape = 0;
            this->durataEtape = nullptr;
        }
    }


    /// supraincarcare operator = 
    Proiect& operator=(const Proiect& other) {
        if (this != &other) {
            if (this->durataEtape != nullptr)
            {
                delete[] durataEtape;
            }
            this->durataEtape = nullptr;

            if (other.nrEtape > 0 && other.durataEtape != nullptr) {
                this->nrEtape = other.nrEtape;
                this->durataEtape = new float[nrEtape];
                for (int i = 0; i < nrEtape; i++)
                {
                    this->durataEtape[i] = other.durataEtape[i];
                }
            }

            else {
                this->nrEtape = 0;
                this->durataEtape = nullptr;
            }
            this->nrMembri = other.nrMembri;
            this->denumire = other.denumire;
            this->bugetLuna = other.bugetLuna;
            this->estimareCheltuieli = other.estimareCheltuieli;

        }
        return *this;
    }
    

    void afisare_info() {
        cout << id << "  " << denumire << " " <<
            nrMembri << "  " << nrEtape << "  " << bugetLuna << " " << estimareCheltuieli << endl;
    }

    //destructor
    ~Proiect() {
        if (this->durataEtape != nullptr)
        {
            delete[] durataEtape;
        }
        this->durataEtape = nullptr;

    }

};


int main()
{
    Proiect p1(50); // apel constructor 1 parametru
    float etape[] = { 1.4, 2.4, 3.5, 5.0 };
    Proiect p2(40, "Renovare Apartament", 3, 4, etape, 3000, 2500); // apel constructor cu toti parametrii
    float etape2[] = { 1.5 , 2.2, 4, 6 , 2.5 };
    
    Proiect p3 = p2; // apel constructor de copiere
    p1.afisare_info();
    cout << endl;
    p2.afisare_info();
    cout << endl;
    p3.afisare_info();
    cout << endl;

    Proiect p5(40, "Reparare masina", 3, 5, etape, 1500, 1000);
    Proiect p4(20);
    p4.afisare_info();
    p4 = p5; // apel operator egal
    p4.afisare_info();
    cout << "---------" << endl;
    p5.afisare_info();
    cout << endl;

    return 0;
}

