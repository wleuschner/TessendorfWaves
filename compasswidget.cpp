#include "compasswidget.h"
#include <QPainter>

CompassWidget::CompassWidget(QWidget *parent) : QWidget(parent)
{
    dir = glm::normalize(glm::vec2(1.0,0.0));
}

glm::vec2 CompassWidget::getDirection()
{
    return glm::vec2(-dir.x,-dir.y);
}

void CompassWidget::paintEvent(QPaintEvent* event)
{
    float radius=this->width()>this->height()?this->height()/2-1:this->width()/2-1;
    QPoint center(this->width()/2,this->height()/2);
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.drawEllipse(center,radius,radius);
    painter.setPen(Qt::red);
    painter.drawLine(center.x(),center.y(),center.x()+(dir.x*radius),center.y()+(dir.y*radius));
}

void CompassWidget::mousePressEvent(QMouseEvent* event)
{
    QPoint center(this->width()/2,this->height()/2);
    QPoint pos = event->pos();
    pos = pos-center;
    dir = glm::normalize(glm::vec2(pos.x(),pos.y()));
    this->repaint();
}
