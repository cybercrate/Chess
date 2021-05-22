#ifndef BISHOP_H
#define BISHOP_H

#include "../ChessPiece.h"

class Bishop : public ChessPiece {
public:
    explicit Bishop(ColorType team, QGraphicsItem* parent = nullptr);

    void setImage() override;
    void moves() override;
};

#endif // BISHOP_H
