#ifndef PECA_H
#define PECA_H

#include <QPushButton>

class Peca : public QPushButton
{
    Q_OBJECT
public:
    enum State {
        Empty,
        Filled,
        Selected,
        Jumpable
    };
    explicit Peca(QWidget *parent = 0);
     ~Peca();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

signals:
    void stateChanged(Peca::State state);

public slots:
    void setState(Peca::State state);
    Peca::State getState();
private:
      Peca::State m_state;
      int x,y;

private slots:
      void updateIcon();
};

#endif // PECA_H
