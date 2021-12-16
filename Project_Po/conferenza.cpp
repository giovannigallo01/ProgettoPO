#include "conferenza.h"

conferenza::conferenza() {}
conferenza::conferenza(QString n, QString a, QString l, QDate d, QList<QString> o, int np): nome(n), acronimo(a), luogo(l), data(d), organizzatori(o), numeroPartecipanti(np) {}

QString conferenza::getNome()const { return nome; }
QString conferenza::getAcronimo()const { return acronimo; }
QString conferenza::getLuogo()const { return luogo; }
QDate conferenza::getData()const { return data; }
const QList<QString>& conferenza::getOrganizzatori()const { return organizzatori; }
int conferenza::getNumeroPartecipanti()const { return numeroPartecipanti; }
QList<articolo> conferenza::getArticoliPerConferenza()const { return articoliPerConferenza; }

void conferenza::setNome(QString n) { nome = n; }
void conferenza::setAcronimo(QString a) { acronimo = a;}
void conferenza::setLuogo(QString l) { luogo = l; }
void conferenza::setData(QDate d) { data = d; }
void conferenza::setNumeroPartecipanti(int np) { numeroPartecipanti = np; }

void conferenza::aggiungiOrganizzatore(QString org)
{
    organizzatori.push_back(org);
}

void conferenza::aggiungiArticoloPerConferenza(articolo articolo)
{
    articoliPerConferenza.push_back(articolo);
}

bool conferenza::operator==(const conferenza& c)const
{
    if(nome == c.nome && luogo == c.luogo && data == c.data)
    {
        return true;
    }
    return false;
}
