#ifndef DBHANDLER_H
#define DBHANDLER_H

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QFile>
#include <QVariant>
#include <QDateTime>
#include <QCryptographicHash>
#include <QSqlError>
#include <QDebug>

class DBHandler
{
public:
    DBHandler();

    bool readSupportedDatatypes(QSqlQuery* p_qry, QString *error);

    bool getCategories(QSqlQuery* p_qry, QString *error);
    bool createCategory(QString name, QString *error);
    bool updateCategory(QString name, QString newName, QString *error);
    bool checkCategoryExists(QString categoryName, bool* categoryExists, QString *error);
    bool deleteCategory(QString name, QString* error);

    bool getCustomfields(QSqlQuery* p_qry, QString *error, QString gereateTyp);
    bool createCustomField(QString *error, QString name, QString geraeteTyp, QString datentyp, bool pflichtfeld);
    bool checkCustomfieldExists(QString fieldName, QString categoryName, bool* customfieldExists,QString *error);
    bool readCustomField(QString geraetetyp, QString fieldname, QString* name, QString *datatype, bool *pflichtfeld);
    bool updateCustomField(QString category, QString fieldname, QString newName, QString newDatatype, bool newRequired, QString *error);
    bool deleteCustomField(QString category, QString fieldname, QString* error);
    bool findByField(QString fieldValue, QString *error, QString category = NULL);

private:

    QSqlDatabase db;


    bool DBExists();
    bool createDB();
    bool openDB();
    bool closeDB();
    bool execute(QString statement, QSqlQuery* p_qry, QString *error);
};

#endif // DBHANDLER_H
