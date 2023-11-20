/*
 * Fahren.cpp
 *
 *  Created on: 19 Kas 2023
 *      Author: kekillialiresid
 */

#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Verhalten.h"

// Konstruktor
Fahren::Fahren(Weg& weg) : Verhalten(weg) {}

// dStrecke fonksiyonunun implementasyonu
double Fahren::dStrecke(Fahrzeug& fzg, double dZeitIntervall) {
    double dGeschwindigkeit = fzg.dGeschwindigkeit(); // Fahrzeug sınıfından hızı al
    double dStrecke = dGeschwindigkeit * dZeitIntervall; // Zaman aralığına göre mesafeyi hesapla

    if (getWeg().getLaenge() - fzg.getAbschnittStrecke() < dStrecke) {
           return getWeg().getLaenge() - fzg.getAbschnittStrecke();
       }

    return dStrecke; // Hesaplanan mesafeyi döndür
}



