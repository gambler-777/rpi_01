#ifndef MODEL_MAIN_H
#define MODEL_MAIN_H

#include <QMainWindow>
#include <QList>
#include <QTime>
#include <QDate>

namespace Ui {
class Model_Main;
}

class Model_Main : public QMainWindow
{
    Q_OBJECT

public:
    explicit Model_Main(QWidget *parent = nullptr);
    ~Model_Main();


private slots:
    void on_pushu_clicked();

    void on_ShotButton_clicked();

    void on_checkBox_Preview_stateChanged(int arg1);

    void on_pushButton_py_clicked();

//    void on_checkBox_auto_stateChanged(int arg1);

private:
    Ui::Model_Main *ui;

    QString ImgName;
    QString Path;
    QString WBStr;
    QString SSStr;
    double SSDouble;
    QString ISOStr;
    QString Preview;

    QString RotStr;
    QString DRCStr;

    long PiCamSSnum;
    QString PiCamDelay;
    int PiCamISO;

    QString CurrentDateTime;

    QList <double>SSsecList; //Chislo viderzhki kotoroe pod drobju
    QList <double>SSmksList; // Shutter speed in microseconds

    QList <long>ISOList; //ISO list

    QList <QString>WBList; //WB Mode

    QString ShotParams; //Nabor vseh parametrov sjomki

   void ShotParamStringCreate();

};

#endif // MODEL_MAIN_H
