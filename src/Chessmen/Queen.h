#ifndef QUEEN_H
#define QUEEN_H

#include "../ChessPiece.h"

class Queen : public ChessPiece {
public:
    explicit Queen(ColorType team, QGraphicsItem* parent = nullptr);

    void setImage() override;
    void moves() override;
};

#endif // QUEEN_H
