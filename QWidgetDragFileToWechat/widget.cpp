#include "widget.h"
#include <QMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include <QUrl>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    if (event->button() == Qt::LeftButton)
    {
        p = event->pos();
    }
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    QWidget::mouseMoveEvent(e);
    if (!(e->buttons() & Qt::LeftButton))
        return;
    if ((e->pos() - p).manhattanLength() < QApplication::startDragDistance())
        return;
    QDrag *dg = new QDrag(this);
    QMimeData *md = new QMimeData;
    QString testFile = "C://Users//bairutai//Desktop//test1.jpg";
    md->setUrls(QList<QUrl>() << QUrl::fromLocalFile(testFile));
    dg->setMimeData(md);
    QPixmap pixMap(testFile);
    dg->setPixmap(pixMap.scaled(50, 50));
    dg->setHotSpot(QPoint(-15, -15));
    dg->exec(Qt::CopyAction | Qt::MoveAction);
    md->deleteLater();
    dg->deleteLater();
}
