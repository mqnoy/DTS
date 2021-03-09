#include "serialcentralprocess.h"

SerialCentralProcess::SerialCentralProcess(QObject *parent) : QObject(parent)
{
    qDebug()<<"SerialCentralProcess executed";

    // open db
    openDBSQLite();
}

void SerialCentralProcess::openDBSQLite()
{
    QString connName = "conn_dts";
    m_database = QSqlDatabase::addDatabase("QSQLITE", connName); // named connection
    QString dbPath = Constant::workingDirApp()+"dts.db";
    m_database.setDatabaseName(dbPath);
    if (!m_database.open()){
        qWarning() << "Unable to connect to database, giving up:" << m_database.lastError().text();
        return;
    }else{
        qDebug()<<"openDBSQLite, success open connection: "<<connName;
        if ( !m_database.tables().contains( "item" ) )
        {
            // some data
            m_database.exec( "create table item(id int, name varchar);" );
            m_database.transaction();
            QSqlQuery query(m_database);
            query.prepare("INSERT INTO item (id, name) "
                          "VALUES (?,?)");
            for ( int i = 0; i < 20; ++i ){
                query.addBindValue(i);
                query.addBindValue(QString::number(i));
                query.exec();
            }
            m_database.commit();
        }
    }
}

void SerialCentralProcess::executeSQLite(const QString &queryId, const QString &sql, QList<QSqlRecord> &recs, int &last_insert_id, bool &returnUD)
{
    last_insert_id = -1;
    returnUD = false;

    // use previously defined db connection
    QSqlQuery *query;
    query = new QSqlQuery(m_database);
    // execute query, get result
    bool executeQuery = query->exec(sql);

    // check for errors
    if (executeQuery) {
        QStringList _sql_operation = sql.split(' ');
        if(_sql_operation.value(0) == "INSERT"){
            last_insert_id = query->lastInsertId().toInt();
        }else if (_sql_operation.value(0) == "SELECT") {
            recs.clear();
            while (query->next()){
                // append to record
                recs.append(query->record());
            }
        }else if (_sql_operation.value(0) == "UPDATE") {
            returnUD = true;
        }else if (_sql_operation.value(0) == "DELETE") {
            returnUD = true;
        }
    }else{
        returnUD = false;
        // emit error signal
        emit qDebug()<<""<<queryId, query->lastError(), QString();
        return;
    }

    // result saved - release resources
    query->finish();
}

void SerialCentralProcess::receiveFromSerial(QString portName, QByteArray buff)
{
    QJsonDocument document = QJsonDocument::fromJson(buff.data());
    QJsonObject object = document.object();

    if(object.value("kind").toString() == "A"){
        // lane A
        _ft_a->display(object.value("ft").toInt());
        _et_a->display(object.value("et").toInt());
        _rt_a->display(object.value("rt").toInt());
        _spd_a->display(object.value("spd").toInt());

        // set status
        _label_status_a->setText(object.value("status").toString());

        // check device is exsists
        QString str_query = QString("INSERT INTO item (name) VALUES(%1);").arg(object.value("ft").toInt());
        QList<QSqlRecord> recList;
        int lastInsertId;
        bool returnUD1;
        executeSQLite("CHECK_ITEM", str_query, recList, lastInsertId, returnUD1);
        if(lastInsertId > 0){
            qDebug()<<"success insert "<<lastInsertId;
        }
        qDebug()<<"conn_db list"<<m_database.connectionNames();

    }else if(object.value("kind").toString() == "B"){
        // lane B
        _ft_b->display(object.value("ft").toInt());
        _et_b->display(object.value("et").toInt());
        _rt_b->display(object.value("rt").toInt());
        _spd_b->display(object.value("spd").toInt());

        // set status
        _label_status_b->setText(object.value("status").toString());

    }
    //qDebug()<<"receiveFromSerial, receive from: "<<portName<<" : "<<buff;
}

void SerialCentralProcess::recInitPtrLCD(QLCDNumber* ft_a, QLCDNumber* et_a, QLCDNumber* rt_a, QLCDNumber* spd_a,
                                         QLCDNumber* ft_b, QLCDNumber* et_b, QLCDNumber* rt_b, QLCDNumber* spd_b)
{
    qDebug()<<"recInitPtrLCD ..";
    _ft_a = ft_a;
    _et_a = et_a;
    _rt_a = rt_a;
    _spd_a = spd_a;
    _ft_b = ft_b;
    _et_b = et_b;
    _rt_b = rt_b;
    _spd_b = spd_b;
}

void SerialCentralProcess::recInitPtrLabel(QLabel* label_status_a, QLabel* label_status_b)
{
    _label_status_a = label_status_a;
    _label_status_b = label_status_b;
}
