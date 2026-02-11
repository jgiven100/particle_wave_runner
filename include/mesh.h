#ifndef PWR_MESH_H
#define PWR_MESH_H

#include <cstddef>

#include "mesh_base.h"

namespace pwr {

// Mesh class
// Store information about particles, nodes, cells, and neighbors
class Mesh : public MeshBase {
   public:
    // ------------------------------------------------------------------------
    // Constructor
    // ------------------------------------------------------------------------
    Mesh(double x_min, double y_min, double z_min, double x_max, double y_max,
         double z_max, size_t nx, size_t ny, size_t nz)
        : x_min_(x_min),
          y_min_(y_min),
          z_min_(z_min),
          x_max_(x_max),
          y_max_(y_max),
          z_max_(z_max),
          nx_(nx),
          ny_(ny),
          nz_(nz) {
        // Initialized, partition, and check mesh
        InitializeMesh_();
        PartitionMesh_();
        CheckMesh_();
    }

    // ------------------------------------------------------------------------
    // Constructor delegation
    // ------------------------------------------------------------------------
    Mesh(double x_max, double y_max, double z_max, size_t nx, size_t ny,
         size_t nz)
        : Mesh(0., 0., 0., x_max, y_max, z_max, nx, ny, nz) {}

    // ------------------------------------------------------------------------
    // Constructor delegation
    // ------------------------------------------------------------------------
    Mesh(size_t nx, size_t ny, size_t nz)
        : Mesh(0., 0., 0., 1., 1., 1., nx, ny, nz) {}

    // ------------------------------------------------------------------------
    // Destructor
    // ------------------------------------------------------------------------
    ~Mesh() = default;

    // ------------------------------------------------------------------------
    // Delete copy constructor
    // ------------------------------------------------------------------------
    Mesh(const Mesh&) = delete;

    // ------------------------------------------------------------------------
    // Delete copy assignment
    // ------------------------------------------------------------------------
    Mesh& operator=(const Mesh&) = delete;

   private:
    // ------------------------------------------------------------------------
    // Initialize mesh
    // ------------------------------------------------------------------------
    void InitializeMesh_();

    // ------------------------------------------------------------------------
    // Partition mesh
    // ------------------------------------------------------------------------
    void PartitionMesh_();

    // ------------------------------------------------------------------------
    // Check mesh
    // ------------------------------------------------------------------------
    void CheckMesh_();

    // Minimum x-dir
    double x_min_;

    // Minimum y-dir
    double y_min_;

    // Minimum z-dir
    double z_min_;

    // Maximum x-dir
    double x_max_;

    // Maximum y-dir
    double y_max_;

    // Maximum z-dir
    double z_max_;

    // Number of elements x-dir
    size_t nx_;

    // Number of elements y-dir
    size_t ny_;

    // Number of elements z-dir
    size_t nz_;
};

}  // namespace pwr
#endif  // PWR_MESH_H
