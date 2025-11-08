#ifndef QT_MASTER_CHART_DISPLAY_H
#define QT_MASTER_CHART_DISPLAY_H

#include "qcustomplot.h"

class ChartDisplay : public QObject
{
	Q_OBJECT
private:
	QWidget* parent{};  //显示图像的label对象
	QScrollBar* hScrollBar{};  //横滚条
	const uint32_t H_SCROLL_BAR_SUM = 1000;  //横滚条总量

	QRadioButton* manualButton;        //手动选项
	QRadioButton* translationButton;   //平移选项
	QRadioButton* stretchButton;       //拉伸选项
    QPushButton* clearButton;          //清除图像按钮
    int displayMode = 2;    //显示模式，手动0，平移1，拉伸2

    QCPRange xGraphsRange;   //所有图像x轴的范围
    QCPRange xShowRange;
	bool xRangeFinishSet = true;  //设定x轴范围是否完成的标识符

	void updateYShowRange(QCPRange& xShowRange);  //更新y轴显示范围

	QCustomPlot* pCustomPlot = nullptr;  //图像显示对象

	QCPItemTracer* tracer = nullptr;
    QCPItemText *tracerLabel = nullptr; //游标标签

    bool autoMode = true;
    bool dynamic = true;

    //关注当前模式的最短长度
    static constexpr double CURRENT_VIEW_LENGTH = 5;
    //从零开始没有任何操作的状态
    bool initialState = true;

public:
	ChartDisplay(QWidget* parent, QCustomPlot* customPlot, QScrollBar* scrollBar,
                 QPushButton* clearButton, QRadioButton* manualButton = nullptr,
                 QRadioButton* translationButton = nullptr, QRadioButton* stretchButton = nullptr);
	~ChartDisplay();

    void addGraph(const QString& name, const QColor& color);
    void deleteGraph(int index);

    void addDataWithoutReplot(uint32_t graphIndex, double x, double y);
    void maximizeXRange();

    QCustomPlot* getCustomPlot() {return pCustomPlot; }

    QScrollBar* getScrollBar() { return hScrollBar; }


    void setLabel(const QString& xLabel, const QString& yLabel);

signals:
    void changeXRange(const QCPRange& newRange, const QCPRange& oldRange);

    void addDataSignal(uint32_t graphIndex, double x, double y);
    void addDataVectorSignal(uint32_t graphIndex, const QVector<double>& keys, const QVector<double>& values, bool alreadySorted);
    void replotSignal();
    void maximizeXRangeSignal();
    void clearSignal();
public slots:
	void on_x_range_changed(const QCPRange& newRange, const QCPRange& oldRange);
	void on_slider_moved(int position);
	void on_mouse_move(QMouseEvent* e);
    void on_clear_clicked();

    void replot();

    void addData(uint32_t graphIndex, double x, double y);
    void addDataVector(uint32_t graphIndex, const QVector<double>& keys, const QVector<double>& values, bool alreadySorted);

    void followCurrent();
    void viewGlobal();
};

#endif
