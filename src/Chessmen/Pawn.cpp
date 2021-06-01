#include "Pawn.h"
#include "../GameInstance.h"

extern GameInstance* game;

Pawn::Pawn(ColorType team, QGraphicsItem* parent) : ChessPiece(team, parent) {
    Pawn::setImage();
    firstMove = true;
}

void Pawn::setImage() {
    if (side == ColorType::Light)
        setPixmap(QPixmap(":/images/Chessmen/PawnLight.png"));
    else
        setPixmap(QPixmap(":/images/Chessmen/PawnDark.png"));
}

void Pawn::moves() {
    location.clear();

    int row = this->getCurrentBox()->rowLocation;
    int column = this->getCurrentBox()->columnLocation;

    if (this->getSide() == ColorType::Light) {
        // Down left.
        ColorType pieceColor = game->collection[row - 1][column - 1]->getChessPieceColor();

        if (column > 0 && row > 0 && pieceColor == ColorType::Dark) {
            location.append(game->collection[row - 1][column - 1]);
            boxSetting(location.last());
        }

        // Down right.
        pieceColor = game->collection[row - 1][column + 1]->getChessPieceColor();

        if (column < 7 && row > 0 && pieceColor == ColorType::Dark) {
            location.append(game->collection[row - 1][column + 1]);
            boxSetting(location.last());
        }

        // Down.
        bool hasChessPiece = game->collection[row - 1][column]->getHasChessPiece();

        if (row > 0 && !hasChessPiece) {
            location.append(game->collection[row - 1][column]);
            boxSetting(location.last());

            if (firstMove && !game->collection[row - 2][column]->getHasChessPiece()) {
                location.append(game->collection[row - 2][column]);
                boxSetting(location.last());
            }
        }
    } else {
        // Left up.
        ColorType pieceColor = game->collection[row + 1][column - 1]->getChessPieceColor();

        if (column > 0 && row < 7 && pieceColor == ColorType::Light) {
            location.append(game->collection[row + 1][column - 1]);
            boxSetting(location.last());
        }

        // Right up.
        pieceColor = game->collection[row + 1][column + 1]->getChessPieceColor();

        if (column < 7 && row < 7 && pieceColor == ColorType::Light) {
            location.append(game->collection[row + 1][column + 1]);
            boxSetting(location.last());
        }

        // Up.
        bool hasChessPiece = game->collection[row + 1][column]->getHasChessPiece();

        if (row < 7 && !hasChessPiece) {
            location.append(game->collection[row + 1][column]);
            boxSetting(location.last());

            hasChessPiece = game->collection[row + 2][column]->getHasChessPiece();

            if (firstMove && !hasChessPiece) {
                location.append(game->collection[row + 2][column]);
                boxSetting(location.last());
            }
        }
    }
}
