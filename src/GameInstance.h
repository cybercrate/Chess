#ifndef GAME_H
#define GAME_H

#include "ChessPiece.h"
#include "Chessboard.h"
#include "ColorType.h"

#include <QGraphicsScene>
#include <QGraphicsView>

class GameInstance : public QGraphicsView {
    Q_OBJECT

    QGraphicsScene* gameScene_;
    [[maybe_unused]] QGraphicsRectItem* deadHolder_{};
    ChessBoard* board_{};
    QGraphicsTextItem* turnDisplay_;

    QList<ChessPiece*> lightDead_;
    QList<ChessPiece*> darkDead_;
    QList<QGraphicsItem*> listG_;

    ColorType turn_;

public:
    ChessBox* collection[8][8]{};
    QGraphicsTextItem* check;

    QList<ChessPiece*> alivePiece;

    // Constructor.
    explicit GameInstance(QWidget* parent = nullptr);

    void drawChessBoard();
    void placeInDeadPlace(ChessPiece* piece);

    // Scene related.
    void addToScene(QGraphicsItem* item);
    void removeFromScene(QGraphicsItem* item);

    ChessPiece* pieceToMove;

    ColorType getTurn();
    void setTurn(ColorType value);
    void changeTurn();

    void displayMainMenu();
    void gameOver();

public slots:
    void start();
};

#endif // GAME_H
