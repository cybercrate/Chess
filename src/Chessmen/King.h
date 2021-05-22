#ifndef KING_H
#define KING_H

#include "../ChessPiece.h"

class King : public ChessPiece {
public:
    explicit King(ColorType team, QGraphicsItem* parent = nullptr);

    void setImage() override;
    void moves() override;

    void findUnsafeLocation();
};

#endif // KING_H
