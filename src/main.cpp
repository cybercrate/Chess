#include "GameInstance.h"

#include <QApplication>

GameInstance* game;

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QApplication::setStyle("Fusion");

    game = new GameInstance();
    game->show();
    game->displayMainMenu();

    return QApplication::exec();
}
