#pragma once

#include <QPushButton>
#include <QDebug>
#include <QTimer>

class Coin : public QPushButton
{
	Q_OBJECT

public:
	Coin(QWidget* parent) {};
	Coin(QString butImg);
	~Coin() = default;
	void changeFlag();//改变标志,执行翻转效果

	int posX;
	int posY;
	bool flag;//正反标志
	bool isWin = false;//胜利标志
private:
	QTimer* timer1;
	QTimer* timer2;
	int min = 1; //最小图片
	int max = 8; //最大图片
	bool isAnimation = false; //是否正在执行动画
	void mousePressEvent(QMouseEvent* e);
};
