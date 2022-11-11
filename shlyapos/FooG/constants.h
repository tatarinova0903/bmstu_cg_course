#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QColor>
#include <limits.h>

#define VIRUS_RADIUS 0.015
#define VIRUS_CENTER 0.1
#define EPS 1e-6

// Limits
#define DOUBLE_MAX std::numeric_limits<double>::max()
#define FLOAT_MAX std::numeric_limits<float>::max()
#define FLOAT_MIN std::numeric_limits<float>::min()

// Время жизни
#define MULTIPLIER 5.0
#define SKIN_TIME (9.0 * MULTIPLIER)
#define WOOD_TIME (96.0 * MULTIPLIER)
#define PAPER_TIME (108.0 * MULTIPLIER)
#define CERAMICS_TIME (20.0 * MULTIPLIER)
#define AIR_TIME (72.0 * MULTIPLIER)

#endif // CONSTANTS_H
