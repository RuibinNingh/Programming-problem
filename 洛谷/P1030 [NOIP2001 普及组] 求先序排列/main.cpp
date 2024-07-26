#include <iostream>
#include <string>
using namespace std;

void buildPreOrder(string in, string post, int inStart, int inEnd, int postStart, int postEnd, char pre[], int &preIndex) {
	if (inStart > inEnd) return;
	
	// 后序遍历的最后一个元素是当前子树的根节点
	char root = post[postEnd];
	pre[preIndex++] = root;
	
	// 在中序遍历中找到根节点的位置
	int rootIndex = in.find(root, inStart);
	
	// 递归构建左子树和右子树
	buildPreOrder(in, post, inStart, rootIndex - 1, postStart, postStart + (rootIndex - inStart) - 1, pre, preIndex);
	buildPreOrder(in, post, rootIndex + 1, inEnd, postStart + (rootIndex - inStart), postEnd - 1, pre, preIndex);
}

int main() {
	string inOrder, postOrder;
	cin >> inOrder >> postOrder;
	
	char preOrder[8];  // 先序遍历结果
	int preIndex = 0;  // 先序遍历数组的当前索引
	
	buildPreOrder(inOrder, postOrder, 0, inOrder.size() - 1, 0, postOrder.size() - 1, preOrder, preIndex);
	
	for (int i = 0; i < inOrder.size(); i++) {
		cout << preOrder[i];
	}
	cout << endl;
	
	return 0;
}

