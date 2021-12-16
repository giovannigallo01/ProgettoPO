#include "articolo.h"
#include "conferenza.h"
#include "rivista.h"

articolo::articolo() {}
articolo::articolo(QString id, QString t, int np, QList<autore> a, QList<QString> k, float p, QList<articolo> ac)
{
    identificativo = id;
    titolo = t;
    numeroPagine = np;
    autori = a;
    keyword = k;
    prezzo = p;
    articoliCorrelati = ac;
}

QString articolo::getIdentificativo()const { return identificativo; }
QString articolo::getTitolo()const { return titolo; }
int articolo::getNumeroPagine()const { return numeroPagine; }
const QList<autore>& articolo::getAutori()const { return autori; }
const QList<QString>& articolo::getKeyword()const { return keyword; }
float articolo::getPrezzo()const { return prezzo; }
const QList<articolo>& articolo::getArticoliCorrelati()const { return articoliCorrelati; }
QString articolo::getPubblicatoPer()const { return pubblicatoPer; }

void articolo::setIdentificativo(QString id) { identificativo = id; }
void articolo::setTitolo(QString t) { titolo = t; }
void articolo::setNumeroPagine(int np) { numeroPagine = np; }
void articolo::setPrezzo(float p) { prezzo = p; }
void articolo::setPubblicatoPer(QString string) { pubblicatoPer = string; }

void articolo::aggiungiAutore(autore a)
{
    autori.push_back(a);
}

void articolo::aggiungiKeyword(QString k)
{
    keyword.push_back(k);
}

bool articolo::operator==(const articolo& a)const
{
    if(identificativo == a.identificativo && titolo == a.titolo && numeroPagine == a.numeroPagine && autori == a.autori &&
            keyword == a.keyword && prezzo == a.prezzo && articoliCorrelati == a.articoliCorrelati)
    {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& out, const articolo& a)
{
    out << "ID: " << a.identificativo.toStdString() << " - Titolo: " << a.titolo.toStdString() << " ~ N°pagine: " << a.numeroPagine
        << " ~ Prezzo: " << a.prezzo << " ~ ";

    out << "Keywords:";
    for(auto key : a.keyword)
    {
        if(key == a.keyword.back())
            out << " " << key.toStdString();
        else
            out << " " << key.toStdString() << ",";
    }
    out << " - ";

    out << "Autori:";
    for(auto aut : a.autori)
    {
        if(aut == a.autori.back())
            out << " " << aut.getNome().toStdString() << " " << aut.getCognome().toStdString();
        else
            out << " " << aut.getNome().toStdString() << " " << aut.getCognome().toStdString() << ",";
    }
    out << " - ";

    out << "Articoli Correlati:";
    if(a.articoliCorrelati.isEmpty())
        out << " (Nessun articolo correlato presente)";
    for(auto art : a.articoliCorrelati)
    {
        if(art == a.articoliCorrelati.back())
            out << " " << art.getTitolo().toStdString();
        else
            out << " " << art.getTitolo().toStdString() << ",";
    }
    out << " ~ ";

    if(a.pubblicatoPer == "conferenza")      
        out << "#pubblicato per una conferenza";
    else if(a.pubblicatoPer == "rivista")
        out << "#pubblicato per una rivista";

    return out;
}
