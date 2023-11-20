/*
 * Fahrrad.cpp
 *
 *  Created on: 9 Kas 2023
 *      Author: kekillialiresid
 */
#include "Fahrrad.h"


Fahrrad::Fahrrad(std::string name, double maxGeschwindigkeit)
    : Fahrzeug(name, maxGeschwindigkeit) {}

Fahrrad::~Fahrrad() {
    // Fahrrad özel kaynak temizleme işlemleri burada yapılır
}

void Fahrrad::vAusgeben(std::ostream& os) const {
    Fahrzeug::vAusgeben(os); // Basisklasse'nin fonksiyonunu çağır
    // Fahrrad'a özgü ek bilgileri burada yazdırabilirsiniz
}

void Fahrrad::vSimulieren() {
    // Simülasyon mantığını burada uygula
    // Örneğin, Fahrrad'ın hızını ve kat ettiği mesafeyi güncelle
	Fahrzeug::vSimulieren();
}

double Fahrrad::dGeschwindigkeit() const {
    double dAktuelleGeschwindigkeit = p_dMaxGeschwindigkeit;
    for (int i = 20; i <= p_dGesamtStrecke; i += 20) {
        dAktuelleGeschwindigkeit *= 0.9; // Her 20 km'de %10 azalt
    }
    return std::max(dAktuelleGeschwindigkeit, 12.0); // Minimum hız 12 km/sa
}
