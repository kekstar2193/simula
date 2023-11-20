/*
 * Parken.cpp
 *
 *  Created on: 19 Kas 2023
 *      Author: kekillialiresid
 */


#include "Parken.h"
#include "Fahrzeug.h"
#include "Weg.h"

Parken::Parken(Weg& weg, double startzeit) : Verhalten(weg), p_dStartzeit(startzeit) {}

double Parken::dStrecke(Fahrzeug& fzg, double dZeitIntervall) {
    // Eğer global zaman, park başlangıç zamanından küçükse, araç hareket etmez
    if (dGlobaleZeit < p_dStartzeit) {
        return 0.0;
    }

    // Park başlangıç zamanı geçildiyse, normal hareket hesaplamalarına devam et
    double geschwindigkeit = fzg.dGeschwindigkeit();
    double strecke = geschwindigkeit * dZeitIntervall;

    // Yolun sonuna ulaşıp ulaşmadığını kontrol et
    if (getWeg().getLaenge() - fzg.getAbschnittStrecke() < strecke) {
        return getWeg().getLaenge() - fzg.getAbschnittStrecke();
    }

    return strecke;
}

