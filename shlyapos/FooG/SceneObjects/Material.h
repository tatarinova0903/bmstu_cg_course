#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <vector>

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
    std::vector<Material> value = {
        { .value = WOOD, .raw_value = "Дерево" },
        { .value = PAPER, .raw_value = "Обои" },
        { .value = CERAMICS, .raw_value = "Керамика" }
    };
};

#endif // MATERIAL_H
