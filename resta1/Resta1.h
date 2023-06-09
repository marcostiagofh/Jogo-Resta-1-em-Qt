#ifndef RESTA1_H
#define RESTA1_H

#include <QMainWindow>
#include <QList>
#include <Peca.h>

namespace Ui {
class Resta1;
}

class Resta1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Resta1(QWidget *parent = 0);
    ~Resta1();
    bool existe_movs_disp(int r, int c);
    bool verifica_fim_de_jogo();
    void executa_movimento(int x1, int y1, int x2, int y2);
    void calcula_movs_disp(int r, int c);

signals:
    void gameOver();

private:
    Ui::Resta1 *ui;
    Peca *m_pecas[7][7];
    QAction *modo;
    void tabuleiro(int modo);
    int num_pecas;
    int estado = 1;
    QList<Peca*> lista;
    Peca *jumper;
private slots:
    void play();
    void iniciarNovoJogo();
    void mostrarSobre();
    void mostrarFimJogo();
    void trocarModo(QAction* modo);
};

#endif // RESTA1_H
