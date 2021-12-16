#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestore.h"
#include <QRadioButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_backToHome();

    void disabilitaRadioButton(QRadioButton*);

    void on_aggiungiAutButton_clicked();

    void on_visualizzaAutButton_clicked();

    void on_aggiungiConfButton_clicked();

    void on_visualizzaConfButton_clicked();

    void on_aggiungiRivButton_clicked();

    void on_visualizzaRivButton_clicked();

    void on_aggiungiArtButton_clicked();

    void on_visualizzaArtButton_clicked();

    void on_aggiungiAutButtonAP_clicked();

    void on_aggiungiConfButtonAC_clicked();

    void on_aggiungiRivButtonAR_clicked();

    void on_aggiungiArticoloButton_clicked();

    void on_visualAutArtAA_clicked();

    void on_AggiungiAutoreButton_clicked();

    void on_visualArtArtAA_clicked();

    void on_AggiungiArtArtButton_clicked();

    void on_confRadioButton_clicked();

    void on_rivRadioButton_clicked();

    void on_sezioneBButton_clicked();

    void on_m1pushButton_clicked();

    void on_mB4Button_clicked();

    void on_mB6Button_clicked();

    void on_sezioneCButton_clicked();

    void on_mC1Button_clicked();

    void on_mC3Button_clicked();

    void on_mC6Button_clicked();

    void on_sezioneEFButton_clicked();

    void on_mE6Button_clicked();

    void on_mF5button_clicked();

    void on_sezioneDButton_clicked();

    void on_mD3button_clicked();

    void on_mD6button1_clicked();

    void on_mD6button2_clicked();

private:
    Ui::MainWindow *ui;
    gestore* Gestore;
    QList<autore> supportoAutori;
    QList<articolo> supportoArticoli;
};
#endif // MAINWINDOW_H
