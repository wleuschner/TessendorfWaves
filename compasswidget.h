#ifndef COMPASSWIDGET_H
#define COMPASSWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <glm/glm.hpp>

class CompassWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CompassWidget(QWidget *parent = 0);
    glm::vec2 getDirection();

protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);

signals:

public slots:

private:
    glm::vec2 dir;
};

#endif // COMPASSWIDGET_H
