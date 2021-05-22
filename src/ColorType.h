#ifndef COLORTYPE_H
#define COLORTYPE_H

#include <QString>

enum class ColorType {
    None,
    Light,
    Dark,
};

QString colorToString(ColorType type);

#endif // COLORTYPE_H
