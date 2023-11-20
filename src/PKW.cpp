/*
 * PKW.cpp
 *
 *  Created on: 9 Kas 2023
 *      Author: kekillialiresid
 */

#include "PKW.h"


PKW::PKW(std::string name, double maxGeschwindigkeit, double verbrauch, double tankvolumen)
    : Fahrzeug(name, maxGeschwindigkeit), p_dVerbrauch(verbrauch), p_dTankvolumen(tankvolumen), p_dTankinhalt(tankvolumen / 2) {}

PKW::~PKW() {
    // PKW özel kaynak temizleme işlemleri burada yapılır
}

void PKW::dTanken(double menge)
{
    if (menge == std::numeric_limits<double>::infinity()) {
        menge = p_dTankvolumen - p_dTankinhalt; // Volltanken
    } else {
        menge = std::min(menge, p_dTankvolumen - p_dTankinhalt); // Maximal bis Tankvolumen auffüllen
    }
    p_dTankinhalt += menge;
    std::cout << "Getankte Menge: " << menge << " Liter\n";
}


void PKW::vAusgeben(std::ostream& os) const {
    Fahrzeug::vAusgeben(os); // Basisklasse'nin Ausgabe fonksiyonunu çağır
    // PKW'ye özgü ek bilgileri burada yazdır
    os << std::left << std::setw(15) << "Verbrauch: " << p_dVerbrauch << " L/100km"
              << std::setw(15) << "Tankvolumen: " << p_dTankvolumen << " Liter"
              << std::setw(15) << "Tankinhalt: " << p_dTankinhalt << " Liter" << '\n';
}

void PKW::vSimulieren() {
    if (p_dTankinhalt > 0) {
        // Önce Fahrzeug::vSimulieren fonksiyonunu çağırarak temel simülasyon işlemlerini yap

    	double deltaZeit = dGlobaleZeit - p_dZeit;
    	Fahrzeug::vSimulieren();

        // Yolculuk sırasında ne kadar yakıt tüketeceğini hesapla
        // Bu adımda geçen süreyi hesapla
        //double deltaZeit = dGlobaleZeit - p_dZeit;

        double strecke = p_dMaxGeschwindigkeit * deltaZeit; // Bu adımda alınan yol
        double verbrauch = strecke * p_dVerbrauch / 100; // 100 km başına tüketim

        // Tank içeriğini güncelle
        p_dTankinhalt -= verbrauch;

        // Eğer tank içeriği 0'ın altına düşerse, 0'a eşitle
        if (p_dTankinhalt < 0) {
            p_dTankinhalt = 0;
        }

        // Son işlem zamanını güncelle
        p_dZeit = dGlobaleZeit;

    } else {
        std::cout << p_sName << " hat keinen Treibstoff mehr und bleibt stehen.\n";
    }
}
