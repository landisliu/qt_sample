#include "qwdlgmanual.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
QWDlgManual::QWDlgManual(QWidget *parent)
    : QDialog(parent)
{
    InitUI();
    InitSignalSlots();
    setWindowTitle("form create manually");
}

QWDlgManual::~QWDlgManual()
{

}

void QWDlgManual::InitUI()
{
    chkBoxUnderline = new QCheckBox("Underline");
    chkBoxBold = new QCheckBox("Bold");
    chkBoxItalic = new QCheckBox("Italic");

    QHBoxLayout* hLayout1 = new QHBoxLayout;
    hLayout1->addWidget(chkBoxBold);
    hLayout1->addWidget(chkBoxUnderline);
    hLayout1->addWidget(chkBoxItalic);

    rBtnRed = new QRadioButton("Red");
    rBtnBlue = new QRadioButton("Blue");
    rBtnBlack = new QRadioButton("Black");
    QHBoxLayout* hLayout2 = new QHBoxLayout;
    hLayout2->addWidget(rBtnRed);
    hLayout2->addWidget(rBtnBlue);
    hLayout2->addWidget(rBtnBlack);

    btnOK = new QPushButton("确定");
    btnCancel = new QPushButton("取消");
    btnClose = new QPushButton("关闭");

    QHBoxLayout* hLayout3 = new QHBoxLayout;
    hLayout3->addStretch();
    hLayout3->addWidget(btnOK);
    hLayout3->addWidget(btnCancel);
    hLayout3->addStretch();
    hLayout3->addWidget(btnClose);


    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("Hello World\n\nThis is my demo!");

    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);
    vLayout->addWidget(txtEdit);
    vLayout->addLayout(hLayout3);

    setLayout(vLayout);
}
void QWDlgManual::InitSignalSlots()
{
    connect(chkBoxUnderline, SIGNAL(clicked(bool)), this, SLOT(on_chkUnderline(bool)));
    connect(chkBoxItalic, SIGNAL(clicked(bool)), this, SLOT(on_chkItalic(bool)));
    connect(chkBoxBold, SIGNAL(clicked(bool)), this, SLOT(on_chkBold(bool)));

    connect(rBtnRed, SIGNAL(clicked()), this, SLOT(setTxtFontColor()));
    connect(rBtnBlue, SIGNAL(clicked()), this, SLOT(setTxtFontColor()));
    connect(rBtnBlack, SIGNAL(clicked()), this, SLOT(setTxtFontColor()));

    connect(btnOK, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));

}

void QWDlgManual::on_chkUnderline(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}
void QWDlgManual::on_chkItalic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}
void QWDlgManual::on_chkBold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::setTxtFontColor()
{
    QPalette palette = txtEdit->palette();
    if(rBtnRed->isChecked())
        palette.setColor(QPalette::Text, Qt::red);
    else if(rBtnBlue->isChecked())
        palette.setColor(QPalette::Text, Qt::blue);
    else if(rBtnBlack->isChecked())
        palette.setColor(QPalette::Text, Qt::black);
    else
        palette.setColor(QPalette::Text, Qt::black);
    txtEdit->setPalette(palette);
}
