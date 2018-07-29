#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tag_tree_node
{
    char *key;
    char *val;
    struct _tag_tree_node *left;
    struct _tag_tree_node *right;
} tree_node;

tree_node *tree_root = NULL;

tree_node* create_new_node(char *key, char *val) {
    tree_node *tree_new;

    tree_new = (tree_node*)malloc(sizeof(tree_node));
    if(tree_new == NULL) {
        exit(EXIT_FAILURE);
    }
    tree_new->left = NULL;
    tree_new->right = NULL;
    tree_new->key = (char*)malloc(sizeof(char) * strlen(key) + 1);
    tree_new->val = (char*)malloc(sizeof(char) * strlen(val) + 1);
    if(tree_new->key == NULL || tree_new->val == NULL) {
        exit(EXIT_FAILURE);
    }

    strcpy(tree_new->key, key);
    strcpy(tree_new->val, val);

    return tree_new;
}

void insert_tree(char *key, char *val, tree_node *node) {
    if(node == NULL) {
        tree_root = create_new_node(key, val);
        return;
    }

    if(strcmp(node->key, key) > 0) {
        if(node->left != NULL) {
            insert_tree(key, val, node->left);
        } else {
            node->left = create_new_node(key, val);
        }
    } else {
        if(node->right != NULL) {
            insert_tree(key, val, node->right);
        } else {
            node->right = create_new_node(key, val);
        }
    }

    return;
}

tree_node* find_key(tree_node* node, char* val) {
    int cmp = strcmp(node->key, val);
    if(cmp > 0) {
        if(node->left == NULL) {
            return NULL;
        }
        return find_key(node->left, val);
    }

    if(cmp < 0) {
        if(node->right == NULL) {
            return NULL;
        }
        return find_key(node->right, val);
    }

    return node;
}

int delete_tree(char *val) {
    tree_node *node = tree_root, *parent_node = NULL;
    tree_node *left_biggest;
    int direction = 0, cmp;

    while(node != NULL && (cmp = strcmp(node->key, val)) != 0) {
        if(cmp > 0) {
            parent_node = node;
            node = node->left;
            direction = -1;
        } else {
            parent_node = node;
            node = node->right;
            direction = 1;
        }
    }

    if(node == NULL) {
        return 0;
    }

    if(node->left == NULL || node->right == NULL) {
        if(node->left == NULL) {
            if(direction == -1) {
                parent_node->left = node->right;
            }
            if(direction == 1) {
                parent_node->right = node->right;
            }
            if(direction == 0) {
                tree_root = node->right;
            }
        } else {
            if(direction == -1) {
                parent_node->left = node->left;
            }
            if(direction == 1) {
                parent_node->right = node->left;
            }
            if(direction == 0) {
                tree_root = node->left;
            }
        }

        free(node->key);
        free(node);
    } else {
        left_biggest = node->left;
        parent_node = node;
        direction = -1;
        while(left_biggest->right != NULL) {
            parent_node = left_biggest;
            left_biggest = left_biggest->right;
            direction = 1;
        }

        free(node->key);
        node->key = left_biggest->key;

        if(direction == -1) {
            parent_node->left = left_biggest->left;
        } else {
            parent_node->right = left_biggest->left;
        }
        free(left_biggest);
    }

    return 1;
}

void print_tree(int depth, tree_node* node) {
    int i;

    if(node == NULL) {
        return;
    }
    print_tree(depth + 1, node->left);
    for(i = 0; i < depth; i++) {
        printf("   ");
    }
    printf("%s :%s \n", node->key, node->val);
    print_tree(depth + 1, node->right);
}

void free_tree(tree_node* node) {
    if(node == NULL) {
        return;
    }
    free_tree(node->left);
    free_tree(node->right);
    free(node->key);
    free(node->val);
    free(node);
}

int main(void) {
    int i, action;
    char tmp[256], tmpval[256];
    tree_node *node_found;

    for(;;) {
        print_tree(0, tree_root);
        printf("0:終了,1:挿入,2:探索,3:削除>");
        scanf("%d", &i);
        if(i == 0) break;
        switch(i) {
            case 1:
                printf("挿入する文字列(キー)");
                scanf("%s", tmp);
                printf("キーに対応させる値:>");
                scanf("%s", tmpval);
                insert_tree(tmp, tmpval, tree_root);
                break;
            case 2:
                printf("検索する文字列:");
                scanf("%s", tmp);
                node_found = find_key(tree_root, tmp);
                if(node_found != NULL) {
                    printf("対応する値は%sです\n", node_found->val);
                } else {
                    printf("見つかりませんでした\n");
                }
                break;
            case 3:
                printf("削除する文字列[:");
                scanf("%s", tmp);
                if(delete_tree(tmp) == 1) {
                    printf("削除しました");
                } else {
                    printf("見つかりませんでした");
                }
                break;
        }
    }
    free_tree(tree_root);
    return EXIT_SUCCESS;
}
