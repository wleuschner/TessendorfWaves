#ifndef CANVAS_H
#define CANVAS_H

#include <QKeyEvent>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <glm/glm.hpp>
#include "camera.h"
#include "oceanwaves.h"
#include "vertex.h"
#include "light.h"
#include "material.h"


class Canvas : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);
    void setHeightField(const fftw_complex* field,const fftw_complex* xmap,const fftw_complex* ymap,const fftw_complex* dxmap,const fftw_complex* dymap);
    void setDimensions(unsigned width,unsigned height);
    void setPatchSize(unsigned patchSize);
    void uploadLight(Light& light,int index);
protected:
    void keyPressEvent(QKeyEvent* event);
    void initializeGL();
    void resizeGL(int w,int h);
    void paintGL();

signals:

private:
    const fftw_complex* field;
    const fftw_complex* slopeXMap;
    const fftw_complex* slopeYMap;
    const fftw_complex* displaceXMap;
    const fftw_complex* displaceYMap;
    unsigned width;
    unsigned height;
    unsigned patchSize;

    Camera camera;

    Material mat;
    Light light;
    std::vector<unsigned> indices;
    std::vector<Vertex> vertices;

    QOpenGLBuffer tvbo;
    QOpenGLBuffer tibo;

    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer vbo;
    QOpenGLBuffer index;
    QOpenGLShaderProgram program;
    glm::mat4 matProj;
};

#endif // CANVAS_H
