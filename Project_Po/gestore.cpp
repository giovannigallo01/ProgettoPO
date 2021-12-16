#include "gestore.h"
#include "climits"

gestore::gestore() {}

gestore::~gestore()
{
    articoli.clear();
    autori.clear();
    conferenze.clear();
    riviste.clear();
}

gestore::gestore(const gestore& g)
{
    for(auto it=g.articoli.begin(); it!=g.articoli.end(); it++)
    {
        articolo art = *it;
        articoli.push_back(art);
    }

    for(auto it=g.autori.begin(); it!=g.autori.end(); it++)
    {
        autore aut = *it;
        autori.push_back(aut);
    }

    for(auto it=g.conferenze.begin(); it!=g.conferenze.end(); it++)
    {
        conferenza conf = *it;
        conferenze.push_back(conf);
    }

    for(auto it=g.riviste.begin(); it!=g.riviste.end(); it++)
    {
        rivista riv = *it;
        riviste.push_back(riv);
    }
}

gestore& gestore::operator=(const gestore &g)
{
    if(this != &g)
    {
        articoli.clear();
        autori.clear();
        conferenze.clear();
        riviste.clear();

        for(auto it=g.articoli.begin(); it!=g.articoli.end(); it++) { articoli.push_back(*it); }
        for(auto it=g.autori.begin(); it!=g.autori.end(); it++) { autori.push_back(*it); }
        for(auto it=g.conferenze.begin(); it!=g.conferenze.end(); it++) { conferenze.push_back(*it); }
        for(auto it=g.riviste.begin(); it!=g.riviste.end(); it++) { riviste.push_back(*it); }
    }
    return *this;
}

void gestore::aggiungiArticoloInConferenza(int idx, articolo a)
{
    int i = 0;
    for(auto it=conferenze.begin(); it!=conferenze.end(); it++)
    {
        if(i == idx)
            it->aggiungiArticoloPerConferenza(a);
        i++;
    }
}

void gestore::aggiungiArticoloInRivista(int idx, articolo a)
{
    int i = 0;
    for(auto it=riviste.begin(); it!=riviste.end(); it++)
    {
        if(i == idx)
            it->aggiungiArticoloPerRivista(a);
        i++;
    }
}

void gestore::setPubblicatoPer(articolo a, QString pubblicatoPer)
{
    for(auto it=articoli.begin(); it!=articoli.end(); it++)
        if(it->getIdentificativo() == a.getIdentificativo())
            it->setPubblicatoPer(pubblicatoPer);
}

void gestore::setDataArticolo(articolo a, QDate data)
{
    for(auto it=articoli.begin(); it!=articoli.end(); it++)
        if(it->getIdentificativo() == a.getIdentificativo())
            it->setData(data);
}

// SEZIONE A
bool gestore::aggiungiAutore(const autore& aut)
{
    for(auto it=autori.begin(); it!=autori.end(); it++)
    {
        autore a = *it;
        if(a.getIdentificativo() == aut.getIdentificativo())
        {
            return false;
        }
    }
    autori.push_back(aut);
    return true;
}

bool gestore::aggiungiConferenza(const conferenza &conf)
{
    for(auto it=conferenze.begin(); it!=conferenze.end(); it++)
    {
        conferenza c = *it;
        if(c.getNome() == conf.getNome())
        {
            return false;
        }
    }
    conferenze.push_back(conf);
    return true;
}

bool gestore::aggiungiRivista(const rivista &riv)
{
    for(auto it=riviste.begin(); it!=riviste.end(); it++)
    {
        rivista r = *it;
        if(r.getNome() == riv.getNome())
        {
            return false;
        }
    }
    riviste.push_back(riv);
    return true;
}

bool gestore::aggiungiArticolo(const articolo& art)
{
    for(auto it=articoli.begin(); it!=articoli.end(); it++)
    {
        articolo a = *it;
        if(a.getIdentificativo() == art.getIdentificativo())
        {
            return false;
        }
    }
    articoli.push_back(art);
    return true;
}

const QList<autore>& gestore::getAutori()const
{
    return autori;
}

const QList<conferenza>& gestore::getConferenze()const
{
    return conferenze;
}

const QList<rivista>& gestore::getRiviste()const
{
    return riviste;
}

const QList<articolo>& gestore::getArticoli()const
{
    return articoli;
}

// SEZIONE B
const QList<articolo> gestore::getArticoliPerAutore(QString id) const
{
    QList<articolo> articoliPerAutore;
    const QList<articolo>& articoli = getArticoli();
    for(auto a : articoli)
    {
        const QList<autore>& autoriPerArticolo = a.getAutori();
        for(auto elem : autoriPerArticolo)
        {
            if(elem.getIdentificativo() == id)
                articoliPerAutore.push_back(a);
        }
    }
    return articoliPerAutore;
}

const QList<articolo> gestore::getArticoliConferenza(int idx) const
{
    QList<articolo> articoliConferenza;
    conferenza c  = conferenze.at(idx);
    articoliConferenza = c.getArticoliPerConferenza();

    return articoliConferenza;
}

const QList<articolo> gestore::getArticoliPerKeyword(QString k) const
{
    QList<articolo> articoliPerKeyword;
    const QList<articolo>& articoli = getArticoli();
    for(auto a : articoli)
    {
        const QList<QString>& keywordPerArticolo = a.getKeyword();
        for(auto elem : keywordPerArticolo)
        {
            if(elem == k)
            {
                articoliPerKeyword.push_back(a);
            }
        }
    }
    return articoliPerKeyword;
}

// SEZIONE C
const QList<articolo> gestore::getArticoliPerAutoreConPrezzoPiuBasso(QString id) const
{
    QList<articolo> articoliPrezzoPiuBasso;
    const QList<articolo>& articoli = getArticoliPerAutore(id);
    float min = std::numeric_limits<float>::max();
    for(auto a : articoli) // mi calcolo il prezzo più basso degli articoli di un autore
    {
        if(a.getPrezzo() < min)
            min = a.getPrezzo();
    }
    for(auto a : articoli) // controllo quali articoli hanno il prezzo uguale al prezzo minore e li aggiungo
    {
        if(a.getPrezzo() == min)
            articoliPrezzoPiuBasso.push_back(a);
    }
    return articoliPrezzoPiuBasso;
}

float gestore::getMediaPrezziArticoliPerAutore(QString id) const
{
    float somma = 0;
    const QList<articolo>& articoli = getArticoliPerAutore(id);
    for(auto a : articoli)
    {
        somma += a.getPrezzo();
    }
    return somma/articoli.size();
}

const QList<QString> gestore::getKeywordGuadagnoPiuAlto() const
{
    QList<QString> keywordPiuCostose;
    float prezzoMax = std::numeric_limits<float>::min();
    QList<QString> tutteKeyword; // creo una lista che sarà popolata da tutte le key
    for(auto a : getArticoli())
    {
        for(auto k : a.getKeyword()) // per ogni articolo prendo le relative key
        {
            if(!tutteKeyword.contains(k)) // aggiungo la key solo se non è già stata inserita in modo tale da non avere key duplicate
                tutteKeyword.push_back(k);
        }
    }

    for(auto k : tutteKeyword)
    {
        const QList<articolo>& articoli = getArticoliPerKeyword(k);
        float tot = 0.00;
        for(auto a : articoli) // prendo, per ogni key, gli articoli che la contengono e sommo i prezzi degli articoli
        {
            tot += a.getPrezzo();
        }
        if(tot > prezzoMax) // aggiorno il prezzo massimo se esiste una sommaPrezzo di articoli per una key maggiore di quella corrente
            prezzoMax = tot;
    }

    for(auto k : tutteKeyword)
    {
        const QList<articolo>& articoli = getArticoliPerKeyword(k);
        float sum = 0.00;
        for(auto a : articoli) // stesso procedimento di prima per prendermi la somma degli articoli per key
        {
            sum += a.getPrezzo();
        }
        if(sum == prezzoMax) // aggiungo le key dove la somma dei prezzi degli articoli è uguale alla somma massima calcolata prima
            keywordPiuCostose.push_back(k);
    }

    return keywordPiuCostose;
}

// SEZIONE D
bool compara1(const articolo& a1, const articolo& a2)
{
    if(a1.getPrezzo() < a2.getPrezzo())
        return true;
    return false;
}

const QList<articolo> gestore::getArticoliConferenzaOrdinatiPerPrezzo(int idx) const
{
    QList<articolo> ordinati = getArticoliConferenza(idx);
    std::sort(ordinati.begin(), ordinati.end(), compara1);
    return ordinati;
}

QDate gestore::getDataDiUnArticolo(articolo a) const // metodo ausiliario che mi ritorna la data di un articolo in base alla relativa conferenza/rivista
{
    QDate data;
    QList<conferenza> c = getConferenze();
    QList<rivista> r = getRiviste();
    if(a.getPubblicatoPer() == "conferenza")
    {
        for(auto elem : c)
        {
           QList<articolo> ar = elem.getArticoliPerConferenza();
           if(ar.contains(a)) // se negli articoli pubblicati per una conferenza cè l'articolo passato per parametro salva la data della conferenza
           {
               data = elem.getData();
               break;
           }
        }
    }
    else if(a.getPubblicatoPer() == "rivista")
    {
        for(auto elem : r)
        {
           QList<articolo> ar = elem.getArticoliPerRivista();
           if(ar.contains(a)) // se negli articoli pubblicati per una rivista cè l'articolo passato per parametro salva la data della rivista
           {
               data = elem.getData();
               break;
           }
        }
    }
    return data;
}

bool compara2(const articolo& a1, const articolo& a2)
{
    int anno1 = a1.getData().year();
    int anno2 = a2.getData().year();

    if(anno1 < anno2)
        return true;
    if(anno1 > anno2)
        return false;
    if(a1.getPrezzo() > a2.getPrezzo())
        return true;
    if(a1.getPrezzo() < a2.getPrezzo())
        return false;
    if(a1.getKeyword().at(0) < a2.getKeyword().at(0))
        return true;
    return false;
}

const QList<articolo> gestore::getArticoliPerAutoreOrdinati(QString id)const
{
    QList<articolo> ordinati = getArticoliPerAutore(id);
    std::sort(ordinati.begin(), ordinati.end(), compara2);
    return ordinati;
}

// SEZIONE E
const QList<QString> gestore::getKeywordArticoliDiRivista(rivista r) const // metodo ausiliario che mi ritorna le keyword degli articoli pubblicati per la rivista passata come parametro
{
    QList<QString> keywordRivista;
    QList<articolo> articoliRivista = r.getArticoliPerRivista();
    for(auto elem : articoliRivista)
    {
        QList<QString> k = elem.getKeyword();
        for(auto key : k)
        {
            if(!keywordRivista.contains(key))
                keywordRivista.push_back(key);
        }
    }
    return keywordRivista;
}

const QList<rivista> gestore::getRivisteSpecialistiche() const
{
    QList<rivista> rivisteSpecialistiche;
    for(int i=0; i<riviste.size(); i++)
    {
        QList<QString> keyRivista1 = getKeywordArticoliDiRivista(riviste.at(i));
        for(int j=0; j<riviste.size(); j++)
        {
            if(i != j)
            {
                QList<QString> keyRivista2 = getKeywordArticoliDiRivista(riviste.at(j));
                bool found = true;
                for(int k=0; k<keyRivista1.size(); k++)
                {
                    if(!keyRivista2.contains(keyRivista1[k])) // se la rivista 2 non contiene una key della rivista 1 posso già dire che non è specialistica, mi fermo e controllo la prossima rivista
                    {
                        found = false;
                        break;
                    }
                }
                if(found == true) // se invece tutte le key della rivista 1 sono contenute nella rivista 2..
                {
                    for(int k=0; k<keyRivista2.size(); k++)
                    {
                        if(!keyRivista1.contains(keyRivista2[k])) // ..controllo che ci sia almeno una key della rivista 2 che non è contenuta nella rivista 1
                        {
                            if(!rivisteSpecialistiche.contains(riviste[i])) //se la rivista corrente non è ancora stata aggiunta, la aggiungo
                            {
                                rivisteSpecialistiche.push_back(riviste[i]);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return rivisteSpecialistiche;
}

// SEZIONE F
const QList<QString> gestore::getKeywordArticoliDiConferenza(int idx) const // metodo ausiliario che mi ritorna le keyword degli articoli pubblicati per la conferenza passata come parametro
{
    QList<QString> keywordConferenza;
    QList<articolo> articoliConferenza = conferenze.at(idx).getArticoliPerConferenza();
    for(auto elem : articoliConferenza)
    {
        QList<QString> k = elem.getKeyword();
        for(auto key : k)
        {
            if(!keywordConferenza.contains(key))
                keywordConferenza.push_back(key);
        }
    }
    return keywordConferenza;
}

const QList<conferenza> gestore::getConferenzeSimili(int idx) const
{
    QList<conferenza> conferenzeSimili;
    QList<QString> keyConferenza1 = getKeywordArticoliDiConferenza(idx);
    QList<QString> tutteKey; // creo una lista che sarà popolata da tutte le key delle due conferenze sotto controllo
    for(int i=0; i<conferenze.size(); i++)
    {
        if(i != idx)
        {
            float keyComuni = 0; // contatore che si incrementerà quando troverò una key comune alle 2 conferenze sotto controllo
            tutteKey = keyConferenza1; // inizio ad aggiungere le key della conferenza 1
            QList<QString> keyConferenza2 = getKeywordArticoliDiConferenza(i);
            for(int j=0; j<keyConferenza2.size(); j++)
            {
                if(!tutteKey.contains(keyConferenza2[j])) // controllo di non inserire duplicati, in modo tale da avere tutte le key della conferenza 1 e della conferenza 2 senza duplicati
                    tutteKey.push_back(keyConferenza2[j]);
            }
            for(int j=0; j<tutteKey.size(); j++) // scorro tutte le key delle 2 conferenze sotto controllo
            {
                if(keyConferenza1.contains(tutteKey[j]) && keyConferenza2.contains(tutteKey[j])) // se la key corrente è contenuta da tutte e due le conferenze incremento il contatore
                    keyComuni++;
            }
            if(((keyComuni/tutteKey.size())*100) >= 80) // se le key comuni sono >= all'80% allora la conferenza è simile a quella passata per parametro
                conferenzeSimili.push_back(conferenze.at(i));
        }
        tutteKey.clear();
    }
    return conferenzeSimili;
}
