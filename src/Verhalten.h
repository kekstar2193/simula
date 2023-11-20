/*
 * Verhalten.h
 *
 *  Created on: 18 Kas 2023
 *      Author: kekillialiresid
 */

#ifndef VERHALTEN_H_
#define VERHALTEN_H_

#include "Weg.h"
#include "Fahrzeug.h"
#include "Tempolimit.h"
#include <list>
#include <memory>
#include "Simulationsobjekt.h"


class Fahrzeug;
class Weg;

class Verhalten {
private:
    Weg& p_Weg;

public:
    Verhalten(Weg& weg) : p_Weg(weg) {}
    Weg& getWeg() const { return p_Weg; }

    virtual double dStrecke(Fahrzeug& fzg, double dZeitIntervall) = 0;

    virtual ~Verhalten() {}
};



#endif /* VERHALTEN_H_ */
