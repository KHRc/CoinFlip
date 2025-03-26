#pragma execution_character_set("utf-8")
#include "button1.h"

Button1::Button1(QString normalImg, QString pressImg) :
	normalImgPath(normalImg), pressedImgPath(pressImg)
{
	QPixmap pixmap;
	if (!pixmap.load(normalImgPath))
	{
		qDebug() << normalImg << "����ͼƬʧ��";
	}
	//����ͼƬ�̶���С
	this->setFixedSize(pixmap.width(), pixmap.height());
	//���ò�����ͼƬ��ʽ
	this->setStyleSheet("QPushButton{border:0px;}");
	//����ͼ��
	this->setIcon(pixmap);
	//����ͼ���С
	this->setIconSize(QSize(pixmap.width(), pixmap.height()));
}
//��������
void Button1::zoom1()
{
	QPropertyAnimation* animation1 = new QPropertyAnimation(this, "geometry");
	//����ʱ����
	animation1->setDuration(200);
	//��ʼλ��
	animation1->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
	//����λ��
	animation1->setEndValue(QRect(this->x(), this->y() - 10, this->width(), this->height()));
	//����Ч��
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
			qDebug() << pressedImgPath << "����ͼƬʧ��";
		}
		//����ͼƬ�̶���С
		this->setFixedSize(pixmap.width(), pixmap.height());
		//���ò�����ͼƬ��ʽ
		this->setStyleSheet("QPushButton{border:0px;}");
		//����ͼ��
		this->setIcon(pixmap);
		//����ͼ���С
		this->setIconSize(QSize(pixmap.width(), pixmap.height()));
	}
	//�ø���ִ����������
	QPushButton::mousePressEvent(event);
}

void Button1::mouseReleaseEvent(QMouseEvent* event)
{
	if (this->normalImgPath != "")
	{
		QPixmap pixmap;
		if (!pixmap.load(normalImgPath))
		{
			qDebug() << normalImgPath << "����ͼƬʧ��";
		}
		//����ͼƬ�̶���С
		this->setFixedSize(pixmap.width(), pixmap.height());
		//���ò�����ͼƬ��ʽ
		this->setStyleSheet("QPushButton{border:0px;}");
		//����ͼ��
		this->setIcon(pixmap);
		//����ͼ���С
		this->setIconSize(QSize(pixmap.width(), pixmap.height()));
	}
	//�ø���ִ����������
	QPushButton::mouseReleaseEvent(event);
}