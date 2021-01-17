#include "Point3d.h"
#include "Vector3d.h"
int main()
{
	Point3d p{1.0, 2.0, 3.0};
	Vector3d v{2.0, 2.0, -3.0};
    p.print();
    p.move_by_vector(v);
    p.print();
    return 0;
}