#include "ChartDisplay.h"
#include <QPen>
#include <QMetaObject>

ChartDisplay::ChartDisplay(QWidget* parent, QCustomPlot* customPlot, QScrollBar* scrollBar,
                           QPushButton* clearButton, QRadioButton* manualButton,
                           QRadioButton* translationButton, QRadioButton* stretchButton)
    : QObject(parent)
{
    //静态图还是动态图
    if(manualButton == nullptr || translationButton == nullptr || stretchButton == nullptr)
        dynamic = false;
    else
        dynamic = true;

//    this->parent = plotParent;
    this->manualButton = manualButton;
    this->translationButton = translationButton;
    this->stretchButton = stretchButton;
    this->clearButton = clearButton;

//    hScrollBar = scrollBar;
//    hScrollBar->setMinimum(0);
//    hScrollBar->setMaximum(1000);
//    hScrollBar->setSingleStep(0);
//    hScrollBar->setPageStep(100);
//    hScrollBar->setValue(1000);
//    hScrollBar->setSliderPosition(1000);
//    hScrollBar->setOrientation(Qt::Horizontal);

    qRegisterMetaType<QVector<int>>("QVector<int>");

    pCustomPlot = customPlot;
//    if(gridLayout != nullptr)
//    {
//        gridLayout->addWidget(pCustomPlot);
//        gridLayout->addWidget(hScrollBar);
//    }

    xShowRange = pCustomPlot->xAxis->range();

    QFont font(QString::fromUtf8("Microsoft YaHei"), 9);
    pCustomPlot->xAxis->setLabelFont(font);
    pCustomPlot->xAxis->setTickLabelFont(font);
    pCustomPlot->yAxis->setLabelFont(font);
    pCustomPlot->yAxis->setTickLabelFont(font);

    pCustomPlot->xAxis->setNumberFormat("f");
    pCustomPlot->xAxis->setNumberPrecision(3);

    //游标说明
    tracer = new QCPItemTracer(pCustomPlot);
    //tracer->setInterpolating(false);
    tracer->setStyle(QCPItemTracer::tsCrosshair);
//    tracer->setPen(QPen(Qt::black));
//    tracer->setSelectedPen(QPen(Qt::red));
//    tracer->setBrush(Qt::red);
    tracer->setSize(8);
    // connect(pCustomPlot, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(on_mouse_move(QMouseEvent*)));
    connect(pCustomPlot, &QCustomPlot::mouseMove, this, &ChartDisplay::on_mouse_move);

    //下面的代码就是设置游标说明的外观和对齐方式等状态
    tracerLabel = new QCPItemText(pCustomPlot);
    tracerLabel->setLayer("overlay");
    tracerLabel->setPen(QPen(Qt::black));
    tracerLabel->setBrush(Qt::white);
    tracerLabel->setPadding(QMargins(2,2,2,2));//边界宽度
    tracerLabel->setPositionAlignment(Qt::AlignLeft | Qt::AlignTop);
    //下面这个语句很重要，它将游标说明锚固在tracer位置处，实现自动跟随
//    tracerLabel->position->setParentAnchor(tracer->position);
    tracerLabel->position->setType(QCPItemPosition::ptAbsolute);
    tracerLabel->position->setCoords(110,52);
    tracerLabel->setVisible(false);

    QFont font2(QString::fromUtf8("Microsoft YaHei"), 8);
    tracerLabel->setFont(font2);

    //设置Y轴范围
    pCustomPlot->yAxis->setRange(-3, 30);
    //x轴名字
    pCustomPlot->xAxis->setLabel("时间(s)");
    //Y轴名字
    pCustomPlot->yAxis->setLabel("数据");
    //设置大小
//    pCustomPlot->resize(plotParent->width(), plotParent->height());
    //可以进行鼠标位置 放大缩小 拖拽 放大缩小坐标系！！！功能非常强大
    pCustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables | QCP::iSelectLegend);
    pCustomPlot->axisRect(0)->setRangeZoom(Qt::Horizontal);
    pCustomPlot->axisRect(0)->setRangeDrag(Qt::Horizontal);
    pCustomPlot->axisRect()->insetLayout()->setMargins(QMargins(0,0,0,0));
//    pCustomPlot->plotLayout()->setMargins(QMargins(0, 5, 0, 0));

//    pCustomPlot->legend->setBrush(QBrush(QColor(255,255,255,160)));
//    pCustomPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft|Qt::AlignTop);
//    pCustomPlot->legend->setFont(font);

    //图例横向排列
    pCustomPlot->legend->setFillOrder(QCPLayoutGrid::foColumnsFirst);
    //添加图例的图层
    QCPLayoutGrid *subLayout = new QCPLayoutGrid;
    pCustomPlot->plotLayout()->insertRow(0);
    pCustomPlot->plotLayout()->addElement(0,0,subLayout);
    subLayout->addElement(0,0,new QCPLayoutElement);
    subLayout->addElement(0,1,pCustomPlot->legend);
    subLayout->addElement(0,2,new QCPLayoutElement);

    pCustomPlot->legend->setFont(font);
    pCustomPlot->plotLayout()->setRowStretchFactor(0, 0.001);
    pCustomPlot->legend->setVisible(true);
    pCustomPlot->legend->setBorderPen(Qt::NoPen);
    //点击图例可以隐藏/显示曲线
    pCustomPlot->legend->setSelectableParts(QCPLegend::spItems);
    connect(pCustomPlot, &QCustomPlot::selectionChangedByUser, this, [this]()
    {
        int graphCount = pCustomPlot->graphCount();
        for (int i = 0; i < graphCount; ++i)
        {
            QCPGraph *graph = pCustomPlot->graph(i);
            QCPPlottableLegendItem *item = pCustomPlot->legend->itemWithPlottable(graph);
            if(item->selected())
            {
                item->setSelected(false);
                if(graph->lineStyle() == QCPGraph::lsLine)
                {
                    item->setTextColor(Qt::gray);
                    graph->setLineStyle(QCPGraph::lsNone);
                }
                else if(graph->lineStyle() == QCPGraph::lsNone)
                {
                    item->setTextColor(Qt::black);
                    graph->setLineStyle(QCPGraph::lsLine);
                }
                emit replotSignal();
            }
        }
    },Qt::QueuedConnection);

    //重绘 每次改变完以后都要调用这个进行重新绘制
    replot();

    if(!pCustomPlot->openGl())
        pCustomPlot->setOpenGl(true);
    qDebug() << "opengl:" << pCustomPlot->openGl();

    qRegisterMetaType<uint32_t>("uint32_t");
//    QObject::connect(pCustomPlot->xAxis, SIGNAL(rangeChanged(QCPRange, QCPRange)), this, SLOT(on_x_range_changed(QCPRange, QCPRange)),Qt::QueuedConnection);
    QObject::connect(pCustomPlot->xAxis, QOverload<const QCPRange&, const QCPRange&>::of(&QCPAxis::rangeChanged), this, &ChartDisplay::on_x_range_changed,Qt::QueuedConnection);
//    QObject::connect(hScrollBar, SIGNAL(sliderMoved(int)), this, SLOT(on_slider_moved(int)), Qt::QueuedConnection);

    if(this->clearButton != nullptr)
        QObject::connect(this->clearButton, SIGNAL(clicked()), this, SLOT(on_clear_clicked()),Qt::QueuedConnection);

    QObject::connect(this, &ChartDisplay::changeXRange, this, &ChartDisplay::on_x_range_changed,Qt::QueuedConnection);
    QObject::connect(this, &ChartDisplay::addDataSignal, this, &ChartDisplay::addData, Qt::QueuedConnection);
    QObject::connect(this, &ChartDisplay::addDataVectorSignal, this, &ChartDisplay::addDataVector, Qt::BlockingQueuedConnection);
//    QObject::connect(this, &ChartDisplay::addDataVectorSignal, this, &ChartDisplay::addDataVector);
    QObject::connect(this, &ChartDisplay::replotSignal, this, &ChartDisplay::replot, Qt::QueuedConnection);
    QObject::connect(this, &ChartDisplay::maximizeXRangeSignal, this, &ChartDisplay::maximizeXRange,Qt::QueuedConnection);
    QObject::connect(this, &ChartDisplay::clearSignal, this, &ChartDisplay::on_clear_clicked,Qt::QueuedConnection);

    connect(manualButton, &QRadioButton::clicked, this, [this](bool checked)
    {
        if(checked)
            displayMode = 0;
    },Qt::QueuedConnection);
    connect(translationButton, &QRadioButton::clicked, this, [this](bool checked)
    {
        if(checked)
            displayMode = 1;
    },Qt::QueuedConnection);
    connect(stretchButton, &QRadioButton::clicked, this, [this](bool checked)
    {
        if(checked)
            displayMode = 2;
    },Qt::QueuedConnection);
}

ChartDisplay::~ChartDisplay()
{

}

inline double myScaleRange(QCPRange& range, double increase)
{
    double extraSize = range.size() * increase;
    range.lower -= extraSize;
    range.upper += extraSize;
    return extraSize * 2;
}

inline double myScaleUpperRange(QCPRange& range, double increase)
{
    double extraSize = range.size() * increase;
    range.upper += extraSize;
    return extraSize;
}


void ChartDisplay::on_x_range_changed(const QCPRange& newRange, const QCPRange& oldRange)
{
//    qDebug()<<"ChartDisplay::on_x_range_changed thread:"<<QThread::currentThreadId();
    if (!xRangeFinishSet)
        return;

    //寻找所有曲线最大的x范围
    QCPRange xAllGraphsRange = xGraphsRange;
    //QCPRange xGraphRange;
    //for (int i = 0; i < pCustomPlot->graphCount(); i++)
    //{
    //    xGraphRange = pCustomPlot->graph(i)->getKeyRange(foundxRange, QCP::sdBoth);
    //    xAllGraphsRange.expand(xGraphRange);
    //}

    if (xAllGraphsRange.size() > 0)
    {
        xShowRange = newRange.bounded(xGraphsRange.lower, xGraphsRange.upper);
//        //限定x轴范围
//        xShowRange = xShowRange.bounded(xAllGraphsRange.lower, xAllGraphsRange.upper);
        
        //设置滚动条
//        double pageStep = xShowRange.size() / xAllGraphsRange.size() * H_SCROLL_BAR_SUM;
//        hScrollBar->setPageStep(pageStep);
//        hScrollBar->setMaximum(H_SCROLL_BAR_SUM - pageStep);
//        hScrollBar->setValue((xShowRange.lower - xAllGraphsRange.lower) / xAllGraphsRange.size() * H_SCROLL_BAR_SUM);
        
        xRangeFinishSet = false;

        QSignalBlocker blocker(pCustomPlot->xAxis);
        
        pCustomPlot->xAxis->setRange(xShowRange);
        updateYShowRange(xShowRange);

//        replot();
        xRangeFinishSet = true;
    }
}

void ChartDisplay::maximizeXRange()
{
    QCPRange xAllGraphsRange;
    QCPRange xGraphRange;
    bool foundxRange;

    xAllGraphsRange = pCustomPlot->graph(0)->getKeyRange(foundxRange, QCP::sdBoth);
    for (int i = 1; i < pCustomPlot->graphCount(); i++)
    {
        xGraphRange = pCustomPlot->graph(i)->getKeyRange(foundxRange, QCP::sdBoth);
        xAllGraphsRange.expand(xGraphRange);
    }
    xGraphsRange = xAllGraphsRange;
    emit changeXRange(xAllGraphsRange, xAllGraphsRange);
}

void ChartDisplay::on_slider_moved(int position)
{
    QCPRange xAllGraphsRange = xGraphsRange;

//    double moveLength = (double)position / H_SCROLL_BAR_SUM * xAllGraphsRange.size() + xAllGraphsRange.lower - xShowRange.lower;
//    xShowRange += moveLength;

//    xShowRange.lower = hScrollBar->value() * xGraphsRange.size() / H_SCROLL_BAR_SUM  + xGraphsRange.lower;
//    xShowRange.upper = hScrollBar->pageStep() * xGraphsRange.size() / H_SCROLL_BAR_SUM + xShowRange.lower;
}

void ChartDisplay::addDataWithoutReplot(uint32_t graphIndex, double x, double y)
{
    pCustomPlot->graph(graphIndex)->addData(x, y);
}

void ChartDisplay::addData(uint32_t graphIndex, double x, double y)
{
//    qDebug()<<"ChartDisplay::addData thread:"<<QThread::currentThreadId();
//    qDebug()<<"x="<< x <<", y=" << y;
    bool foundxRange;
    if(x < pCustomPlot->graph(graphIndex)->getKeyRange(foundxRange, QCP::sdBoth).upper)
        emit clearSignal();

    pCustomPlot->graph(graphIndex)->addData(x, y);
    if (dynamic && !xGraphsRange.contains(x)) //如果是动态图
    {
        double oldRangeUpper = xGraphsRange.upper;
        if (xGraphsRange.lower == 0 && xGraphsRange.upper == 0)
        {
            xGraphsRange.lower = x;
        }
        xGraphsRange.expand(x);
//        QCPRange xShowRange = pCustomPlot->xAxis->range();
        if (displayMode == 0)
        {
//            emit changeXRange(xShowRange, xShowRange);
        }
        else if (displayMode == 1)
        {
            xShowRange += xGraphsRange.upper - oldRangeUpper;
//            emit changeXRange(xShowRange, xShowRange);
        }
        else if (displayMode == 2)
        {
            xShowRange.upper += xGraphsRange.upper - oldRangeUpper;
//            emit changeXRange(xShowRange, xShowRange);
        }

        if(initialState && xGraphsRange.size() > 8)
        {
            followCurrent();
            initialState = false;
        }
    }
}

void ChartDisplay::addDataVector(uint32_t graphIndex, const QVector<double> &keys, const QVector<double> &values, bool alreadySorted)
{
//    qDebug()<<"ChartDisplay::addDataVector thread:"<<QThread::currentThreadId();

    pCustomPlot->graph(graphIndex)->addData(keys,values,alreadySorted);

    if(!dynamic)
    {
        xGraphsRange.lower = keys.constFirst();
        xGraphsRange.upper = keys.constLast();
    }
    else
    {
//        double oldRangeUpper = xGraphsRange.upper;
//        if (xGraphsRange.lower == 0 && xGraphsRange.upper == 0)
//        {
//            xGraphsRange.lower = x;
//        }
//        xGraphsRange.expand(x);
////        QCPRange xShowRange = pCustomPlot->xAxis->range();
//        if (manualButton->isChecked())
//        {
////            emit changeXRange(xShowRange, xShowRange);
//        }
//        else if (translationButton->isChecked())
//        {
//            xShowRange += xGraphsRange.upper - oldRangeUpper;
////            emit changeXRange(xShowRange, xShowRange);
//        }
//        else if (stretchButton->isChecked())
//        {
//            xShowRange.upper += xGraphsRange.upper - oldRangeUpper;
////            emit changeXRange(xShowRange, xShowRange);
//        }
    }
}

void ChartDisplay::on_mouse_move(QMouseEvent* e)
{
    QCPGraph* mGraph;
    //将像素点转换成qcustomplot中的坐标值，并通过setGraphKey将锚点值设为真实数据值。tracer->setGraphKey(xAxis->pixelToCoord(event->pos().x()));
    int graphCount = pCustomPlot->graphCount();
    //获得鼠标位置处对应的横坐标数据x
    double x = pCustomPlot->xAxis->pixelToCoord(e->pos().x());
    //遍历曲线
    for (int i = 0; i < graphCount; ++i)
    {
        //判断哪一条曲线被选中
        if (pCustomPlot->graph(i)->selected())
        {
            //显示锚点
            tracer->setVisible(true);
            mGraph = pCustomPlot->graph(i);

            tracer->setGraph(mGraph);//将锚点设置到被选中的曲线上
            tracer->setGraphKey(x); //将游标横坐标设置成刚获得的横坐标数据x
            tracer->setInterpolating(false); //游标的纵坐标可以通过曲线数据线性插值自动获得
            tracer->updatePosition(); //使得刚设置游标的横纵坐标位置生效
            double xValue = tracer->position->key();
            double yValue = tracer->position->value();

            tracerLabel->setVisible(true);
            tracerLabel->setText(QString("time=%1s, %2=%3")
                                 .arg(xValue, 0, 'f', 3)
                                 .arg(mGraph->name())
                                 .arg(yValue));
            pCustomPlot->replot(QCustomPlot::rpQueuedReplot);
            break;
        }
        else
        {
            //没有曲线被选中，不显示锚点
            tracer->setVisible(false);
            tracerLabel->setVisible(false);
        }
    }
}


void ChartDisplay::replot()
{
    if (xGraphsRange.size() > 0)
    {
        if(dynamic)
        {
            //限定x轴范围
            xShowRange = xShowRange.bounded(xGraphsRange.lower, xGraphsRange.upper);
        }
        else  //静态图
        {
            xShowRange = xGraphsRange;
        }

//        //异步设置滚动条
//        QMetaObject::invokeMethod(hScrollBar, [this]
//        {
//            double pageStep = xShowRange.size() / xGraphsRange.size() * H_SCROLL_BAR_SUM;
//            hScrollBar->setPageStep(pageStep);
//            hScrollBar->setMaximum(H_SCROLL_BAR_SUM - pageStep);
//            int scrollBarValue = (xShowRange.lower - xGraphsRange.lower) / xGraphsRange.size() * H_SCROLL_BAR_SUM;
//            hScrollBar->setValue(scrollBarValue);
//
////            qDebug() << pageStep << H_SCROLL_BAR_SUM - pageStep << scrollBarValue;
////            qDebug() << xShowRange.lower << xShowRange.upper << xGraphsRange.lower << xGraphsRange.upper;
//        },Qt::QueuedConnection);

        xRangeFinishSet = false;

        QSignalBlocker blocker(pCustomPlot->xAxis);

        pCustomPlot->xAxis->setRange(xShowRange);
        updateYShowRange(xShowRange);

        xRangeFinishSet = true;

//        if(xShowRange.size() > 10 && autoMode)
//        {
//            translationButton->setChecked(true);
//            autoMode = false;
//        }
    }

    pCustomPlot->replot(QCustomPlot::rpQueuedReplot);
}


void ChartDisplay::updateYShowRange(QCPRange& xShowRange)
{
    //限定y轴范围
    bool foundyRange = false;
    //寻找所有曲线最大的范围
    QCPRange yAllGraphsRange;
    QCPRange yGraphRange;
    int visible = 0; //可见曲线的数目
    for (int i = 0; i < pCustomPlot->graphCount(); i++)
    {
        if(pCustomPlot->graph(i)->lineStyle() == QCPGraph::lsNone)
            continue;

        visible++;
        yGraphRange = pCustomPlot->graph(i)->getValueRange(foundyRange, QCP::sdBoth, xShowRange);

        if(visible == 1)
        {
            yAllGraphsRange = yGraphRange;
        }
        else
        {
            yAllGraphsRange.expand(yGraphRange);
        }
    }
    //如果曲线范围是0~0，不更新y轴范围
    if(yAllGraphsRange.upper == 0 && yAllGraphsRange.lower == 0)
    {
        QCPRange yDefaultRange(-3, 30);
        pCustomPlot->yAxis->setRange(yDefaultRange);
        return;
    }

    if(yAllGraphsRange.upper - yAllGraphsRange.lower < 1e-10)
    {
        yAllGraphsRange.upper += 1e-10;
    }
    myScaleRange(yAllGraphsRange, 0.1);
    pCustomPlot->yAxis->setRange(yAllGraphsRange);
}

void ChartDisplay::on_clear_clicked()
{
    //清空所有图像数据
    for(int i = 0; i < pCustomPlot->graphCount(); i++)
    {
        pCustomPlot->graph(i)->data()->clear();
    }
    xGraphsRange.lower = 0;
    xGraphsRange.upper = 0;

    viewGlobal();
    initialState = true;

//    emit replotSignal();
}

void ChartDisplay::addGraph(const QString& name, const QColor& color)
{
    QCPGraph* newGraph = pCustomPlot->addGraph();
    newGraph->setName(name);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(color);

    newGraph->setPen(pen);
    newGraph->setSelectable(QCP::stSingleData);
    newGraph->setLineStyle(QCPGraph::lsLine);
}

void ChartDisplay::deleteGraph(int index)
{
    pCustomPlot->removeGraph(index);
}

void ChartDisplay::setLabel(const QString& xLabel, const QString& yLabel)
{
    //x轴名字
    pCustomPlot->xAxis->setLabel(xLabel);
    //Y轴名字
    pCustomPlot->yAxis->setLabel(yLabel);
}

//查看当前
void ChartDisplay::followCurrent()
{
    double totalRangeSize = xGraphsRange.size();

    if(totalRangeSize > 8)
    {
        xShowRange.upper = xGraphsRange.upper;
        xShowRange.lower = xGraphsRange.upper - 8;
    //         translationButton->setChecked(true);
        displayMode = 1;
        emit replotSignal();
    }
    else
    {
        viewGlobal();
    }
}

void ChartDisplay::viewGlobal()
{
    xShowRange = xGraphsRange;
//    stretchButton->setChecked(true);
    displayMode = 2;
    emit replotSignal();
}
