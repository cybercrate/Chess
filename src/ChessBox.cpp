#include "ChessBox.h"
#include "Chessmen/King.h"
#include "GameInstance.h"

extern GameInstance* game;

ChessBox::ChessBox(QGraphicsItem* parent) : QGraphicsRectItem(parent) {
    // Making the square board_ box.
    setRect(0.0, 0.0, 50.0, 50.0);
    brush_.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setChessPieceColor(ColorType::None);
}

ChessBox::~ChessBox() {
    delete this;
}

void ChessBox::mousePressEvent(QGraphicsSceneMouseEvent* sceneMouseEvent) {
    // Deselecting counter part of ChessPiece.
    if (currentPiece == game->pieceToMove && currentPiece) {
        currentPiece->mousePressEvent(sceneMouseEvent);
        return;
    }

    // If selected.
    if (game->pieceToMove) {
        // If same team.
        if (this->getChessPieceColor() == game->pieceToMove->getSide())
            return;

        // Removing the eaten piece.
        auto moveLocation = game->pieceToMove->moveLocation();

        // To make sure the selected box is in move zone.
        int check = 0;

        for (auto& item : moveLocation)
            if (item == this)
                check++;

        // If not present return.
        if (check == 0)
            return;

        // Change the color back to normal.
        game->pieceToMove->resetColor();

        // Make the first move false applicable for pawn only.
        game->pieceToMove->firstMove = false;

        // This is to eat or consume the enemy present inn the movable region.
        if (this->getHasChessPiece()) {
            this->currentPiece->setIsPlaced(false);
            this->currentPiece->setCurrentBox(nullptr);
            game->placeInDeadPlace(this->currentPiece);
        }

        // Changing the new stat and resetting the previous left region.
        game->pieceToMove->getCurrentBox()->setHasChessPiece(false);
        game->pieceToMove->getCurrentBox()->currentPiece = nullptr;
        game->pieceToMove->getCurrentBox()->resetOriginalColor();
        placePiece(game->pieceToMove);
        game->pieceToMove = nullptr;

        // Changing turn_.
        game->changeTurn();
        checkForCheck();
    } else if (this->getHasChessPiece()) {
        // Selecting counterpart of the ChessPiece.
        this->currentPiece->mousePressEvent(sceneMouseEvent);
    }
}

void ChessBox::setColor(const QColor& color) {
    brush_.setColor(color);
    setBrush(color);
}

void ChessBox::placePiece(ChessPiece* piece) {
    piece->setPos(x() + 25 - double(piece->pixmap().width()) / 2,
                  y() + 25 - double(piece->pixmap().width()) / 2);
    piece->setCurrentBox(this);
    setHasChessPiece(true, piece);
    currentPiece = piece;
}

void ChessBox::resetOriginalColor() {
    setColor(originalColor_);
}

void ChessBox::setOriginalColor(QColor value) {
    originalColor_ = std::move(value);
    setColor(originalColor_);
}

bool ChessBox::getHasChessPiece() const {
    return hasChessPiece_;
}

void ChessBox::setHasChessPiece(bool value, ChessPiece* piece) {
    hasChessPiece_ = value;

    if (value)
        setChessPieceColor(piece->getSide());
    else
        setChessPieceColor(ColorType::None);
}

void ChessBox::checkForCheck() {
    int c = 0;
    auto pList = game->alivePiece;

    for (auto& i : pList) {
        auto pKing = dynamic_cast<King*>(i);
        if (pKing)
            continue;

        i->moves();
        i->resetColor();

        auto bList = i->moveLocation();
        for (auto& j : bList) {
            auto qKing = dynamic_cast<King*>(j->currentPiece);

            if (qKing) {
                if (qKing->getSide() == i->getSide())
                    continue;

                j->setColor(Qt::blue);
                i->getCurrentBox()->setColor(Qt::darkRed);

                if (!game->check->isVisible()) {
                    game->check->setVisible(true);
                } else {
                    j->resetOriginalColor();
                    i->getCurrentBox()->resetOriginalColor();
                    game->gameOver();
                }
                c++;
            }
        }
    }

    if (!c) {
        game->check->setVisible(false);
        for (auto& item : pList)
            item->getCurrentBox()->resetOriginalColor();
    }
}

ColorType ChessBox::getChessPieceColor() {
    return chessPieceColor_;
}

void ChessBox::setChessPieceColor(ColorType value) {
    chessPieceColor_ = value;
}
