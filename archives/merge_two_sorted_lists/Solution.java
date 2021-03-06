package merge_two_sorted_lists;

import util.singly_linked_list.ListNode;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * Created by Zhiyong Pan on 2021-01-04.
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode p = dummyHead;

        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                p.next = l1;
                l1 = l1.next;
            } else {
                p.next = l2;
                l2 = l2.next;
            }
            p = p.next;
        }

        // append the remained list
        if (l1 != null) p.next = l1;
        if (l2 != null) p.next = l2;

        return dummyHead.next;
    }

    @Test
    void example1() {
        ListNode l1 = new ListNode(1);
        l1.next = new ListNode(2);
        l1.next.next = new ListNode(4);

        ListNode l2 = new ListNode(1);
        l2.next = new ListNode(3);
        l2.next.next = new ListNode(4);

        ListNode head = mergeTwoLists(l1, l2);

        Assertions.assertEquals(1, head.val);
        Assertions.assertEquals(1, head.next.val);
        Assertions.assertEquals(2, head.next.next.val);
        Assertions.assertEquals(3, head.next.next.next.val);
        Assertions.assertEquals(4, head.next.next.next.next.val);
        Assertions.assertEquals(4, head.next.next.next.next.next.val);
    }

    @Test
    void example2() {
        Assertions.assertNull(mergeTwoLists(null, null));
    }

    @Test
    void example3() {
        ListNode l1 = null;
        ListNode l2 = new ListNode(0);
        ListNode head = mergeTwoLists(l1, l2);
        Assertions.assertEquals(0, head.val);
    }

    @Test
    void example4() {
        ListNode l1 = new ListNode(1);

        ListNode l2 = new ListNode(2);
        l2.next = new ListNode(3);
        l2.next.next = new ListNode(4);

        ListNode head = mergeTwoLists(l1, l2);

        Assertions.assertEquals(1, head.val);
        Assertions.assertEquals(2, head.next.val);
        Assertions.assertEquals(3, head.next.next.val);
        Assertions.assertEquals(4, head.next.next.next.val);
    }
}
