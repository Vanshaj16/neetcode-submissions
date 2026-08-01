class Solution {
public:
    vector<string> res;
    int n,m;
    vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
    struct trieNode{
        bool endNode;
        string word;
        trieNode* children[26];
    };
    trieNode* getNode(){
        trieNode* temp=new trieNode();
        temp->endNode=false;
        for(int i=0;i<26;i++){
            temp->children[i]=NULL;
        }
        temp->word="";
        return temp;
    }
    void insert(trieNode* root,string str){
        trieNode* pCrawl=root;
        for(char ch:str){
            if(pCrawl->children[ch-'a']==NULL){
                pCrawl->children[ch-'a']=getNode();
            }
            pCrawl=pCrawl->children[ch-'a'];
        }
        pCrawl->endNode=true;
        pCrawl->word=str;
    }
    void dfs(vector<vector<char>>& board,int i,int j,trieNode* root){
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='#' || root->children[board[i][j]-'a']==NULL){
            return;
        }
        root=root->children[board[i][j]-'a'];
        if(root->endNode==true){
            res.push_back(root->word);
            root->endNode=false;
        }
        char temp=board[i][j];
        board[i][j]='#';
        for(auto& it:dir){
            int r=i+it[0];
            int c=j+it[1];
            dfs(board,r,c,root);
        }
        board[i][j]=temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size();
        m=board[0].size();
        trieNode* root=getNode();
        for(string str:words){
            insert(root,str);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=board[i][j];
                if(root->children[ch-'a']!=NULL){
                    dfs(board,i,j,root);
                }
            }
        }
        return res;
    }
};
