#include "ColorType.h"

QString colorToString(ColorType type) {
    switch (type) {
    case ColorType::Light:
        return "Light";
    case ColorType::Dark:
        return "Dark";
    default:
        return "None";
    }
}
