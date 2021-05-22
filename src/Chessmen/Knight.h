#ifndef KNIGHT_H
#define KNIGHT_H

#include "../ChessPiece.h"

class Knight : public ChessPiece {
public:
    explicit Knight(ColorType team, QGraphicsItem* parent = nullptr);

    void setImage() override;
    void moves() override;
};

#endif // KNIGHT_H
