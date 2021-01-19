class Solution {
public: 
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result ;
        
        
         if(root == NULL)
         {return result; }  
        
        queue<TreeNode> q ; 
        q.push(root); 
        while(!queue.empty())
        {
         int size =q.size();
         vector<int> currentLevel;
         for(int i = 0;i<size;i++) 
         {
             TreeNode* currentNode = q.pop(); 
             currentLevel.push_back(currentNode->val); 
             if(currentNode->left!=NULL)
             {
                q.push(currentNode); 
                 
             }
             if(currentNode->right != NULL)
             {
                q.push(currentNode); 
             }
             result.push_back(currentLevel); 
         }
        }
        

        
        return result ; 
        
    }
};