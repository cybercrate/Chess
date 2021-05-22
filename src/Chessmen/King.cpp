#include "King.h"
#include "../GameInstance.h"
#include "Pawn.h"

extern GameInstance* game;

King::King(ColorType team, QGraphicsItem* parent) : ChessPiece(team, parent) {
    King::setImage();
}

void King::setImage() {
    if (side == ColorType::Light)
        setPixmap(QPixmap(":/images/KingLight.png"));
    else
        setPixmap(QPixmap(":/images/KingDark.png"));
}

void King::moves() {
    location.clear();

    int row = this->getCurrentBox()->rowLocation;
    int column = this->getCurrentBox()->columnLocation;

    ColorType team = this->getSide();

    // Up left.
    if (column > 0 && row > 0 &&
            game->collection[row - 1][column - 1]->getChessPieceColor() != team) {
        location.append(game->collection[row - 1][column - 1]);
        game->collection[row - 1][column - 1]->setColor(Qt::darkRed);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
    }

    // Up right.
    if (column < 7 && row > 0 &&
            game->collection[row - 1][column + 1]->getChessPieceColor() != team) {
        location.append(game->collection[row - 1][column + 1]);
        game->collection[row - 1][column + 1]->setColor(Qt::darkRed);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
    }

    // Up.
    if (row > 0 && game->collection[row - 1][column]->getChessPieceColor() != team) {
        location.append(game->collection[row - 1][column]);
        game->collection[row - 1][column]->setColor(Qt::darkRed);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
    }

    // Down.
    if (row < 7 && game->collection[row + 1][column]->getChessPieceColor() != team) {
        location.append(game->collection[row + 1][column]);
        game->collection[row + 1][column]->setColor(Qt::darkRed);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
    }

    // Left.
    if (column > 0 && game->collection[row][column - 1]->getChessPieceColor() != team) {
        location.append(game->collection[row][column - 1]);
        game->collection[row][column - 1]->setColor(Qt::darkRed);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
    }

    // Right.
    if (column < 7 && game->collection[row][column + 1]->getChessPieceColor() != team) {
        location.append(game->collection[row][column + 1]);
        game->collection[row][column + 1]->setColor(Qt::darkRed);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
    }

    // Down left.
    if (column > 0 && row < 7 &&
            game->collection[row + 1][column - 1]->getChessPieceColor() != team) {
        location.append(game->collection[row + 1][column - 1]);
        game->collection[row + 1][column - 1]->setColor(Qt::darkRed);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
    }

    // Down right.
    if (column < 7 && row < 7 &&
            game->collection[row + 1][column + 1]->getChessPieceColor() != team) {
        location.append(game->collection[row + 1][column + 1]);
        game->collection[row + 1][column + 1]->setColor(Qt::darkRed);

        if (location.last()->getHasChessPiece())
            location.last()->setColor(Qt::red);
    }

    findUnsafeLocation();
}

void King::findUnsafeLocation() {
    auto pList = game->alivePiece;
    for (auto& i : pList) {
        if (i->getSide() != this->getSide()) {
            auto bList = i->moveLocation();
            for (auto& j : bList) {
                auto C = dynamic_cast<Pawn*>(i);
                if (C)
                    continue;

                for (auto& k : location)
                    if (j == k)
                        k->setColor(Qt::darkBlue);
            }
        }
    }
}
