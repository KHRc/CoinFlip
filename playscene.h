#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QSound>
#include "button1.h"
#include "Coin.h"
#include "dataconfig.h"

class PlayScene : public QMainWindow
{
	Q_OBJECT
public:
	PlayScene(QWidget* parent = nullptr) {};
	PlayScene(int index);
	void PlayScene::paintEvent(QPaintEvent*);
	//翻转周围金币
	void flipCoins(int x, int y);
	Coin* coinBtn[4][4] = { 0 };
signals:
	void chooseSceneBack();

public slots:

private:
	int levalIndex;
	int gameArray[4][4]; //二维数组数据
	bool isWin = true; //是否胜利
	QSound* backSound = new QSound(":/res/BackButtonSound.wav", this);
	//翻金币音效
	QSound* flipSound = new QSound(":/res/ConFlipSound.wav", this);
	//胜利按钮音效
	QSound* winSound = new QSound(":/res/LevelWinSound.wav", this);

};

#endif // PLAYSCENE_H
