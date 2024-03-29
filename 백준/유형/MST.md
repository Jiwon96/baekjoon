# MST
* MST는 최소비용으로 spanning tree를 만드는 것
* 방법:
  *  Prim Algorithm
     *  노드를 speciality로 최소 간선을 수집하면서 트리를 구성함
      *  Time complexity = theta(V^2 or VlogE)
      *  [알고리즘 참고](https://www.weeklyps.com/entry/%ED%94%84%EB%A6%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Prims-algorithm)
      *  [알고리즘 참고 VlogE](https://4legs-study.tistory.com/112)
  *  Kruskal algorithm
     *  간선을 speciality로 최소 간선을 수집하면서 트리를 구성함
      *  Time complexity = theta(ElogE)
      *  [알고리즘 참고](https://swblossom.tistory.com/51)
      *  
* speiclity -
  *  Tree를 만드는 것이므로 Union-Find 알고리즘이 필요하다.
  *  루트가 같은지가 speiclaity
  *  Prim과 Kruskal의 data struct로 주의깊게 볼 필요 있음.
     * prim은 노드 기반이기 때문에 vector를 2차원으로 만듬 ex) vector<int> v[N]
     * 하지만 kruskal은 edge 기반이기 때문에 priority_queue< edge weight, {node1, node2}> pq를 만든 다음에 edge로 정렬을 해서 union_find 응용하면서 트리를 만들어감
