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
	void changeFlag();//�ı��־,ִ�з�תЧ��

	int posX;
	int posY;
	bool flag;//������־
	bool isWin = false;//ʤ����־
private:
	QTimer* timer1;
	QTimer* timer2;
	int min = 1; //��СͼƬ
	int max = 8; //���ͼƬ
	bool isAnimation = false; //�Ƿ�����ִ�ж���
	void mousePressEvent(QMouseEvent* e);
};
