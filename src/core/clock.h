//
// Created by krist on 28.10.2025.
//

#ifndef CLOCK_H
#define CLOCK_H

#pragma once
#include <chrono>

namespace gs {

// Stabil klokke for måling av tidsintervaller.
// Returnerer sekunder siden programstart som double.
double now_seconds();

// Sov i minst ms millisekunder (best effort).
void sleep_ms(int ms);

}

#endif //CLOCK_H
