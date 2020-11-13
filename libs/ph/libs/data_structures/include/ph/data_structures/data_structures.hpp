#pragma once
namespace ph::data_structures
{

template <class Vertex, class Edge>
class Graph
{
      using Vertices = vector<Vertex>;
      using Edges = vector<Edge>;
private:
      Vertices m_vertices;
      Edges m_edges;
      
public:
      Graph (const Vertices& vertices, const Edges& edges) : m_vertices(vertices), m_edges(edges)
      {
            
      }
      
      // The set of vertices of a graph G
      Vertices& vertices ()
      {
            return m_vertices;
      }
      
      // The set of edges of a graph G
      Edges& edges ()
      {
            return m_edges;
      }
      
      
  
      
};


}
