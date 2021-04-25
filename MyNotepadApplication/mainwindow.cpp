#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QFile>
#include<QMessageBox>
#include <QString>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QFont>
#include<QFontDialog>
#include<QColorDialog>
#include<QColor>
#include<QPalette>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#if !QT_CONFIG(clipboard)
    ui->actionCut->setEnabled(false);
    ui->actionCopy->setEnabled(false);
    ui->actionPaste->setEnabled(false);
#endif
    ui->toolBar->setMovable(false);
    ui->toolBar1->setMovable(false);
    ui->toolBar_2->setMovable(false);
    ui->toolBar_3->setMovable(false);
    ui->toolBar_4->setMovable(false);
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_actionNew_triggered()
{
    file_path.clear();
    ui->textEdit->setText(QString());
}
void MainWindow::on_actionOpen_triggered()
{
    QString file_name=QFileDialog::getOpenFileName(this,"open the file");
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName;
    if (file_path.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        file_path = fileName;
    } else {
        fileName = file_path;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    file_path = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter p;
        p.setPrinterName("HP Laser Jet");
        QPrintDialog pd(&p,this);
        if(pd.exec()==QDialog::Rejected)
        {
            QMessageBox::warning(this,"Error","Can't access printer");
            return;
        }
        ui->textEdit->print(&p);
}

void MainWindow::on_actionCut_triggered()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->cut();
#endif
}

void MainWindow::on_actionCopy_triggered()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->copy();
#endif
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionFont_triggered()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected)
        ui->textEdit->setFont(font);
}

void MainWindow::on_actionColor_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"Choose color");
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
}

void MainWindow::on_actionBackbround_Color_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"Choose color");
    if(color.isValid())
    {
        ui->textEdit->setStyleSheet("background-color:"+color.name()+";");
     }
}

void MainWindow::on_actionBold_triggered(bool bold)
{
         bold ? ui->textEdit->setFontWeight(QFont::Bold):
         ui->textEdit->setFontWeight(QFont::Normal);
}

void MainWindow::on_actionItalic_triggered(bool italic)
{
    ui->textEdit->setFontItalic(italic);
}

void MainWindow::on_actionUnderline_triggered(bool checked)
{
    ui->textEdit->setFontUnderline(checked);
}

void MainWindow::on_actionHighlight_Text_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"Choose color");
    if(color.isValid())
       ui->textEdit->setTextBackgroundColor(color);
}

void MainWindow::on_actionInfo_triggered()
{
    QMessageBox::about(this, tr("About  This Notepad"),
                 tr("The <b style='color:blue'>Notepad</b> is Created by <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<b style='color:navy'>Gireesh 4044</b>"));
}

void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}
