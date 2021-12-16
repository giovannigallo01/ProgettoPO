#ifndef RIVISTA_H
#define RIVISTA_H

#include <QString>
#include <QDate>
#include "articolo.h"

class rivista
{
private:
    QString nome;
    QString acronimo;
    QString editore;
    QDate data;
    int volume;
    QList<articolo> articoliPerRivista;

public:
    rivista();
    rivista(QString n, QString a, QString e, QDate d, int v);

    QString getNome()const;
    QString getAcronimo()const;
    QString getEditore()const;
    QDate getData()const;
    int getVolume()const;
    const QList<articolo>& getArticoliPerRivista()const;


    void setNome(QString n);
    void setAcronimo(QString a);
    void setEditore(QString e);
    void setData(QDate d);
    void setVolume(int v);

    void aggiungiArticoloPerRivista(articolo articolo);

    bool operator==(const rivista& r)const;

    friend ostream& operator<<(ostream& out, const rivista& r)
    {
        QString dataString = r.data.toString(Qt::DateFormat::ISODate);
        out << r.nome.toStdString() << " - " << r.acronimo.toStdString() << " ~ " << dataString.toStdString() << " ~ ";
        out << "Editore: " << r.editore.toStdString() << " ~ " << "Volume: " << r.volume;
        return out;
    }
};

#endif // RIVISTA_H
