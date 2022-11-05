#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>

#define MATERIAL_TYPES_COUNT 3

enum MaterialType
{
      WOOD, PAPER, CERAMICS
};

struct Material
{
    MaterialType value;
    std::string raw_value;
};

struct Materials
{
    Material value[MATERIAL_TYPES_COUNT] = {
        { .value = WOOD, .raw_value = "Дерево" },
        { .value = PAPER, .raw_value = "Обои" },
        { .value = CERAMICS, .raw_value = "Керамика" }
    };
};

#endif // MATERIAL_H
