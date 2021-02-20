#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextCodec>
#include <QDebug>
#include <QDateTime>
// 文件流
// 文本流 数据流（二进制格式）
#include <QTextStream>  // 操作的数据类型：基础数据类型：int， float string
#include <QDataStream>  // QImage QPoint QRect 1. 不依赖平台

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


//    connect(ui->selectFile, &QPushButton::clicked, this, [=]()
//    {
//        QString fileName = QFileDialog::getOpenFileName(this, "open file", "d:\\");
//        if(fileName.isEmpty() == true)
//        {
//            QMessageBox::warning(this, "waining", "select file faild!");
//            return;
//        }
//        ui->filePath->setText(fileName);

//        // 创建文件对象
//        // 默认读取的文件格式：UTF8
//        QFile file(fileName);
//        QTextCodec* codec = QTextCodec::codecForName("gbk");
//        // 指定打开方式
//        bool isOk = file.open(QFile::ReadOnly);
//        if (isOk == false)
//        {
//            QMessageBox::critical(this,"ERROR", "file open faild!");
//            return;
//        }
//        // 读文件
//        QByteArray array = file.readAll();
//        // 显示到文本框
//        ui->textEdit->setText(codec->toUnicode(array));
//        // 关闭文件
//        file.close();

//        // 默认读取的文件格式：UTF8
//        QFile file(fileName);
//        // 指定打开方式
//        bool isOk = file.open(QFile::ReadOnly);
//        if (isOk == false)
//        {
//            QMessageBox::critical(this,"ERROR", "file open faild!");
//            return;
//        }
//        // 创建流对象
//        QTextStream stream(&file);  // 设置IO设备给流对象
//        stream.setCodec("utf8");
//        // 读文件
//        QByteArray array;
//        while(false == stream.atEnd())
//        {
//            array += stream.readLine();
//        }

//        // 读文件
//        QByteArray array;
//        while(!file.atEnd())
//        {
//            array += file.readLine();
//        }

//        // 显示到文本框
//        ui->textEdit->setText(array);

//        char buf[128] ={0};
//        file.write(QString("hello,word").toUtf8());
//        file.write(buf, strlen(buf));
//        file.write(buf);
//        // 关闭文件
//        file.close();




//    });



//    QFile f("aaaa1.txt");
//    f.open(QFile::WriteOnly);
//    QTextStream txt(&f);

//    // 写文件
//    txt << QString("hello,world!") << 123456;
//    f.close();

//    QString buf1;
//    f.open(QFile::ReadOnly);
//    txt.setDevice(&f);
//    txt >> buf1;
//    qDebug() << buf1.toUtf8().data();


    QFile f("aaaa1.txt");
    f.open(QFile::WriteOnly);
    QDataStream ds(&f);

    // 写文件
    ds << QString("hello,world!") << 123456;
    f.close();

    QString buf2;
    int number;
    f.open(QFile::ReadOnly);
    ds.setDevice(&f);
    ds >> buf2 >> number;
    qDebug() << buf2.toUtf8().data() << number;


    QImage image(":/Image/face.png");
    QByteArray aaaa;
    QDataStream ss(&aaaa, QIODevice::ReadWrite);
    ss << image;

    QFileInfo info("D:\\Temp\\qt\\Image\\face.png");
    qDebug() << "file size: " << info.size();
    qDebug() << "file path: " << info.path();
    qDebug() << "file name: " << info.fileName();
    qDebug() << "modify date: " << info.lastModified().toString("yyyy-MM-dd hh:mm:ss");



}

Widget::~Widget()
{
    delete ui;
}
