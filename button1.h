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
	QString normalImgPath;  //默认显示图片路径
	QString pressedImgPath; //按下后显示图片路径
	void zoom1();
	void zoom2();
signals:

public slots:
};

#endif // BUTTON1_H
