/*
 * Tempolimit.h
 *
 *  Created on: 16 Kas 2023
 *      Author: kekillialiresid
 */

#ifndef TEMPOLIMIT_H_
#define TEMPOLIMIT_H_

#include <limits>

enum class Tempolimit {
    Innerorts = 50, // 50 km/h
    Landstrasse = 100, // 100 km/h
    Autobahn = std::numeric_limits<int>::max() // Unbegrenzt
};




#endif /* TEMPOLIMIT_H_ */
