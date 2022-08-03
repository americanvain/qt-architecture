#ifndef EXCEL_DATA_H
#define EXCEL_DATA_H
#include <QString>
class Excel_data{
public:
    QString value_;
    void set_name(QString nameshuru);
    QString get_name() const;
    QString get_id() const;
    QString get_value() const;
private:
    QString name_;
    const QString id_;
};

#endif // EXCEL_DATA_H
