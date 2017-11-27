#include "oceanwaves.h"
#include <random>

OceanWaves::OceanWaves()
{
    //this->fA = 0.1;
    this->fA = 0.000010;
    this->pInitialSpectrum = NULL;
    this->pSpectrum = NULL;
    this->pSlopeXSpectrum = NULL;
    this->pSlopeYSpectrum = NULL;
    this->pHeightMap = NULL;
    this->pSlopeXMap = NULL;
    this->pSlopeYMap = NULL;
    this->pDisplaceXMap = NULL;
    this->pDisplaceYMap = NULL;
    this->fftwPlan = NULL;
    this->fftwSlopeXPlan = NULL;
    this->fftwSlopeYPlan = NULL;
    this->fftwDisplaceXPlan = NULL;
    this->fftwDisplaceYPlan = NULL;
}

OceanWaves::~OceanWaves()
{
    if(pInitialSpectrum!=NULL)
    {
        fftw_free(pInitialSpectrum);
    }
    if(pSpectrum!=NULL)
    {
        fftw_free(pSpectrum);
    }
    if(pSlopeXSpectrum!=NULL)
    {
        fftw_free(pSlopeXSpectrum);
    }
    if(pSlopeYSpectrum!=NULL)
    {
        fftw_free(pSlopeYSpectrum);
    }
    if(pHeightMap!=NULL)
    {
        fftw_free(pHeightMap);
    }
    if(pSlopeXMap!=NULL)
    {
        fftw_free(pSlopeXMap);
    }
    if(pSlopeYMap!=NULL)
    {
        fftw_free(pSlopeYMap);
    }
    if(pDisplaceXMap!=NULL)
    {
        fftw_free(pDisplaceXMap);
    }
    if(pDisplaceYMap!=NULL)
    {
        fftw_free(pDisplaceYMap);
    }
    if(fftwPlan!=NULL)
    {
        fftw_destroy_plan(fftwPlan);
    }
    if(fftwSlopeXPlan!=NULL)
    {
        fftw_destroy_plan(fftwSlopeXPlan);
    }
    if(fftwSlopeYPlan!=NULL)
    {
        fftw_destroy_plan(fftwSlopeYPlan);
    }
    if(fftwDisplaceXPlan!=NULL)
    {
        fftw_destroy_plan(fftwDisplaceXPlan);
    }
    if(fftwDisplaceYPlan!=NULL)
    {
        fftw_destroy_plan(fftwDisplaceYPlan);
    }
}

void OceanWaves::init(unsigned width,unsigned height,unsigned patchSize,double windSpeed,glm::vec2 windDir)
{
    if(pInitialSpectrum!=NULL)
    {
        fftw_free(pInitialSpectrum);
    }
    if(pSpectrum!=NULL)
    {
        fftw_free(pSpectrum);
    }
    if(pSlopeXSpectrum!=NULL)
    {
        fftw_free(pSlopeXSpectrum);
    }
    if(pSlopeYSpectrum!=NULL)
    {
        fftw_free(pSlopeYSpectrum);
    }
    if(pHeightMap!=NULL)
    {
        fftw_free(pHeightMap);
    }
    if(pSlopeXMap!=NULL)
    {
        fftw_free(pSlopeXMap);
    }
    if(pSlopeYMap!=NULL)
    {
        fftw_free(pSlopeYMap);
    }
    if(pDisplaceXMap!=NULL)
    {
        fftw_free(pDisplaceXMap);
    }
    if(pDisplaceYMap!=NULL)
    {
        fftw_free(pDisplaceYMap);
    }
    if(fftwPlan!=NULL)
    {
        fftw_destroy_plan(fftwPlan);
    }
    if(fftwSlopeXPlan!=NULL)
    {
        fftw_destroy_plan(fftwSlopeXPlan);
    }
    if(fftwSlopeYPlan!=NULL)
    {
        fftw_destroy_plan(fftwSlopeYPlan);
    }
    if(fftwDisplaceXPlan!=NULL)
    {
        fftw_destroy_plan(fftwDisplaceXPlan);
    }
    if(fftwDisplaceYPlan!=NULL)
    {
        fftw_destroy_plan(fftwDisplaceYPlan);
    }

    this->iHeight = height;
    this->iWidth = width;
    this->patchSize = patchSize;
    this->fWindSpeed = windSpeed;
    this->vWindDir = windDir;
    pInitialSpectrum = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*width*height);
    pSpectrum = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*width*height);
    pSlopeXSpectrum = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*width*height);
    pSlopeYSpectrum = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*width*height);
    pDisplaceXSpectrum = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*width*height);
    pDisplaceYSpectrum = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*width*height);
    pHeightMap = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*width*height);
    pSlopeXMap = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*width*height);
    pSlopeYMap = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*width*height);
    pDisplaceXMap = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*width*height);
    pDisplaceYMap = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*width*height);
    this->fftwPlan = fftw_plan_dft_2d(this->iHeight,this->iWidth,this->pSpectrum,this->pHeightMap,FFTW_BACKWARD,FFTW_ESTIMATE);
    this->fftwSlopeXPlan = fftw_plan_dft_2d(this->iHeight,this->iWidth,this->pSlopeXSpectrum,this->pSlopeXMap,FFTW_BACKWARD,FFTW_ESTIMATE);
    this->fftwSlopeYPlan = fftw_plan_dft_2d(this->iHeight,this->iWidth,this->pSlopeYSpectrum,this->pSlopeYMap,FFTW_BACKWARD,FFTW_ESTIMATE);
    this->fftwDisplaceXPlan = fftw_plan_dft_2d(this->iHeight,this->iWidth,this->pDisplaceXSpectrum,this->pDisplaceXMap,FFTW_BACKWARD,FFTW_ESTIMATE);
    this->fftwDisplaceYPlan = fftw_plan_dft_2d(this->iHeight,this->iWidth,this->pDisplaceYSpectrum,this->pDisplaceYMap,FFTW_BACKWARD,FFTW_ESTIMATE);


    double fMultiplier;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> randn;
    for(unsigned y=0;y<height;y++)
    {
        for(unsigned x=0;x<width;x++)
        {
            int ix=x;
            int iy=y;
            if(x>width/2)
            {
                ix-=iWidth;
            }
            if(y>height/2)
            {
                iy-=iHeight;
            }
            glm::vec2 vWaveDir(2*ix*PI/patchSize,2*iy*PI/patchSize);
            std::complex<double> r(randn(gen),randn(gen));

            if(!((vWaveDir.x==0.0) && (vWaveDir.y==0.0)))
            {
                fMultiplier = sqrt(phillips(this->fA,vWaveDir,this->fWindSpeed,this->vWindDir));
            }
            else
            {
                fMultiplier=0.0;
            }
            r = r*fMultiplier;
            pInitialSpectrum[y*width+x][0] = r.real();
            pInitialSpectrum[y*width+x][1] = r.imag();
        }
    }
    //fftw_execute(this->fftwPlan);
}

const fftw_complex* OceanWaves::getInitialSpectrum()
{
    return pInitialSpectrum;
}

const fftw_complex* OceanWaves::getSpectrum()
{
    return pSpectrum;
}

const fftw_complex* OceanWaves::getHeightField()
{
    return pHeightMap;
}

const fftw_complex* OceanWaves::getSlopeXMap()
{
    return pSlopeXMap;
}

const fftw_complex* OceanWaves::getSlopeYMap()
{
    return pSlopeYMap;
}

const fftw_complex* OceanWaves::getDisplaceXMap()
{
    return pDisplaceXMap;
}

const fftw_complex* OceanWaves::getDisplaceYMap()
{
    return pDisplaceYMap;
}

double OceanWaves::getWindSpeed()
{
    return fWindSpeed;
}

const glm::vec2& OceanWaves::getWindDir()
{
    return vWindDir;
}

double OceanWaves::getMaxWaveHeight()
{
    return (fWindSpeed*fWindSpeed)/G;
}

unsigned int OceanWaves::getFieldWidth()
{
    return iWidth;
}

unsigned int OceanWaves::getFieldHeight()
{
    return iHeight;
}

void OceanWaves::update(double t)
{
    for(unsigned y=0;y<this->iHeight;y++)
    {
        for(unsigned x=0;x<this->iWidth;x++)
        {
            //Update Height
            int ix=x;
            int iy=y;
            if(x>iWidth/2)
            {
                ix-=iWidth;
            }
            if(y>iHeight/2)
            {
                iy-=iHeight;
            }
            glm::vec2 vWaveDir(2*ix*PI/patchSize,2*iy*PI/patchSize);
            std::complex<double> h0_k(pInitialSpectrum[y*this->iWidth+x][0],pInitialSpectrum[y*this->iWidth+x][1]);
            std::complex<double> h0_mk(pInitialSpectrum[((this->iHeight-1)-y)*this->iWidth+(this->iWidth-1-x)][0],pInitialSpectrum[((this->iHeight-1)-y)*this->iWidth+(this->iWidth-1-x)][1]);
            double klen = glm::length(vWaveDir);
            double w = sqrt(G*klen);
            std::complex<double> val = h0_k*exp(std::complex<double>(0,w*t)) + std::conj(h0_mk)*exp(std::complex<double>(0,-w*t));
            pSpectrum[y*this->iWidth+x][0] = val.real();
            pSpectrum[y*this->iWidth+x][1] = val.imag();

            //Update Normals
            std::complex<double> slopeXFFT = val * std::complex<double>(0,vWaveDir.x);
            std::complex<double> slopeYFFT = val * std::complex<double>(0,vWaveDir.y);

            pSlopeXSpectrum[y*this->iWidth+x][0] = slopeXFFT.real();
            pSlopeXSpectrum[y*this->iWidth+x][1] = slopeXFFT.imag();
            pSlopeYSpectrum[y*this->iWidth+x][0] = slopeYFFT.real();
            pSlopeYSpectrum[y*this->iWidth+x][1] = slopeYFFT.imag();

            //Update Displacement
            std::complex<double> displaceXFFT;
            std::complex<double> displaceYFFT;
            if(klen<0.0000001)
            {
                displaceXFFT = std::complex<double>(0.0,0.0);
                displaceYFFT = std::complex<double>(0.0,0.0);
            }
            else
            {
                displaceXFFT = val * std::complex<double>(0.0,-vWaveDir.x/klen);
                displaceYFFT = val * std::complex<double>(0.0,-vWaveDir.y/klen);
            }
            pDisplaceXSpectrum[y*this->iWidth+x][0] = displaceXFFT.real();
            pDisplaceXSpectrum[y*this->iWidth+x][1] = displaceXFFT.imag();
            pDisplaceYSpectrum[y*this->iWidth+x][0] = displaceYFFT.real();
            pDisplaceYSpectrum[y*this->iWidth+x][1] = displaceYFFT.imag();
        }
    }
    fftw_execute(this->fftwPlan);
    fftw_execute(this->fftwSlopeXPlan);
    fftw_execute(this->fftwSlopeYPlan);
    fftw_execute(this->fftwDisplaceXPlan);
    fftw_execute(this->fftwDisplaceYPlan);
}

double OceanWaves::phillips(double fA,glm::vec2 vWaveDir,double fWindSpeed,glm::vec2 vWindDir)
{
    double L = (fWindSpeed*fWindSpeed) / G;
    double w = L / 75.0;
    double d = glm::dot(glm::normalize(vWindDir),glm::normalize(vWaveDir));
    double klen = glm::length(vWaveDir);
    double result = fA*((exp(-1.0/(L*L*klen*klen)))/(klen*klen*klen*klen))*d*d;
    if(klen==0 || d<=0.0)
    {
        return 0.0;
    }
    double damp = exp(-1.0/(klen*klen*w*w));
    return result*damp;
}
