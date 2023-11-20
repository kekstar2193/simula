//============================================================================
// Name        : Aufgabenblock_2.cpp
// Author      : Asidovic
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "Fahren.h"
#include "Parken.h"
#include "Verhalten.h"

using namespace std;


void vAufgabe2() {
    std::vector<std::unique_ptr<Fahrzeug>> vFahrzeuge;
    int anzahlPKW, anzahlFahrrad;
    std::string name;
    double maxGeschwindigkeit, verbrauch, tankvolumen;

    std::cout << "Anzahl der PKWs: ";
    std::cin >> anzahlPKW;
    for (int i = 0; i < anzahlPKW; ++i) {
        std::cout << "PKW #" << i+1 << " Name: ";
        std::cin >> name;
        std::cout << "Maximalgeschwindigkeit: ";
        std::cin >> maxGeschwindigkeit;
        std::cout << "Verbrauch (Liter/100km): ";
        std::cin >> verbrauch;
        std::cout << "Tankvolumen (optional, Default=55): ";
        std::cin >> tankvolumen;
        vFahrzeuge.push_back(std::make_unique<PKW>(name, maxGeschwindigkeit, verbrauch, tankvolumen));
    }

    std::cout << "Anzahl der Fahrraeder: ";
    std::cin >> anzahlFahrrad;
    for (int i = 0; i < anzahlFahrrad; ++i) {
        std::cout << "Fahrrad #" << i+1 << " Name: ";
        std::cin >> name;
        std::cout << "Maximalgeschwindigkeit: ";
        std::cin >> maxGeschwindigkeit;
        vFahrzeuge.push_back(std::make_unique<Fahrrad>(name, maxGeschwindigkeit));
    }

    const double zeittakt = 0.3; // 15 Minuten
    const double gesamtZeit = 10; // 5 Stunden für die Simulation
    const double tankZeit = 3.0; // Nach 3 Stunden tanken
    double epsilon = 0.001; // Toleranz für double-Vergleiche


    while (dGlobaleZeit < gesamtZeit) {


           if (std::fabs(dGlobaleZeit - tankZeit) < epsilon) {
                for (auto& fahrzeug : vFahrzeuge) {
                    // Fahrzeug'un PKW olup olmadığını kontrol et
                    PKW* pkw = dynamic_cast<PKW*>(fahrzeug.get());
                    if (pkw) {
                        // PKW ise tankı doldur
                        pkw->dTanken(std::numeric_limits<double>::infinity()); // Sonsuz miktar vererek tamamen doldur
                        fahrzeug->vAusgeben(std::cout);
                    }
                }
            }

           dGlobaleZeit += zeittakt;

           for (auto& fahrzeug : vFahrzeuge) {
               Fahrzeug::vKopf();
        	   fahrzeug->vSimulieren(); // Simülasyon fonksiyonu
               fahrzeug->vAusgeben(std::cout);   // Ausgabe fonksiyonu
           }

           std::cout << "Globale Zeit: " << dGlobaleZeit << " Stunden\n";

       }
}


void vAufgabe4() {
    // Weg nesnesi oluşturma
    Weg meinWeg("Hauptstrasse", 10.0, Tempolimit::Innerorts);

    // Weg nesnesini standart çıktıya yazdırma
    std::cout << meinWeg << std::endl;
}

void vAufgabe5() {
    Weg meinWeg("Autobahn", 500);

    std::unique_ptr<Fahrzeug> fzg1(new Fahrzeug("BMW", 120));
    std::unique_ptr<Fahrzeug> fzg2(new Fahrzeug("Audi", 150));
    std::unique_ptr<Fahrzeug> fzg3(new Fahrzeug("Mercedes", 130));

    meinWeg.vAnnahme(std::move(fzg1));
    meinWeg.vAnnahme(std::move(fzg2));
    meinWeg.vAnnahme(std::move(fzg3));

    for (int i = 0; i < 10; ++i) { // Örnek olarak 10 adım simülasyon
        std::cout << "Simülasyon Adımı: " << i + 1 << std::endl;
        meinWeg.vSimulieren();
        // Diğer çıktılar...
        std::cout << "---------------------------------" << std::endl;
    }

    // Sonuçların görüntülenmesi
    // ...
}

void vAufgabe6() {
    // Yolları oluştur
    Weg autobahn("Autobahn", 500); // 500 km uzunluğunda
    Weg landstrasse("Landstrasse", 300); // 300 km uzunluğunda

    // Araçları oluştur
    Fahrzeug auto1("Auto1", 120); // Saatte 120 km hızla
    Fahrzeug auto2("Auto2", 90); // Saatte 90 km hızla

    // Araçlara davranışları ata
    auto1.vNeueStrecke(autobahn);
    auto2.vNeueStrecke(landstrasse, 1); // 5 dakika sonra başlayacak (0.0833 saat)

    const double zeittakt = 0.25; // 15 dakika (0.25 saat)
    const double gesamtZeit = 10; // 10 saat için simülasyon

    while (dGlobaleZeit < gesamtZeit) {
        dGlobaleZeit += zeittakt;

        // Araçların simülasyonunu gerçekleştir
        auto1.vSimulieren();
        auto2.vSimulieren();

        // Araçların güncel durumlarını yazdır
        std::cout << "Zeit: " << dGlobaleZeit << " Stunden" << std::endl;
        std::cout << "Fahrzeug " << auto1.getName() << " hat " << auto1.getGesamtStrecke() << " km kat etti." << std::endl;
        std::cout << "Fahrzeug " << auto2.getName() << " hat " << auto2.getGesamtStrecke() << " km kat etti." << std::endl;
    }
}



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//vAufgabe2();
	//vAufgabe4();
	//vAufgabe5();

	vAufgabe6();

	return 0;
}

