#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalsort(const vector<list<int>> &adjacencylist, vector<int> indegree)
{
  vector<int> ans;
  ans.reserve(indegree.size() + 1);
  //list to store vertices with indegree 0
  list<int> indegree0;
  for (size_t i = 1; i < indegree.size(); i++)
  {
    if (indegree[i] == 0)
      indegree0.push_back(i);
  }
  while (!indegree0.empty())
  {
    const int x = indegree0.front();
    indegree0.pop_front();
    ans.push_back(x);
    for (const int i : adjacencylist[x])
    {
      if (--indegree[i] == 0)
        indegree0.push_back(i);
    }
  }
  return ans;
}

int main()
{
  int v, e;
  cin >> v >> e;
  vector<list<int>> adjacencylist(v + 1);
  vector<int> indegree(v + 1);
  for (int i = 1; i <= e; i++)
  {
    int v1, v2;
    cin >> v1 >> v2;
    adjacencylist[v1].push_back(v2);
    ++indegree[v2];
  }
  for (int i = 1; i <= v; i++)
  {
    cout << "Adjacency List[" << i << "%d] :";
    for (int j : adjacencylist[i])
    {
      cout << j << "  ";
    }
    cout << endl;
  }
  auto const &ans = topologicalsort(adjacencylist, move(indegree));
  for (int i : ans)
    cout << i << "  ";
}
