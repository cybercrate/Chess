#include "ChessPiece.h"
#include "Chessmen/King.h"
#include "GameInstance.h"

extern GameInstance* game;

ChessPiece::ChessPiece(ColorType team, QGraphicsItem* parent) : QGraphicsPixmapItem(parent) {
    side = team;
    isPlaced = true;
    firstMove = true;
}

void ChessPiece::mousePressEvent(QGraphicsSceneMouseEvent* sceneMouseEvent) {
    // Deselect.
    if (this == game->pieceToMove) {
        game->pieceToMove->getCurrentBox()->resetOriginalColor();
        game->pieceToMove->resetColor();
        game->pieceToMove = nullptr;
        return;
    }

    // If it is already consumed or not the respective color's turn_.
    if (!getIsPlaced() || (game->getTurn() != this->getSide() && !game->pieceToMove))
        return;

    // Selecting.
    if (!game->pieceToMove) {
        game->pieceToMove = this;
        game->pieceToMove->getCurrentBox()->setColor(Qt::red);
        game->pieceToMove->moves();
    } else if (this->getSide() != game->pieceToMove->getSide()) {
        // Consuming counterPart of the chess box.
        this->getCurrentBox()->mousePressEvent(sceneMouseEvent);
    }
}

void ChessPiece::setCurrentBox(ChessBox* value) {
    currentBox = value;
}

ChessBox* ChessPiece::getCurrentBox() {
    return currentBox;
}

ColorType ChessPiece::getSide() {
    return side;
}

[[maybe_unused]] void ChessPiece::setSide(ColorType value) {
    side = value;
}

bool ChessPiece::getIsPlaced() const {
    return isPlaced;
}

void ChessPiece::setIsPlaced(bool value) {
    isPlaced = value;
}

QList<ChessBox*> ChessPiece::moveLocation() {
    return location;
}

void ChessPiece::resetColor() {
    for (auto& item : location)
        item->resetOriginalColor();
}

bool ChessPiece::boxSetting(ChessBox* box) {
    if (box->getHasChessPiece()) {
        auto pKing = dynamic_cast<King*>(location.last()->currentPiece);

        if (pKing)
            box->setColor(Qt::black);
        else
            box->setColor(Qt::red);
        return true;
    } else {
        location.last()->setColor(Qt::darkRed);
    }

    return false;
}
