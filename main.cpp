#include <iostream>
#include <set>
#include <string>
#include <vector>;
using namespace std;

set<int> getpossible(int max, int id, vector<int> pos){
    set<int> possible;
    vector<int> prestep;
    vector<int> nextstep;
    
    prestep.push_back(id);
    
    for(int i=0; i<pos.size(); i++){
        int step = pos[i];
        for(int j=0; j<prestep.size(); j++){
            int curr = prestep[i];
            if(curr - step > 0){
                possible.insert(curr - step); 
                nextstep.push_back(curr - step);
            }
            if(curr + step <= max){
                possible.insert(curr + step); 
                nextstep.push_back(curr + step);
            }
        }
        prestep = nextstep;
        nextstep.clear();
    }
    return possible;
}

int main(){
    
    int N,M,D;
    vector<int> listD;
    
	cin >> N >> M;
    
    for(int i=0; i<M; i++){
        cin >> D;
        listD.push_back(D);
    }
    
    set<int> result;
    set<int> cache;
    for(int i = 1; i<= M; i++){
        cache = getpossible(N, i, listD);
        for(set<int>::iterator item = cache.begin(); item!= cache.end(); item++){
            result.insert(*item);
        }
    }
    
	cout << result.size() << endl;

	return 0;
}