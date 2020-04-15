#include "widget.h"
#include <QClipboard>
#include <QApplication>
#include <QPushButton>
#include <QMimeData>
#include <QUrl>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(100,100);
    QPushButton* testBtn = new QPushButton("test",this);
    connect(testBtn,&QPushButton::clicked,this,[](){
        QClipboard *board = QApplication::clipboard();
        QString testFile = "C://Users//bairutai//Desktop//test1.jpg";
        QString testFile2 = "C://Users//bairutai//Desktop//test.png";
        //以前的写法
        QImage image(testFile);
        if (!image.isNull())
        {
            board->setImage(image);
        }
        //新的写法
        QList<QString> urlList;
        urlList<<QUrl::fromLocalFile(testFile).toString();
        urlList<<QUrl::fromLocalFile(testFile2).toString();
        QMimeData *md = new QMimeData;
        md->setData("text/uri-list", urlList.join("\n").toLatin1());
        board->setMimeData(md);
    });
}

Widget::~Widget()
{
}
