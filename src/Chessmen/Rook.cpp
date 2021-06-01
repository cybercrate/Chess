#include "Rook.h"
#include "../GameInstance.h"

extern GameInstance* game;

Rook::Rook(ColorType team, QGraphicsItem* parent) : ChessPiece(team, parent) {
    Rook::setImage();
}

void Rook::setImage() {
    if (side == ColorType::Light)
        setPixmap(QPixmap(":/images/Chessmen/RookLight.png"));
    else
        setPixmap(QPixmap(":/images/Chessmen/RookDark.png"));
}

void Rook::moves() {
    location.clear();
    int row = this->getCurrentBox()->rowLocation;
    int column = this->getCurrentBox()->columnLocation;

    ColorType team = this->getSide();

    // For up.
    for (int i = row - 1, j = column; i >= 0; i--) {
        if (game->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }

    // For down.
    for (auto i = row + 1, j = column; i <= 7; i++) {
        if (game->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }

    // For left.
    for (auto I = row, J = column - 1; J >= 0; J--) {
        if (game->collection[I][J]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(game->collection[I][J]);
            if (boxSetting(location.last()))
                break;
        }
    }

    // For right.
    for (auto I = row, J = column + 1; J <= 7; J++) {
        if (game->collection[I][J]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(game->collection[I][J]);
            if (boxSetting(location.last()))
                break;
        }
    }
}
