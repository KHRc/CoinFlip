#pragma execution_character_set("utf-8")
#include "playscene.h"

PlayScene::PlayScene(int index) : levalIndex(index)
{
	this->setFixedSize(320, 588);
	this->setWindowIcon(QIcon(":/res/Coin0001.png"));
	this->setWindowTitle("翻金币场景");

	QMenuBar* bar = menuBar();
	this->setMenuBar(bar);
	QMenu* startMenu = bar->addMenu("开始");
	QAction* quitAction = startMenu->addAction("退出");
	connect(quitAction, &QAction::triggered, [=]() {
		this->close();
		});

	//创建返回按钮
	Button1* closeBtn = new Button1(":/res/BackButton.png", ":/res/BackButtonSelected.png");
	closeBtn->setParent(this);
	closeBtn->move(this->width() - closeBtn->width(), this->height() - closeBtn->height());
	connect(closeBtn, &Button1::clicked, [=]() {
		backSound->play();
		QTimer::singleShot(500, this, [=]() {
			this->hide();
			emit this->chooseSceneBack();
			});
		});

	//显示具体关卡内容
	QLabel* label = new QLabel;
	label->setParent(this);
	QFont font;
	font.setFamily("华文新魏");
	font.setPointSize(20);
	label->setFont(font);
	QString str = QString("Level: %1").arg(this->levalIndex);
	label->setText(str);
	//设置位置和大小
	label->setGeometry(30, this->height() - 50, 120, 50);
	//加载关卡数据
	dataConfig config;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gameArray[i][j] = config.mData[this->levalIndex][i][j];
		}
	}

	//胜利背景图
	QLabel* winLabel = new QLabel;
	QPixmap tmpPix;
	tmpPix.load(":/res/LevelCompletedDialogBg.png");
	winLabel->setGeometry(0, 0, tmpPix.width(), tmpPix.height());
	winLabel->setPixmap(tmpPix);
	winLabel->setParent(this);
	winLabel->move((this->width() - tmpPix.width()) * 0.5, -tmpPix.height());

	//创建金币的背景图片
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			QLabel* label = new QLabel;
			label->setGeometry(0, 0, 50, 50);
			label->setPixmap(QPixmap(":/res/BoardNode.png"));
			label->setParent(this);
			label->move(57 + i * 50, 200 + j * 50);

			//金币对象
			QString img;
			if (gameArray[i][j] == 1)
			{
				img = ":/res/Coin0001.png";
			}
			else
			{
				img = ":/res/Coin0008.png";
			}
			Coin* coin = new Coin(img);
			coin->setParent(this);
			coin->move(59 + i * 50, 204 + j * 50);
			coin->posX = i;
			coin->posY = j;
			coin->flag = gameArray[i][j];
			coinBtn[i][j] = coin;
			connect(coin, &Coin::clicked, [=]() {
				//qDebug() << "点击的位置：" << coin->posX << coin->posY;
				flipSound->play();
				coin->changeFlag();
				gameArray[i][j] = gameArray[i][j] == 0 ? 1 : 0;
				//延时翻转周围金币
				QTimer::singleShot(300, this, [=]() {
					flipCoins(coin->posX + 1, coin->posY);
					flipCoins(coin->posX - 1, coin->posY);
					flipCoins(coin->posX, coin->posY + 1);
					flipCoins(coin->posX, coin->posY - 1);
					//判断是否胜利
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							if (coinBtn[i][j]->flag == false)
							{
								isWin = false;
								break;
							}
						}
					}
					if (isWin)
					{
						//qDebug() << "胜利了";
						winSound->play();
						QPropertyAnimation* animation1 = new QPropertyAnimation(winLabel, "geometry");
						animation1->setDuration(1000);
						animation1->setStartValue(QRect(winLabel->x(), winLabel->y(), winLabel->width(), winLabel->height()));
						animation1->setEndValue(QRect(winLabel->x(), winLabel->y() + 114, winLabel->width(), winLabel->height()));
						animation1->setEasingCurve(QEasingCurve::OutBounce);
						animation1->start();
						for (int i = 0; i < 4; i++)
							for (int j = 0; j < 4; j++)
								coinBtn[i][j]->isWin = true;
					}
					else
					{
						isWin = true;
					}
					});
				});
		}
	}
}

void PlayScene::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	QPixmap pix;
	pix.load(":/res/PlayLevelSceneBg.png");
	painter.drawPixmap(0, 0, this->width(), this->height(), pix);
	//加载标题
	pix.load(":/res/Title.png");
	pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
	painter.drawPixmap(10, 30, pix.width(), pix.height(), pix);
}

void PlayScene::flipCoins(int x, int y)
{
	if (x >= 0 && x <= 3 && y >= 0 && y <= 3)
	{
		coinBtn[x][y]->changeFlag();
		gameArray[x][y] = gameArray[x][y] == 0 ? 1 : 0;
	}
}