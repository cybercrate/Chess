#ifndef ROOK_H
#define ROOK_H

#include "../ChessPiece.h"

class Rook : public ChessPiece {
public:
    explicit Rook(ColorType team, QGraphicsItem* parent = nullptr);

    void setImage() override;
    void moves() override;
};

#endif // ROOK_H
