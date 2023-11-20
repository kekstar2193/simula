/*
 * Parken.h
 *
 *  Created on: 19 Kas 2023
 *      Author: kekillialiresid
 */

#ifndef PARKEN_H_
#define PARKEN_H_

#include "Verhalten.h"

class Parken : public Verhalten {

private:
	double p_dStartzeit;

public:

	Parken(Weg& weg, double startzeit);

    double dStrecke(Fahrzeug& fzg, double dZeitIntervall) override;
    // Diğer üyeler...
};




#endif /* PARKEN_H_ */
