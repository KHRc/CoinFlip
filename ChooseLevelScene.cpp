#pragma execution_character_set("utf-8")
#include "ChooseLevelScene.h"

ChooseLevelScene::ChooseLevelScene(QWidget* parent)
	: QMainWindow(parent)
{
	this->setFixedSize(320, 588);
	this->setWindowIcon(QIcon(":/res/Coin0001.png"));
	this->setWindowTitle("选择关卡");
	QMenuBar* bar = this->menuBar();
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
		QTimer::singleShot(500, this, [=]() {
			backSound->play();
			this->hide();
			emit this->chooseSceneBack();
			});
		});

	//创建选择关卡按钮
	for (int i = 0; i < 20; i++)
	{
		Button1* menuBtn = new Button1(":/res/LevelIcon.png");
		menuBtn->setParent(this);
		menuBtn->move(25 + i % 4 * 70, 130 + i / 4 * 70);
		//按钮上显示的文字
		QLabel* label = new QLabel;
		label->setParent(this);
		label->setFixedSize(menuBtn->width(), menuBtn->height());
		label->setText(QString::number(i + 1));
		label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //设置居中
		label->move(25 + (i % 4) * 70, 130 + (i / 4) * 70);
		//设置鼠标穿透(穿过Label作用到button上)
		label->setAttribute(Qt::WA_TransparentForMouseEvents, true);
		connect(menuBtn, &Button1::clicked, [=]() {
			//QString str = QString("您选择的是第 %1 关").arg(i + 1);
			//qDebug() << str;
			chooseSound->play();
			if (pScene == nullptr)
			{
				this->hide();
				pScene = new PlayScene(i + 1);
				pScene->setGeometry(this->geometry());
				pScene->show();

				//重置关卡
				connect(pScene, &PlayScene::chooseSceneBack, [=]() {
					this->setGeometry(pScene->geometry());
					this->show();
					delete pScene;
					pScene = NULL;
					});
			}
			});
	}
}

ChooseLevelScene::~ChooseLevelScene()
{
}

void ChooseLevelScene::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	QPixmap pix;
	pix.load(":/res/OtherSceneBg.png");
	painter.drawPixmap(0, 0, this->width(), this->height(), pix);
	pix.load(":/res/Title.png");
	painter.drawPixmap((this->width() - pix.width()) * 0.5, 30, pix.width(), pix.height(), pix);
}