/*
 * Fahrzeug.cpp
 *
 *  Created on: 22 Eyl 2023
 *      Author: kekillialiresid
 */
#include "Fahrzeug.h"
#include "Fahren.h"
#include "Parken.h"



double dGlobaleZeit = 0.0; // Global zamanı başlat
//operator uberladung
std::ostream& operator<<(std::ostream& os, const Fahrzeug& fahrzeug)
{
    fahrzeug.vAusgeben(os);
    return os;
}

//Konstruktoren
Fahrzeug::Fahrzeug() : Simulationsobjekt(""), p_dMaxGeschwindigkeit(0.0), p_dGesamtStrecke(0.0), p_dGesamtZeit(0.0), p_dAbschnittStrecke(0.0) { // @suppress("Symbol is not resolved")
    std::cout << "Fahrzeug erzeugt: (Kein Name), ID: " << p_iID << std::endl;
}
Fahrzeug::Fahrzeug(std::string name) : Simulationsobjekt(name), p_dMaxGeschwindigkeit(0.0), p_dGesamtStrecke(0.0), p_dGesamtZeit(0.0),p_dAbschnittStrecke(0.0) {
    std::cout << "Fahrzeug erzeugt: " << p_sName << ", ID: " << p_iID << std::endl;
}

double Fahrzeug::dGeschwindigkeit() const {
    return p_dMaxGeschwindigkeit; // PKW her zaman maksimum hızda hareket eder
}

Fahrzeug::Fahrzeug(std::string name, double maxGeschwindigkeit) : Simulationsobjekt(name), p_dMaxGeschwindigkeit(maxGeschwindigkeit > 0 ? maxGeschwindigkeit : 0), p_dGesamtStrecke(0.0), p_dGesamtZeit(0.0), p_dAbschnittStrecke(0.0)
{
    // Konstruktor-Logik hier
}

Fahrzeug::~Fahrzeug() {
    //std::cout << "Fahrzeug zerstoert: " << p_sName << ", ID: " << p_iID << std::endl;
}

//Memberfunktion vAusgeben
void Fahrzeug::vAusgeben(std::ostream& os) const
{
    Simulationsobjekt::vAusgeben(os); // Simulationsobjekt'in vAusgeben metodunu çağır
    // Fahrzeug'a özel ek bilgileri burada yazdır
    os << "MaxGeschwindigkeit: " << p_dMaxGeschwindigkeit << ", Gesamtstrecke: " << p_dGesamtStrecke << std::endl;
}

// Klassenfunktion vKopf zur Ausgabe der Überschrift
void Fahrzeug::vKopf()
{
    std::cout << std::left
    		  << std::setw(10) << "ID"
              << std::setw(15) << "Name"
              << std::setw(20) << "MaxGeschwindigkeit"
              << std::setw(15) << "Gesamtstrecke"
              << '\n'
              << std::setfill('-') << std::setw(60) << "" << std::setfill(' ') << '\n';
}


void Fahrzeug::vSimulieren()
{
    double deltaZeit = dGlobaleZeit - p_dZeit;
    if (deltaZeit > 0) {
        double dTempGeschwindigkeit = dGeschwindigkeit(); // Aktüel hızı al
        double dStreckeDiesesIntervall = dTempGeschwindigkeit * deltaZeit; // Yeni mesafeyi hesapla
        double dStrecke = p_pVerhalten->dStrecke(*this, deltaZeit);

        if (p_dGesamtStrecke + dStreckeDiesesIntervall >= p_pVerhalten->getWeg().getLaenge())
           {
                    p_dGesamtStrecke = p_pVerhalten->getWeg().getLaenge(); // Yolu tamamla
                    std::cout << "Fahrzeug " << getName() << " hat das Ende des Weges erreicht." << std::endl;
           }
        else
        	{
                    p_dGesamtStrecke += dStreckeDiesesIntervall; // Yeni mesafeyi hesapla
            }



        p_dAbschnittStrecke += dStreckeDiesesIntervall;
        p_dGesamtZeit += deltaZeit;
        p_dZeit = dGlobaleZeit; // Son işlem zamanını güncelle,


    }
    std::cout << "Fahrzeug " << p_sName << " hat " << p_dGesamtStrecke << " km kat etti." << std::endl;
}

bool Fahrzeug::operator<(const Fahrzeug& other) const {

	return p_dGesamtStrecke < other.p_dGesamtStrecke;
}

Fahrzeug& Fahrzeug::operator=(const Fahrzeug& other) {
    if (this != &other) {
        // Sadece belirli üye değişkenleri kopyala
    	p_sName = other.p_sName;
    	p_dMaxGeschwindigkeit = other.p_dMaxGeschwindigkeit;
        // Örneğin: p_sName = other.p_sName;
        // ID'yi kopyalama
    }
    return *this;
}

void Fahrzeug::vNeueStrecke(Weg& weg) {
	p_pVerhalten = std::make_unique<Fahren>(weg);
    p_dAbschnittStrecke = 0.0;
}

void Fahrzeug::vNeueStrecke(Weg& weg, double startzeit) {
    // Parken türünde bir Verhalten nesnesi oluştur
    p_pVerhalten = std::make_unique<Parken>(weg, startzeit);
}

