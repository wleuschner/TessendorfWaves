#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <complex>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    t=0.0;
    analysisImage = NULL;
    updateTimer.setInterval(1000/25);
    updateTimer.setSingleShot(false);
    connect(ui->btnChange,SIGNAL(clicked(bool)),this,SLOT(changeClicked()));
    connect(&updateTimer,SIGNAL(timeout()),this,SLOT(update()));
    //changeClicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    t+=1.0/25;
    simulation.update(t);
    switch(ui->tabWidget->currentIndex())
    {
        //Rendering
        case 0:
        {
            const fftw_complex* field = simulation.getHeightField();
            const fftw_complex* xmap = simulation.getSlopeXMap();
            const fftw_complex* ymap = simulation.getSlopeYMap();
            const fftw_complex* dxmap = simulation.getDisplaceXMap();
            const fftw_complex* dymap = simulation.getDisplaceYMap();
            ui->canvas->update();
            ui->canvas->setHeightField(field,xmap,ymap,dxmap,dymap);
            break;
        }
        //HeightMap
        case 1:
        {
            unsigned int w = simulation.getFieldWidth();
            unsigned int h = simulation.getFieldHeight();
            float maxWave = simulation.getMaxWaveHeight();
            const fftw_complex* field = simulation.getHeightField();
            for(unsigned y=0;y<h;y++)
            {
                for(unsigned x=0;x<w;x++)
                {

                    unsigned char g = std::max(std::min(255.0,((field[y*w+x][0]+1)/2)*255),0.0);
                    analysisImage[y*w+x] = g;
                    //qDebug()<<field[y*w+x][0]<<g<<maxWave;
                }
            }
            QImage img(analysisImage,w,h,QImage::Format_Grayscale8);
            ui->labelHeightMap->setPixmap(QPixmap::fromImage(img));
            break;
        }
        //Spectrum
        case 2:
        {
            unsigned int w = simulation.getFieldWidth();
            unsigned int h = simulation.getFieldHeight();
            const fftw_complex* field = simulation.getSpectrum();
            for(unsigned y=0;y<h;y++)
            {
                for(unsigned x=0;x<w;x++)
                {
                    std::complex<double> val(field[y*w+x][0],field[y*w+x][1]);
                    double f = (log(abs(val)+1))/32;
                    unsigned char g = fmin(255,((log(abs(val)+1)))*4096*256);
                    analysisImage[y*w+x] = g;
                    //qDebug()<<field[y*w+x]<<g;
                }
            }
            QImage img(analysisImage,w,h,QImage::Format_Grayscale8);
            ui->labelSpectrum->setPixmap(QPixmap::fromImage(img));
            break;
        }
        case 3:
        {
            unsigned int w = simulation.getFieldWidth();
            unsigned int h = simulation.getFieldHeight();
            const fftw_complex* field = simulation.getInitialSpectrum();
            for(unsigned y=0;y<h;y++)
            {
                for(unsigned x=0;x<w;x++)
                {
                    std::complex<double> val(field[y*w+x][0],field[y*w+x][1]);
                    double f = (log(abs(val)+1))/32;
                    unsigned char g = fmin(255,((log(abs(val)+1)))*4096*256);
                    analysisImage[y*w+x] = g;
                    //qDebug()<<field[y*w+x]<<g;
                }
            }
            QImage img(analysisImage,w,h,QImage::Format_Grayscale8);
            ui->labelInitialSpectrum->setPixmap(QPixmap::fromImage(img));
        }
    }
}

void MainWindow::changeClicked()
{
    updateTimer.stop();
    if(analysisImage!=NULL)
    {
        delete analysisImage;
    }
    unsigned width;
    unsigned height;
    unsigned patchSize = ui->spinboxPatchSize->value();
    float windSpeed = ui->spinboxSpeed->value();
    glm::vec2 windDir = ui->compass->getDirection();

    switch(ui->comboGridSize->currentIndex())
    {
        case 0:
        {
            width=32;
            height=32;
            break;
        }
        case 1:
        {
            width=64;
            height=64;
            break;
        }
        case 2:
        {
            width=128;
            height=128;
            break;
        }
        case 3:
        {
            width=256;
            height=256;
            break;
        }
        case 4:
        {
            width=512;
            height=512;
            break;
        }
        case 5:
        {
            width=1024;
            height=1024;
            break;
        }
        case 6:
        {
            width=2048;
            height=2048;
            break;
        }
    }
    t=0.0;
    analysisImage = (unsigned char*)malloc(sizeof(unsigned char)*width*height);
    ui->canvas->setPatchSize(patchSize);
    ui->canvas->setDimensions(width,height);
    simulation.init(width,height,patchSize,windSpeed,windDir);
    updateTimer.start();
}
