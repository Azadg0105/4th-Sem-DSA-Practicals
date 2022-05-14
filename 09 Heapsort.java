import java.io.*;
import java.util.*;


public class heapsort {
    public int[] heap;
    public int count;
    public void downadjust(int i) {
        int j, temp, n;
        n = heap[0];
        if (2 * i <= n) {
            j = 2 * i;// j on left child of i
            if (j + 1 <= n && heap[j + 1] > heap[j]) // j points to larger of left and right child
                j = j + 1;
            if (heap[i] < heap[j]) {
                temp = heap[i];
                heap[i] = heap[j];
                heap[j] = temp;
                downadjust(j);
            }
        }
    }
    public void upadjust(int i) {
        int temp;
        while (i > 1 && heap[i] > heap[i / 2]) {
            temp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = temp;
            i = i / 2;
        }
    }
    public void insert(int x) {
        heap[++heap[0]] = x;
        upadjust(heap[0]);
    }
    public void create() {
        int i, x, n;
        heap = new int[30];
        heap[0] = 0;
        Scanner reader = new Scanner(System.in);
        System.out.println("\nEnter No. of elements : ");
        n = reader.nextInt();
        count = n;
        System.out.println("\nEnter heap data : ");
        for (i = 0; i < n; i++) {
            x = reader.nextInt();
            insert(x);
        }
    }
    public void sort() {
        int last, temp;
        while (heap[0] > 1) {
            last = heap[0];
            temp = heap[1];
            heap[1] = heap[last];
            heap[last] = temp;
            heap[0]--;
            downadjust(1);
        }
    }
    public void print() {
        int n, i;
        n = count;
        System.out.println("\nsorted data : ");
        for (i = 1; i <= n; i++)
            System.out.print(" " + heap[i]);
    }

    public static void main(String[] args) {
        int x;
        heapsort myobject = new heapsort();
        myobject.create();
        myobject.sort();
        myobject.print();
    }
}