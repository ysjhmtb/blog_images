const ListNode = class {

    constructor(val) {
        this.val = val;
        let next = null;
    }
};


const Solution = class {

    reorderList(head) {

        if (head == null)
            return;

        let list = [];

        let node = head.next;

        while (node != null) {
            list.push(node);
            node = node.next;
        }

        let i = 0;
        let j = list.length - 1;
        let temp = head;

        while (j > i) {
            temp.next = list[j];
            temp = temp.next;
            temp.next = list[i];
            temp = temp.next;
            i++;
            j--;
        }

        if (i == j) {
            temp.next = list[i];
            temp = temp.next;
        }
        temp.next = null;

    }
};


let l1 = new ListNode(1);
let l2 = new ListNode(2);
let l3 = new ListNode(3);
let l4 = new ListNode(4);
let l5 = new ListNode(5);

l1.next = l2;
l2.next = l3;
l3.next = l4;
l4.next = l5;

let ref = new Solution();
ref.reorderList(l1);

let result = l1;

while(result != null){
    console.log(result.val + ", ");
    result = result.next;
}