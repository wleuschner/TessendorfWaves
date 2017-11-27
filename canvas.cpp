#include "canvas.h"
#include "vertex.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

Canvas::Canvas(QWidget *parent) :
    QOpenGLWidget(parent)
{
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(3,3);
    format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    format.setSwapInterval(1);
    setFormat(format);
    setUpdateBehavior(QOpenGLWidget::NoPartialUpdate);

    glm::vec3 pos = glm::vec3(0.0,20.0,150.0);
    glm::vec3 amb = glm::vec3(0.5,0.5,0.5);
    glm::vec3 dif = glm::vec3(0.7,0.7,0.7);
    glm::vec3 spec = glm::vec3(0.85,0.85,0.85);
    light = Light(pos,amb,dif,spec);

    mat = Material(glm::vec3(0.0,0.0,0.7),glm::vec3(0.0,0.0,0.85),glm::vec3(0.0,0.0,0.255),1.0);
    camera.reset();
    camera.strafeZ(128);
}

void Canvas::uploadLight(Light& light,int index)
{
    glm::vec3 pos = light.getPosition();
    glm::vec3 ambient = light.getAmbient();
    glm::vec3 diffuse = light.getDiffuse();
    glm::vec3 specular = light.getSpecular();

    std::string pos_string = QString("light[%0].pos").arg(index).toStdString();
    std::string ambient_string = QString("light[%0].amb").arg(index).toStdString();
    std::string diffuse_string = QString("light[%0].dif").arg(index).toStdString();
    std::string specular_string = QString("light[%0].spec").arg(index).toStdString();

    program.setUniformValueArray(pos_string.c_str(),(GLfloat*)glm::value_ptr(pos),1,3);
    program.setUniformValueArray(ambient_string.c_str(),glm::value_ptr(ambient),1,3);
    program.setUniformValueArray(diffuse_string.c_str(),glm::value_ptr(diffuse),1,3);
    program.setUniformValueArray(specular_string.c_str(),glm::value_ptr(specular),1,3);
}

void Canvas::setHeightField(const fftw_complex* field,const fftw_complex* xmap,const fftw_complex* ymap,const fftw_complex* dxmap,const fftw_complex* dymap)
{
    this->makeCurrent();
    this->field=field;
    this->slopeXMap=xmap;
    this->slopeYMap=ymap;
    this->displaceXMap=dxmap;
    this->displaceYMap=dymap;

    //Create VBOs with new dimensions
    if(vbo.isCreated())
    {
        vbo.bind();
        vbo.destroy();
    }
    vbo = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.setUsagePattern(QOpenGLBuffer::DynamicDraw);
    vbo.bind();

    vertices.clear();

    double step = width;
    step = step/patchSize;
    for(unsigned y=0;y<height;y++)
    {
        for(unsigned x=0;x<width;x++)
        {
            Vertex v;
            //float fx = x*step-width*(patchSize/2.0);
            //float fy = y*step-height*(patchSize/2.0);
            v.pos.x=(float)((x)-(width)/2.0f)+displaceXMap[(y*width)+x][0];
            v.pos.z=(float)((height-y)-(height)/2.0f)+displaceYMap[(y*width)+x][0];
            v.pos.y=((float)field[(y*width)+(x)][0]);
            //v.pos.z=-20.0f;

            v.norm=glm::vec3(-slopeXMap[(y*width)+x][0],1.0f,-slopeYMap[(y*width)+x][0]);
            v.norm=glm::normalize(v.norm);
            vertices.push_back(v);
        }
    }

/*    for(unsigned y=0;y<height-1;y++)
    {
        for(unsigned x=0;x<width-1;x++)
        {
            glm::vec3 v1 = vertices[(y*width+x)].pos;
            glm::vec3 v2 = vertices[((y+1)*width+x)].pos;
            glm::vec3 v3 = vertices[(y*width+(x+1))].pos;
            glm::vec3 v6 = vertices[(y+1)*width+(x+1)].pos;

            glm::vec3 n1 = glm::cross(v2-v1,v3-v1);
            glm::vec3 n2 = glm::cross(v2-v3,v6-v3);

            vertices[(y*width+x)].norm = glm::normalize(0.5f*(vertices[(y*width+x)].norm + n1));//v1
            vertices[((y+1)*width+x)].norm = glm::normalize(0.5f*((vertices[((y+1)*width+x)].norm + 0.5f*(n1+n2))));
            vertices[((y+1)*width+x)].norm = glm::normalize(0.5f*((vertices[(y*width+(x+1))].norm + 0.5f*(n1+n2))));
            vertices[(y+1)*width+(x+1)].norm = glm::normalize(0.5f*(vertices[(y+1)*width+(x+1)].norm + n1));//v6

        }
    }*/
    vbo.allocate(vertices.data(),sizeof(Vertex)*width*height);
}

void Canvas::setDimensions(unsigned width,unsigned height)
{
    this->makeCurrent();
    this->width = width;
    this->height = height;

    //Create Indexbuffer with new dimensions
    if(index.isCreated())
    {
        index.bind();
        index.destroy();
    }
    index = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    index.create();
    index.setUsagePattern(QOpenGLBuffer::StaticDraw);
    index.bind();

    indices.clear();

    for(unsigned y=0;y<height-1;y++)
    {
        for(unsigned x=0;x<width-1;x++)
        {
            indices.push_back(y*width+x);
            indices.push_back((y+1)*width+x);
            indices.push_back(y*width+(x+1));

            indices.push_back(y*width+(x+1));
            indices.push_back((y+1)*width+x);
            indices.push_back((y+1)*width+(x+1));
        }
    }
    index.allocate(indices.data(),sizeof(unsigned)*indices.size());
}

void Canvas::setPatchSize(unsigned patchSize)
{
    this->patchSize = patchSize;
}

void Canvas::keyPressEvent(QKeyEvent* event)
{
    qDebug()<<"KEYPRESS";
    switch(event->key())
    {
    case Qt::Key_W:
        camera.strafeZ(-1.0);
        break;
    case Qt::Key_S:
        camera.strafeZ(1.0);
        break;
    case Qt::Key_A:
        camera.strafeX(-1.0);
        break;
    case Qt::Key_D:
        camera.strafeX(1.0);
        break;
    case Qt::Key_PageUp:
        camera.strafeY(1.0);
        break;
    case Qt::Key_PageDown:
        camera.strafeY(-1.0);
        break;
    case Qt::Key_Down:
        camera.roll(-1.0);
        break;
    case Qt::Key_Up:
        camera.roll(1.0);
        break;
    case Qt::Key_Right:
        camera.yaw(1.0);
        break;
    case Qt::Key_Left:
        camera.yaw(-1.0);
        break;
    }
}

void Canvas::initializeGL()
{
    vao.create();
    vao.bind();

    QOpenGLShader vs(QOpenGLShader::Vertex);
    QOpenGLShader fs(QOpenGLShader::Fragment);
    if(!vs.compileSourceFile("shaders/effect.vs"))
    {
        qDebug()<<vs.log();
    }

    if(!fs.compileSourceFile("shaders/effect.fs"))
    {
        qDebug()<<fs.log();
    }
    program.addShader(&vs);
    program.addShader(&fs);
    if(!program.link())
    {
        qDebug()<<program.log();
    }
    program.bind();

    glClearDepth(1.0);
    glClearColor(0.8,0.8,1.0,1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glCullFace(GL_CW);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void Canvas::resizeGL(int w,int h)
{
    glViewport(0,0,w,h);
    if(h!=0.0)
    {
        matProj = glm::perspective<float>(glm::radians(45.0f),(float)w/(float)h,0.1f,100.0f);
    }
    else
    {
        matProj = glm::perspective<float>(glm::radians(45.0f),(float)w/1.0f,0.1f,100.0f);
    }
}

void Canvas::paintGL()
{
    this->makeCurrent();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    program.bind();
    vao.bind();
    vbo.bind();
    index.bind();

    glm::mat4 view = camera.lookAt();
    glm::mat3 normalMatrix = glm::transpose(glm::inverse(glm::mat3(glm::transpose(view))));
    glm::mat4 proj = glm::transpose(matProj);
    glm::vec4 eye = glm::vec4(camera.getPosition(),1.0);
    program.setAttributeBuffer("vertex",GL_FLOAT,0,3,sizeof(Vertex));
    program.enableAttributeArray("vertex");

    program.setAttributeBuffer("normal",GL_FLOAT,sizeof(float)*3,3,sizeof(Vertex));
    program.enableAttributeArray("normal");

    uploadLight(light,0);
    program.setUniformValue("numLights",1);

    glm::vec3 ambient = mat.getAmbient();
    glm::vec3 diffuse = mat.getDiffuse();
    glm::vec3 specular = mat.getSpecular();
    float shininess = mat.getShininess();
    program.setUniformValueArray("material.amb",glm::value_ptr(ambient),1,3);
    program.setUniformValueArray("material.dif",glm::value_ptr(diffuse),1,3);
    program.setUniformValueArray("material.spec",glm::value_ptr(specular),1,3);
    program.setUniformValue("material.shininess",shininess);

    program.setUniformValueArray("eye",glm::value_ptr(eye),1,3);
    program.setUniformValue("projection",QMatrix4x4(glm::value_ptr<float>(proj)));
    program.setUniformValue("view",QMatrix4x4(glm::value_ptr<float>(view)));
    program.setUniformValue("normalMatrix",QMatrix3x3(glm::value_ptr<float>(normalMatrix)));

    glDrawElements(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0);
}
