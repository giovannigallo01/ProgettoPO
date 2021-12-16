#include "rivista.h"

rivista::rivista() {}
rivista::rivista(QString n, QString a, QString e, QDate d, int v): nome(n), acronimo(a), editore(e), data(d), volume(v) {}

QString rivista::getNome()const { return nome; }
QString rivista::getAcronimo()const { return acronimo; }
QString rivista::getEditore()const { return editore; }
QDate rivista::getData()const { return data; }
int rivista::getVolume()const { return volume; }
const QList<articolo>& rivista::getArticoliPerRivista()const { return articoliPerRivista;}

void rivista::setNome(QString n) { nome = n; }
void rivista::setAcronimo(QString a) { acronimo = a; }
void rivista::setEditore(QString e) { editore = e; }
void rivista::setData(QDate d) { data = d; }
void rivista::setVolume(int v) { volume = v; }

void rivista::aggiungiArticoloPerRivista(articolo articolo) { articoliPerRivista.push_back(articolo); }

bool rivista::operator==(const rivista& r)const
{
    if(nome == r.nome && data == r.data && volume == r.volume)
    {
        return true;
    }
    return false;
}
