#include "Button.h"

#include <QBrush>

Button::Button(const QString& name, QGraphicsItem* parent) : QGraphicsRectItem(parent) {
    // Draw the rect.
    setRect(0.0, 0.0, 60.0, 60.0);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);

    // Draw text_.
    text_ = new QGraphicsTextItem(name, this);
    double xPos = rect().width() / 2 - text_->boundingRect().width() / 2;
    double yPos = rect().height() / 2 - text_->boundingRect().height() / 2;
    text_->setPos(xPos, yPos);
    text_->setDefaultTextColor(Qt::white);

    // Allow responding to hover.
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent* sceneMouseEvent) {
    if (sceneMouseEvent)
        emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent* sceneHoverEvent) {
    // Change color.
    if (sceneHoverEvent) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::lightGray);
        setBrush(brush);
    }
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent* sceneHoverEvent) {
    // Change color.
    if (sceneHoverEvent) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkGray);
        setBrush(brush);
    }
}
