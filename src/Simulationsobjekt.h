/*
 * Simulationsobjekt.h
 *
 *  Created on: 15 Kas 2023
 *      Author: kekillialiresid
 */

#ifndef SIMULATIONSOBJEKT_H
#define SIMULATIONSOBJEKT_H

#include <string>
#include <iostream>

class Simulationsobjekt {
protected:
    std::string p_sName;
    static int p_iMaxID;
    const int p_iID;
    double p_dZeit;

public:
    Simulationsobjekt(const std::string& name);
    virtual void vAusgeben(std::ostream& os) const = 0;


    virtual void vSimulieren() = 0; // Saf sanal metod

    virtual ~Simulationsobjekt();


    // Copy-Konstruktör yasaklanıyor
    Simulationsobjekt(const Simulationsobjekt&) = delete;
    Simulationsobjekt& operator=(const Simulationsobjekt&) = delete;

    // ID oluşturma fonksiyonu
    static int generateId() {
        static int currentId = 0;
        return ++currentId;
    }

    virtual double dGeschwindigkeit() const = 0;
};




#endif /* SIMULATIONSOBJEKT_H */
