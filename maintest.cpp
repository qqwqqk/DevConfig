#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <vector>;
using namespace std;

class Edge{
public:
	int role, lang;
	Edge(int r, int l){ role = r; lang = l;}
};

class Network{
public:
	set<int> nodeA;
	set<int> nodeB;
};

int main(){
	vector<Edge> edgeCache;
	set<int> nodeCacheA;
	set<int> nodeCacheB;
	vector<Network> result;
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		Edge item(a,b);
		edgeCache.push_back(item);
		nodeCacheA.insert(a);
		nodeCacheB.insert(b);
	}

	while (!nodeCacheA.empty() && !nodeCacheB.empty()){
		Network subNetwork;
		set<int>::iterator iter = nodeCacheA.begin();
		subNetwork.nodeA.insert(*iter);
		nodeCacheA.erase(iter);
		int length = 0;

		while (1){
			length = subNetwork.nodeB.size();

			for (int i = 0; i < edgeCache.size();){
				iter = subNetwork.nodeA.find(edgeCache[i].role);
				if (iter != subNetwork.nodeA.end()){
					iter = subNetwork.nodeB.find(edgeCache[i].lang);
					if (iter == subNetwork.nodeB.end()){ subNetwork.nodeB.insert(edgeCache[i].lang); }

					iter = nodeCacheB.find(edgeCache[i].lang);
					if (iter != nodeCacheB.end()){ nodeCacheB.erase(iter); }

					edgeCache.erase(edgeCache.begin() + i);
				}
				else {
					i++;
				}
			}

			if (subNetwork.nodeB.size() == length){ break; }
			
			for (int i = 0; i < edgeCache.size();){
				iter = subNetwork.nodeB.find(edgeCache[i].lang);
				if (iter != subNetwork.nodeB.end()){
					iter = subNetwork.nodeA.find(edgeCache[i].role);
					if (iter == subNetwork.nodeA.end()){ subNetwork.nodeA.insert(edgeCache[i].role); }

					iter = nodeCacheA.find(edgeCache[i].role);
					if (iter != nodeCacheA.end()){ nodeCacheA.erase(iter); }

					edgeCache.erase(edgeCache.begin() + i);
				}
				else {
					i++;
				}
			}

			}
		result.push_back(subNetwork);
	}

	cout << result.size() << endl;

	return 0;
}