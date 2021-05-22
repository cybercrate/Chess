#ifndef CHESSBOX_H
#define CHESSBOX_H

#include "ChessPiece.h"
#include "ColorType.h"

#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class ChessPiece;

class ChessBox : public QGraphicsRectItem {
    QBrush brush_{};
    QColor originalColor_{};
    ColorType chessPieceColor_{ColorType::None};
    bool hasChessPiece_{};

public:
    int rowLocation{};
    int columnLocation{};

    ChessPiece* currentPiece{};

    // Constructor.
    explicit ChessBox(QGraphicsItem* parent = nullptr);
    ~ChessBox() override;

    void mousePressEvent(QGraphicsSceneMouseEvent* sceneMouseEvent) override;

    void setColor(const QColor& color);
    void placePiece(ChessPiece* piece);

    void resetOriginalColor();
    void setOriginalColor(QColor value);

    [[nodiscard]] bool getHasChessPiece() const;
    void setHasChessPiece(bool value, ChessPiece* piece = nullptr);

    static void checkForCheck();

    ColorType getChessPieceColor();
    void setChessPieceColor(ColorType value);
};

#endif // CHESSBOX_H
