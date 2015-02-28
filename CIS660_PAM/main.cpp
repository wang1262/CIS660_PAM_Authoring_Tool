//
//  main.cpp
//

#include <iostream>


void polarize_mesh(Manifold& m, VertexAttributeVector<double>& fun, double vmin, double vmax, const int divisions)
{
    
}


void smooth_and_refit(HMesh::Manifold& m_in,  HMesh::Manifold& m_ref, int iter, double alpha, bool preserve_poles)
{
    smooth_geodesic(m_in, m_ref);
}



int main(int argc, const char * argv[])
{
    const int DIVISIONS = 100;
    Manifold m_in;
    string file_name = argv[1];
    HMesh::load(file_name, m_in);
    Manifold m_out = m_in;
    
    object f = VertexAttributeVector<double>(m_out.allocated_vertices(),0);
    string str = file_name + "-assigned.txt";
    ifstream ifs(str.c_str());
    double extremum, vmin=1e32, vmax=-1e32;
    for(VertexID v: m_out.vertices()) {
        ifs >> extremum >> f[v];
        vmin = min(vmin, f[v]);
        vmax = max(vmax, f[v]);
    }
    
    cout << "polarizing" << endl;
    //polarize_mesh(m_out, f, vmin, vmax, DIVISIONS);
    
    cout << "refitting" << endl;
    //smooth_and_refit(m_out, m_in, 1, 0.5, true);

    //obj_save(m_out);
}

