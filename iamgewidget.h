#ifndef IAMGEWIDGET_H
#define IAMGEWIDGET_H

#include <QWidget>
#include<QListWidget>
#include<QLabel>
namespace Ui {
class IamgeWidget;
}

class IamgeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit IamgeWidget(QWidget *parent = nullptr);
    ~IamgeWidget();
public:
    void init();
private slots:
    void slot_itemClicked(QListWidgetItem*);
private:
    QStringList m_imgList;      // 文件目录下所有的图像文件名
    QListWidget *listWidget;  // 预览窗口
    QString m_strPath;          // 文件夹路径
    QLabel m_showWidget;// 图像显示窗口

private:
    Ui::IamgeWidget *ui;
};

#endif // IAMGEWIDGET_H
