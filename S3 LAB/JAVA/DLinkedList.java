import java.util.Scanner;

public class DLinkedList {
    class Node {
        int data;
        Node next;
        Node prev;

        Node(int data) {
            this.data = data;
            this.prev = null;
            this.next = null;
        }
    }

    public Node head;

    public void addNode(int data) {
        Node newNode = new Node(data);
        if (head == null)
            head = newNode;
        else {
            Node temp = head;
            while (temp.next != null)
                temp = temp.next;
            temp.next = newNode;
            newNode.prev = temp;
        }
    }

    public void removeNode(int data) {
        if (head == null) {
            System.out.println("List empty");
            return;
        }
        if (head.data == data) {
            if (head.next != null)
                head.next.prev = null;
            head = head.next;
            return;
        }
        Node temp = head;
        while (temp != null) {
            if (temp.data == data)
                break;
            temp = temp.next;
        }
        if (temp == null) {
            System.out.println("data not found");
            return;
        }
        if (temp.next != null)
            temp.next.prev = temp.prev;
        temp.prev.next = temp.next;
    }

    public void display() {
        if (head == null) {
            System.out.println("Empty List ");
            return;
        }
        Node temp = head;
        System.out.print("List :");
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    public static void main(String args[]) {
        DLinkedList list = new DLinkedList();
        while (true) {
            System.out.println("\nEnter \n1. add Node\n2 remove Node\n3 exit");
            Scanner sc = new Scanner(System.in);
            char ch = sc.nextLine().charAt(0);
            switch (ch) {
                case '1':
                    System.out.print("enter the data :");
                    list.addNode(sc.nextInt());
                    list.display();
                    break;
                case '2':
                    System.out.print("enter the data to be delete:");
                    list.removeNode(sc.nextInt());
                    list.display();
                    break;
                case '3':
                    return;
            }
        }
    }
}