#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListView>
#include <QStandardItemModel>
#include <QTableView>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget window;
   window.setWindowTitle("Класс QTableView");
   window.resize(500, 200);

   QTableView *view = new QTableView();
   QStandardItemModel *model = new QStandardItemModel(&window);
   model->setRowCount(3);
   model->setColumnCount(4);
   for (int row = 0, r = model->rowCount(); row < r; ++row) {
      for (int col = 0, c = model->columnCount(); col < c; ++col) {
         QStandardItem *item = new QStandardItem(
                        QString("%1, %2").arg(row).arg(col));
         model->setItem(row, col, item);
      }
   }
   model->setHeaderData(0, Qt::Horizontal, "A");
   model->setHeaderData(1, Qt::Horizontal, "B");
   model->setHeaderData(2, Qt::Horizontal, "C");
   model->setHeaderData(3, Qt::Horizontal, "D");

   model->setHeaderData(0, Qt::Vertical, "01");
   model->setHeaderData(1, Qt::Vertical, "02");
   model->setHeaderData(2, Qt::Vertical, "03");
   view->setModel(model);

   QPushButton *btn1 = new QPushButton("Получить значение");

   QVBoxLayout *vbox = new QVBoxLayout();
   vbox->addWidget(view);
   vbox->addWidget(btn1);
   window.setLayout(vbox);

   QObject::connect(btn1, &QPushButton::clicked, [=]() {
      QModelIndex ind = view->currentIndex();
      if (ind.isValid()) {
         qDebug() << "Данные:" << ind.data().toString();
         qDebug() << "row:" << ind.row() << "column:" << ind.column();
      }
      else {
         qDebug() << "Нет текущего элемента";
      }
   });

   window.show();
   return app.exec();
}


