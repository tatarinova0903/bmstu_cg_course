#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <vector>
#include <QColor>

#define MATERIAL_TYPES_COUNT 3

enum MaterialType
{
      WOOD, PAPER, CERAMICS, SKIN, CORONA
};

struct Material
{
    MaterialType value;
    std::string raw_value;
    QColor color;
};


struct Materials
{
    Material woodMaterial = { .value = WOOD, .raw_value = "Дерево", .color = QColor(100, 64, 15) };
    Material paperMaterial = { .value = PAPER, .raw_value = "Обои", .color = QColor(135, 206, 250) };
    Material ceramicsMaterial = { .value = CERAMICS, .raw_value = "Керамика", .color = QColor(255, 182, 193) };

    Material skinMaterial = { .value = SKIN, .raw_value = "Кожа", .color = QColor(240, 161, 137) };
    Material virusMaterial = { .value = CORONA, .raw_value = "Вирус", .color = QColor(255, 0, 0) };

    std::vector<Material> value = { woodMaterial, paperMaterial, ceramicsMaterial };
};

#endif // MATERIAL_H
