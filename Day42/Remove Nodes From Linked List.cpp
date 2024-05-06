class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* current = head;

        while (current != nullptr) {
            st.push(current);
            current = current->next;
        }

        current = st.top();
        st.pop();
        int maximum = current->val;
        ListNode* resultHead = new ListNode(maximum);

        while (!st.empty()) {
            current = st.top();
            st.pop();
            if (current->val < maximum) {
                continue;
            }
            else {
                ListNode* newNode = new ListNode(current->val);
                newNode->next = resultHead;
                resultHead = newNode;
                maximum = current->val;
            }
        }

        return resultHead;
    }
};
