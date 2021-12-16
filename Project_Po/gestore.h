#ifndef GESTORE_H
#define GESTORE_H

#include "articolo.h"
#include "autore.h"
#include "conferenza.h"
#include "rivista.h"

class gestore
{
private:
    QList<articolo> articoli;
    QList<autore> autori;
    QList<conferenza> conferenze;
    QList<rivista> riviste;

public:
    gestore();
    ~gestore();
    gestore(const gestore& g);
    gestore& operator=(const gestore& g);

    void aggiungiArticoloInConferenza(int idx, articolo a);
    void aggiungiArticoloInRivista(int idx, articolo a);
    void setPubblicatoPer(articolo a, QString pubblicatoPer);
    void setDataArticolo(articolo a, QDate data);

    //SEZIONE A
    bool aggiungiArticolo(const articolo& art);
    bool aggiungiAutore(const autore& aut);
    bool aggiungiConferenza(const conferenza& conf);
    bool aggiungiRivista(const rivista& riv);
    const QList<articolo>& getArticoli()const;
    const QList<autore>& getAutori()const;
    const QList<conferenza>& getConferenze()const;
    const QList<rivista>& getRiviste()const;

    //SEZIONE B
    const QList<articolo> getArticoliPerAutore(QString id)const; // B-1
    const QList<articolo> getArticoliConferenza(int idx)const; // B-4
    const QList<articolo> getArticoliPerKeyword(QString k)const; // B-6

    //SEZIONE C
    const QList<articolo> getArticoliPerAutoreConPrezzoPiuBasso(QString id)const; // C-1
    float getMediaPrezziArticoliPerAutore(QString id)const; // C-3
    const QList<QString> getKeywordGuadagnoPiuAlto()const; // C-6

    //SEZIONE D
    const QList<articolo> getArticoliConferenzaOrdinatiPerPrezzo(int idx)const; // D-3
    QDate getDataDiUnArticolo(articolo a) const; // Metodo ausiliario
    const QList<articolo> getArticoliPerAutoreOrdinati(QString id)const; // D-6 //

    //SEZIONE E //
    const QList<QString> getKeywordArticoliDiRivista(rivista r) const; // Metodo ausiliario
    const QList<rivista> getRivisteSpecialistiche()const; // E-6

    //SEZIONE F
    const QList<QString> getKeywordArticoliDiConferenza(int idx) const; // Metodo ausiliario
    const QList<conferenza> getConferenzeSimili(int idx)const; // F-5

};

#endif // GESTORE_H
