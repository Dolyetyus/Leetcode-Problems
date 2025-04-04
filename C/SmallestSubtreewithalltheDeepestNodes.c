struct TraversalState {
    struct TreeNode *deepest1;
    int depth1;
    struct TreeNode **path1;
    struct TreeNode *deepest2;
    int depth2;
    struct TreeNode **path2;
};

void traverse(struct TreeNode* root, int depth, struct TreeNode*** temppath, struct TraversalState* state) {
    if (root == NULL) return;

    struct TreeNode** new_temppath = realloc(*temppath, (depth + 1) * sizeof(struct TreeNode*));
    if (!new_temppath) return;
    *temppath = new_temppath;
    (*temppath)[depth] = root;

    traverse(root->left, depth + 1, temppath, state);

    if (depth > state->depth1) {
        // Update first deepest path
        state->deepest1 = root;
        state->depth1 = depth;
        free(state->path1);
        state->path1 = malloc((depth + 1) * sizeof(struct TreeNode*));
        memcpy(state->path1, *temppath, (depth + 1) * sizeof(struct TreeNode*));
        
        // Reset second deepest
        state->deepest2 = NULL;
        state->depth2 = 0;
        free(state->path2);
        state->path2 = NULL;
    } 
    else if (depth == state->depth1) {
        // Update second deepest path
        state->deepest2 = root;
        state->depth2 = depth;
        free(state->path2);
        state->path2 = malloc((depth + 1) * sizeof(struct TreeNode*));
        memcpy(state->path2, *temppath, (depth + 1) * sizeof(struct TreeNode*));
    }

    traverse(root->right, depth + 1, temppath, state);
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    struct TraversalState state = {
        .deepest1 = NULL,
        .depth1 = 0,
        .path1 = NULL,
        .deepest2 = NULL,
        .depth2 = 0,
        .path2 = NULL
    };
    
    struct TreeNode** temppath = NULL;
    traverse(root, 0, &temppath, &state);
    
    free(temppath);

    if (state.depth1 == 0) return root;
    
    if (state.deepest2 == NULL) {
        free(state.path2);
        return state.deepest1;
    }
    
    int lca_depth = 0;
    for (; lca_depth < state.depth1; lca_depth++) {
        if (state.path1[lca_depth] != state.path2[lca_depth]) break;
    }
    
    struct TreeNode* result = lca_depth > 0 ? state.path1[lca_depth - 1] : state.path1[0];
    
    free(state.path1);
    free(state.path2);
    
    return result;
}
