#ifndef QWDLGMANUAL_H
#define QWDLGMANUAL_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QPlainTextEdit>
class QWDlgManual : public QDialog
{
    Q_OBJECT

private:
    QCheckBox* chkBoxUnderline;
    QCheckBox* chkBoxItalic;
    QCheckBox* chkBoxBold;

    QRadioButton* rBtnBlue;
    QRadioButton* rBtnRed;
    QRadioButton* rBtnBlack;

    QPlainTextEdit* txtEdit;

    QPushButton* btnOK;
    QPushButton* btnCancel;
    QPushButton* btnClose;

    void InitUI();
    void InitSignalSlots();
private slots:
    void on_chkUnderline(bool checked);
    void on_chkItalic(bool checked);
    void on_chkBold(bool checked);

    void setTxtFontColor();

public:
    QWDlgManual(QWidget *parent = 0);
    ~QWDlgManual();
};

#endif // QWDLGMANUAL_H
