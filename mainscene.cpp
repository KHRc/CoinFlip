#pragma execution_character_set("utf-8")
#include "mainscene.h"
#include "ui_mainscene.h"

MainScene::MainScene(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainScene)
{
	ui->setupUi(this);
	this->setFixedSize(320, 588);
	this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
	this->setWindowTitle("翻金币");
	//创建开始按钮
	Button1* startBtn = new Button1(":/res/MenuSceneStartButton.png");
	startBtn->setParent(this);
	//设置按钮位置:水平居中，垂直在总高*0.7位置
	startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5, this->height() * 0.7);

	connect(ui->actionQuit, &QAction::triggered, [=]() {
		this->close();
		});
	//开始按钮点击特效
	connect(startBtn, &Button1::clicked, [=]() {
		//增加弹跳特效
		startSound->play();
		startBtn->zoom1();
		startBtn->zoom2();
		QTimer::singleShot(500, this, [=]() {
			this->hide();
			chooseScene->setGeometry(this->geometry());
			chooseScene->show();
			});
		});
	//监听选择关卡场景返回按钮
	connect(chooseScene, &ChooseLevelScene::chooseSceneBack, [=]() {
		this->setGeometry(chooseScene->geometry());
		this->show();
		});
}

MainScene::~MainScene()
{
	delete ui;
}

void MainScene::paintEvent(QPaintEvent*)
{
	//用重写MainScene的PaintEvent，增加背景图
	QPainter painter(this);
	QPixmap pix;
	pix.load(":/res/PlayLevelSceneBg.png");
	painter.drawPixmap(0, 0, this->width(), this->height(), pix);
	pix.load(":/res/Title.png");
	pix = pix.scaled(pix.width() * 0.6, pix.height() * 0.6);
	painter.drawPixmap(10, 35, pix.width(), pix.height(), pix);
}