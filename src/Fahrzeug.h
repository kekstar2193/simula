/*
 * Fahrzeug.h
 *
 *  Created on: 22 Eyl 2023
 *      Author: kekillialiresid
 */

#ifndef FAHRZEUG_H
#define FAHRZEUG_H

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Simulationsobjekt.h"
#include "Verhalten.h"
#include "Weg.h"
#include "Tempolimit.h"

extern double dGlobaleZeit; // Global zaman değişkeni

// Vorwärtsdeklaration der Fahrzeug-Klasse
class Fahrzeug;
class Weg;
class Verhalten;
// Deklaration der Klassenfunktion vKopf
void vKopf();


class Fahrzeug : public Simulationsobjekt {
protected:

    double p_dMaxGeschwindigkeit;
    double p_dGesamtStrecke;
    double p_dGesamtZeit;
    double p_dAbschnittStrecke; // Yeni üye değişken
    std::unique_ptr<Verhalten> p_pVerhalten; // Verhalten için smart pointer


public:
    Fahrzeug(std::string name);
    Fahrzeug();
    Fahrzeug(std::string name, double maxGeschwindigkeit);

    Fahrzeug(const Fahrzeug& other) = delete; // Copy konstruktörü yasakla

    Fahrzeug& operator=(const Fahrzeug& other); // Zuweisungsoperator tanımı

    virtual ~Fahrzeug();

    virtual double dGeschwindigkeit() const override;

    // Memberfunktion vAusgeben
    virtual void vAusgeben(std::ostream& os) const override;

    static void vKopf();

    virtual void vSimulieren() override; // Simulasyon fonksiyonu

    bool operator<(const Fahrzeug& other) const;

    const std::string& getName() const
    {
        return p_sName;
    }

    double getAbschnittStrecke() const
    {
    	return p_dAbschnittStrecke;
    }
    double getGesamtStrecke() const
    {
    	return	p_dGesamtStrecke;
    }

    void vNeueStrecke(Weg& weg); // Yeni fonksiyon

    void vNeueStrecke(Weg& weg, double startzeit);



};

std::ostream& operator<<(std::ostream& os, const Fahrzeug& fahrzeug);



#endif // FAHRZEUG_H
