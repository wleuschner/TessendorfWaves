#include "vertex.h"

Vertex::Vertex()
{
}

Vertex::Vertex(const glm::vec3& pos,const glm::vec3& norm)
{
    this->pos = pos;
    this->norm = norm;
}
