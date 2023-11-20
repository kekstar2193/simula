/*
 * Weg.h
 *
 *  Created on: 16 Kas 2023
 *      Author: kekillialiresid
 */

#ifndef WEG_H
#define WEG_H

#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Tempolimit.h"
#include <list>
#include <memory>


class Fahrzeug;
class Verhalten;
class Weg;

class Weg : public Simulationsobjekt {
private:
    double p_dLaenge;
    std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
    Tempolimit p_eTempolimit;

public:
    Weg();
    Weg(const std::string& name, double laenge, Tempolimit tempolimit = Tempolimit::Autobahn);

    double getTempolimit() const;
    const std::string& getName() const;

    virtual void vSimulieren() override;
    virtual void vAusgeben(std::ostream& os) const override;

    void vAnnahme(std::unique_ptr<Fahrzeug> pFzg);
    void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double startzeit); // Park eden araçlar için

    static void vKopf();
    double dGeschwindigkeit() const override;
    double getLaenge() const
    {
    	return p_dLaenge;
    }
};

std::ostream& operator<<(std::ostream& os, const Weg& weg);

#endif // WEG_H

