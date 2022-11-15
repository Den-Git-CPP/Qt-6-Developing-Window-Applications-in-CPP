#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSplitter>

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent=nullptr);
   ~Widget();
private slots:
   void on_btn1_clicked();
   void on_btn2_clicked();
private:
   QSplitter *splitter;
   QLabel *label1;
   QLabel *label2;
   QPushButton *btn1;
   QPushButton *btn2;
   QVBoxLayout *vbox;
   QByteArray state;
};
#endif // WIDGET_H
