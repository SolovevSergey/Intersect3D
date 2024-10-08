#include "test.h"


static void OnPlaneSegmentOneExist(const Vector3D& A, const Vector3D& B, double alpha, double beta) {
    if (A.is_parallel_to(B)) {
        return;
    }
    if (alpha > 1 || beta > 1 || alpha < 0 || beta < 0) return;
    TestOneExist(A * (alpha - 1), A * alpha, B * (beta - 1), B * beta, Vector3D(0, 0, 0));
}

static void OnPlaneSegmentNotExist(const Vector3D& A, const Vector3D& B) {
    if (A.is_parallel_to(B)) {
        return;
    }
    TestNotExist(A * 1, A * 2, B * 1, B * 2);
}


TEST(SegmentOnPlane, OneExist) {
    OnPlaneSegmentOneExist(Vector3D(1, 0, 0), Vector3D(0, 1, 0), 0, 0);
    OnPlaneSegmentOneExist(Vector3D(1, 1, 0), Vector3D(0, 0, 1), 1, 0);
    OnPlaneSegmentOneExist(Vector3D(1, 0, 3), Vector3D(1, 0, 0), 1, 1);
    OnPlaneSegmentOneExist(Vector3D(1, 3, 4), Vector3D(1, 1, 1), 0, 0);
    OnPlaneSegmentOneExist(Vector3D(1, 0, 0), Vector3D(3, 1, 0), 1, 1);
    OnPlaneSegmentOneExist(Vector3D(1, 0, 1e-4), Vector3D(7, 0, 1e4), 0, 1);
    OnPlaneSegmentOneExist(Vector3D(1, 1e4, 0), Vector3D(0, 1e-4, 1.9), 1, 0);
    OnPlaneSegmentOneExist(Vector3D(1, 23, 45), Vector3D(1e4, 1e-4, 0),  0, 1);
}

TEST(SegmentOnPlane, NotExist) {
    OnPlaneSegmentNotExist(Vector3D(1, 0, 0), Vector3D(0, 1, 0));
    OnPlaneSegmentNotExist(Vector3D(1, 1, 0), Vector3D(0, 0, 1));
    OnPlaneSegmentNotExist(Vector3D(1, 0, 3), Vector3D(1, 0, 0));
    OnPlaneSegmentNotExist(Vector3D(1, 3, 4), Vector3D(1, 1, 1));
    OnPlaneSegmentNotExist(Vector3D(1, 0, 0), Vector3D(1.3, 0, 0));
    OnPlaneSegmentNotExist(Vector3D(1, 0, 1e-4), Vector3D(7, 0, 1e4));
    OnPlaneSegmentNotExist(Vector3D(1, 1e4, 0), Vector3D(0, 1e-4, 1.9));
    OnPlaneSegmentNotExist(Vector3D(1, 23, 45), Vector3D(1e4, 1e-4, 0));
}