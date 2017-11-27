#ifndef CAMERA_H
#define CAMERA_H
#include<glm/glm.hpp>
#include<QMatrix4x4>
#include<QVector3D>

class Camera
{
public:
    Camera();
    glm::mat4 lookAt();

    void strafeX(float x);
    void strafeY(float y);
    void strafeZ(float z);

    void roll(float angle);
    void pitch(float angle);
    void yaw(float angle);

    void reset();

    glm::vec3 getPosition();
    glm::vec3 getViewingNormal();
private:
    glm::vec3 s;
    glm::vec3 u;
    glm::vec3 v;


    glm::vec3 pos;
};

#endif // CAMERA_H
