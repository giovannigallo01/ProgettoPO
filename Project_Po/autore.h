#ifndef AUTORE_H
#define AUTORE_H

#include <QString>
#include <QList>
#include <iostream>
using namespace std;

class autore
{
private:
    QString identificativo;
    QString nome;
    QString cognome;
    QList<QString> afferenze;

public:
    autore();
    autore(QString id, QString n, QString c, QList<QString> aff);

    QString getIdentificativo()const;
    QString getNome()const;
    QString getCognome()const;
    const QList<QString>& getAfferenze()const;

    void setIdentificativo(QString id);
    void setNome(QString n);
    void setCognome(QString c);

    void aggiungiAfferenza(QString aff);

    bool operator==(const autore& a)const;

    friend ostream& operator<<(ostream& out, const autore& a)
    {
        out << a.identificativo.toStdString() << " - " << a.nome.toStdString() << " " << a.cognome.toStdString() << " ~ ";
        out << "AFFERENZE:";
        if(a.afferenze.isEmpty())
            out << " (Nessuna afferenza presente) ";
        for(auto aff : a.afferenze)
        {
            if(aff == a.afferenze.back())
            {
                out << " " << aff.toStdString();
                return out;
            }
            out << " " << aff.toStdString() << ",";
        }
        return out;
    }
};

#endif // AUTORE_H
