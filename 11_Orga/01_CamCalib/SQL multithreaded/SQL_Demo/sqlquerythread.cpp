#include "sqlquerythread.h"

// SqlWorker ----

SqlWorker::SqlWorker(QObject *parent)
{

    m_database = QSqlDatabase::addDatabase("QMYSQL"); // create connection to DB

    if (m_database.isValid())
    {
        qDebug() << "Driver:" << m_database.driverName() << "successfully loaded" ;
    }
    else
    {
        qDebug() << "Error with connection. Available drivers: " << QSqlDatabase::drivers();
    }

    m_database.setHostName("localhost");
    m_database.setDatabaseName("testschema");
    m_database.setUserName("VPJSS15");
    m_database.setPassword("1234");

    if(m_database.open()){
        qDebug() << "Database successfully connected.";
    }
    else
    {
        qDebug() << m_database.lastError();
    }
}

SqlWorker::~SqlWorker()
{

    m_database.close(); // close connection to DB
}

void SqlWorker::slotExecute(const QString &query)
{
    // execute the query an pass back result via "results" signal
    QSqlQuery sqlquery(query);
/*
    qDebug() << "is Active:";
    qDebug() << sqlquery.isActive();
    qDebug() << "is Valid:";
    qDebug() << sqlquery.isValid();

    while (sqlquery.next()) {
        QString country = sqlquery.value(0).toString();
        qDebug() << country;
    }
*/
    emit( results(sqlquery) );
}

// SqlQueryThread ----

void SqlQueryThread::run()
{
    // Create worker object within the context of the new thread
    m_worker = new SqlWorker();

    // forward to the worker: a 'queued connection'!
    connect( this, SIGNAL( queue( const QString& ) ), m_worker, SLOT( slotExecute( const QString& ) ) );
    // forward a signal back out
    connect( m_worker, SIGNAL( results( const QSqlQuery& ) ), this, SIGNAL( queryFinished( const QSqlQuery& ) ) );

    exec();  // start own event loop
    qDebug() << "SqlQueryThread successfully stopped.";
}

// delegate query to worker
void SqlQueryThread::execute( const QString& query )
{
    emit queue( query ); // queues to worker
}

// slot to initially recieve query
void SqlQueryThread::slotExecQuery(const QString &query)
{
    execute(query);
}

void SqlQueryThread::quitSqlQueryThread(){
    qDebug() << "About to stop SqlQueryThread...";
    this->quit(); // close event loop
    while(this->isRunning()){}
}





