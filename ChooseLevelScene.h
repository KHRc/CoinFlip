#pragma once

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QSound>

#include "button1.h"
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
	Q_OBJECT
signals:
	void chooseSceneBack();

public:
	ChooseLevelScene(QWidget* parent = nullptr);
	~ChooseLevelScene();
	void paintEvent(QPaintEvent*);

private:
	PlayScene* pScene = nullptr;
	QSound* chooseSound = new QSound(":/res/TapButtonSound.wav", this);
	QSound* backSound = new QSound(":/res/BackButtonSound.wav", this);
};
