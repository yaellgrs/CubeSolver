#include "View/qt/mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->scene = new QGraphicsScene(this);
    ui->Cube->setScene(this->scene);

    // un carré rouge avec contour noir
    ui->Cube->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    this->m_cube = new Cube3D();

    this->m_cube->setFromState(resolu);
    drawCube();

    new QShortcut(QKeySequence(Qt::Key_U), this, [this] { apply(U); });
    new QShortcut(QKeySequence(Qt::Key_D), this, [this] { apply(D); });
    new QShortcut(QKeySequence(Qt::Key_L), this, [this] { apply(L); });
    new QShortcut(QKeySequence(Qt::Key_R), this, [this] { apply(R); });
    new QShortcut(QKeySequence(Qt::Key_B), this, [this] { apply(B); });
    new QShortcut(QKeySequence(Qt::Key_F), this, [this] { apply(F); });

    new QShortcut(QKeySequence(Qt::CTRL |Qt::Key_U), this, [this] { apply(U_PRIME); });
    new QShortcut(QKeySequence(Qt::CTRL |Qt::Key_D), this, [this] { apply(D_PRIME); });
    new QShortcut(QKeySequence(Qt::CTRL |Qt::Key_L), this, [this] { apply(L_PRIME); });
    new QShortcut(QKeySequence(Qt::CTRL |Qt::Key_R), this, [this] { apply(R_PRIME); });
    new QShortcut(QKeySequence(Qt::CTRL |Qt::Key_B), this, [this] { apply(B_PRIME); });
    new QShortcut(QKeySequence(Qt::CTRL |Qt::Key_F), this, [this] { apply(F_PRIME); });


    new QShortcut(QKeySequence(Qt::SHIFT |Qt::Key_U), this, [this] { apply(U2); });
    new QShortcut(QKeySequence(Qt::SHIFT |Qt::Key_D), this, [this] { apply(D2); });
    new QShortcut(QKeySequence(Qt::SHIFT |Qt::Key_L), this, [this] { apply(L2); });
    new QShortcut(QKeySequence(Qt::SHIFT |Qt::Key_R), this, [this] { apply(R2); });
    new QShortcut(QKeySequence(Qt::SHIFT |Qt::Key_B), this, [this] { apply(B2); });
    new QShortcut(QKeySequence(Qt::SHIFT |Qt::Key_F), this, [this] { apply(F2); });


    new QShortcut(QKeySequence(Qt::Key_A), this, [this] {
        for(int i = 0; i < 50; i++){
            this->m_cube->state->Sort(1);
            drawCube();
        }

    });
    new QShortcut(QKeySequence(Qt::Key_Z), this, [this] {
        this->m_cube->setFromState(resolu);
        drawCube();
    });
}

void MainWindow::apply(Mouvement m)
{
    m_cube->setFromState(m_cube->state->applyMove(m));
    drawCube();                       // 2. vue
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::DrawSticker(int x, int y, int w, int h, QColor color){
    this->scene->addRect(x, y, w, h, QPen(Qt::black), color);
}

void MainWindow::drawCube()
{
    this->scene->clear();
    DrawFace(5, 150, 0);
    DrawFace(2, 0, 150);
    DrawFace(1, 150, 150);
    DrawFace(4, 300, 150);
    DrawFace(3, 450, 150);
    DrawFace(0, 150, 300);

    //	std::vector<int> faceOrder = { 2, 1, 4, 3 };
}

void MainWindow::DrawFace(int face, int xGap, int yGap){
    int n = this->m_cube->getOrder();
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            CubeColor color = this->m_cube->getSticker((Face)face, row, col);

            // std::cout << colorToString(color) << " ";
            DrawSticker(xGap + 50*col, yGap + 50*row, 50, 50, toQColor(color));
        }

    }
}
