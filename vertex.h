#ifndef VERTEX_H
#define VERTEX_H
#include<glm/glm.hpp>


class Vertex
{
public:
    Vertex();
    Vertex(const glm::vec3& pos,const glm::vec3& norm);
    glm::vec3 pos;
    glm::vec3 norm;
};

#endif // VERTEX_H
