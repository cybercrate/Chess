#ifndef PAWN_H
#define PAWN_H

#include "../ChessPiece.h"

class Pawn : public ChessPiece {
public:
    explicit Pawn(ColorType team, QGraphicsItem* parent = nullptr);

    void setImage() override;
    void moves() override;
};

#endif // PAWN_H
