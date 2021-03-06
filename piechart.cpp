#include "piechart.h"

#include "filesdatamodel.h"

PieChart::PieChart(QWidget *parent) : MyView(parent)
{
}

void PieChart::drawChart(QPainter &painter)
{
    QAbstractItemModel *model = this->model();
    int modelSize = model->rowCount(QModelIndex());
    int startAngle = 0;
    int spanAngle = 0;
    for(int i = 0; i < modelSize; i++)
    {
        painter.setPen(palet[i%12]);
        painter.setBrush(QBrush(palet[i%12],Qt::SolidPattern));
        double percent = model->data(model->index(i,2),Qt::DisplayRole).toDouble();
        spanAngle = 360 * percent * 16 / 100;
        painter.drawPie(drawRect, startAngle, spanAngle);
        startAngle += spanAngle;
    }
}
