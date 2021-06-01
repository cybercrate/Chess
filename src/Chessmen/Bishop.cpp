#include "Bishop.h"
#include "../GameInstance.h"

extern GameInstance* game;

Bishop::Bishop(ColorType team, QGraphicsItem* parent) : ChessPiece(team, parent) {
    Bishop::setImage();
}

void Bishop::setImage() {
    if (side == ColorType::Light)
        setPixmap(QPixmap(":/images/Chessmen/BishopLight.png"));
    else
        setPixmap(QPixmap(":/images/Chessmen/BishopDark.png"));
}

void Bishop::moves() {
    location.clear();

    int row = this->getCurrentBox()->rowLocation;
    int column = this->getCurrentBox()->columnLocation;

    ColorType team = this->getSide();

    // Upper Left.
    for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
        ColorType pieceColor = game->collection[i][j]->getChessPieceColor();

        if (pieceColor == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }

    // Upper right.
    for (int i = row - 1, j = column + 1; i >= 0 && j <= 7; i--, j++) {
        ColorType pieceColor = game->collection[i][j]->getChessPieceColor();

        if (pieceColor == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }

    // Downward right.
    for (int i = row + 1, j = column + 1; i <= 7 && j <= 7; i++, j++) {
        ColorType pieceColor = game->collection[i][j]->getChessPieceColor();

        if (pieceColor == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }

    // Downward left.
    for (int i = row + 1, j = column - 1; i <= 7 && j >= 0; i++, j--) {
        ColorType pieceColor = game->collection[i][j]->getChessPieceColor();

        if (pieceColor == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }
}
