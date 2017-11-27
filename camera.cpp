#include "camera.h"
#include <glm/gtx/transform.hpp>

Camera::Camera()
{
    reset();
}

glm::mat4 Camera::lookAt()
{
    glm::mat4 ret(s.x,s.y,s.z,glm::dot(s,-pos),
                   u.x,u.y,u.z,glm::dot(u,-pos),
                   v.x,v.y,v.z,glm::dot(v,-pos),
                   0,0,0,1);
    return ret;
}

void Camera::strafeX(float x)
{
    glm::vec3 n = glm::cross(glm::vec3(0.0,1.0,0.0),v);
    pos+=x*n;
}

void Camera::strafeY(float y)
{
    pos+=y*glm::vec3(0.0,1.0,0.0);
}

void Camera::strafeZ(float z)
{

    pos+=z*v;
}

void Camera::yaw(float angle)
{
    glm::mat4 rot;
    rot = glm::rotate(rot,glm::radians(angle),u);
    s = glm::vec3(rot*glm::vec4(s,1.0));
    v = glm::vec3(rot*glm::vec4(v,1.0));
}


void Camera::roll(float angle)
{
    glm::mat4 rot;
    rot = glm::rotate(rot,glm::radians(angle),s);
    u = glm::vec3(rot*glm::vec4(u,1.0));
    v = glm::vec3(rot*glm::vec4(v,1.0));
}

void Camera::reset()
{
    s = glm::vec3(1.0,0.0,0.0);
    u = glm::vec3(0.0,1.0,0.0);
    v = glm::vec3(0.0,0.0,1.0);
}

glm::vec3 Camera::getPosition()
{
    return pos;
}

glm::vec3 Camera::getViewingNormal()
{
    return v;
}
