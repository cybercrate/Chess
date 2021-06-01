#include "GameInstance.h"
#include "Button.h"
#include "Chessmen/King.h"

GameInstance::GameInstance(QWidget* parent) : QGraphicsView(parent) {
    // Making the scene.
    gameScene_ = new QGraphicsScene();
    gameScene_->setSceneRect(0.0, 0.0, 499.0, 532.0);

    // Making the view.
    setFixedSize(499, 530);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene_);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
    pieceToMove = nullptr;

    // Display turn_.
    turnDisplay_ = new QGraphicsTextItem();
    turnDisplay_->setPos(double(width()) / 2 - 23.0, 1.0);
    turnDisplay_->setZValue(1.0);
    turnDisplay_->setDefaultTextColor(Qt::white);
    turnDisplay_->setFont(QFont("", 16));
    turnDisplay_->setPlainText("Light");

    // Display check.
    check = new QGraphicsTextItem();
    check->setPos(5.0, 1.0);
    check->setZValue(4.0);
    check->setDefaultTextColor(Qt::white);
    check->setFont(QFont("", 16));
    check->setPlainText("Check!");
    check->setVisible(false);
    setTurn(ColorType::Light);
}

void GameInstance::drawChessBoard() {
    board_ = new ChessBoard();
    ChessBoard::drawBoxes(width() / 2 - 248, 33);
}

void GameInstance::placeInDeadPlace(ChessPiece* piece) {
    if (piece->getSide() == ColorType::Light) {
        lightDead_.append(piece);
        auto pKing = dynamic_cast<King*>(piece);

        if (pKing) {
            check->setPlainText("Dark Won!");
            gameOver();
        }

        for (auto& item : lightDead_)
            item->setVisible(false);
    } else {
        darkDead_.append(piece);
        auto pKing = dynamic_cast<King*>(piece);

        if (pKing) {
            check->setPlainText("light_ Won!");
            gameOver();
        }

        for (auto& item : darkDead_)
            item->setVisible(false);
    }
    alivePiece.removeAll(piece);
}

void GameInstance::addToScene(QGraphicsItem* item) {
    gameScene_->addItem(item);
}

void GameInstance::removeFromScene(QGraphicsItem* item) {
    gameScene_->removeItem(item);
}

ColorType GameInstance::getTurn() {
    return turn_;
}

void GameInstance::setTurn(ColorType value) {
    turn_ = value;
}

void GameInstance::changeTurn() {
    setTurn(getTurn() == ColorType::Light ? ColorType::Dark : ColorType::Light);
    turnDisplay_->setPlainText(colorToString(getTurn()));
}

void GameInstance::start() {
    for (auto& item : listG_)
        removeFromScene(item);

    addToScene(turnDisplay_);
    addToScene(check);
    board_->addChessPiece();
}

void GameInstance::displayMainMenu() {
    // Create button.
    auto playButton = new Button("Play");
    playButton->setScale(1.2);
    double xPos = double(width()) / 2 - 5 - playButton->boundingRect().width() / 2;
    double yPos = 246.0;
    playButton->setPos(xPos, yPos);
    connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
    addToScene(playButton);
    listG_.append(playButton);
    drawChessBoard();
}

void GameInstance::gameOver() {
    setTurn(ColorType::Light);
    alivePiece.clear();
    board_->reset();
}
