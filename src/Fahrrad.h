/*
 * Fahrrad.h
 *
 *  Created on: 9 Kas 2023
 *      Author: kekillialiresid
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_


#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug {
public:
    Fahrrad(std::string name, double maxGeschwindigkeit);
    virtual ~Fahrrad();
    virtual void vAusgeben(std::ostream& os) const override;
    virtual void vSimulieren() override;
    virtual double dGeschwindigkeit() const override;
    // Fahrrad'a özgü diğer üye fonksiyonlar...
};



#endif /* FAHRRAD_H_ */
