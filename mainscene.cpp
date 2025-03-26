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
	this->setWindowTitle("�����");
	//������ʼ��ť
	Button1* startBtn = new Button1(":/res/MenuSceneStartButton.png");
	startBtn->setParent(this);
	//���ð�ťλ��:ˮƽ���У���ֱ���ܸ�*0.7λ��
	startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5, this->height() * 0.7);

	connect(ui->actionQuit, &QAction::triggered, [=]() {
		this->close();
		});
	//��ʼ��ť�����Ч
	connect(startBtn, &Button1::clicked, [=]() {
		//���ӵ�����Ч
		startSound->play();
		startBtn->zoom1();
		startBtn->zoom2();
		QTimer::singleShot(500, this, [=]() {
			this->hide();
			chooseScene->setGeometry(this->geometry());
			chooseScene->show();
			});
		});
	//����ѡ��ؿ��������ذ�ť
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
	//����дMainScene��PaintEvent�����ӱ���ͼ
	QPainter painter(this);
	QPixmap pix;
	pix.load(":/res/PlayLevelSceneBg.png");
	painter.drawPixmap(0, 0, this->width(), this->height(), pix);
	pix.load(":/res/Title.png");
	pix = pix.scaled(pix.width() * 0.6, pix.height() * 0.6);
	painter.drawPixmap(10, 35, pix.width(), pix.height(), pix);
}