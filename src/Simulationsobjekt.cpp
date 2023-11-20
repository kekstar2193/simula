/*
 * Simulationsobjekt.cpp
 *
 *  Created on: 16 Kas 2023
 *      Author: kekillialiresid
 */



#include "Simulationsobjekt.h"

int Simulationsobjekt::p_iMaxID = 0; // Statische Membervariable für ID

// Yapıcı Metod
Simulationsobjekt::Simulationsobjekt(const std::string& name) : p_sName(name), p_iID(++p_iMaxID), p_dZeit(0.0) {
    std::cout << "Simulationsobjekt erzeugt: " << p_sName << ", ID: " << p_iID << std::endl;
}

// Yıkıcı Metod
Simulationsobjekt::~Simulationsobjekt() {
    std::cout << "Simulationsobjekt zerstört: " << p_sName << ", ID: " << p_iID << std::endl;
}

// vAusgeben Metodu
void Simulationsobjekt::vAusgeben(std::ostream& os) const {
    os << "ID: " << p_iID << ", Name: " << p_sName << ", Lokale Zeit: " << p_dZeit << std::endl;
}

// Diğer metodlar (eğer varsa) burada tanımlanabilir.

