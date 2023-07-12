#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <QClipboard>

using namespace std;

vector<string> wordList;
string words;

vector<string> readWordsFromFile(const string& filename) {
    vector<string> words;
    ifstream file(filename);
    string word;

    if (file.is_open()) {
        while (getline(file, word)) {
            words.push_back(word);
        }
        file.close();
    } else {
        cout << "Error opening file: " << filename << endl;
    }

    return words;
}

string printRandomWords(const std::vector<std::string>& wordList, int n) {
    // Check if the wordList has enough unique words

    // Create a copy of the wordList
    std::vector<std::string> availableWords = wordList;

    // Seed the random number generator
    std::random_device rd;
    std::mt19937 generator(rd());

    // Shuffle the wordList
    std::shuffle(availableWords.begin(), availableWords.end(), generator);

    string output;
    // Print the first n words
    for (int i = 0; i < n; ++i)
    {
        output += availableWords[i];
    }


    return output;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->word12->isChecked();
    ui->Description->setText(QString::fromStdString("A 12-word seed phrase has 2048 choose 12 [2048!/(12!*(2048-12)!)] possible word combinations.\nThat is 1.1005262e+31 possible combinations. Give up now."));
    wordList = readWordsFromFile("english.txt");
    string wordListOutput;
    for(int i = 0; i < wordList.size(); i++)
    {
        if(i == wordList.size() - 1)
        {
            wordListOutput += wordList.at(i);
        }
        else
        {
            wordListOutput += wordList.at(i) += "\n";
        }
    }

    ui->WordListText->setText(QString::fromStdString(wordListOutput));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_GenerateButton_clicked()
{
    if(ui->word12->isChecked())
    {
        words = printRandomWords(wordList, 12);
        ui->GeneratedWordsText->setText(QString::fromStdString(words));
    }
    else if(ui->word15->isChecked())
    {
        words = printRandomWords(wordList, 15);
        ui->GeneratedWordsText->setText(QString::fromStdString(words));
    }
    else if(ui->word18->isChecked())
    {
        words = printRandomWords(wordList, 18);
        ui->GeneratedWordsText->setText(QString::fromStdString(words));
    }
    else if(ui->word21->isChecked())
    {
        words = printRandomWords(wordList, 21);
        ui->GeneratedWordsText->setText(QString::fromStdString(words));
    }
    else if(ui->word24->isChecked())
    {
        words = printRandomWords(wordList, 24);
        ui->GeneratedWordsText->setText(QString::fromStdString(words));
    }

    QApplication::clipboard()->setText(QString::fromStdString(words));
}

void MainWindow::on_word12_clicked()
{
    ui->Description->setText(QString::fromStdString("A 12-word seed phrase has 2048 choose 12 [2048!/(12!*(2048-12)!)] possible word combinations.\nThat is 1.1005262e+31 possible combinations. Give up now."));
}

void MainWindow::on_word15_clicked()
{
    ui->Description->setText(QString::fromStdString("A 15-word seed phrase has 2048 choose 15 [2048!/(15!*(2048-15)!)] possible word combinations.\nThat is 3.3972763e+37 possible combinations. Give up now."));
}

void MainWindow::on_word18_clicked()
{
    ui->Description->setText(QString::fromStdString("An 18-word seed phrase has 2048 choose 18 [2048!/(18!*(2048-18)!)] possible word combinations.\nThat is 5.8218426e+43 possible combinations. Give up now."));
}

void MainWindow::on_word21_clicked()
{
    ui->Description->setText(QString::fromStdString("A 21-word seed phrase has 2048 choose 21 [2048!/(21!*(2048-21)!)] possible word combinations.\nThat is 6.0940162e+49 possible combinations. Give up now."));
}

void MainWindow::on_word24_clicked()
{
    ui->Description->setText(QString::fromStdString("A 24-word seed phrase has 2048 choose 24 [2048!/(24!*(2048-24)!)] possible word combinations.\nThat is 4.1731122e+55 possible combinations. Give up now."));
}


