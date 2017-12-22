#ifndef SQLQUERYTHREAD_H
#define SQLQUERYTHREAD_H


#include <QtCore/QThread>
#include <QtSql>
#include <QDebug>

class SqlWorker : public QObject
{
    Q_OBJECT

public:
    SqlWorker( QObject* parent = 0);
    ~SqlWorker();

    //const QString getDatabaseName();
public slots:
    void slotExecute( const QString& query );

signals:
    void results( const QSqlQuery& query );
    //void results(QSqlRecord& record );

private:
    QSqlDatabase m_database;
};


class SqlQueryThread : public QThread
{
    Q_OBJECT

signals:
    void queryFinished( const QSqlQuery& query );

public:
    void execute(const QString &query);

public slots:
    void slotExecQuery(const QString& query);



   void quitSqlQueryThread();
signals:
    void queue( const QString& query );

public:
    //const QString getDatabaseName();

protected:
    void run();

private:
    SqlWorker* m_worker;

};

#endif // SQLQUERYTHREAD_H
