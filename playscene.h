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
	//��ת��Χ���
	void flipCoins(int x, int y);
	Coin* coinBtn[4][4] = { 0 };
signals:
	void chooseSceneBack();

public slots:

private:
	int levalIndex;
	int gameArray[4][4]; //��ά��������
	bool isWin = true; //�Ƿ�ʤ��
	QSound* backSound = new QSound(":/res/BackButtonSound.wav", this);
	//�������Ч
	QSound* flipSound = new QSound(":/res/ConFlipSound.wav", this);
	//ʤ����ť��Ч
	QSound* winSound = new QSound(":/res/LevelWinSound.wav", this);

};

#endif // PLAYSCENE_H
