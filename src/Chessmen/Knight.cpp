#include "Knight.h"
#include "../GameInstance.h"

extern GameInstance* game;

Knight::Knight(ColorType team, QGraphicsItem* parent) : ChessPiece(team, parent) {
    Knight::setImage();
}

void Knight::setImage() {
    if (side == ColorType::Light)
        setPixmap(QPixmap(":/images/KnightLight.png"));
    else
        setPixmap(QPixmap(":/images/KnightDark.png"));
}

// There are total 8 places where a knight can move.
void Knight::moves() {
    int row = this->getCurrentBox()->rowLocation;
    int column = this->getCurrentBox()->columnLocation;

    ColorType team = this->getSide();

    // Up up left.
    int i = row - 2;
    int j = column - 1;

    if (i >= 0 && j >= 0 && game->collection[i][j]->getChessPieceColor() != team) {
        location.append(game->collection[i][j]);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    // Up up right.
    i = row - 2;
    j = column + 1;

    if (i >= 0 && j <= 7 && game->collection[i][j]->getChessPieceColor() != team) {
        location.append(game->collection[i][j]);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    // Down down left.
    i = row + 2;
    j = column - 1;

    if (i <= 7 && j >= 0 && game->collection[i][j]->getChessPieceColor() != team) {
        location.append(game->collection[i][j]);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    // Down down right.
    i = row + 2;
    j = column + 1;

    if (i <= 7 && j <= 7 && game->collection[i][j]->getChessPieceColor() != team) {
        location.append(game->collection[i][j]);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    // Left left up.
    i = row - 1;
    j = column - 2;

    if (i >= 0 && j >= 0 && game->collection[i][j]->getChessPieceColor() != team) {
        location.append(game->collection[i][j]);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    // Left left down.
    i = row + 1;
    j = column - 2;

    if (i <= 7 && j >= 0 && game->collection[i][j]->getChessPieceColor() != team) {
        location.append(game->collection[i][j]);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    // Right right up.
    i = row - 1;
    j = column + 2;

    if (i >= 0 && j <= 7 && game->collection[i][j]->getChessPieceColor() != team) {
        location.append(game->collection[i][j]);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }

    // Right right down.
    i = row + 1;
    j = column + 2;

    if (i <= 7 && j <= 7 && game->collection[i][j]->getChessPieceColor() != team) {
        location.append(game->collection[i][j]);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
        else
            location.last()->setColor(Qt::darkRed);
    }
}
