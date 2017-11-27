#ifndef OCEANWAVES_H
#define OCEANWAVES_H
#include<complex>
#include<fftw3.h>
#include<glm/glm.hpp>


class OceanWaves
{
public:
    OceanWaves();
    ~OceanWaves();

    void init(unsigned width,unsigned height,unsigned patchSize,double windSpeed,glm::vec2 windDir);
    void update(double t);

    double phillips(double fA,glm::vec2 vWaveDir,double fWindSpeed,glm::vec2 vWindDir);

    const fftw_complex* getInitialSpectrum();
    const fftw_complex* getSpectrum();
    const fftw_complex* getHeightField();
    const fftw_complex* getSlopeXMap();
    const fftw_complex* getSlopeYMap();
    const fftw_complex* getDisplaceXMap();
    const fftw_complex* getDisplaceYMap();
    double getWindSpeed();
    const glm::vec2& getWindDir();
    double getMaxWaveHeight();
    unsigned int getFieldWidth();
    unsigned int getFieldHeight();
private:

    const double PI = 3.14159265359;
    const double G = 9.81;

    double fA;
    fftw_plan fftwPlan;
    fftw_plan fftwSlopeXPlan;
    fftw_plan fftwSlopeYPlan;
    fftw_plan fftwDisplaceXPlan;
    fftw_plan fftwDisplaceYPlan;

    double fWindSpeed;
    glm::vec2 vWindDir;

    unsigned patchSize;
    unsigned iWidth;
    unsigned iHeight;

    fftw_complex* pInitialSpectrum;
    fftw_complex* pSpectrum;
    fftw_complex* pSlopeXSpectrum;
    fftw_complex* pSlopeYSpectrum;
    fftw_complex* pDisplaceXSpectrum;
    fftw_complex* pDisplaceYSpectrum;

    fftw_complex* pHeightMap;
    fftw_complex* pSlopeXMap;
    fftw_complex* pSlopeYMap;
    fftw_complex* pDisplaceXMap;
    fftw_complex* pDisplaceYMap;
};

#endif // OCEANWAVES_H
