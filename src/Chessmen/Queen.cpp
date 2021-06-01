#include "Queen.h"
#include "../GameInstance.h"

extern GameInstance* game;

Queen::Queen(ColorType team, QGraphicsItem* parent) : ChessPiece(team, parent) {
    Queen::setImage();
}

void Queen::setImage() {
    if (side == ColorType::Light)
        setPixmap(QPixmap(":/images/Chessmen/QueenLight.png"));
    else
        setPixmap(QPixmap(":/images/Chessmen/QueenDark.png"));
}

void Queen::moves() {
    location.clear();

    int row = this->getCurrentBox()->rowLocation;
    int column = this->getCurrentBox()->columnLocation;

    ColorType team = this->getSide();

    // Up.
    for (int i = row - 1, j = column; i >= 0; i--) {
        if (game->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }

    // Down.
    for (int i = row + 1, j = column; i <= 7; i++) {
        if (game->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }

    // Left.
    for (int i = row, j = column - 1; j >= 0; j--) {
        if (game->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }

    // Right.
    for (int i = row, j = (column + 1); j <= 7; j++) {
        if (game->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }

    // Upper left.
    for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
        if (game->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }

    // Upper right.
    for (int i = row - 1, j = column + 1; i >= 0 && j <= 7; i--, j++) {
        if (game->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }

    // Downward right.
    for (int i = row + 1, j = column + 1; i <= 7 && j <= 7; i++, j++) {
        if (game->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }

    // Downward left.
    for (int i = row + 1, j = column - 1; i <= 7 && j >= 0; i++, j--) {
        if (game->collection[i][j]->getChessPieceColor() == team) {
            break;
        } else {
            location.append(game->collection[i][j]);
            if (boxSetting(location.last()))
                break;
        }
    }
}
