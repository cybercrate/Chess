#include "Chessboard.h"
#include "Chessmen/Bishop.h"
#include "Chessmen/King.h"
#include "Chessmen/Knight.h"
#include "Chessmen/Pawn.h"
#include "Chessmen/Queen.h"
#include "Chessmen/Rook.h"
#include "GameInstance.h"
#include "Globals.h"

extern GameInstance* game;

ChessBoard::ChessBoard() {
    setUpDark();
    setUpLight();
}

void ChessBoard::drawBoxes(int x, int y) {
    int shift = 62;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            auto box = new ChessBox();
            game->collection[i][j] = box;
            box->rowLocation = i;
            box->columnLocation = j;
            box->setPos((x + shift * j), (y + shift * i));

            if ((i + j) % 2 == 0)
                box->setOriginalColor(LightSquareColor);
            else
                box->setOriginalColor(DarkSquareColor);

            game->addToScene(box);
        }
    }
}

void ChessBoard::addChessPiece() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            auto box = game->collection[i][j];

            if (i < 2) {
                static int k;
                box->placePiece(dark_[k]);
                game->alivePiece.append(dark_[k]);
                game->addToScene(dark_[k++]);
            }

            if (i > 5) {
                static int h;
                box->placePiece(light_[h]);
                game->alivePiece.append(light_[h]);
                game->addToScene(light_[h++]);
            }
        }
    }
}

void ChessBoard::setUpLight() {
    ChessPiece* piece;

    for (int i = 0; i < 8; i++) {
        piece = new Pawn(ColorType::Light);
        light_.append(piece);
    }

    piece = new Rook(ColorType::Light);
    light_.append(piece);
    piece = new Knight(ColorType::Light);
    light_.append(piece);
    piece = new Bishop(ColorType::Light);
    light_.append(piece);
    piece = new Queen(ColorType::Light);
    light_.append(piece);
    piece = new King(ColorType::Light);
    light_.append(piece);
    piece = new Bishop(ColorType::Light);
    light_.append(piece);
    piece = new Knight(ColorType::Light);
    light_.append(piece);
    piece = new Rook(ColorType::Light);
    light_.append(piece);
}

void ChessBoard::setUpDark() {
    ChessPiece* piece;

    piece = new Rook(ColorType::Dark);
    dark_.append(piece);
    piece = new Knight(ColorType::Dark);
    dark_.append(piece);
    piece = new Bishop(ColorType::Dark);
    dark_.append(piece);
    piece = new Queen(ColorType::Dark);
    dark_.append(piece);
    piece = new King(ColorType::Dark);
    dark_.append(piece);
    piece = new Bishop(ColorType::Dark);
    dark_.append(piece);
    piece = new Knight(ColorType::Dark);
    dark_.append(piece);
    piece = new Rook(ColorType::Dark);
    dark_.append(piece);

    for (int i = 0; i < 8; i++) {
        piece = new Pawn(ColorType::Dark);
        dark_.append(piece);
    }
}

void ChessBoard::reset() {
    int k = 0;
    int h = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            auto Box = game->collection[i][j];
            Box->setHasChessPiece(false);
            Box->setChessPieceColor(ColorType::None);
            Box->currentPiece = nullptr;

            if (i < 2) {
                Box->placePiece(dark_[k]);
                dark_[k]->setIsPlaced(true);
                dark_[k]->firstMove = true;
                game->alivePiece.append(dark_[k++]);
            }

            if (i > 5) {
                Box->placePiece(light_[h]);
                light_[h]->setIsPlaced(true);
                light_[h]->firstMove = true;
                game->alivePiece.append(light_[h++]);
            }
        }
    }
}
