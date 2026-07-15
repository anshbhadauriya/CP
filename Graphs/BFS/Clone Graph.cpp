/*
agr infuture conusion ho iss ques me so revise https://leetcode.com/problems/copy-list-with-random-pointer/description/

do it in same way as clone linked list

intuition is simple but implementation is tricky:

sbse pehle sare node me visit kro 
visit krte time sare node ka copy banao
mp[original] -> copy

abh dusri baar sare node visit kro
abh mp[original] ke neighbours use krke copy ke neighbours connect kro
example->

mp[original ke neighbour] gives address of copied ke neighbour

so just push mp[curr] (mtlb copy  wala curr) ->neighbour.push_back( mp[origianl ka neighbour])


*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(!node) return NULL;

        unordered_map<Node*,Node*>mp;

        queue<Node*>q;

        q.push(node);

        mp[node]= new Node(node->val);

        while(!q.empty()){

            auto curr=q.front();
            q.pop();

            for(auto x:curr->neighbors){
                if(!mp.count(x)){
                mp[x]=new Node(x->val);
                q.push(x);
                }
            }

        }

        while(!q.empty()) q.pop();  //queue ko clear kro

        q.push(node);

        unordered_set<Node*>visited;

        visited.insert(node);

        while(!q.empty()){

            auto curr=q.front();
            q.pop();

            for(auto x:curr->neighbors){

                auto copy=mp[curr];
                copy->neighbors.push_back(mp[x]); // har original edge ko clone graph me copy karna hai

                if(!visited.count(x)){

                    q.push(x);

                    visited.insert(x);

                }

            }
        }

        return mp[node];



    }
};

/*
TC-> O(V+E)  2 bar bfs kra hai
SC-> O(V)
*/
