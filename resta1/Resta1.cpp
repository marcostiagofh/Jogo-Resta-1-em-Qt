#include "Resta1.h"
#include "ui_Resta1.h"
#include <QDebug>
#include <QActionGroup>
#include <QMessageBox>
#include <QStatusBar>
#include <QString>

Resta1::Resta1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Resta1) {
    ui->setupUi(this);    

    QActionGroup* group = new QActionGroup(this);
    group->setExclusive(true);
    group->addAction(ui->actionTradicional);
    group->addAction(ui->actionBanquinho);
    group->addAction(ui->actionCruz);
    group->addAction(ui->actionFlecha);
    group->addAction(ui->actionLosango);
    group->addAction(ui->actionMais);
    group->addAction(ui->actionPiramide);

    for (int r = 0; r < 7; r++) {
        for (int c = 0; c < 7; c++) {
            m_pecas[r][c] =
              this->findChild<Peca*>(
                QString("peca%1%2").arg(r).arg(c));
            if (m_pecas[r][c]) {
                m_pecas[r][c]->setX(r);
                m_pecas[r][c]->setY(c);

                QObject::connect(
                  m_pecas[r][c],
                  SIGNAL(clicked()),
                  this,
                  SLOT(play()));

                m_pecas[r][c]->setState(Peca::Filled);
            }
        }
    }
    ui->statusBar->showMessage(QString("Pecas restantes: 32"));
    m_pecas[3][3]->setState(Peca::Empty);
    this->num_pecas = 32;

    QObject::connect(
        group,
        SIGNAL(triggered(QAction*)),
        this,
        SLOT(trocarModo(QAction*)));

    QObject::connect(
        ui->actionSair,
        SIGNAL(triggered()),
        qApp,
        SLOT(quit()));

    QObject::connect(
        ui->actionSobre,
        SIGNAL(triggered()),
        this,
        SLOT(mostrarSobre()));

    QObject::connect(
        this,
        SIGNAL(gameOver()),
        this,
        SLOT(mostrarFimJogo()));
    QObject::connect(
        ui->actionNovo,
        SIGNAL(triggered()),
        this,
        SLOT(iniciarNovoJogo()));

    this->adjustSize();
    this->setFixedSize(this->size());

}

Resta1::~Resta1()
{
    delete ui;
}

void Resta1::trocarModo(QAction* modo){
    this->modo = modo;
    this->iniciarNovoJogo();
}

void Resta1::play() {
    Peca* peca = qobject_cast<Peca*>(
                QObject::sender());
    //ui->statusBar->showMessage(QString("Progresso: %1%").arg(QString::number(progress, 'f', 2)));
    /*if (peca == ui->peca54) {
        emit gameOver();
    } else {
        m_pecas[3][3]->setState(Peca::Filled);
        peca->setState(Peca::Empty);
    }*/

    QList<Peca*> lista;
    switch(this->estado){
        case 1:
        {
            this->lista.clear();
            if(verifica_fim_de_jogo())
                emit gameOver();
            this->calcula_movs_disp(peca->getX(),peca->getY());
            if(this->lista.size() == 1){
                this->executa_movimento(peca->getX(),peca->getY(),this->lista.front()->getX(),this->lista.front()->getY());
                this->num_pecas--;
            } else if(this->lista.size() > 1){
                peca->setState(Peca::Selected);
                this->jumper = peca;
                foreach(Peca *p, this->lista){
                    p->setState(Peca::Jumpable);
                }
                this->estado = 2;
            } else {
                //nenhuma acao deve ser feita
            }
        }
        break;
        case 2:
        {
            if(this->lista.contains(peca)){
                foreach(Peca *p, this->lista){
                    if(p->getX() == peca->getX() && p->getY() == peca->getY()){
                        executa_movimento(this->jumper->getX(),this->jumper->getY(),p->getX(),p->getY());
                        this->num_pecas--;
                    } else {
                        p->setState(Peca::Empty);
                    }
                }
                this->estado = 1;
            } else {
                //faça nada
            }
        }
        default:
        break;
    }
    ui->statusBar->showMessage(QString("Pecas restantes: %1").arg(QString::number(this->num_pecas,'d',0)));
}

void Resta1::mostrarSobre(){
        qDebug() << "Mostrando...";
        QMessageBox::information(this,
               tr("Sobre"),
               tr("Resta Um\n\nMarcos Henriques - marcostiagofh@gmail.com"));
}

void Resta1::mostrarFimJogo() {
    if(this->num_pecas == 1){
        QMessageBox::information(this,
           tr("Fim"),
           tr("Parabéns, você venceu!"));
    } else if(this->num_pecas > 1){
        QMessageBox::information(this,
               tr("Fim"),
               tr("Você perdeu. Não existem mais jogadas possíveis."));
    } else {
        QMessageBox::information(this,
               tr("Fim"),
               tr("Situação inválida"));
    }
}

void Resta1::iniciarNovoJogo(){
    //detectar estado atual e limpar tabuleiro
    if(modo == ui-> actionTradicional){
        qDebug() << "Modo: Tradicional";
        this->tabuleiro(1);
    } else if(modo == ui-> actionBanquinho){
        qDebug() << "Modo: Banquinho";
        this->tabuleiro(2);
    } else if(modo == ui-> actionCruz){
        qDebug() << "Modo: Cruz";
        this->tabuleiro(3);
    } else if(modo == ui-> actionFlecha){
        qDebug() << "Modo: Flecha";
        this->tabuleiro(4);
    } else if(modo == ui-> actionLosango){
        qDebug() << "Modo: Losango";
        this->tabuleiro(5);
    } else if(modo == ui-> actionMais){
        qDebug() << "Modo: Mais";
        this->tabuleiro(6);
    } else if(modo == ui-> actionPiramide){
        qDebug() << "Modo: Piramide";
        this->tabuleiro(7);
    }
    ui->statusBar->showMessage(QString("Pecas restantes: %1").arg(QString::number(this->num_pecas,'d',0)));
}

void Resta1::tabuleiro(int modo){
//limpa tabuleiro
for (int r = 0; r < 7; r++)
    for (int c = 0; c < 7; c++)
        if (this->m_pecas[r][c])
            this->m_pecas[r][c]->setState(Peca::Empty);
//preenche de acordo com o modo
switch(modo){
    case 1: //tradicional
    {
        for (int r = 0; r < 7; r++)
            for (int c = 0; c < 7; c++)
                if (this->m_pecas[r][c])
                    this->m_pecas[r][c]->setState(Peca::Filled);

        this->m_pecas[3][3]->setState(Peca::Empty);
        this->num_pecas = 32;
    } break;
    case 2: //banquinho
    {
        for (int r = 0; r <= 3; r++)
            for (int c = 2; c <= 4; c++)
                if (this->m_pecas[r][c])
                    this->m_pecas[r][c]->setState(Peca::Filled);

        this->m_pecas[3][3]->setState(Peca::Empty);
        this->num_pecas = 11;
    } break;
    case 3: //cruz
    {
        for (int r = 1; r <= 4; r++)
            if (this->m_pecas[r][3])
                this->m_pecas[r][3]->setState(Peca::Filled);
        for (int c = 2; c <= 4; c++)
            if (this->m_pecas[2][c])
                this->m_pecas[2][c]->setState(Peca::Filled);
        this->num_pecas = 6;
    } break;
    case 4: //flecha
    {
        for (int r = 0; r <= 2; r++)
            for (int c = 1; c <= 5; c++)
                if (this->m_pecas[r][c])
                    this->m_pecas[r][c]->setState(Peca::Filled);

        for (int r = 5; r <= 6; r++)
            for (int c = 2; c <= 4; c++)
                if (this->m_pecas[r][c])
                    this->m_pecas[r][c]->setState(Peca::Filled);

        for (int r = 3; r <= 4; r++)
            if (this->m_pecas[r][3])
                this->m_pecas[r][3]->setState(Peca::Filled);

        this->m_pecas[0][2]->setState(Peca::Empty);
        this->m_pecas[0][4]->setState(Peca::Empty);
        this->num_pecas = 17;
    } break;
    case 5: //losango
    {
    for (int r = 0; r < 7; r++)
        for (int c = 0; c < 7; c++)
            if (this->m_pecas[r][c])
                this->m_pecas[r][c]->setState(Peca::Filled);

        this->m_pecas[3][3]->setState(Peca::Empty);
        this->m_pecas[0][2]->setState(Peca::Empty);
        this->m_pecas[0][4]->setState(Peca::Empty);
        this->m_pecas[2][0]->setState(Peca::Empty);
        this->m_pecas[4][0]->setState(Peca::Empty);
        this->m_pecas[6][2]->setState(Peca::Empty);
        this->m_pecas[6][4]->setState(Peca::Empty);
        this->m_pecas[2][6]->setState(Peca::Empty);
        this->m_pecas[4][6]->setState(Peca::Empty);
        this->num_pecas = 24;
    } break;
    case 6: //mais
    {
        for (int r = 1; r < 6; r++)
            if (this->m_pecas[r][3])
                this->m_pecas[r][3]->setState(Peca::Filled);
        for (int c = 1; c < 6; c++)
            if (this->m_pecas[3][c])
                this->m_pecas[3][c]->setState(Peca::Filled);
        this->num_pecas = 9;
    } break;
    case 7: //piramide
    {
        int esq = 0, dir = 6;
        for (int r = 4; r >= 1; r--){
            for (int c = esq; c <= dir; c++){
                if (this->m_pecas[r][c])
                    this->m_pecas[r][c]->setState(Peca::Filled);

            }
            esq++; dir--;
        }
        this->num_pecas = 16;
    } break;
    default: //invalido
    break;
}


}

//ao clicar numa peça, mostre movs disp.
bool Resta1::existe_movs_disp(int r, int c){

    if((((r)>=0) && ((r+2)<=6) && this->m_pecas[r+1][c] && (this->m_pecas[r+1][c]->getState() == Peca::Filled) && this->m_pecas[r+2][c] && (this->m_pecas[r+2][c]->getState() == Peca::Empty)) ||
       (((r-2)>=0) && ((r)<=6) && this->m_pecas[r-1][c] && (this->m_pecas[r-1][c]->getState() == Peca::Filled) && this->m_pecas[r-2][c] && (this->m_pecas[r-2][c]->getState() == Peca::Empty)) ||
       (((c)>=0) && ((c+2)<=6) && this->m_pecas[r][c+1] && (this->m_pecas[r][c+1]->getState() == Peca::Filled) && this->m_pecas[r][c+2] && (this->m_pecas[r][c+2]->getState() == Peca::Empty)) ||
       (((c-2)>=0) && ((c)<=6) && this->m_pecas[r][c-1] && (this->m_pecas[r][c-1]->getState() == Peca::Filled) && this->m_pecas[r][c-2] && (this->m_pecas[r][c-2]->getState() == Peca::Empty)))
            return true;
    else
        return false;
}

//verifica fim de jogo
bool Resta1::verifica_fim_de_jogo(){
    for (int r = 0; r < 7; r++)
        for (int c = 0; c < 7; c++)
            if (this->m_pecas[r][c] && (this->m_pecas[r][c]->getState() == Peca::Filled))
                if(this->existe_movs_disp(r,c))
                    return false;
    return true;
}

void Resta1::executa_movimento(int x1, int y1, int x2, int y2){
    this->m_pecas[x1][y1]->setState(Peca::Empty);
    this->m_pecas[(x2+x1)/2][(y2+y1)/2]->setState(Peca::Empty);
    this->m_pecas[x2][y2]->setState(Peca::Filled);
}

void Resta1::calcula_movs_disp(int r, int c){
    if(((r)>=0) && ((r+2)<=6) && this->m_pecas[r+1][c] && (this->m_pecas[r+1][c]->getState() == Peca::Filled) && this->m_pecas[r+2][c] && (this->m_pecas[r+2][c]->getState() == Peca::Empty))
        this->lista << this->m_pecas[r+2][c];
    if(((r-2)>=0) && ((r)<=6) && this->m_pecas[r-1][c] && (this->m_pecas[r-1][c]->getState() == Peca::Filled) && this->m_pecas[r-2][c] && (this->m_pecas[r-2][c]->getState() == Peca::Empty))
        this->lista << this->m_pecas[r-2][c];
    if(((c)>=0) && ((c+2)<=6) && this->m_pecas[r][c+1] && (this->m_pecas[r][c+1]->getState() == Peca::Filled) && this->m_pecas[r][c+2] && (this->m_pecas[r][c+2]->getState() == Peca::Empty))
        this->lista << this->m_pecas[r][c+2];
    if(((c-2)>=0) && ((c)<=6) && this->m_pecas[r][c-1] && (this->m_pecas[r][c-1]->getState() == Peca::Filled) && this->m_pecas[r][c-2] && (this->m_pecas[r][c-2]->getState() == Peca::Empty))
        this->lista << this->m_pecas[r][c-2];
}
