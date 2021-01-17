#include "Point3d.h"
#include "Vector3d.h"
#include <iostream>

void Point3d::print() const 
{
    std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}

void Point3d::move_by_vector(const Vector3d &vector3d)
{
    m_x += vector3d.m_x;
    m_y += vector3d.m_y;
    m_z += vector3d.m_z;
    vector3d.print();
}