Kosaraju's algorithm finds all the Strongly Connected Components (SCCs) in a directed graph.

It does not just tell whether the graph is strongly connected.

######### works in Directed graph only ########
What is a Strongly Connected Component (SCC)?

An SCC is a maximal group of vertices such that:

Every vertex can reach every other vertex in the group.
In other words, for any two vertices u and v in the SCC:
u → v is possible.
v → u is also possible.

<img width="1073" height="438" alt="image" src="https://github.com/user-attachments/assets/65a9e588-d12b-41cb-8bbd-35fe1a3b3019" />


But how to actually find these strongly connected components?

so when we do dfs to find these component and lets suppose we start traversing from B and go like B-C-A-B then B is already visited now B goes to other neighbor so how can u stop
this here and not let our dfs call go to D
so we can reverse the edge from B to D to stop over traversal to go to D
but yeh kaise pta chlega ki B to D wali hi edge ko reverse krna hai 
so we can reverse all edges of graph
But isme bhi ek problem hai!!

agr kisi ne E se dfs shuru kra so notice ki same cheez abh D to B edge ke lie hogi 


<img width="1043" height="337" alt="image" src="https://github.com/user-attachments/assets/e59b128d-88eb-464c-aaa3-655407ac7b8e" />

so now what to do?

if u notice ki agr pehle B se dfs krke A B C ko visited mark krlete too agr fir D se krte DFS too fir agr DFS call B ki trf jati so ham check krlete ki kya B already visited hai
agr already visited hai so need to go there
so ham yeh kr skte hai 
lekin abh yeh kaise pta chlega ki pehle B ki trf se traverse kro then D wali side
bcs ham we know ham B se D nhi ja skte lekin D se B ja skte hai so there is a dependecy D->B

so how to know all these dependecies????

## TOPOLOGICAL SORT !!
topo logical sort says ki pehle baccho (childrens) ko stack me daldo then parent 

<img width="1598" height="975" alt="image" src="https://github.com/user-attachments/assets/582e91a0-9025-4879-8707-c70f8eb73b20" />

<img width="557" height="712" alt="image" src="https://github.com/user-attachments/assets/84b415cb-359a-411f-af42-209c46c9e46d" />

reverse isslie taki parent last me aajae aur children pehle 


after toposort stack will look like this

<img width="1072" height="691" alt="image" src="https://github.com/user-attachments/assets/5ef28e88-a58a-4253-b4e8-cc0b716442b5" />

abh stack ke top se down ke form me dfs kro simply 


<img width="1065" height="683" alt="image" src="https://github.com/user-attachments/assets/e5e3e400-965d-4f29-8475-eeb148e9bf86" />

H->I->G->J abh J se kahi aur nhi ja skte mtlb ek strongly conntected component (SCC) mil gya 
so abh K se J nhi ja skte bcs that component is already visited
so K alone is strongly connected component

<img width="1071" height="667" alt="image" src="https://github.com/user-attachments/assets/c8f3bfd1-596d-436c-8854-d7ec00c8b1ba" />

<img width="1077" height="675" alt="image" src="https://github.com/user-attachments/assets/4f49192f-a03b-4b53-b02f-f2f5780f879f" />

<img width="1068" height="682" alt="image" src="https://github.com/user-attachments/assets/a5c64ae7-f7e9-4363-b985-ec4f931a636c" />













