#include "model_main.h"
#include "ui_model_main.h"

Model_Main::Model_Main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Model_Main)
{
    ui->setupUi(this);



    SSsecList.append(800);
//    SSsecList.append(640);
//    SSsecList.append(500);
    SSsecList.append(400);
//    SSsecList.append(320);
    SSsecList.append(200);
//    SSsecList.append(160);
    SSsecList.append(100);
//    SSsecList.append(60);
    SSsecList.append(40);
    SSsecList.append(20);
//    SSsecList.append(15);
    SSsecList.append(10);
    SSsecList.append(8);
    SSsecList.append(4);
    SSsecList.append(2);
    SSsecList.append(1);
    SSsecList.append(.5);
    SSsecList.append(.25);
    SSsecList.append(.1666);

    for (int i=0; i<SSsecList.count(); i++)
    {
    ui->comboBox_SS->addItem("1/"+QString::number(SSsecList.value(i)));
    SSmksList.append(1000000.0/SSsecList.value(i));
        if(SSsecList.at(i)<=1){
            double k=1/SSsecList.at(i);
            ui->comboBox_SS->setItemText(i,QString::number((int)k));
        }
    }

    ISOList.append(800);
    ISOList.append(640);
    ISOList.append(500);
    ISOList.append(400);
    ISOList.append(320);
    ISOList.append(200);
    ISOList.append(160);
    ISOList.append(100);

    for (int i=0; i<ISOList.count(); i++)
    {
    ui->comboBox_ISO->addItem(QString::number(ISOList.value(i)));
    }

    WBList.append("auto");
    WBList.append("off");
    WBList.append("sun");
    WBList.append("cloud");
    WBList.append("shade");
    WBList.append("tungsten");
    WBList.append("fluorescent");
    WBList.append("incandescent");
    WBList.append("flash");
    WBList.append("horizon");
    WBList.append("greyworld");

    for (int i=0; i<WBList.count(); i++)
    {
    ui->comboBox_WB->addItem(WBList.value(i));
    }
    Preview = " -n";
}

Model_Main::~Model_Main()
{
    delete ui;
}

void Model_Main::on_pushu_clicked() //button generating string with shot parameters
{
    ImgName = ui->LineFileName->text();
    Path = ui->LinePath->text();
    WBStr = " -awb "+ui->comboBox_WB->currentText();

    if(ui->checkBox_3->isChecked())
    {
        ISOStr ="";
        SSStr = "";
    }
    else {
        ISOStr = " -ISO "+ui->comboBox_ISO->currentText();
        int index = ui->comboBox_SS->currentIndex();
        SSStr = " -ss "+QString::number((int)SSmksList.at(index));
        }


    if(ui->checkBoxRot->isChecked())
         RotStr = " -rot 180";
    else RotStr = "";

    if(ui->checkBox_DRC->isChecked())
        DRCStr = " -drc high";
    else DRCStr = "";

    PiCamDelay = " -t "+ui->spinBoxDelay->text();

//    ShotParams = "raspistill -o "+Path+ImgName+".jpg"+PiCamDelay+ISOStr+SSStr+DRCStr+RotStr+WBStr+Preview;
//      ShotParams = "raspistill -o "+Path+ImgName+".jpg"+PiCamDelay+ISOStr+SSStr+DRCStr+RotStr+WBStr+Preview;
      ShotParams = "echo \"raspistill -o "+Path+ImgName+".jpg"+PiCamDelay+ISOStr+\
              SSStr+DRCStr+RotStr+WBStr+Preview+"\" > /home/maks/file1.txt";



//    PiCamSSStr = ui->comboBox_SS->currentText();
    ui->textEdit->setText(ShotParams);
}


void Model_Main::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1){
    ui->comboBox_SS->setEnabled(0);
    ui->comboBox_ISO->setEnabled(0);
    }
    else{
    ui->comboBox_SS->setEnabled(1);
    ui->comboBox_ISO->setEnabled(1);
    }
    return;
}

void Model_Main::on_ShotButton_clicked()
{
    system(qPrintable(ShotParams));
}

void Model_Main::on_checkBox_Preview_stateChanged(int arg1)
{
    if (arg1)
        Preview = "";
    else Preview = " -n";
}

void Model_Main::on_pushButton_py_clicked()
{
    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    ui->LineDate->setText(cd.toString(Qt::ISODate)+"-"+ct.toString("hh-mm-ss"));
    CurrentDateTime = cd.toString(Qt::ISODate)+"-"+ct.toString("hh-mm-ss");
    QString MkdirCom = "mkdir /home/maks/3dphoto/"+CurrentDateTime;

    system(qPrintable(MkdirCom));
}

void Model_Main::ShotParamStringCreate()
{}

