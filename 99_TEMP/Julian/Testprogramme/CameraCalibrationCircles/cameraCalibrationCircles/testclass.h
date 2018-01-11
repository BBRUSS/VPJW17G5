#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QWidget>

class TestClass : public QWidget
{
    Q_OBJECT
public:
    explicit TestClass(QWidget *parent = nullptr);
    ~TestClass();

signals:

private slots:
    void showCVLogo();
    void closeCVLogo();
};

#endif // TESTCLASS_H
