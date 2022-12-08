#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QColor>
#include <limits.h>

#define VIRUS_RADIUS 0.016
#define VIRUS_CENTER 0.1
#define EPS 1e-6

// Limits
#define DOUBLE_MAX std::numeric_limits<double>::max()
#define FLOAT_MAX std::numeric_limits<float>::max()
#define FLOAT_MIN std::numeric_limits<float>::min()

// Время жизни
#define MULTIPLIER 3.0
#define SKIN_TIME (9.0 * MULTIPLIER)
#define WOOD_TIME (20.0 * MULTIPLIER)
#define PAPER_TIME (30.0 * MULTIPLIER)
#define CERAMICS_TIME (20.0 * MULTIPLIER)
#define AIR_TIME (70.0 * MULTIPLIER)

#endif // CONSTANTS_H
