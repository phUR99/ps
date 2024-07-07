#include <string>
#include <vector>

using namespace std;

struct node{
    node *left = NULL, *right = NULL;
    int x, num;    
};

vector<pair<int, int>> level[100005];
vector<int> pre, post;

///////////////////////////////////////////
void maketree(node* &nodeptr, int x, int num){
    if(nodeptr== NULL){
        node *leaf = new node;
        leaf->x = x;
        leaf->num = num;      
        nodeptr = leaf;          
        return;
    }
    else{
        if(nodeptr->x > x){
            maketree(nodeptr->left, x, num);            
        }
        else{
            maketree(nodeptr->right, x, num);            
        }
    }
}
void preorder(node* nodeptr){
    if(nodeptr == NULL) return;
    pre.push_back(nodeptr->num);
    preorder(nodeptr->left);
    preorder(nodeptr->right);
}
void postorder(node* nodeptr){
    if(nodeptr == NULL) return;    
    postorder(nodeptr->left);
    postorder(nodeptr->right);
    post.push_back(nodeptr->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int height = 0;    
    for(int i = 0; i < nodeinfo.size(); i++){
        level[nodeinfo[i][1]].push_back({nodeinfo[i][0], i+1});        
        height = max(height, nodeinfo[i][1]);
    }    
    node *root = new node;    
    root->x = level[height][0].first;
    root->num = level[height][0].second;
    
    for (int i = height-1; i >= 0; i--){
        for(auto child : level[i]){
            maketree(root, child.first, child.second);
        }
    }
    preorder(root); postorder(root);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}