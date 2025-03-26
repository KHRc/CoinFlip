#ifndef BUTTON1_H
#define BUTTON1_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QPropertyAnimation>
class Button1 : public QPushButton
{
	Q_OBJECT
public:
	Button1(QString normalImg, QString pressImg = "");
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	QString normalImgPath;  //Ĭ����ʾͼƬ·��
	QString pressedImgPath; //���º���ʾͼƬ·��
	void zoom1();
	void zoom2();
signals:

public slots:
};

#endif // BUTTON1_H
