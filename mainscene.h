#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QSound>
#include "button1.h"
#include "ChooseLevelScene.h"

namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = nullptr);
    ~MainScene();
    void paintEvent(QPaintEvent *);

private:
    Ui::MainScene *ui;
    ChooseLevelScene* chooseScene = new ChooseLevelScene;
    QSound* startSound = new QSound(":/res/TapButtonSound.wav", this);
};

#endif // MAINSCENE_H
