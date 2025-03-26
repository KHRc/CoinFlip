#pragma execution_character_set("utf-8")
#include "button1.h"

Button1::Button1(QString normalImg, QString pressImg) :
	normalImgPath(normalImg), pressedImgPath(pressImg)
{
	QPixmap pixmap;
	if (!pixmap.load(normalImgPath))
	{
		qDebug() << normalImg << "加载图片失败";
	}
	//设置图片固定大小
	this->setFixedSize(pixmap.width(), pixmap.height());
	//设置不规则图片样式
	this->setStyleSheet("QPushButton{border:0px;}");
	//设置图标
	this->setIcon(pixmap);
	//设置图标大小
	this->setIconSize(QSize(pixmap.width(), pixmap.height()));
}
//弹跳动画
void Button1::zoom1()
{
	QPropertyAnimation* animation1 = new QPropertyAnimation(this, "geometry");
	//设置时间间隔
	animation1->setDuration(200);
	//起始位置
	animation1->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
	//结束位置
	animation1->setEndValue(QRect(this->x(), this->y() - 10, this->width(), this->height()));
	//弹跳效果
	animation1->setEasingCurve(QEasingCurve::OutBounce);
	animation1->start();
}

void Button1::zoom2()
{
	QPropertyAnimation* animation2 = new QPropertyAnimation(this, "geometry");
	animation2->setDuration(200);
	animation2->setStartValue(QRect(this->x(), this->y() - 10, this->width(), this->height()));
	animation2->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
	animation2->setEasingCurve(QEasingCurve::OutBounce);
	animation2->start();
}

void Button1::mousePressEvent(QMouseEvent* event)
{
	if (this->pressedImgPath != "")
	{
		QPixmap pixmap;
		if (!pixmap.load(pressedImgPath))
		{
			qDebug() << pressedImgPath << "加载图片失败";
		}
		//设置图片固定大小
		this->setFixedSize(pixmap.width(), pixmap.height());
		//设置不规则图片样式
		this->setStyleSheet("QPushButton{border:0px;}");
		//设置图标
		this->setIcon(pixmap);
		//设置图标大小
		this->setIconSize(QSize(pixmap.width(), pixmap.height()));
	}
	//让父类执行其他内容
	QPushButton::mousePressEvent(event);
}

void Button1::mouseReleaseEvent(QMouseEvent* event)
{
	if (this->normalImgPath != "")
	{
		QPixmap pixmap;
		if (!pixmap.load(normalImgPath))
		{
			qDebug() << normalImgPath << "加载图片失败";
		}
		//设置图片固定大小
		this->setFixedSize(pixmap.width(), pixmap.height());
		//设置不规则图片样式
		this->setStyleSheet("QPushButton{border:0px;}");
		//设置图标
		this->setIcon(pixmap);
		//设置图标大小
		this->setIconSize(QSize(pixmap.width(), pixmap.height()));
	}
	//让父类执行其他内容
	QPushButton::mouseReleaseEvent(event);
}