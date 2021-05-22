#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessPiece.h"

#include <QGraphicsRectItem>

class ChessBoard {
    QList<ChessPiece*> light_;
    QList<ChessPiece*> dark_;

public:
    ChessBoard();

    // Drawing.
    static void drawBoxes(int x, int y);

    void setUpLight();
    void setUpDark();

    void addChessPiece();
    void reset();
};

#endif // CHESSBOARD_H
