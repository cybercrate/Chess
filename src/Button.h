#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button : public QObject, public QGraphicsRectItem {
    Q_OBJECT

    QGraphicsTextItem* text_;

public:
    explicit Button(const QString& name, QGraphicsItem* parent = nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent* sceneMouseEvent) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent* sceneHoverEvent) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* sceneHoverEvent) override;

signals:
    void clicked();
};

#endif // BUTTON_H
