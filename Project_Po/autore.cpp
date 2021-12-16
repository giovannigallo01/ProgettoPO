#include "autore.h"

autore::autore() {}
autore::autore(QString id, QString n, QString c, QList<QString> aff): identificativo(id), nome(n), cognome(c), afferenze(aff) {}

QString autore::getIdentificativo()const { return identificativo; }
QString autore::getNome()const { return nome; }
QString autore::getCognome()const { return cognome; }
const QList<QString>& autore::getAfferenze()const { return afferenze; }

void autore::setIdentificativo(QString id) { identificativo = id; }
void autore::setNome(QString n) { nome = n; }
void autore::setCognome(QString c) { cognome = c; }

void autore::aggiungiAfferenza(QString aff)
{
    afferenze.push_back(aff);
}

bool autore::operator==(const autore& a)const
{
    if(identificativo == a.identificativo && nome == a.nome && cognome == a.cognome && afferenze == a.afferenze)
    {
        return true;
    }
    return false;
}

