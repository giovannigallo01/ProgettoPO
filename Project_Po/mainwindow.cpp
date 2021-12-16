#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <sstream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Gestore = new gestore();

    ui->plainTextEdit->setReadOnly(true);

    ui->afferenzaAutText->setToolTip("Per ogni afferenza andare a capo!");
    ui->listaAutoriAP->setToolTip("Lista degli autori presenti!");
    ui->organizzatoriConfText->setToolTip("Per ogni organizzatore andare a capo!");
    ui->listaConferenzeAC->setToolTip("Lista delle conferenze presenti!");
    ui->dataConfText->setToolTip("Inserire la data dal calendario!");
    ui->listaRivisteAR->setToolTip("Lista delle riviste prresenti!");
    ui->keyArtText->setToolTip("Per ogni keyword andare a capo!");
    ui->confRivComboBox->setToolTip("Selezionare il nome della conferenza o rivista per il quale si vuole pubblicare l'articolo");
    ui->idAutoreDaAggiungere->setToolTip("Scrivi l'id dell'autore (tra quelli presenti) che vuoi aggiungere per l'articolo");
    ui->idArticoloDaAggAA->setToolTip("Scrivi l'id dell'articolo (tra quelli presenti) che vuoi correlare all'articolo");
    ui->listaAutoriAA->setToolTip("Autori presenti!");
    ui->listaArticoliAA->setToolTip("Articolo presenti!");
    ui->m1comboBox->setToolTip("Selezionare l'autore di cui si vogliono visualizzare gli articoli!");
    ui->m1lista->setToolTip("Articoli relativi all'autore selezionato!");
    ui->mB4comboBox->setToolTip("Selezionare la conferenza di cui si vogliono visualizzare gli articoli!");
    ui->mB4lista->setToolTip("Articoli relativi alla conferenza selezionata!");
    ui->mB6comboBox->setToolTip("Selezionare la keyword di cui si vogliono visualizzare gli articoli!");
    ui->mB6lista->setToolTip("Articoli relativi alla keyword selezionata!");
    ui->mC1comboBox->setToolTip("Selezionare l'autore di cui si vogliono visualizzare gli articoli con prezzo più basso!");
    ui->mC1lista->setToolTip("Articoli relativi all'autore selezionato!");
    ui->mC3comboBox->setToolTip("Selezionare l'autore di cui si vuole visualizzare la media dei prezzi di tutti i suoi articoli!");
    ui->mC3line->setToolTip("Prezzo medio degli articoli dell'autore selezionato!");
    ui->mC6lista->setToolTip("Keyword la cui somma degli articoli porta al guadagno più alto!");
    ui->mD3comboBox->setToolTip("Selezionare la conferenza di cui si vogliono visualizzare gli articoli ordinati!");
    ui->mD3lista->setToolTip("Articoli relativi alla conferenza selezionata, ordinati per prezzo crescente!");
    ui->mD6lista1->setToolTip("Autori presenti!");
    ui->mD6lineEdit->setToolTip("Scrivere l'id dell'autore di cui si vogliono visualizzare gli articoli ordinati");
    ui->mD6lista2->setToolTip("Articoli relativi all'autore selezionato, ordinati per anno crescente, a parità di anno, "
                              "ordinati per prezzo decrescente e a parità di prezzo ordinati in ordine alfabetico per la prima "
                              "keyword nella lista");
    ui->mE6lista->setToolTip("Riviste specialistiche presenti!");
    ui->mF5comboBox->setToolTip("Selezionare la conferenza di qui si vogliono visualizzare le conferenze simili");
    ui->mF5lista->setToolTip("Conferenze simili alla conferenza selezionata");

    connect(ui->HomeButton, &QPushButton::clicked, this, &MainWindow::on_backToHome);
    connect(ui->HomeButton_2, &QPushButton::clicked, this, &MainWindow::on_backToHome);
    connect(ui->HomeButton_3, &QPushButton::clicked, this, &MainWindow::on_backToHome);
    connect(ui->HomeButton_4, &QPushButton::clicked, this, &MainWindow::on_backToHome);
    connect(ui->HomeButton_5, &QPushButton::clicked, this, &MainWindow::on_backToHome);
    connect(ui->HomeButton_6, &QPushButton::clicked, this, &MainWindow::on_backToHome);
    connect(ui->HomeButton_7, &QPushButton::clicked, this, &MainWindow::on_backToHome);
    connect(ui->HomeButton_8, &QPushButton::clicked, this, &MainWindow::on_backToHome);
    connect(ui->HomeButton_9, &QPushButton::clicked, this, &MainWindow::on_backToHome);
    connect(ui->HomeButton_10, &QPushButton::clicked, this, &MainWindow::on_backToHome);
    connect(ui->HomeButton_11, &QPushButton::clicked, this, &MainWindow::on_backToHome);
    connect(ui->HomeButton_12, &QPushButton::clicked, this, &MainWindow::on_backToHome);
}

MainWindow::~MainWindow()
{
    delete Gestore;
    delete ui;
}

void MainWindow::disabilitaRadioButton(QRadioButton* button)
{
    button->setAutoExclusive(false);
    button->setChecked(false);
    button->setAutoExclusive(true);

}

void MainWindow::on_backToHome()
{
    ui->stackedWidget->setCurrentWidget(ui->homePage);
}


//SEZIONE A

void MainWindow::on_aggiungiAutButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->aggiungiAutPage);
}

void MainWindow::on_visualizzaAutButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->visualizzaAutPage);
    ui->listaAutoriVA->clear();
    const QList<autore>& autori = Gestore->getAutori();
    for(auto a : autori)
    {
        stringstream s;
        s << a;
        QString nuova_str = QString::fromStdString(s.str());
        ui->listaAutoriVA->addItem(nuova_str);
    }
}

void MainWindow::on_aggiungiConfButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->aggiungiConfPage);
}

void MainWindow::on_visualizzaConfButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->visualizzaConfPage);
    ui->listaConferenzeVC->clear();
    const QList<conferenza>& conferenze = Gestore->getConferenze();
    for(auto c : conferenze)
    {
        stringstream s;
        s << c;
        QString nuova_str = QString::fromStdString(s.str());
        ui->listaConferenzeVC->addItem(nuova_str);
    }
}

void MainWindow::on_aggiungiRivButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->aggiungiRivPage);
}

void MainWindow::on_visualizzaRivButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->visualizzaRivPage);
    ui->listaRivisteVR->clear();
    const QList<rivista>& riviste = Gestore->getRiviste();
    for(auto r : riviste)
    {
        stringstream s;
        s << r;
        QString nuova_str = QString::fromStdString(s.str());
        ui->listaRivisteVR->addItem(nuova_str);
    }
}

void MainWindow::on_aggiungiArtButton_clicked()
{
    if(Gestore->getAutori().isEmpty())
    {
        QMessageBox::critical(this, "Errore", "Devi inserire prima un autore!", QMessageBox::Ok);
        return;
    }

    if(Gestore->getConferenze().isEmpty() && Gestore->getRiviste().isEmpty())
    {
        QMessageBox::critical(this, "Errore", "Devi inserire prima una conferenza o una rivista!", QMessageBox::Ok);
        return;
    }
    ui->stackedWidget->setCurrentWidget(ui->aggiungiArtPage);
}

void MainWindow::on_visualizzaArtButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->visualizzaArtPage);
    ui->listaArticoliVA->clear();
    const QList<articolo>& articoli = Gestore->getArticoli();
    QList<conferenza> conferenze = Gestore->getConferenze();
    QList<rivista> riviste = Gestore->getRiviste();
    for(auto art : articoli)
    {
        if(art.getPubblicatoPer() == "conferenza")
        {
            for(auto c : conferenze)
            {
                for(auto a : c.getArticoliPerConferenza())
                {
                    if(art.getIdentificativo() == a.getIdentificativo())
                    {
                        stringstream s;
                        s << art;
                        QString nuova_str = QString::fromStdString(s.str()) + " (" + c.getNome() + ")";
                        ui->listaArticoliVA->addItem(nuova_str);
                    }
                }
            }
        }
        else if(art.getPubblicatoPer() == "rivista")
        {
            for(auto r : riviste)
            {
                for(auto a : r.getArticoliPerRivista())
                {
                    if(art.getIdentificativo() == a.getIdentificativo())
                    {
                        stringstream s;
                        s << art;
                        QString nuova_str = QString::fromStdString(s.str()) + " (" + r.getNome() + ")";
                        ui->listaArticoliVA->addItem(nuova_str);
                    }
                }
            }
        }


    }
}

void MainWindow::on_aggiungiAutButtonAP_clicked()
{
    if(ui->idAutText->text().isEmpty() || ui->nomeAutText->text().isEmpty() || ui->cognomeAutText->text().isEmpty())
    {
        QMessageBox::critical(this, "Errore", "Uno o più campi obbligatori sono vuoti", QMessageBox::Ok);
        return;
    }

    QString id = ui->idAutText->text().simplified();
    QString nome = ui->nomeAutText->text().simplified();
    QString cognome = ui->cognomeAutText->text().simplified();

    QList<QString> listaAfferenze;
    if (!ui->afferenzaAutText->toPlainText().isEmpty())
    {
        QString afferenze = ui->afferenzaAutText->toPlainText();
        listaAfferenze = afferenze.split("\n");
    }

    autore a(id, nome, cognome, listaAfferenze);

    if(Gestore->aggiungiAutore(a) == true)
    {
        ui->statusbar->showMessage("Autore aggiunto con successo!", 3000);
        QString s = "Autore: " + id + " - " + nome + " " + cognome;
        ui->listaAutoriAP->addItem(s);
    }
    else
    {
        QMessageBox::critical(this, "Errore", "Autore già presente", QMessageBox::Ok);
        return;
    }

    ui->idAutText->clear();
    ui->nomeAutText->clear();
    ui->cognomeAutText->clear();
    ui->afferenzaAutText->clear();
}

void MainWindow::on_aggiungiConfButtonAC_clicked()
{
    if(ui->nomeConfText->text().isEmpty() || ui->luogoConfText->text().isEmpty() || ui->acronimoConfText->text().isEmpty() ||
            ui->partecipantiConfText->value() == 0 || ui-> organizzatoriConfText->toPlainText().isEmpty())
    {
        QMessageBox::critical(this, "Errore", "Uno o più campi obbligatori sono vuoti", QMessageBox::Ok);
        return;
    }

    QString nome = ui->nomeConfText->text().simplified();
    QString acronimo = ui->acronimoConfText->text().simplified();
    QString luogo = ui->luogoConfText->text().simplified();

    QList<QString> listaOrganizzatori;
    QString organizzatori = ui->organizzatoriConfText->toPlainText();
    listaOrganizzatori = organizzatori.split("\n");

    int numeroPartecipanti = ui->partecipantiConfText->value();
    QDate data = ui->dataConfText->selectedDate();

    conferenza c(nome, acronimo, luogo, data, listaOrganizzatori, numeroPartecipanti);

    QString dataString = data.toString(Qt::DateFormat::ISODate);

    if(Gestore->aggiungiConferenza(c) == true)
    {
        ui->statusbar->showMessage("Conferenza aggiunta con successo!", 3000);
        QString s = "Conferenza: " + nome + " ~ " + dataString;
        ui->listaConferenzeAC->addItem(s);
    }
    else
    {
        QMessageBox::critical(this, "Errore", "Conferenza già presente", QMessageBox::Ok);
        return;
    }

    ui->nomeConfText->clear();
    ui->acronimoConfText->clear();
    ui->luogoConfText->clear();
    ui->organizzatoriConfText->clear();
    ui->partecipantiConfText->setValue(0);
    ui->dataConfText->setSelectedDate(QDate::currentDate());
}

void MainWindow::on_aggiungiRivButtonAR_clicked()
{
    if(ui->nomeRivText->text().isEmpty() || ui->acronimoRivText->text().isEmpty() || ui->editoreRivText->text().isEmpty() || ui->volumeRivText->value() == 0)
    {
        QMessageBox::critical(this, "Errore", "Uno o più campi obbligatori sono vuoti", QMessageBox::Ok);
        return;
    }

    QString nome = ui->nomeRivText->text().simplified();
    QString acronimo = ui->acronimoRivText->text().simplified();
    QString editore = ui->editoreRivText->text().simplified();
    int volume = ui->volumeRivText->value();
    QDate data = ui->dataRivText->selectedDate();

    rivista r(nome, acronimo, editore, data, volume);

    QString dataString = data.toString(Qt::DateFormat::ISODate);

    if(Gestore->aggiungiRivista(r) == true)
    {
        ui->statusbar->showMessage("Rivista aggiunta con successo!", 3000);
        QString s = "Rivista: " + nome + " ~ " + dataString;
        ui->listaRivisteAR->addItem(s);
    }
    else
    {
        QMessageBox::critical(this, "Errore", "Rivista già presente", QMessageBox::Ok);
        return;
    }

    ui->nomeRivText->clear();
    ui->acronimoRivText->clear();
    ui->editoreRivText->clear();
    ui->volumeRivText->setValue(0);
    ui->dataRivText->setSelectedDate(QDate::currentDate());
}

void MainWindow::on_aggiungiArticoloButton_clicked()
{
    if(ui->idArtText->text().isEmpty() || ui->titoloArtText->text().isEmpty() || ui->npagineArtText->value() == 0 ||
            ui->prezzoArtText->value() == 0.00 || ui->keyArtText->toPlainText().isEmpty() || supportoAutori.isEmpty() ||
            (!ui->confRadioButton->isChecked() && !ui->rivRadioButton->isChecked()))
    {
        QMessageBox::critical(this, "Errore", "Uno o più campi obbligatori sono vuoti", QMessageBox::Ok);
        return;
    }

    QString id = ui->idArtText->text().simplified();
    QString titolo = ui->titoloArtText->text().simplified();
    int numeroPagine = ui->npagineArtText->value();
    float prezzo = ui->prezzoArtText->value();

    QList<QString> listaKeyword;
    QString keyword = ui->keyArtText->toPlainText();
    listaKeyword = keyword.split("\n");

    articolo a (id, titolo, numeroPagine, supportoAutori, listaKeyword, prezzo, supportoArticoli);

    if(Gestore->aggiungiArticolo(a) == true)
    {
        if(ui->confRadioButton->isChecked())
        {
            int idxConf = ui->confRivComboBox->currentIndex();
            Gestore->aggiungiArticoloInConferenza(idxConf, a);
            Gestore->setPubblicatoPer(a, "conferenza");
            conferenza c = Gestore->getConferenze().at(idxConf);
            Gestore->setDataArticolo(a, c.getData());
        }
        else if(ui->rivRadioButton->isChecked())
        {
            int idxRiv = ui->confRivComboBox->currentIndex();
            Gestore->aggiungiArticoloInRivista(idxRiv, a);
            Gestore->setPubblicatoPer(a, "rivista");
            rivista r = Gestore->getRiviste().at(idxRiv);
            Gestore->setDataArticolo(a, r.getData());
        }
        ui->statusbar->showMessage("Articolo aggiunto con successo!", 3000);
    }
    else
    {
        QMessageBox::critical(this, "Errore", "Articolo già presente", QMessageBox::Ok);
        return;
    }

    ui->idArtText->clear();
    ui->titoloArtText->clear();
    ui->npagineArtText->setValue(0);
    ui->prezzoArtText->setValue(0.00);
    ui->keyArtText->clear();
    ui->confRivComboBox->clear();
    supportoAutori.clear();
    supportoArticoli.clear();
    ui->listaAutoriAA->clear();
    ui->listaArticoliAA->clear();
    ui->idArticoloDaAggAA->clear();
    disabilitaRadioButton(ui->confRadioButton);
    disabilitaRadioButton(ui->rivRadioButton);
}

void MainWindow::on_visualAutArtAA_clicked()
{
    if(ui->listaAutoriAA->count() != 0)
    ui->listaAutoriAA->clear();

    QList<autore> autori = Gestore->getAutori();
    for(int i=0; i<autori.size(); i++)
    {
        QString stringAutore = autori[i].getIdentificativo() + " - " + autori[i].getNome() + " " + autori[i].getCognome();
        ui->listaAutoriAA->addItem(stringAutore);
    }
}

void MainWindow::on_AggiungiAutoreButton_clicked()
{
    bool trovato = false;
    QString id = ui->idAutoreDaAggiungere->text();
    for(auto elem : Gestore->getAutori())
    {
        if(elem.getIdentificativo() == id && supportoAutori.contains(elem))
        {
            QMessageBox::critical(this, "Errore", "Autore già inserito!", QMessageBox::Ok);
            return;
        }
        if(elem.getIdentificativo() == id && !supportoAutori.contains(elem))
        {
            trovato = true;
            supportoAutori.push_back(elem);
            ui->statusbar->showMessage("Autore aggiunto all'articolo!", 3000);
        }
    }
    if(trovato == false)
    {
        QMessageBox::critical(this, "Errore", "Autore inesistente!", QMessageBox::Ok);
        return;
    }

    ui->idAutoreDaAggiungere->clear();
}

void MainWindow::on_visualArtArtAA_clicked()
{
    if(ui->listaArticoliAA->count() != 0)
        ui->listaArticoliAA->clear();

    QList<articolo> articoli = Gestore->getArticoli();
    for(auto it=articoli.begin(); it!=articoli.end(); it++)
    {
        QString stringArticolo = it->getIdentificativo() + " - " + it->getTitolo();
        ui->listaArticoliAA->addItem(stringArticolo);
    }
}

void MainWindow::on_AggiungiArtArtButton_clicked()
{
    bool trovato = false;
    QString id = ui->idArticoloDaAggAA->text();
    for(auto elem : Gestore->getArticoli())
    {
        if(elem.getIdentificativo() == id && supportoArticoli.contains(elem))
        {
            QMessageBox::critical(this, "Errore", "Articolo già inserito!", QMessageBox::Ok);
            return;
        }
        if(elem.getIdentificativo() == id && !supportoArticoli.contains(elem))
        {
            trovato = true;
            supportoArticoli.push_back(elem);
            ui->statusbar->showMessage("Articolo correlato all'articolo!", 3000);
        }
    }
    if(trovato == false)
    {
        QMessageBox::critical(this, "Errore", "Articolo inesistente!", QMessageBox::Ok);
        return;
    }

    ui->idArticoloDaAggAA->clear();
}

void MainWindow::on_confRadioButton_clicked()
{
    if((ui->confRivComboBox->count() != 0))
        ui->confRivComboBox->clear();

    QList<conferenza> conferenze = Gestore->getConferenze();
    for(auto it=conferenze.begin(); it!=conferenze.end(); it++)
    {
        QString stringConferenza = it->getNome() + " - " + it->getData().toString(Qt::DateFormat::ISODate);
        ui->confRivComboBox->addItem(stringConferenza);
    }
}

void MainWindow::on_rivRadioButton_clicked()
{
    if(ui->confRivComboBox->count() != 0)
        ui->confRivComboBox->clear();

    QList<rivista> riviste = Gestore->getRiviste();
    for(auto it=riviste.begin(); it!=riviste.end(); it++)
    {
        QString stringRivista = it->getNome() + " - Volume: " + QString::number(it->getVolume()) + " - " + it->getData().toString(Qt::DateFormat::ISODate);
        ui->confRivComboBox->addItem(stringRivista);
    }
}


// SEZIONE B

void MainWindow::on_sezioneBButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneBPage);

    if(ui->m1comboBox->count() != 0)
        ui->m1comboBox->clear();
    QList<autore> autori = Gestore->getAutori();
    for(auto it=autori.begin(); it!=autori.end(); it++)
    {
        QString stringAutore = it->getNome() + " " + it->getCognome();
        ui->m1comboBox->addItem(stringAutore);
    }

    if(ui->mB4comboBox->count() != 0)
        ui->mB4comboBox->clear();
    QList<conferenza> conferenze = Gestore->getConferenze();
    for(auto it=conferenze.begin(); it!=conferenze.end(); it++)
        ui->mB4comboBox->addItem(it->getNome());

    if(ui->mB6comboBox->count() != 0)
        ui->mB6comboBox->clear();
    QList<articolo> articoli = Gestore->getArticoli();
    QList<QString> tutteKey;
    for(auto art : articoli)
        for(auto key : art.getKeyword())
            tutteKey.push_back(key);
    tutteKey.removeDuplicates();
    for(auto k : tutteKey)
        ui->mB6comboBox->addItem(k);

    ui->m1comboBox->setCurrentIndex(0);
    ui->m1lista->clear();
    ui->mB4comboBox->setCurrentIndex(0);
    ui->mB4lista->clear();
    ui->mB6comboBox->setCurrentIndex(0);
    ui->mB6lista->clear();
    tutteKey.clear();
}

void MainWindow::on_m1pushButton_clicked()
{
    if(ui->m1lista->count() != 0)
        ui->m1lista->clear();

    int idx = ui->m1comboBox->currentIndex();
    QString idAutore = Gestore->getAutori().at(idx).getIdentificativo();
    if(Gestore->getArticoliPerAutore(idAutore).isEmpty())
    {
        QMessageBox::information(this, "Informazione", "Non esistono articoli per l'autore selezionato!", QMessageBox::Ok);
        return;
    }
    for(auto art : Gestore->getArticoliPerAutore(idAutore))
    {
        QString stringArticolo = art.getIdentificativo() + " " + art.getTitolo();
        ui->m1lista->addItem(stringArticolo);
    }
}

void MainWindow::on_mB4Button_clicked()
{
    if(ui->mB4lista->count() != 0)
        ui->mB4lista->clear();

    int idx = ui->mB4comboBox->currentIndex();
    QList<articolo> articoli = Gestore->getArticoliConferenza(idx);
    if(articoli.isEmpty())
    {
        QMessageBox::information(this, "Informazione", "Non esistono articoli per la conferenza selezionata!", QMessageBox::Ok);
        return;
    }
    for(auto art : articoli)
    {
        QString stringArticolo = art.getIdentificativo() + " " + art.getTitolo();
        ui->mB4lista->addItem(stringArticolo);
    }
}

void MainWindow::on_mB6Button_clicked()
{
    if(ui->mB6lista->count() != 0)
        ui->mB6lista->clear();

    QString key = ui->mB6comboBox->currentText();
    for(auto art : Gestore->getArticoliPerKeyword(key))
    {
        QString stringArticolo = art.getIdentificativo() + " " + art.getTitolo();
        ui->mB6lista->addItem(stringArticolo);
    }
}


// SEZIONE C

void MainWindow::on_sezioneCButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneCPage);

    if(ui->mC1comboBox->count() != 0)
        ui->mC1comboBox->clear();
    if(ui->mC3comboBox->count() != 0)
        ui->mC3comboBox->clear();
    QList<autore> autori = Gestore->getAutori();
    for(auto it=autori.begin(); it!=autori.end(); it++)
    {
        QString stringAutore = it->getNome() + " " + it->getCognome();
        ui->mC1comboBox->addItem(stringAutore);
        ui->mC3comboBox->addItem(stringAutore);
    }

    ui->mC1comboBox->setCurrentIndex(0);
    ui->mC3comboBox->setCurrentIndex(0);
    ui->mC1lista->clear();
    ui->mC3line->clear();
    ui->mC6lista->clear();
}


void MainWindow::on_mC1Button_clicked()
{
    if(ui->mC1lista->count() != 0)
        ui->mC1lista->clear();

    int idx = ui->mC1comboBox->currentIndex();
    QString idAutore = Gestore->getAutori().at(idx).getIdentificativo();
    if(Gestore->getArticoliPerAutore(idAutore).isEmpty())
    {
        QMessageBox::information(this, "Informazione", "Non esistono articoli per l'autore selezionato!", QMessageBox::Ok);
        return;
    }
    for(auto art : Gestore->getArticoliPerAutoreConPrezzoPiuBasso(idAutore))
    {
        QString stringArticolo = art.getIdentificativo() + " " + art.getTitolo();
        ui->mC1lista->addItem(stringArticolo);
    }
}

void MainWindow::on_mC3Button_clicked()
{
    if(ui->mC3line->text() != "")
        ui->mC3line->clear();

    int idx = ui->mC3comboBox->currentIndex();
    QString idAutore = Gestore->getAutori().at(idx).getIdentificativo();
    if(Gestore->getArticoliPerAutore(idAutore).isEmpty())
    {
        QMessageBox::information(this, "Informazione", "Non esistono articoli per l'autore selezionato!", QMessageBox::Ok);
        return;
    }
    float media = Gestore->getMediaPrezziArticoliPerAutore(idAutore);
    ui->mC3line->setText(QString::number(media));
}

void MainWindow::on_mC6Button_clicked()
{
    if(ui->mC6lista->count() != 0)
        ui->mC6lista->clear();
    QList<QString> key = Gestore->getKeywordGuadagnoPiuAlto();
    for(auto k : key)
        ui->mC6lista->addItem(k);
}


// SEZIONE D

void MainWindow::on_sezioneDButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneDPage);

    if(ui->mD3comboBox->count() != 0)
        ui->mD3comboBox->clear();
    if(ui->mD6lista1->count() != 0)
        ui->mD6lista1->clear();
    if(ui->mD6lista2->count() != 0)
        ui->mD6lista2->clear();
    ui->mD6lineEdit->clear();

    QList<conferenza> conferenze = Gestore->getConferenze();
    for(auto it=conferenze.begin(); it!=conferenze.end(); it++)
        ui->mD3comboBox->addItem(it->getNome());

    ui->mD3comboBox->setCurrentIndex(0);

}

void MainWindow::on_mD3button_clicked()
{
    if(ui->mD3lista->count() != 0)
        ui->mD3lista->clear();

    int idx = ui->mD3comboBox->currentIndex();
    QList<articolo> articoliOrdinati = Gestore->getArticoliConferenzaOrdinatiPerPrezzo(idx);
    if(articoliOrdinati.isEmpty())
    {
        QMessageBox::information(this, "Informazione", "Non esistono articoli per questa conferenza!", QMessageBox::Ok);
        return;
    }
    for(auto art : articoliOrdinati)
    {
        QString stringArticolo = art.getIdentificativo() + " " + art.getTitolo() + " ~ " + QString::number(art.getPrezzo());
        ui->mD3lista->addItem(stringArticolo);
    }
}

void MainWindow::on_mD6button1_clicked()
{
    if(ui->mD6lista1->count() != 0)
    ui->mD6lista1->clear();

    QList<autore> autori = Gestore->getAutori();
    for(auto aut : autori)
    {
        QString stringAutore = aut.getIdentificativo() + " - " + aut.getNome() + " " + aut.getCognome();
        ui->mD6lista1->addItem(stringAutore);
    }
}

void MainWindow::on_mD6button2_clicked()
{
    if(ui->mD6lista2->count() != 0)
        ui->mD6lista2->clear();

    QString idAutore = ui->mD6lineEdit->text().simplified();
    QList<articolo> articoliOrdinati = Gestore->getArticoliPerAutoreOrdinati(idAutore);
    bool check = false;
    for(auto aut : Gestore->getAutori())
        if(aut.getIdentificativo() == idAutore)
            check = true;
    if(check == false)
    {
        QMessageBox::critical(this, "Errore", "Autore inesistente!", QMessageBox::Ok);
        return;
    }
    if(articoliOrdinati.isEmpty())
    {
        QMessageBox::information(this, "Informazione", "Non esistono articoli per questo autore!", QMessageBox::Ok);
        return;
    }
    for(auto art : articoliOrdinati)
    {
        QString anno = QString::number(Gestore->getDataDiUnArticolo(art).year());
        QString primaKey = art.getKeyword().at(0);
        QString stringArticolo = art.getIdentificativo() + " " + art.getTitolo() + " - " + anno + " - " +
                                 QString::number(art.getPrezzo()) + " - Prima key: " + primaKey;
        //cout << anno.toStdString();
        ui->mD6lista2->addItem(stringArticolo);
    }
}


// SEZIONE E-F

void MainWindow::on_sezioneEFButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sezioneEFPage);

    if(ui->mE6lista->count() != 0)
        ui->mE6lista->clear();
    if(ui->mF5comboBox->count() != 0)
        ui->mF5comboBox->clear();

    QList<conferenza> conferenze = Gestore->getConferenze();
    for(auto it=conferenze.begin(); it!=conferenze.end(); it++)
        ui->mF5comboBox->addItem(it->getNome());

    ui->mF5comboBox->setCurrentIndex(0);
    ui->mF5lista->clear();
}

void MainWindow::on_mE6Button_clicked()
{
    if(ui->mE6lista->count() != 0)
        ui->mE6lista->clear();
    QList<rivista> rivisteSpecialistiche = Gestore->getRivisteSpecialistiche();
    if(rivisteSpecialistiche.isEmpty())
    {
        QMessageBox::information(this, "Informazione", "Non esistono riviste specialistiche!", QMessageBox::Ok);
        return;
    }
    for(auto riv : rivisteSpecialistiche)
    {
        QString stringRivista = riv.getNome() + " Volume: " + QString::number(riv.getVolume());
        ui->mE6lista->addItem(stringRivista);
    }
}

void MainWindow::on_mF5button_clicked()
{
    if(ui->mF5lista->count() != 0)
        ui->mF5lista->clear();
    int idx = ui->mF5comboBox->currentIndex();
    QList<conferenza> conferenzeSimili = Gestore->getConferenzeSimili(idx);
    if(conferenzeSimili.isEmpty())
    {
        QMessageBox::information(this, "Informazione", "Non esistono conferenze simili a quella selezionata!", QMessageBox::Ok);
        return;
    }
    for(auto elem : conferenzeSimili)
        ui->mF5lista->addItem(elem.getNome());
}


