#ifndef CONFERENZA_H
#define CONFERENZA_H

#include <QString>
#include <QList>
#include <QDate>
#include "articolo.h"

class conferenza
{
private:
    QString nome;
    QString acronimo;
    QString luogo;
    QDate data;
    QList<QString> organizzatori;
    int numeroPartecipanti;
    QList<articolo> articoliPerConferenza;

public:
    conferenza();
    conferenza(QString n, QString a, QString l, QDate d, QList<QString> o, int np);

    QString getNome()const;
    QString getAcronimo()const;
    QString getLuogo()const;
    QDate getData()const;
    const QList<QString>& getOrganizzatori()const;
    int getNumeroPartecipanti()const;
    QList<articolo> getArticoliPerConferenza()const;

    void setNome(QString n);
    void setAcronimo(QString a);
    void setLuogo(QString l);
    void setData(QDate d);
    void setNumeroPartecipanti(int p);

    void aggiungiOrganizzatore(QString org);
    void aggiungiArticoloPerConferenza(articolo articolo);

    bool operator==(const conferenza& c)const;

    friend ostream& operator<<(ostream& out, const conferenza& c)
    {
        QString dataString = c.data.toString(Qt::DateFormat::ISODate);
        out << c.nome.toStdString() << " - " << c.acronimo.toStdString() <<" ~ " << c.luogo.toStdString() << " " <<
               dataString.toStdString() << " ~ " << "N° partecipanti: " << c.numeroPartecipanti << " - ";
        out << "Organizzatori:";
        for(auto org : c.organizzatori)
        {
            if(org == c.organizzatori.back())
            {
                out << " " << org.toStdString();
                return out;
            }
            out << " " << org.toStdString() << ",";
        }
        return out;
    }
};

#endif // CONFERENZA_H
