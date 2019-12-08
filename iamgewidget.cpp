#include "iamgewidget.h"
#include "ui_iamgewidget.h"
#include<QVBoxLayout>
#include<QDebug>
IamgeWidget::IamgeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IamgeWidget)
{
    ui->setupUi(this);
    this->init();
}

IamgeWidget::~IamgeWidget()
{
    delete ui;
}
void IamgeWidget::init(){
    // 窗口基本设置
       this->setWindowTitle("Image Preview");
       this->setMinimumSize(780, 600);
       m_showWidget.setWindowTitle("single Show");
       m_showWidget.setAlignment(Qt::AlignCenter);

       const QSize IMAGE_SIZE(240, 160);
       const QSize ITEM_SIZE(240, 190);

       // QListWidget基本设置
       listWidget = new QListWidget(this);
       listWidget->setIconSize(IMAGE_SIZE);
       listWidget->setResizeMode(QListView::Adjust);
       listWidget->setViewMode(QListView::IconMode);
       listWidget->setMovement(QListView::Static);
       listWidget->setSpacing(8);

       // 创建单元项
       for (int i = 0; i<10; ++i) {
           QPixmap pixmap(":/image/image/u=153010587,567888075&fm=26&gp=0.jpg");
           QListWidgetItem *listWidgetItem = new QListWidgetItem(QIcon(pixmap.scaled(IMAGE_SIZE)), "OA");
           listWidgetItem->setSizeHint(ITEM_SIZE);
           listWidget->insertItem(i, listWidgetItem);
       }

       // 窗口布局
           QVBoxLayout *mainLayout = new QVBoxLayout;
           mainLayout->addWidget(listWidget);
           mainLayout->setMargin(0);
           this->setLayout(mainLayout);
           // 信号与槽
              connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(slot_itemClicked(QListWidgetItem*)));

      }
void IamgeWidget::slot_itemClicked(QListWidgetItem* item){
    qDebug()<<item;
    m_showWidget.setPixmap(QPixmap(":/image/image/u=153010587,567888075&fm=26&gp=0.jpg"));
       m_showWidget.showMaximized();
}
