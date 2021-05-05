/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab3ds;

import java.util.*;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class Lab_3 {
    public static void main(String[] args) {
        final ReadWriteLock readwriteLock = new ReentrantReadWriteLock();
        final Lock writeLock = readwriteLock.writeLock();
        final Lock readLock = readwriteLock.readLock();
        int n = 10;
        ArrayList<Integer> readerwriteList = new ArrayList<Integer>(n);
        writeLock.lock();
        try {
            for (int i = 0; i < 10; i++) {
                readerwriteList.add(i);
                System.out.println(readerwriteList);
            }
        } finally {
            writeLock.unlock();
        }
        System.out.println(readerwriteList);
        readLock.lock();
        for (int i = 0; i < readerwriteList.size(); i++) {
            System.out.println(readerwriteList.get(i) + "");
        }
        readLock.unlock();
    }

}