#include "Coin.h"


Coin::Coin(QString butImg)
{
    QPixmap pixmap;
    bool ret = pixmap.load(butImg);
    if (!ret)
    {
        qDebug() << butImg << "����ͼƬʧ��!";
    }

    this->setFixedSize(pixmap.width(), pixmap.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));

    //������ת���ź�
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    //����
    connect(timer1, &QTimer::timeout, [=]() {
		QPixmap pixmap;
		QString str = QString(":/res/Coin000%1.png").arg(this->min++);
		pixmap.load(str);
		this->setFixedSize(pixmap.width(), pixmap.height());
		this->setStyleSheet("QPushButton{border:0px;}");
		this->setIcon(pixmap);
		this->setIconSize(QSize(pixmap.width(), pixmap.height()));
        if (this->min > this->max)//����������ֵ��������Сֵ����ֹͣ��ʱ��
        {
			this->min = 1;
            this->isAnimation = false;
			timer1->stop();
        }
    });
    //����
    connect(timer2, &QTimer::timeout, [=]() {
        QPixmap pixmap;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
        if (this->max < this->min) //���С����Сֵ���������ֵ����ֹͣ��ʱ��
        {
            this->max = 8;
            this->isAnimation = false;
            timer2->stop();
        }
    });
}

void Coin::changeFlag() 
{
    if (this->flag)
    {
        timer1->start(30);
		this->flag = false;
    }
    else
    {
		timer2->start(30);
		this->flag = true;
    }
    this->isAnimation = true;
}



void Coin::mousePressEvent(QMouseEvent* e)
{
    if (this->isAnimation || isWin == true)
    {
        return;
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}
