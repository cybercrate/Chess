#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "ChessBox.h"
#include "ColorType.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class ChessBox;

// Abstract class.
class ChessPiece : public QGraphicsPixmapItem {
protected:
    ChessBox* currentBox{};
    ColorType side;
    QList<ChessBox*> location;
    bool isPlaced;

public:
    bool firstMove;

    // Constructor
    ChessPiece(ColorType team, QGraphicsItem* parent = nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent* sceneMouseEvent);
    void setCurrentBox(ChessBox* value);

    QList<ChessBox*> moveLocation();
    ChessBox* getCurrentBox();

    ColorType getSide();
    [[maybe_unused]] void setSide(ColorType value);

    virtual void setImage() = 0;
    virtual void moves() = 0;

    bool getIsPlaced() const;
    bool boxSetting(ChessBox* box);

    void setIsPlaced(bool value);
    void resetColor();
};

#endif // CROSSPIECE_H
