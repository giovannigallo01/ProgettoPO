#ifndef ARTICOLO_H
#define ARTICOLO_H

#include "autore.h"
#include <QDate>

class articolo
{
    friend ostream& operator<<(ostream& out, const articolo& a);
private:
    QString identificativo;
    QString titolo;
    int numeroPagine;
    QList<autore> autori;
    QList<QString> keyword;
    float prezzo;
    QList<articolo> articoliCorrelati;
    QString pubblicatoPer;
    QDate data;

public:
    articolo();
    articolo(QString id, QString t, int np, QList<autore> a, QList<QString> k, float p, QList<articolo> ac);

    QString getIdentificativo()const;
    QString getTitolo()const;
    int getNumeroPagine()const;
    const QList<autore>& getAutori()const;
    const QList<QString>& getKeyword()const;
    float getPrezzo()const;
    const QList<articolo>& getArticoliCorrelati()const;
    QString getPubblicatoPer()const;
    QDate getData() const { return data; }

    void setIdentificativo(QString id);
    void setTitolo(QString t);
    void setNumeroPagine(int np);
    void setPrezzo(float p);
    void setPubblicatoPer(QString string);
    void setData(QDate d) { data = d; }

    void aggiungiAutore(autore autore);
    void aggiungiKeyword(QString keyword);

    bool operator==(const articolo& a)const;
};

#endif // ARTICOLO_H
