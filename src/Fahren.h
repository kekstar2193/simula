/*
 * Fahren.h
 *
 *  Created on: 19 Kas 2023
 *      Author: kekillialiresid
 */

#ifndef FAHREN_H_
#define FAHREN_H_

#include "Verhalten.h"

class Fahren : public Verhalten {

public:

	Fahren(Weg& weg);
	virtual double dStrecke(Fahrzeug& fzg, double dZeitIntervall) override;

};




#endif /* FAHREN_H_ */
